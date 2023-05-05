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

$(OUTPUT):
	mkdir -p $@

# $@ indicates the token before ':', here => %.o
# $< indicates the first dependency after ':', here => %.c
# $^ indicates all dependencies after ':', here => %.c $(DEPS)
$(OUTPUT)/%.o: %.c $(DEPS) $(OUTPUT)
	$(CC) -c -o $@ $< $(CFLAGS)

# $^ indicates all dependencies after ':', here => $(OBJS)
.PHONY: app
app: $(OBJS)
	$(CC) -o $(BINARY) $^ $(CFLAGS) $(LIBS)

.PHONY: clean
clean:
	rm -f $(OUTPUT)/*.o $(BINARY)
