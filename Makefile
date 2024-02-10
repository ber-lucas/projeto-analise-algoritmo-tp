CC = gcc
CFLAGS = -g -Wall

TARGET = tp
SOURCE = tp

ALGORITMOS = ag.c fb.c pd.c util.c

all: $(TARGET).c
	$(CC) $(CFLAGS) -o $(SOURCE) $(ALGORITMOS) $(TARGET).c

clean: 
	$(RM) $(SOURCE) output.txt