#include <stdio.h>
// R= Ryan H= Haaris comments since his computer sucks
// Pattern 1: Right Triangle R
void rightTriangle(int size) {
    // Outer loop for each rowR
    for (int i = 1; i <= size; i++) {
        // Inner loop prints '*' i times for each row R
        for (int j = 1; j <= i; j++) {
            printf("*");
        }
        printf("\n"); // Move to next line after each row R
    }
}

// Pattern 2: Upside Down Triangle H
void upsideDownTriangle(int size) {
    // Outer loop starts from size and decreases H
    for (int i = size; i >= 1; i--) {
        // Inner loop prints '*' i times H
        for (int j = 1; j <= i; j++) {
            printf("*");
        }
        printf("\n"); // Newline after each row H
    }
}

// Pattern 3: Diamond H
void diamond(int size) {
    // Top half of the diamond H
    for (int i = 1; i <= size; i++) {
        // Print spaces (size - i) for alignment H
        for (int j = 1; j <= size - i; j++) {
            printf(" ");
        }
        // Print stars (2*i - 1) per row H
        for (int k = 1; k <= 2 * i - 1; k++) {
            printf("*");
        }
        printf("\n");
    }

    // Bottom half of the diamond R
    for (int i = size - 1; i >= 1; i--) {
        // Print spaces (size - i) R
        for (int j = 1; j <= size - i; j++) {
            printf(" ");
        }
        // Print stars (2*i - 1) R
        for (int k = 1; k <= 2 * i - 1; k++) {
            printf("*");
        }
        printf("\n");
    }
}

// Pattern 4: Pascal's Triangle R
void pascal(int size) {
    // Loop through each row R
    for (int line = 0; line < size; line++) {
        int num = 1; // First number in each row is always 1 H

        // Loop through elements in each row H
        for (int j = 0; j <= line; j++) {
            printf("%d ", num);
            // Calculate next number using binomial coefficient H
            num = num * (line - j) / (j + 1);
        }
        printf("\n");
    }
}

// Pattern 5: Multiplication Table R
void multiplicationTable(int size) {
    // Loop through rows R
    for (int i = 1; i <= size; i++) {
        // Loop through columns R
        for (int j = 1; j <= size; j++) {
            // Print product with formatting R
            printf("%4d", i * j);
        }
        printf("\n");
    }
}

// Pattern 6: Checkerboard H
void checkerboard(int size) {
    // Loop through rows H
    for (int i = 0; i < size; i++) {
        // Loop through columns H
        for (int j = 0; j < size; j++) {
            // Alternate '*' and space based on sum of indexes H
            if ((i + j) % 2 == 0) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    int choice, size;
    char again = 'y';

   
    while (again == 'y' || again == 'Y') {
     
        printf("=== Pattern Generator ===\n");
        printf("1. Right Triangle\n");
        printf("2. Upside Down Triangle\n");
        printf("3. Diamond\n");
        printf("4. Pascal's Triangle\n");
        printf("5. Multiplication Table\n");
        printf("6. Checkerboard\n");

     
        printf("\nChoose a pattern (1-6): ");
        scanf("%d", &choice);

 
        printf("Enter size: ");
        scanf("%d", &size);
        printf("\n");

      
        if (choice == 1) {
            printf("Right Triangle:\n");
            rightTriangle(size);
        } else if (choice == 2) {
            printf("Upside Down Triangle:\n");
            upsideDownTriangle(size);
        } else if (choice == 3) {
            printf("Diamond:\n");
            diamond(size);
        } else if (choice == 4) {
            printf("Pascal's Triangle:\n");
            pascal(size);
        } else if (choice == 5) {
            printf("Multiplication Table:\n");
            multiplicationTable(size);
        } else if (choice == 6) {
            printf("Checkerboard:\n");
            checkerboard(size);
        } else {
            printf("You cant have that choice, life aint sunshine and rainbows pal. Enter a number between 1 and 6.\n");
        }

        // Ask user to run again for shizzingigles
        printf("\nYou want another pattern man? (y/n): ");
        scanf(" %c", &again); // Leading space to clear leftover newline
        printf("\n");
    }

    
    printf("Thank you for using our Pattern Generator twin!\n");
    return 0;
}
