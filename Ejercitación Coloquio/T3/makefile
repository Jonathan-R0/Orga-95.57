CFLAGS = -g -std=c99 -Wall -Wconversion -Wno-sign-conversion -Werror 
EXEC = exe 
OBJ = len.o cmp.o
CC = gcc

all: $(EXEC)

len.o: len.S
	$(CC) $(CFLAGS) -c len.S

cmp.o: cmp.S
	$(CC) $(CFLAGS) -c cmp.S

$(EXEC): $(OBJ) test.c
	$(CC) $(CFLAGS) $(OBJ) test.c -o $(EXEC)

clean:
	rm $(EXEC) $(OBJ)
