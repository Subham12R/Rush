#include <stdio.h>
#include <stdlib.h>

typedef struct BST
{
    int data;
    struct BST* left;
    struct BST* right;
} BST;

BST* createNode(int data) {
    BST* newNode = (BST*)malloc(sizeof(BST));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

BST* insert(BST* root, int data) {
    if(root == NULL) return createNode(data);

    if(data < root->data) {
        root->left = insert(root->left, data);
    }
    else if(data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

BST* search(BST* root, int data) {
    if(root == NULL || root->data == data) return root;

    if(data < root->data) {
        return search(root->left, data);
    }
    return search(root->right, data);
}

BST* inorder(BST* root) {
    if(root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
    return root;
}
int main(){
    BST* root = NULL;
    
    root = insert(root, 7);
    insert(root, 3);
    insert(root, 2);
    insert(root, 5);
    insert(root, 9);
    insert(root, 8);
    insert(root, 12);

    printf("BST created with root value: %d\n", root->data);
    inorder(root);
    printf("\n");
    return 0;
}
