#include <iostream>
#include <string>

int main() {
    std::string nama;
    std::string nim;
    std::string jurusan;
    int semester;

    std::cout << "=== Biodata Mahasiswa ===\n";
    std::cout << "Nama     : ";
    std::getline(std::cin, nama);

    std::cout << "NIM      : ";
    std::getline(std::cin, nim);

    std::cout << "Jurusan  : ";
    std::getline(std::cin, jurusan);

    std::cout << "Semester : ";
    std::cin >> semester;

    std::cout << "\n=== Data Mahasiswa ===\n";
    std::cout << "Nama     : " << nama << '\n';
    std::cout << "NIM      : " << nim << '\n';
    std::cout << "Jurusan  : " << jurusan << '\n';
    std::cout << "Semester : " << semester << '\n';

    return 0;
}