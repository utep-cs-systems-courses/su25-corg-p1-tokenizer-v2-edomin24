OBJS = uimain.o tokenizer.o tester.o

CFLAGS = -g -O3

all: runner

# Compile .o files from .c files

uimain.o: uimain.c tokenizer.h history.h
	cc $(CFLAGS) -c uimain.c

tokenizer.o: tokenizer.c tokenizer.h
	cc $(CFLAGS) -c tokenizer.c

history.o: history.h history.c
	cc $(CFLAGS) -c history.c

runner: $(OBJS)
	cc $(CFLAGS) -o runner $(OBJS)

clean:
	rm -f *.o runner

run: runner
	./runner

