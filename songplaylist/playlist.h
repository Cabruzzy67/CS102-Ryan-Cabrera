#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_SONGS 100

struct Song {
    char title[MAX_SONGS];
    char artist[MAX_SONGS];
    int duration;
};

void add_song(struct Song playlist[], int *song_count, int *current_numberthing,
              char *title, char *artist, int duration);
void remove_song(struct Song playlist[], int *song_count, int *current_numberthing,
                 char *title);
void next_song(int *current_numberthing, int song_count);
void prev_song(int *current_numberthing, int song_count);
void print_current(struct Song playlist[], int current_numberthing, int song_count);
void print_playlist(struct Song playlist[], int song_count, int current_numberthing);
void format_duration(int seconds, char *buffer);

#endif
