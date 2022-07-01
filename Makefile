CC=gcc
CFLAGS=-Wall -g -Iinc
SRCDIR=src
OBJDIR=obj
DSTDIR=dst
SRCS=$(SRCDIR)/rbuffer.c ./test.c
OBJS=$(OBJDIR)/rbuffer.o ./test.o
INCDIR=inc

all: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(DSTDIR)/test

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(INCDIR)/%.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f obj/*.o dst/*
