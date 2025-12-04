#include "spellchecker.h"

struct WordNode* insertWord(struct WordNode *root, char *word) {
    if (root == NULL) {
        struct WordNode *node = malloc(sizeof(struct WordNode));
        strcpy(node->word, word);
        node->left = node->right = NULL;
        return node;
    }
    if (strcmp(word, root->word) < 0)
        root->left = insertWord(root->left, word);
    else if (strcmp(word, root->word) > 0)
        root->right = insertWord(root->right, word);
    return root;
}
// yo haaris check tjis when u done
struct WordNode* findWord(struct WordNode *root, char *word) {
    if (root == NULL)
        return NULL;
    int cmp = strcmp(word, root->word);
    if (cmp == 0)
        return root;
    else if (cmp < 0)
        return findWord(root->left, word);
    else
        return findWord(root->right, word);
}

void loadDictionary(struct WordNode **root, char *words[], int count) {
    for (int i = 0; i < count; i++)
        *root = insertWord(*root, words[i]);
}

void freeTree(struct WordNode *root) {
    if (root == NULL)
        return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}
