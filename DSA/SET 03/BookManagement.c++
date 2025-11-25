#include <iostream>
using namespace std;

struct BST {
    int isbn;
    struct BST* right;
    struct BST* left;
};

struct BST* createNode(int isbn){
    struct BST* newNode = new BST();
    newNode->right = newNode->left = nullptr;
    newNode->isbn = isbn;
    return newNode;
}


struct BST* insert(struct BST* root, int isbn){
    if(root == nullptr){
        return createNode(isbn);
    }

    if(isbn < root->isbn)root->left = insert(root->left, isbn);
    if(isbn > root->isbn)root->right = insert(root->right, isbn);

    return root;
}

struct BST* search(struct BST* root, int isbn){
    if(root == nullptr || root->isbn == isbn){
        return root;
    }

    if(isbn < root->isbn)return search(root->left, isbn);
    return search(root->right, isbn);
}

void inorder(struct BST* root){
    if(root != nullptr){
    inorder(root->left);
    cout<< root->isbn << " ";
    inorder(root -> right);
    }
}

struct BST* findMin(struct BST* root){
    while(root && root->left != nullptr)
        root = root->left;
    return root;
}

struct BST* deleteNode(struct BST* root, int isbn) {
    if (root == NULL) {
        printf("Book not found!\n");
        return root;
    }

    if (isbn < root->isbn)
        root->left = deleteNode(root->left, isbn);
    else if (isbn > root->isbn)
        root->right = deleteNode(root->right, isbn);
    else {
       
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        }
    
        else if (root->left == NULL) {
            struct BST* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct BST* temp = root->left;
            free(root);
            return temp;
        }
    
        else {
            struct BST* temp = findMin(root->right);
            root->isbn = temp->isbn;
            root->right = deleteNode(root->right, temp->isbn);
        }
    }
    return root;
}



int main() {
    struct BST* root = NULL;
    int choice, isbn;

    while (1) {
        printf("\n--- BOOK MANAGEMENT SYSTEM (BST) ---\n");
        printf("1. Insert a book\n");
        printf("2. Search a book\n");
        printf("3. Delete a book\n");
        printf("4. Display all books (Inorder)\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter ISBN to insert: ");
                scanf("%d", &isbn);
                root = insert(root, isbn);
                break;

            case 2:
                printf("Enter ISBN to search: ");
                scanf("%d", &isbn);
                if (search(root, isbn))
                    printf("Book with ISBN %d exists.\n", isbn);
                else
                    printf("Book not found.\n");
                break;

            case 3:
                printf("Enter ISBN to delete: ");
                scanf("%d", &isbn);
                root = deleteNode(root, isbn);
                break;

            case 4:
                printf("Books in sorted order: ");
                inorder(root);
                printf("\n");
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }
}