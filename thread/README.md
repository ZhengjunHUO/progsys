## Need to link libpthread when compiling jointhread.c 
```bash
gcc -Wall -Wextra -O2 -g -pthread -o main jointhread.c
```
## Compile mutex.c and execute
```bash
$ gcc -Wall -Wextra -pthread -O2 -g -o test mutex.c
$ ./test 
The solde was $1000.
Thread[4993]: Get $900!
Thread[4992]: Overdraft is not allowed!
The solde is $100.
$ ./test 
The solde was $1000.
Thread[4995]: Get $300!
Thread[4996]: Overdraft is not allowed!
The solde is $700.
```
