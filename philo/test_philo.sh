#!/bin/bash

# Couleurs
GREEN='\033[0;32m'
RED='\033[0;31m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

echo -e "${BLUE}=== COMPILATION ===${NC}"
make re

# Fonction 100% compatible Mac pour arrêter un test après X secondes
run_with_timeout() {
    local timeout_sec=$1
    shift
    local cmd=("$@")

    echo -e "${NC}Commande : ${cmd[*]}"
    
    # Lance la commande en arrière-plan
    "${cmd[@]}" &
    local pid=$!

    # Attend le temps spécifié
    sleep "$timeout_sec"

    # Si le processus tourne encore, on le tue
    if kill -0 "$pid" 2>/dev/null; then
        kill "$pid" 2>/dev/null
        wait "$pid" 2>/dev/null
        echo -e "${GREEN}-> Test arrêté proprement par le script après $timeout_sec secondes (C'est normal !)${NC}"
    else
        wait "$pid" 2>/dev/null
        echo -e "${GREEN}-> Le test s'est terminé tout seul avant la limite.${NC}"
    fi
}

echo -e "\n${BLUE}=== TEST 1 : 1 Philosophe ===${NC}"
echo -e "${RED}Attendu : Le philosophe meurt vers 800ms.${NC}"
./philo 1 800 200 200

echo -e "\n${BLUE}=== TEST 2 : Survie tranquille ===${NC}"
echo -e "${GREEN}Attendu : Personne ne meurt (Arrêt auto dans 10s).${NC}"
run_with_timeout 10 ./philo 5 800 200 200

echo -e "\n${BLUE}=== TEST 3 : Repas limités ===${NC}"
echo -e "${GREEN}Attendu : S'arrête tout seul après 7 repas. Personne ne meurt.${NC}"
./philo 5 800 200 200 7

echo -e "\n${BLUE}=== TEST 4 : Timing serré (survie) ===${NC}"
echo -e "${GREEN}Attendu : Personne ne meurt (Arrêt auto dans 10s).${NC}"
run_with_timeout 10 ./philo 4 410 200 200

echo -e "\n${BLUE}=== TEST 5 : Timing mortel ===${NC}"
echo -e "${RED}Attendu : Un philosophe doit mourir assez vite.${NC}"
./philo 4 310 200 100

echo -e "\n${BLUE}=== TEST 6 : 2 Philosophes (Vérification des temps) ===${NC}"
echo -e "${RED}Attendu : Un philosophe meurt.${NC}"
./philo 2 150 60 60

echo -e "\n${BLUE}=== TEST 7 : Fuites de mémoire (Repas limités) ===${NC}"
echo -e "${GREEN}Attendu : Pas de leaks.${NC}"
# Sur Mac 42, on utilise souvent "leaks" à la place de "valgrind"
if command -v valgrind &> /dev/null; then
    valgrind --leak-check=full ./philo 5 800 200 200 7
else
    echo "valgrind non trouvé, test ignoré (tu peux tester avec 'leaks -atExit -- ./philo 5 800 200 200 7')."
fi

echo -e "\n${GREEN}=== TESTS TERMINÉS ===${NC}"