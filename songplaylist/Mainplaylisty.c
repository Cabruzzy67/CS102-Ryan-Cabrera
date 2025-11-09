#include "playlist.h"

int main() {
    struct Song playlist[MAX_SONGS];
    int song_count = 0;
    int current_numberthing = 0;
    char command[256];

    printf("---------Music Playlist Manager---------\n");
    printf("Commands: add, remove, next, prev, current, list, quit\n");

    while (1) {
        printf("> ");
        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = '\0';

        if (strncasecmp(command, "add", 3) == 0) {
            char title[100], artist[100];
            int duration;
            if (sscanf(command, "add \"%[^\"]\" \"%[^\"]\" %d", title, artist, &duration) == 3)
                add_song(playlist, &song_count, &current_numberthing, title, artist, duration);
            else
                printf("Error: Bad Almanakadd format gng. \n");
        } else if (strncasecmp(command, "remove", 6) == 0) {
            char title[100];
            if (sscanf(command, "remove \"%[^\"]\"", title) == 1)
                remove_song(playlist, &song_count, &current_numberthing, title);
            else
                printf("Error: Your missing format stuff, FWEAH.\n");
        } else if (strcasecmp(command, "next") == 0) {
            next_song(&current_numberthing, song_count);
            print_current(playlist, current_numberthing, song_count);
        } else if (strcasecmp(command, "prev") == 0) {
            prev_song(&current_numberthing, song_count);
            print_current(playlist, current_numberthing, song_count);
        } else if (strcasecmp(command, "current") == 0) {
            print_current(playlist, current_numberthing, song_count);
        } else if (strcasecmp(command, "list") == 0) {
            print_playlist(playlist, song_count, current_numberthing);
        } else if (strcasecmp(command, "quit") == 0) {
            printf("SEEYUH!\n");
            break;
        } else {
            printf("Error: invalid commands twizzy.\n");
        }
    }

    return 0;
}
