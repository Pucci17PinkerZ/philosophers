*This project has been created as part of the 42 curriculum by nfiora-d.*

# 🧠 Philosopers

![Language](https://img.shields.io/badge/Language-C-blue)
![School](https://img.shields.io/badge/School-42-black)

## 📋 Description
This project is a simulation of the classic **Dining Philosophers problem**, a famous illustration of synchronization issues in concurrent programming.
The goal is to manage multiple threads (philosophers) competing for limited resources (forks) without falling into **deadlock** or **starvation**.

---

## 🛠️ Instructions
Way of use :

### Compilation
To compile the mandatory part:
```bash
cd philo && make
```

```bash
./philo <nbr_of_philo> <time_to_die> <time_to_eat> <time_to_sleep> [number_of_times_each_philosopher_must_eat]
```

the parameter -> number_of_times_each_philosopher_must_eat is optional.

The max of Philo is 200.

All state changes are formatted specifically as required by the subject:

	- `timestamp_in_ms X has taken a fork` 

	- `timestamp_in_ms X is eating` 

	- `timestamp_in_ms X is sleeping` 

	- `timestamp_in_ms X is thinking` 

	- `timestamp_in_ms X died` 

	- **Constraint**: Death messages must be displayed within **10 ms** of the actual death. 

## Resources

Youtube video explaining Threads (portfolio courses)

- [https://youtu.be/ldJ8WGZVXZk?si=1mE-J_w9k-9516Ef](https://youtu.be/ldJ8WGZVXZk?si=1mE-J_w9k-9516Ef)

Youtube video explaining Mutex (portfolio courses)

- [https://youtu.be/raLCgPK-Igc?si=LNbVmxWqYDeu_OYc](https://youtu.be/raLCgPK-Igc?si=LNbVmxWqYDeu_OYc)

website explaining the concept

- [https://www.codequoi.com/threads-mutex-et-programmation-concurrente-en-c/](https://www.codequoi.com/threads-mutex-et-programmation-concurrente-en-c/)


---
