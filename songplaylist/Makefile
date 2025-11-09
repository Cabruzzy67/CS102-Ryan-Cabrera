CC = gcc
CFLAGS = -Wall -Wextra -std=c99
OBJ = Mainplaylisty.o playlist.o
TARGET = playlist_manager

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

Mainplaylisty.o: Mainplaylisty.c playlist.h
	$(CC) $(CFLAGS) -c Mainplaylisty.c

playlist.o: playlist.c playlist.h
	$(CC) $(CFLAGS) -c playlist.c

clean:
	rm -f $(OBJ) $(TARGET)