#include <iostream>
#include <cstring>
using namespace std;

struct Node{
    char song[50];
    Node* next;
};

Node* head = nullptr;

Node* createNode(char song[]){
    Node* newNode = new Node;
    strcpy(newNode->song, song);
    newNode->next = nullptr;
    return newNode;
}

void insertBeginning(char song[]){
    Node* newNode = createNode(song);
    newNode->next = head;
    head = newNode;
    cout << "Song Inserted at the Beginning" << endl;   
}

void insertEnd(char song[]){
    Node* newNode = createNode(song);
    if(head == nullptr){
        head = newNode;
    }else{
        Node* temp  = newNode;

        while (temp->next == nullptr)temp = temp->next;

        temp->next = newNode;

        cout << "Song Inserted at the End" << endl;
        
    }
}


void insertatPos(char song[], int pos){
    if(pos == 1){
        insertBeginning(song);
        return;
    }

    Node* newNode = createNode(song);
    Node* temp = head;

    for(int i = 1; i < pos - 1 && temp != nullptr; i++)
        temp = temp->next;

    if(temp == nullptr){
        cout<<"Invalid Position"<<endl;
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    cout << "Song Inserted at position";
}


void deleteBeginning(){
    if(head == nullptr){
        cout << "Playlist Empty!" << endl;
    }
    Node* temp = head;
    head = head->next;
    free(temp);
    cout << "Song deleted from beginning";
}

void deleteEnd(){
    if(head == nullptr){
        cout << "Playlist Empty!" << endl;
    }
    if(head->next == nullptr){
        free(head);
        head = nullptr;
        return;
        cout<<"Deleted from End"<<endl;
    }

    Node* temp = head;
    while(temp->next == nullptr){
        temp->next = temp;
    }

    free(temp->next);
    temp->next = nullptr;

    cout<<"Deleted from End"<<endl;
}

void deletePos(int pos){
    Node* temp = head;
    if(head == nullptr){
        cout << "Playlist Empty!" << endl;
    }
    if(pos == 1){
        deleteBeginning();
        return;
    }

    for(int i = 1; temp != nullptr && i < pos - 1; i++)
        temp = temp->next;

    if (temp == nullptr || temp->next == nullptr) {
        printf("Position out of range.\n");
        return;
    }

    Node* deleteNode = temp->next;
    temp->next = deleteNode->next;
    free(deleteNode);

    cout << "Song deleted from position" << endl;
}

void bulkInsert(int n){
    char song[50];

    for(int i = 0; i<n; i++){
        cout << "Enter Song " << i + 1; 
        cin >> song;
        insertEnd(song);
    }
}

void playSongs(){
    if(head == nullptr){
        cout << "Playlist Empty" << endl;
        return;
    }

    Node* temp = head;
    cout << "Playing Songs: " << endl;
    while(temp != nullptr){
        cout << "Playing song: " << temp->song << endl;
        temp = temp->next;
    }
}

int main(){
    int choice, pos;
    char song[50];

    while(true){
        cout << "1. Insert Beginning \n";
        cout << "2. Insert End \n";
        cout << "3. Insert Position \n";
        cout << "4. Delete Beginning \n";
        cout << "5. Delete End \n";
        cout << "6. Delete Position \n";
        cout << "7. Bulk Insert \n";
        cout << "8. Play songs \n";
        cout << "9. Exit \n";
        cout << "Enter choice: ";
        cin >> choice;
    switch (choice) {
    
            case 1:
                cout << "Enter song name: ";
                cin >> song;
                insertBeginning(song);
                break;

            case 2:
                cout << "Enter song name: ";
                cin >> song;
                insertEnd(song);
                break;

            case 3:
                cout << "Enter song name: ";
                cin >> song;
                cout << "Enter position: ";
                cin >> pos;
                insertatPos(song, pos);
                break;

            case 4:
                deleteBeginning();
                break;

            case 5:
                deleteEnd();
                break;

            case 6:
                cout << "Enter position: ";
                cin >> pos;
                deletePos(pos);
                break;

            case 7:
                int n;
                cout << "Enter no. of songs: ";
                cin >> n;
                bulkInsert(n);

                break;

            case 8:
                playSongs();
                
                break;

            case 9: 
                cout << "Exiting ... ";
                return 0;

                break;

            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }
    return 0;
}