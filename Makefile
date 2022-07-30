VPATH = src/

CC = gcc
CFLAGS = -lstdc++

objs = main.o lp.o

all: despacho

despacho: $(objs)
	$(CC) $(objs) $(CFLAGS) -o despacho

main.o: main.cpp lp.h
lp.o: lp.cpp lp.h

clean:
	-rm -f $(objs) *~
purge: clean
	-rm -f despacho
