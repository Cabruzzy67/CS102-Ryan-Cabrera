#include "playlist.h"

void format_duration(int seconds, char *buffer) {
    int minutes = seconds / 60;
    int sec = seconds % 60;
    sprintf(buffer, "%d:%02d", minutes, sec);
}

void add_song(struct Song playlist[], int *song_count, int *current_numberthing,
              char *title, char *artist, int duration) {
    if (*song_count >= MAX_SONGS) {
        printf("Error: ur playlist is full bro.\n");
        return;
    }
    strcpy(playlist[*song_count].title, title);
    strcpy(playlist[*song_count].artist, artist);
    playlist[*song_count].duration = duration;
    (*song_count)++;
    if (*song_count == 1)
        *current_numberthing= 0;
    char dur[10];
    format_duration(duration, dur);
    printf("Added: \"%s\" by %s (%s)\n", title, artist, dur);
}

void remove_song(struct Song playlist[], int *song_count, int *current_numberthing,
                 char *title) {
    int found = -1;
    for (int i = 0; i < *song_count; i++) {
        if (strcmp(playlist[i].title, title) == 0) {
            found = i;
            break;
        }
    }
    if (found == -1) {
        printf("Error: song not found womp womp.\n");
        return;
    }
    printf("Removed: \"%s\" by %s\n",
           playlist[found].title, playlist[found].artist);
    for (int j = found; j < *song_count - 1; j++)
        playlist[j] = playlist[j + 1];
    (*song_count)--;
    if (*song_count == 0)
        *current_numberthing = 0;
    else if (*current_numberthing >= *song_count)
        *current_numberthing = *song_count - 1;
}

void next_song(int *current_numberthing, int song_count) {
    if (song_count == 0) {
        printf("Error:  ur playlist is empty.\n");
        return;
    }
    if (*current_numberthing >= song_count - 1) {
        printf("Error: you reached the end of the playlist.\n");
        return;
    }
    (*current_numberthing)++;
}

void prev_song(int *current_numberthing, int song_count) {
    if (song_count == 0) {
        printf("Error: playlist is empty twin.\n");
        return;
    }
    if (*current_numberthing <= 0) {
        printf("Error: slow your role pal you reached the beginning of the playlist.\n");
        return;
    }
    (*current_numberthing)--;
}

void print_current(struct Song playlist[], int current_numberthing, int song_count) {
    if (song_count == 0) {
        printf("Error: playlist is empty.\n");
        return;
    }
    char dur[10];
    format_duration(playlist[current_numberthing].duration, dur);
    printf("Now playing: %s by %s (%s)\n",
           playlist[current_numberthing].title,
           playlist[current_numberthing].artist,
           dur);
}

void print_playlist(struct Song playlist[], int song_count, int current_numberthing) {
    if (song_count == 0) {
        printf("Playlist is empty.\n");
        return;
    }
    int total = 0;
    for (int i = 0; i < song_count; i++)
        total += playlist[i].duration;
    char total_dur[10];
    format_duration(total, total_dur);
    printf("Playlist (%d songs, %s total):\n", song_count, total_dur);
    for (int i = 0; i < song_count; i++) {
        char dur[10];
        format_duration(playlist[i].duration, dur);
        if (i == current_numberthing)
            printf(" [→] %s - %s (%s)\n", playlist[i].title, playlist[i].artist, dur);
        else
            printf("     %s - %s (%s)\n", playlist[i].title, playlist[i].artist, dur);
    }
}
