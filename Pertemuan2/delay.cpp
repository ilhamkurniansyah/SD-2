#include <iostream>
using namespace std;

// Deklarasi Struktur Node
struct Node {
    int value;
    Node *next;
};

Node *head = NULL;
Node *tail = NULL;

// Fungsi Cetak List
void printList() {
    Node *temp = head;

    cout << "Isi Linked List: ";

    while (temp != NULL) {
        cout << temp->value << " -> ";
        temp = temp->next;
    }

    cout << "NULL\n";
}

// Fungsi tambah node di akhir
void insertLast(int n) {
    Node *newNode = new Node{n, NULL};

    if (head == NULL) {
        head = tail = newNode;
    }
    else {
        tail->next = newNode;
        tail = newNode;
    }
}

// Hapus node pertama
void deleteFirst() {
    if (head == NULL) {
        cout << "Listnya kosong\n";
        return;
    }

    Node *temp = head;

    head = head->next;

    if (head == NULL) {
        tail = NULL;
    }

    delete temp;
}

// Hapus node terakhir
void deleteLast() {
    if (head == NULL) {
        cout << "Listnya kosong\n";
        return;
    }

    // Jika hanya ada satu node
    if (head == tail) {
        delete head;
        head = NULL;
        tail = NULL;
        return;
    }

    Node *p = head; //mulai p dari head

    // Cari node sebelum tail
    while (p->next != tail) {
        p = p->next;
    }

    delete tail;

    tail = p;
    tail->next = NULL;
}

// Hapus node dengan nilai tertentu
void deleteMiddle(int value) {
    if (head == NULL) {
        cout << "Listnya kosong\n";
        return;
    }

    // Jika yang dihapus adalah node pertama
    if (head->value == value) {
        deleteFirst();
        return;
    }

    Node *temp = head;

    // Cari node sebelum node yang akan dihapus
    while (temp->next != NULL && temp->next->value != value) {
        temp = temp->next;
    }

    // Jika nilai tidak ditemukan
    if (temp->next == NULL) {
        cout << "Nilai " << value << " tidak ditemukan\n";
        return;
    }

    Node *hapus = temp->next;

    temp->next = hapus->next;

    // Jika node yang dihapus adalah tail
    if (hapus == tail) {
        tail = temp;
    }

    delete hapus;
}

int main() {
    // Contoh list awal
    insertLast(10);
    insertLast(20);
    insertLast(30);

    cout << "List awal:\n";
    printList();

    cout << "\nHapus node pertama:\n";
    deleteFirst();
    printList();

    cout << "\nHapus node terakhir:\n";
    deleteLast();
    printList();

    cout << "\nHapus node dengan nilai 20:\n";
    deleteMiddle(20);
    printList();

    return 0;
}