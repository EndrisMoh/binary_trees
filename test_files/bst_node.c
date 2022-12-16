#include <stdio.h>
#include <stdlib.h>

typedef struct BstNode {
    int data;
    struct BstNode *left;
    struct BstNode *right;
} BstNode;

BstNode* BstNode_create(int data) {
    BstNode *rPtr = (BstNode*)malloc(sizeof(BstNode));
    rPtr->data = data;
    rPtr->left = NULL;
    rPtr->right = NULL;
    return rPtr;
}

void BstNode_insert(BstNode **node, int data) {
    if (*node == NULL) {
        *node = BstNode_create(data);
    } else if (data > (*node)->data) {
        BstNode_insert(&(*node)->right, data);
    } else {
        BstNode_insert(&(*node)->left, data);
    }
}

BstNode *BstNode_search(BstNode *node, int data) {
    if (node == NULL) {
        return NULL;
    } else if (data == node->data) {
        return node;
    } else if (data > node->data) {
        return BstNode_search(node->right, data);
    } else {
        return BstNode_search(node->left, data);
    }
}

void BstNode_destroy(BstNode **node) {
    if ((*node)->left != NULL) {
        BstNode_destroy(&(*node)->left);
    }

    if ((*node)->right != NULL) {
        BstNode_destroy(&(*node)->right);
    }

    free(*node);
    *node = NULL;
}

int main() {
    BstNode *root = BstNode_create(10);
    BstNode_insert(&root, 3);
    BstNode_insert(&root, 11);
    BstNode_insert(&root, 5);
    BstNode_insert(&root, 14);
    BstNode_insert(&root, 9);
    BstNode_insert(&root, 13);

    const int MAX_SEARCH = 5;
    int numbers[MAX_SEARCH];
    numbers[0] = 5;
    numbers[1] = 8;
    numbers[2] = 13;
    numbers[3] = 9;
    numbers[4] = 22;

    BstNode *found_node;

    for (int i = 0; i < MAX_SEARCH; ++i) {
        printf("searching [%d] ", numbers[i]);

        found_node = BstNode_search(root, numbers[i]);
        printf("%s.\n", found_node != NULL ? "found" : "not found");
    }

    BstNode_destroy(&root);

    return EXIT_SUCCESS;
}
