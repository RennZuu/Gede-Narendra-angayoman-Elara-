#include <iostream>
using namespace std;

int main () {
    int n, m, a;
    cout << "Masukkan detik lampu: ";
    cin >> n;

    m = n - 24; 
    a = m % 103;

    if (a >= 1 && a <= 20) {
        cout << "Lampu Hijau";
    } 
    else if (a >= 21 && a <= 23) {
        cout << "Lampu Kuning";
    } 
    else {
        cout << "Lampu Merah";
    }
    return 0;
}
