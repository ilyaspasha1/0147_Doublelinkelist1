#include <iostream>
using namespace std;

// membuat struktur untuk object double linkedList
struct Node {
    // deklarasi noMHS dan name untuk menampung data
    int noMHS;
    string name;
    // deklarasi pointer next dan prev untuk data sebelum dan sesudah
    Node* next;
    Node* prev;
};

// deklarasi pointer START dan pemberian nilai
Node* START = NULL;

// deklarasi prosedur addnode
void addnode() {
    // pembuatan node dan pemberian value untuk data noMHS dan name
    Node* newNode = new Node(); // step 1 buat node baru
    cout << "\nEnter the roll number of the student : ";
    cin >> newNode->noMHS; // assign value to the data field of the new node
    cout << "\nEnter the name of the student : ";
    cin >> newNode->name; // Assign value to the data field of the new node

// Insert the new node in the list
    // kondisi jika START == NULL atau noMHS node baru <= noMHS START
    if (START == NULL || newNode->noMHS <= START->noMHS) {
        // step 2: insert the new node at the beginning
        // kondisi jika START tidak kosong dan noMHS node baru sama dengan noMHS START
        if (START != NULL && newNode->noMHS == START->noMHS) {
            cout << "\033[31mDuplicate roll numbers not allowed\033[0m" << endl;
            delete newNode; // to free the allocated memory for the new node
            return;
        }
        // if the list is empty, make the new node the start
        newNode->next = START; // step 3: make the new node point to the first node
        if (START != NULL) {
            START->prev = newNode; // step 4: make the first node point to the new node
        }
        newNode->prev = NULL; // step 5 : make the new node's prev pointer null
        START = newNode; // step 6 : make the new node the first node
    }
    else {
        // insert the new node in the middle or at the end
        Node* current = START; // step 1.a : start from the first node
        Node* previous = NULL; // step 1.b : previous node is null initially

        // looping selama current != NULL dan noMHS dari current < noMHS newNode
        while (current != NULL && current->noMHS < newNode->noMHS) {
            previous = current; // step 1.d: move the previous to the current
            current = current->next; // step 1.e: move the current to the next
        }

        // set nilai next node baru = current dan prev node baru = previous
        newNode->next = current; // step 4: make the next field of the new node
        newNode->prev = previous; // step 5: make the previous field of the new node

        if (current != NULL) {
            current->prev = newNode; // step 6: make the previous field of the current node point to newNode
        }

        if (previous != NULL) {
            previous->next = newNode; // step 7: make the next field of the previous node point to newNode
        }
        else {
            // if previous is still NULL, it means newNode is now the first node
            START = newNode;
        }
    }
}
