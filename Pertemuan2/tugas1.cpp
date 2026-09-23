#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class LinkedList {
private:
    Node* head;
    Node* tail;

public:
    LinkedList() {
        head = NULL;
        tail = NULL;
    }

    void tambahAwal(int nilai) {
        Node* baru = new Node;

        baru->data = nilai;
        baru->next = head;

        head = baru;

        if (tail == NULL) {
            tail = baru;
        }
    }

    void tambahAkhir(int nilai) {
        Node* baru = new Node;

        baru->data = nilai;
        baru->next = NULL;

        if (head == NULL) {
            head = baru;
            tail = baru;
        } else {
            tail->next = baru;
            tail = baru;
        }
    }

    void tambahSetelah(int cari, int nilaiBaru) {
        Node* temp = head;

        while (temp != NULL) {
            if (temp->data == cari) {

                Node* baru = new Node;
                baru->data = nilaiBaru;
                baru->next = temp->next;

                temp->next = baru;

                if (temp == tail) {
                    tail = baru;
                }

                return;
            }

            temp = temp->next;
        }

        cout << "Nilai " << cari << " tidak ditemukan!\n";
    }

    void hapus(int nilai) {
        if (head == NULL) {
            cout << "Linked List kosong!\n";
            return;
        }

        if (head->data == nilai) {
            Node* hapus = head;
            head = head->next;

            if (head == NULL) {
                tail = NULL;
            }

            delete hapus;
            return;
        }

        Node* temp = head;

        while (temp->next != NULL) {
            if (temp->next->data == nilai) {

                Node* hapus = temp->next;

                temp->next = hapus->next;

                if (hapus == tail) {
                    tail = temp;
                }

                delete hapus;
                return;
            }

            temp = temp->next;
        }

        cout << "Nilai " << nilai << " tidak ditemukan!\n";
    }

    void tampilkan() {
        Node* temp = head;

        cout << "Isi Linked List: ";

        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }

        cout << "NULL\n";
    }
};


int main() {
    LinkedList list;

    int pilihan;
    int nilai;
    int nilaiCari;
    int nilaiBaru;

    do {
        cout << "\n===== MENU SINGLE LINKED LIST =====\n";
        cout << "1. Tambah di awal\n";
        cout << "2. Tambah di akhir\n";
        cout << "3. Tambah setelah nilai tertentu\n";
        cout << "4. Hapus berdasarkan nilai\n";
        cout << "5. Tampilkan Linked List\n";
        cout << "0. Keluar\n";
        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan) {

            case 1:
                cout << "Masukkan nilai: ";
                cin >> nilai;

                list.tambahAwal(nilai);
                list.tampilkan();
                break;

            case 2:
                cout << "Masukkan nilai: ";
                cin >> nilai;

                list.tambahAkhir(nilai);
                list.tampilkan();
                break;

            case 3:
                cout << "Masukkan nilai baru: ";
                cin >> nilaiBaru;

                cout << "Masukkan nilai yang ingin dicari: ";
                cin >> nilaiCari;

                list.tambahSetelah(nilaiCari, nilaiBaru);
                list.tampilkan();
                break;

            case 4:
                cout << "Masukkan nilai yang ingin dihapus: ";
                cin >> nilai;

                list.hapus(nilai);
                list.tampilkan();
                break;

            case 5:
                list.tampilkan();
                break;

            case 0:
                cout << "Program selesai.\n";
                break;

            default:
                cout << "Pilihan tidak valid!\n";
        }

    } while (pilihan != 0);

    return 0;
}