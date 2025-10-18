#include <stdio.h>
#include <stdlib.h>
#include "csv_parser.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <csv_file>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        printf("Error: Cannot open file %s\n", argv[1]);
        return 1;
    }

    printf("--------CS102 CSV Parser--------\nCSV Preview:\n\n");

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        char *p = line;
        while (*p) {
            if (*p == '\n' || *p == '\r') {
                *p = '\0';
                break;
            }
            p++;
        }

        parse_and_print(line);
    }

    fclose(file);
    return 0;
}
