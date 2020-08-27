CFLAGS = -g -std=c99 -Wall -Wconversion -Wno-sign-conversion -Werror 
EXEC = exe 
OBJ = fasm.o
CC = gcc

all: $(EXEC)

fasm.o: fasm.S
	$(CC) $(CFLAGS) -c fasm.S

$(EXEC): $(OBJ) segundo_parcial.c
	$(CC) $(CFLAGS) $(OBJ) segundo_parcial.c -o $(EXEC)

clean:
	rm $(EXEC) $(OBJ)
