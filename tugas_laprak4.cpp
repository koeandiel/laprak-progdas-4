#include <iostream>
#include <vector>
#include <string>
#include <limits> // Untuk std::numeric_limits

using namespace std;

// Class untuk daftar nama
class NameList {
private:
    vector<string> names; // Menyimpan daftar nama

public:
    // Method non-return type untuk menambah nama
    void addName(const string& name) {
        names.push_back(name);
        cout << "Nama '" << name << "' berhasil ditambahkan.\n";
    }

    // Method non-return type untuk menampilkan semua nama
    void displayNames() {
        cout << "Daftar Nama:\n";
        for (size_t i = 0; i < names.size(); ++i) {
            cout << i + 1 << ". " << names[i] << endl;
        }
    }

    // Method dengan return type untuk mencari nama
    bool findName(const string& name) {
        for (const auto& n : names) {
            if (n == name) {
                return true; // Mengembalikan true jika nama ditemukan
            }
        }
        return false; // Mengembalikan false jika nama tidak ditemukan
    }
};

// Fungsi untuk menampilkan menu
void displayMenu() {
    cout << "=== Menu Daftar Nama ===\n";
    cout << "1. Tambah Nama\n";
    cout << "2. Tampilkan Nama\n";
    cout << "3. Cari Nama\n";
    cout << "4. Keluar\n";
    cout << "========================\n";
}

// Fungsi untuk mendapatkan pilihan dari pengguna
int getUserChoice() {
    int choice;
    cout << "Masukkan pilihan Anda: ";
    
    // Loop untuk memastikan input yang valid
    while (true) {
        cin >> choice;

        if (cin.fail()) {
            cin.clear(); // Menghapus kesalahan
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Mengabaikan input yang salah
            cout << "Input tidak valid. Silakan masukkan angka: ";
        } else {
            cin.ignore(); // Mengabaikan karakter newline setelah input angka
            return choice;
        }
    }
}

// Fungsi non-return type untuk menjalankan program
void runNameListSystem() {
    NameList nameList;
    int choice;

    do {
        displayMenu();
        choice = getUserChoice();

        string name;
        switch (choice) {
            case 1:
                cout << "Masukkan nama: ";
                getline(cin, name); // Menggunakan getline untuk nama dengan spasi
                nameList.addName(name);
                break;
            case 2:
                nameList.displayNames();
                break;
            case 3:
                cout << "Masukkan nama yang dicari: ";
                getline(cin, name); // Menggunakan getline untuk nama dengan spasi
                if (nameList.findName(name)) {
                    cout << "Nama '" << name << "' ditemukan.\n";
                } else {
                    cout << "Nama '" << name << "' tidak ditemukan.\n";
                }
                break;
            case 4:
                cout << "Keluar dari program.\n";
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi.\n";
        }

        // Menunggu input dari pengguna sebelum melanjutkan
        cout << "Tekan Enter untuk melanjutkan...";
        cin.get(); // Menunggu input dari pengguna
    } while (choice != 4);
}

int main() {
    runNameListSystem(); // Menjalankan sistem daftar nama
    return 0;
}
