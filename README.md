# philosophers
Solving the Dining Philosopher Problem in C.  
Using Mutex, pthread, semaphore funcions

## Build and Run

```
git clone git@github.com:kyoshong/philosophers.git
cd philosophers
```

### Mandatory

Each philosopher is a thread

```
cd philo && make
```
### Bonus
Each philosopher is a process
```
cd philo_bonus && make
```

### Run philosophers
| No. | argument |
|--|--|
| 0 | build file name : philo / philo_bonus |
| 1 | number of philosophers (under 200) |
| 2 | time to die (milliseconds) |
| 3 | time to eat (milliseconds) |
| 4 | time to sleep (milliseconds) |
| 5 | number of times each philosopher must eat (optional) |

ex) 
```
./philo 500 200 100 
```
