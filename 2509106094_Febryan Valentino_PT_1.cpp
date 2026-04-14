#include <iostream>
#include <string>

using namespace std;

struct RekapMhs {
    string namaMhs;
    string nim;
    int skor;
};

// 1. BUBBLE SORT: Nama secara Descending (Z-A)
void bubbleSortNama(RekapMhs arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            // Descending: Tukar jika yang kiri LEBIH KECIL dari yang kanan
            if (arr[j].namaMhs < arr[j + 1].namaMhs) {
                RekapMhs temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void selectionSortNilai(RekapMhs arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j].skor < arr[minIdx].skor) {
                minIdx = j;
            }
        }

        RekapMhs temp = arr[minIdx];
        arr[minIdx] = arr[i];
        arr[i] = temp;
    }
}

void insertionSortNIM(RekapMhs arr[], int n) {
    for (int i = 1; i < n; i++) {
        RekapMhs key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j].nim > key.nim) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void tampilkanData(RekapMhs arr[], int n) {
    cout << "\n===============================================" << endl;
    cout << "NIM\t\t| Nama\t\t| Nilai" << endl;
    cout << "-----------------------------------------------" << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i].nim << "\t| " 
             << arr[i].namaMhs << "\t| " 
             << arr[i].skor << endl;
    }
    cout << "===============================================" << endl;
}

int main() {
    int n;
    cout << "Masukkan jumlah mahasiswa: ";
    cin >> n;

    RekapMhs mhs[100]; // Array statis (asumsi maksimal 100)

    for (int i = 0; i < n; i++) {
        cout << "\nData Mahasiswa Ke-" << i + 1 << endl;
        cout << "Nama  : "; cin.ignore(); getline(cin, mhs[i].namaMhs);
        cout << "NIM   : "; cin >> mhs[i].nim;
        cout << "Nilai : "; cin >> mhs[i].skor;
    }

    int pilihan;
    cout << "\n--- MENU SORTING (NIM GENAP) ---" << endl;
    cout << "1. Urut Nama (Descending - Bubble Sort)" << endl;
    cout << "2. Urut Nilai (Ascending - Selection Sort)" << endl;
    cout << "3. Urut NIM (Ascending - Insertion Sort)" << endl;
    cout << "Pilih metode (1-3): ";
    cin >> pilihan;

    switch (pilihan) {
        case 1:
            bubbleSortNama(mhs, n);
            cout << "\n[Hasil: Nama Descending]";
            break;
        case 2:
            selectionSortNilai(mhs, n);
            cout << "\n[Hasil: Nilai Ascending]";
            break;
        case 3:
            insertionSortNIM(mhs, n);
            cout << "\n[Hasil: NIM Ascending]";
            break;
        default:
            cout << "\nPilihan tidak valid!";
            return 0;
    }

    tampilkanData(mhs, n);

    return 0;
}