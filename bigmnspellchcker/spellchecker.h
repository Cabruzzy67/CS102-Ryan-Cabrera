#ifndef SPELLCHECKER_H
#define SPELLCHECKER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct WordNode {
    char word[50];
  
    struct WordNode *left;
   
    struct WordNode *right;};

struct WordNode* insertWord(struct WordNode *root, char *word);
struct WordNode* findWord(struct WordNode *root, char *word);

void freeTree(struct WordNode *root);
void loadDictionary(struct WordNode **root, char *words[], int count);

#endif
