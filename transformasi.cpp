#include <iostream>
#include <vector>

using namespace std;

void tampilkanMatriks(const vector<vector<double> >& matriks) {
    cout << "Matriks:\n";
    for (const auto& row : matriks) {
        for (double elem : row) {
            cout << elem << " ";
        }
        cout << endl;
    }
}

void tukarBaris(vector<vector<double> >& matriks, int baris1, int baris2) {
    swap(matriks[baris1], matriks[baris2]);
}

void tukarKolom(vector<vector<double> >& matriks, int kolom1, int kolom2) {
    for (auto& row : matriks) {
        swap(row[kolom1], row[kolom2]);
    }
}

void kaliBarisDenganSkalar(vector<vector<double> >& matriks, int baris, double skalar) {
    for (auto& elem : matriks[baris]) {
        elem *= skalar;
    }
}

void kaliKolomDenganSkalar(vector<vector<double> >& matriks, int kolom, double skalar) {
    for (auto& row : matriks) {
        row[kolom] *= skalar;
    }
}

vector<vector<double> > buatMatriksDinamis(int baris, int kolom) {
    vector<vector<double> > matriks(baris, vector<double>(kolom));
    for (int i = 0; i < baris; ++i) {
        for (int j = 0; j < kolom; ++j) {
            cout << "Masukkan elemen [" << i+1 << "][" << j+1 << "]: ";
            cin >> matriks[i][j];
        }
    }
    return matriks;
}

int main() {
    int baris, kolom;
    cout << "Masukkan jumlah baris: ";
    cin >> baris;
    cout << "Masukkan jumlah kolom: ";
    cin >> kolom;

    vector<vector<double> > matriks = buatMatriksDinamis(baris, kolom);
    tampilkanMatriks(matriks);

    string jenisTransformasi; // Ubah jenis variabel menjadi string
    cout << "Apakah Anda ingin melakukan pertukaran baris (B), kolom (K), kali baris dengan skalar (SB), atau kali kolom dengan skalar (SK)? ";
    cin >> ws; // Mengabaikan whitespace yang mungkin tersisa di buffer input
    getline(cin, jenisTransformasi); // Membaca input sebagai string

    if (jenisTransformasi == "B" || jenisTransformasi == "b") {
        int baris1, baris2;
        cout << "Masukkan nomor baris pertama untuk ditukar: ";
        cin >> baris1;
        cout << "Masukkan nomor baris kedua untuk ditukar: ";
        cin >> baris2;
        tukarBaris(matriks, baris1 - 1, baris2 - 1);
    } else if (jenisTransformasi == "K" || jenisTransformasi == "k") {
        int kolom1, kolom2;
        cout << "Masukkan nomor kolom pertama untuk ditukar: ";
        cin >> kolom1;
        cout << "Masukkan nomor kolom kedua untuk ditukar: ";
        cin >> kolom2;
        tukarKolom(matriks, kolom1 - 1, kolom2 - 1);
    } else if (jenisTransformasi == "SB" || jenisTransformasi == "sb") {
        int baris;
        double skalar;
        cout << "Masukkan nomor baris untuk perkalian skalar: ";
        cin >> baris;
        cout << "Masukkan nilai skalar: ";
        cin >> skalar;
        kaliBarisDenganSkalar(matriks, baris - 1, skalar);
    } else if (jenisTransformasi == "SK" || jenisTransformasi == "sk") {
        int kolom;
        double skalar;
        cout << "Masukkan nomor kolom untuk perkalian skalar: ";
        cin >> kolom;
        cout << "Masukkan nilai skalar: ";
        cin >> skalar;
        kaliKolomDenganSkalar(matriks, kolom - 1, skalar);
    } else {
        cout << "Jenis transformasi tidak valid.\n";
        return 1;
    }

    cout << "Setelah transformasi:\n";
    tampilkanMatriks(matriks);

    return 0;
}
