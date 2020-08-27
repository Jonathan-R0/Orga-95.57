CFLAGS = -g -std=c99 -Wall -Wconversion -Wno-sign-conversion -Werror 
EXEC = exe 
OBJ = len.o
CC = gcc

all: $(EXEC)

len.o: len.S
	$(CC) $(CFLAGS) -c len.S

$(EXEC): $(OBJ) my_strlen.c
	$(CC) $(CFLAGS) $(OBJ) my_strlen.c -o $(EXEC)

clean:
	rm $(EXEC) $(OBJ)
