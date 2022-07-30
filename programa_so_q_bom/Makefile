CC = gcc
CFLAGS = -lstdc++

objs = main.o lp.o

all: lp_gen

lp_gen: $(objs)
	$(CC) $(objs) $(CFLAGS) -o lp_gen

main.o: main.cpp lp.h
lp.o: lp.cpp lp.h

clean:
	-rm -f $(objs) *~
purge: clean
	-rm -f lp_gen
