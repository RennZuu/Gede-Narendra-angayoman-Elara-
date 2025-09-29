#include <iostream>
#include <string>
using namespace std;

bool isVokal(char c) {
    c = tolower(c);
    return (c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o');
}

string balikString(const string &s) {
    string hasil = "";
    for (int i = s.length() - 1; i >= 0; i--) {
        hasil += s[i];
    }
    return hasil;
}

int main() {
    string password;
    cout << "Masukkan password: ";
    cin >> password;

    // Cari posisi angka ASCII di tengah
    int pos = 0;
    while (pos < password.size() && !isdigit(password[pos])) pos++;

    // Ambil angka ASCII
    string asciiStr = "";
    while (pos < password.size() && isdigit(password[pos])) {
        asciiStr += password[pos];
        pos++;
    }

    int asciiFirst = stoi(asciiStr);
    char firstChar = char(asciiFirst);

    // Gabungkan string tanpa angka ASCII
    string tanpaAngka = password.substr(0, password.find(asciiStr)) 
                      + password.substr(password.find(asciiStr) + asciiStr.length());

    // Balik string pakai loop
    tanpaAngka = balikString(tanpaAngka);

    // Jika huruf pertama (ASCII) adalah vokal → taruh di belakang
    if (isVokal(firstChar)) {
        tanpaAngka += firstChar;
    }

    cout << "\nPassword: " << password << endl;
    cout << "Kode ASCII: " << asciiFirst << " = " << firstChar << endl;
    cout << "Kata tanpa vokal: " << tanpaAngka << endl;

    return 0;
}

