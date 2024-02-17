#include <iostream>
#include <vector>

using namespace std;

// Function to perform vector addition
vector<double> tambahVektor(const vector<double>& v1, const vector<double>& v2) {
    int maxLength = max(v1.size(), v2.size());
    vector<double> result(maxLength, 0.0);
    
    for (int i = 0; i < maxLength; i++) {
        if (i < v1.size()) result[i] += v1[i];
        if (i < v2.size()) result[i] += v2[i];
    }
    
    return result;
}

// Function to perform vector subtraction
vector<double> kurangVektor(const vector<double>& v1, const vector<double>& v2) {
    int maxLength = max(v1.size(), v2.size());
    vector<double> result(maxLength, 0.0);
    
    for (int i = 0; i < maxLength; i++) {
        if (i < v1.size()) result[i] += v1[i];
        if (i < v2.size()) result[i] -= v2[i];
    }
    
    return result;
}

// Function to perform dot product
double dotProduct(const vector<double>& v1, const vector<double>& v2) {
    if (v1.size() != v2.size()) {
        cout << "Vektor harus memiliki dimensi yang sama untuk produk dot" << endl;
        return 0.0; // Return 0 in case of dimension mismatch
    }
    
    double result = 0.0;
    
    for (int i = 0; i < v1.size(); i++) {
        result += v1[i] * v2[i];
    }
    
    return result;
}

int main() {
    int dimensi;
    cout << "Masukkan jumlah dimensi (2/3): ";
    cin >> dimensi;
    
    vector<double> vektorA(dimensi);
    vector<double> vektorB(dimensi);
    
    cout << "Masukkan komponen vektor A:" << endl;
    for (int i = 0; i < dimensi; i++) {
        cout << "A" << i + 1 << ": ";
        cin >> vektorA[i];
    }
    
    cout << "Masukkan komponen vektor B:" << endl;
    for (int i = 0; i < dimensi; i++) {
        cout << "B" << i + 1 << ": ";
        cin >> vektorB[i];
    }
    
    char operasi;
    cout << "Pilih operasi (+ untuk penjumlahan, - untuk pengurangan, . untuk produk dot): ";
    cin >> operasi;
    
    if (operasi == '+') {
        vector<double> hasil = tambahVektor(vektorA, vektorB);
        cout << "Hasil penjumlahan vektor: (";
        for (int i = 0; i < hasil.size(); i++) {
            cout << hasil[i];
            if (i < hasil.size() - 1) cout << ", ";
        }
        cout << ")" << endl;
    } else if (operasi == '-') {
        vector<double> hasil = kurangVektor(vektorA, vektorB);
        cout << "Hasil pengurangan vektor: (";
        for (int i = 0; i < hasil.size(); i++) {
            cout << hasil[i];
            if (i < hasil.size() - 1) cout << ", ";
        }
        cout << ")" << endl;
    } else if (operasi == '.') {
        double hasil = dotProduct(vektorA, vektorB);
        cout << "Hasil produk dot vektor: " << hasil << endl;
    } else {
        cout << "Operasi tidak valid." << endl;
    }
    
    return 0;
}
