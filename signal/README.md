## sigqueue & sigaction
```bash
gcc -Wall -Wextra -O2 -g -o listen sigaction.c 
gcc -Wall -Wextra -O2 -g -o send sigqueue.c

# in first terminal; note down the printed pid
./listen 

# in second termial
./send <PID>
```
