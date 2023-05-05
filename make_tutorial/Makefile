CC=gcc
IDIR=./include
CFLAGS=-I$(IDIR)
OUTPUT=.output
BINARY=helloapp
LIBS=-lm
_DEPS=helloapp.h
DEPS=$(patsubst %,$(IDIR)/%,$(_DEPS))
_OBJS=helloapp.o appfunc.o 
OBJS=$(patsubst %,$(OUTPUT)/%,$(_OBJS))

# @ means not to print the command being executed
$(OUTPUT):
	@mkdir -p $@

# $@ indicates the token before ':', here => %.o
# $< indicates the first dependency after ':', here => %.c
# $^ indicates all dependencies after ':', here => %.c $(DEPS)
# | indicates an order-only prerequisites: built before a target, but without forcing the target to be updated if the prerequisite is updated
$(OUTPUT)/%.o: %.c $(DEPS) | $(OUTPUT)
	$(CC) -c -o $@ $< $(CFLAGS)

# $^ indicates all dependencies after ':', here => $(OBJS)
$(BINARY): $(OBJS)
	$(CC) -o $(BINARY) $^ $(CFLAGS) $(LIBS)

.PHONY: clean
clean:
	rm -f $(OUTPUT)/*.o $(BINARY)
