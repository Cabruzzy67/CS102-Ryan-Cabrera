CC = gcc
CFLAGS = -Wall -Wextra -std=c99
OBJ = bigspell.o spellchecker.o
TARGET = bigspell

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

bigspell.o: bigspell.c spellchecker.h
	$(CC) $(CFLAGS) -c bigspell.c

spellchecker.o: spellchecker.c spellchecker.h
	$(CC) $(CFLAGS) -c spellchecker.c

clean:
	rm -f $(OBJ) $(TARGET)
