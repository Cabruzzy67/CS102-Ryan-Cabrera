#include <stdio.h>
#include <stdlib.h>
#include "csv_parser.h"

void parse_and_print(char *line) {
    char *fields[10]; 
    int count = 0;
    char *start = line;

    while (*line) {
        if (*line == ',') {
            *line = '\0';
            fields[count++] = start;
            start = line + 1;
        }
        line++;
    }
    fields[count++] = start;

    printf("Name: %s\n", fields[0]);
    printf("Grades: ");

    float sum = 0;
    int numGrades = 0;

    for (int i = 1; i < count; i++) {
        printf("%s", fields[i]);
        if (i < count - 1) printf(", ");
        sum += atof(fields[i]);
        numGrades++;
    }

    float avg = sum / numGrades;
    printf("\nAverage: %.2f\n\n", avg);
}
