# Philosophers

**Global Rules**

- Global variables are forbidden!
- Your(s) program(s) should take the following arguments: <br/>  	`number_of_philosophers` `time_to_die` `time_to_eat` `time_to_sleep `    `\[number_of_times_each_philosopher_must_eat \] `
  - **number_of_philosophers**: The number of philosophers and also the number of forks.
  - **time_to_die** (in miliseconds): If a philosopher didn't start eating time_to_die miliseconds since the beginning of their last meal or the beginning of the simulation, they die.
  - **time_to_eat** (in milliseconds): The time it takes for a philosopher to eat. During that time, they will need to hold two forks.
  - **time_to_sleep** (in milliseconds): The time a philosopher will spend sleeping.
  - **number_of_times_each_philosopher_must_eat** (optional argument): If all philosophers have eaten at least number_of_times_each_philosopher_must_eat times, the simulation stops. If not specified, the simulation stops when a philosopher dies.
- Each philisopher has a number ranging from 1 to number_of_philosophers.
- Philosopher number 1 sits next to philosopher number number_of_philosophers. Any other philosopher number N sits between philosopher number N - 1 and philosopher number N + 1.

About the logs of your program:

- Any state change of a philosopher must be formatted as follows:
  - timestamp_in_ms X has taken a fork
  - timestamp_in_ms X is eating
  - timestamp_in_ms X is sleeping
  - timestamp_in_ms X is thinking
  - timestamp_in_ms X died
- A displayed state message should not be mixed up with another message.
- A message announcing a philosopher died should be displayed no more than 10 ms after the actual death of the philosopher.
- Again, philosophers should avoid dying!

**Project Instructions**

| Specs  | Explanation |
| ------------- | ------------- |
| Program name | philo |
| Turn in files | Makefile, \*.h, \*c, in directory philo/ |
| Makefile | NAME, all, clean, fclean, re |
| Arguments | number_of_philosophers time_to_die time_to_eat time_to_sleep <br/> \[number_of_times_each_philosopher_must_eat \] |
| External functs. | memset, printf, malloc, free, write, <br/> usleep, gettimeofday, pthread_create, <br/> pthread_detach, pthread_join, pthread_mutex_init, <br/> pthread_mutex_destroy, pthread_mutex_lock, <br/> pthread_mutex_unlock |
| Libft authorized | No |
| Description | Philosophers with threads and mutexes |

The specific rules for the mandatory part are:
- Each philosopher should be a thread.
- There is one fork between each pair of philosophers. Therefore, if there are severa philosophers, each philosophers has a fork on their left side and a fork on their right side. If there is only one philosopher, there should be only one fork on the table.
- To prevent philosophers from duplication forks, you should protect the forks state with a mutex for each of them.
