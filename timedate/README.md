## nanosleep
```bash
gcc -Wall -Wextra -O2 -g -o sleep nanosleep2.c 
./sleep
Process 5828 will sleep 30 sec ...
^CCatch signal [Interrupt]!
Receive interrupt signal, still got 24 sec 679778672 nanosec to sleep ...
Catch signal [Interrupt]!
Receive interrupt signal, still got 17 sec 409923482 nanosec to sleep ...
Catch signal [Interrupt]!
Receive interrupt signal, still got 9 sec 12056961 nanosec to sleep ...
Done !

# Do a Ctrl+c to interrupt 
# Or in another terminal
kill -SIGINT 5828
```

### POSIX Timer
```bash
gcc -Wall -Wextra -lrt -O2 -g -o timer timer.c
```
