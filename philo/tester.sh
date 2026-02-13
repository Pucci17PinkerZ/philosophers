#!/bin/bash

PHILO="./philo"
RED='\033[0;31m'
GREEN='\033[0;32m'
BLUE='\033[0;34m'
NC='\033[0m'

echo -e "${BLUE}=== PHILOSOPHERS STRESS TESTER ===${NC}"

# Fonction de verification
check_survival() {
    ARGS="$1"
    DURATION="$2"
    NAME="$3"
    
    echo -n "Test: $NAME ($ARGS) ... "
    OUTPUT=$(timeout $DURATION $PHILO $ARGS)
    
    if echo "$OUTPUT" | grep -q "died"; then
        echo -e "${RED}[FAIL]${NC}"
        echo "   -> Un philosophe est mort (log: $(echo "$OUTPUT" | grep "died" | head -n 1))"
    else
        echo -e "${GREEN}[PASS]${NC}"
    fi
}

check_death() {
    ARGS="$1"
    NAME="$2"
    
    echo -n "Test: $NAME ($ARGS) ... "
    OUTPUT=$($PHILO $ARGS)
    
    if echo "$OUTPUT" | grep -q "died"; then
        echo -e "${GREEN}[PASS]${NC}"
    else
        echo -e "${RED}[FAIL]${NC}"
        echo "   -> Personne n'est mort (ou message manquant)"
    fi
}

# 1. Correction du bug d'initialisation
# Si philo meurt à t=0 ou t=1, c'est FAIL.
check_survival "4 410 200 200" "5s" "Basique (Survie)"

# 2. Test Impair (Souvent source de blocage si l'algo est mauvais)
# 5 philos doivent survivre. Si l'algo est naif, un philo 'vole' la fourchette et un autre meurt.
check_survival "5 800 200 200" "5s" "Impair (5 Philos)"

# 3. Test de Performance (Beaucoup de threads)
# Vérifie si le PC tient la charge et si les mutex ne ralentissent pas trop
check_survival "199 800 200 200" "5s" "Stress CPU (199 Philos)"

# 4. Test "Tight" (Temps serrés)
# 4 philos, die=310, eat=200, sleep=100.
# Cycle: Eat(200) + Sleep(100) = 300ms. Il reste 10ms de marge avant 310ms.
# Si ton usleep est imprécis ou ton code lent, ça meurt.
check_survival "4 310 200 100" "5s" "Timing Serré (Marge 10ms)"

# 5. Test de Mort Précise
# Philo 1, die 200. Doit mourir vite.
check_death "1 200 0 0" "Mort Rapide"

echo -e "${BLUE}=== FIN DES TESTS ===${NC}"