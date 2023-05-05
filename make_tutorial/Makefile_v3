CC=gcc
CFLAGS=-I.
DEPS = helloapp.h

# $@ indicates the token before ':', here => %.o
# $< indicates the first dependency after ':', here => %.c
# $^ indicates all dependencies after ':', here => %.c $(DEPS)
%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

.PHONY: app
app: helloapp.o appfunc.o
	$(CC) -o helloapp helloapp.o appfunc.o
