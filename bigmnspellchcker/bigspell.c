#include "spellchecker.h"

int bigspell() {
    struct WordNode *root = NULL;
    char *dictionary[] = {"alphanakly", "sigma", "allocp", "krishmam", "helly", "computer", "science", "cooper", "stack"};
    int wordCount = sizeof(dictionary) / sizeof(dictionary[0]);
    printf("Hold up twin lemme pull up the dictionary...\n");


    loadDictionary(&root, dictionary, wordCount);
    printf("I found %d words: ", wordCount);
    for (int i = 0; i < wordCount; i++) 
    
    
    
    {
        printf("%s", dictionary[i]);
        if (i < wordCount - 1) printf(", ");
    }
    printf("\n");
    char input[50];
    while (1) {
        printf("Give me a word to check (or 'quit' to exit): ");
        scanf("%49s", input);
        if (strcmp(input, "quit") == 0)
            break;





        struct WordNode *result = findWord(root, input);
        if (result)
            printf("\"%s\" is spelled correctly good boy\n", input);
        else
            printf("\"%s\" is NOT in the dictionary go back to hss and read some books gng\n", input);
    }
    printf("SEEYUH!\n");
    freeTree(root);
    return 0;
}
