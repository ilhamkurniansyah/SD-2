#include <iostream>
using namespace std;

// Deklarasi sebuah struktur node
struct Node {
    int value;
    Node *next;
};

Node *head = NULL;
Node *tail = NULL;

// Insert di depan
void insertFirst(int n) {
    Node *newNode = new Node;

    newNode->value = n;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        tail = head;
    }
    else {
        newNode->next = head;
        head = newNode;
    }
}

// Insert di belakang
void insertLast(int n) {
    Node *newNode = new Node;

    newNode->value = n;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        tail = head;
    }
    else {
        tail->next = newNode;
        tail = newNode;
    }
}

// Insert setelah nilai tertentu
void insertAfter(int n, int check) {
    if (head == NULL) {
        cout << "Linked list kosong, tidak dapat menambahkan node setelah "
             << check << endl;
        return;
    }

    Node *newNode = new Node;

    newNode->value = n;
    newNode->next = NULL;

    Node *p = head;

    // Mencari node dengan nilai check
    while (p != NULL && p->value != check) {
        p = p->next;
    }

    // Jika node tidak ditemukan
    if (p == NULL) {
        cout << "Node dengan nilai " << check << " tidak ada\n";
        delete newNode;
    }
    else {
        // Hubungkan node baru
        newNode->next = p->next;
        p->next = newNode;

        // Jika p adalah node terakhir
        if (p == tail) {
            tail = newNode;
        }
    }
}

// Cetak linked list
void printList() {
    Node *temp = head;

    cout << "Isi dari linked list : ";

    while (temp != NULL) {
        cout << temp->value << " -> ";
        temp = temp->next;
    }

    cout << "NULL\n";
}

int main() {
    insertFirst(10);
    insertLast(20);
    insertLast(30);
    insertAfter(25, 20);
    insertFirst(5);

    printList();

    return 0;
}
