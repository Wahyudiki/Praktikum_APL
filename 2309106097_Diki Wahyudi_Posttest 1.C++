#include <iostream>
#include <string>
#include <cmath>

using namespace std;

// Deklarasi fungsi
void tampilkanMenu();
bool validasiLogin(string, string);
void konversiSuhu();

int main() {
    char ulangProgram;
    string user, pass;

    do {
        cout << "Masukkan Username: ";
        cin >> user;
        cout << "Masukkan Password: ";
        cin >> pass;

        if (validasiLogin(user, pass)) {
            konversiSuhu();
        } else {
            cout << "Batas login maksimum. Program Berhenti." << endl;
            return 0;
        }

        cout << "\nUlang program? (y/n) ";
        cin >> ulangProgram;
    } while (ulangProgram == 'y' || ulangProgram == 'n');

    return 0;
}

void tampilkanMenu() {
    cout << "Konversi Suhu" << endl;
    cout << "1. Celcius ke Reamur, Fahrenheit, Kelvin" << endl;
    cout << "2. Reamur ke Celcius, Fahrenheit, Kelvin" << endl;
    cout << "3. Fahrenheit ke Celcius, Reamur, Kelvin" << endl;
    cout << "4. Kelvin ke Celcius, Reamur, Fahrenheit" << endl;
    cout << "Masukkan pilihan Anda (1-4): ";
}

bool validasiLogin(string user, string pass) {
    static const string USERNAME = "diki";
    static const string PASSWORD = "097";
    int chances = 3;
    bool loginSuccess = false;

    while (chances > 0) {
        if (user == USERNAME && pass == PASSWORD) {
            loginSuccess = true;
            cout << "Login Berhasil!" << endl;
            break;
        } else {
            chances--;
            cout << "Login Gagal! Sisa Percobaan: " << chances << endl;
            cout << "Masukkan Username: ";
            cin >> user;
            cout << "Masukkan Password: ";
            cin >> pass;
        }
    }

    return loginSuccess;
}

void konversiSuhu() {
    int choice;
    double temp, celcius, reamur, fahrenheit, kelvin;

    tampilkanMenu();
    cin >> choice;

    switch (choice) {
        case 1:
            cout << "Masukkan suhu dalam Celcius: ";
            cin >> celcius;
            reamur = celcius * 0.8;
            fahrenheit = (celcius * 9 / 5) + 32;
            kelvin = celcius + 273.15;
            cout << "Reamur: " << reamur << endl;
            cout << "Fahrenheit: " << fahrenheit << endl;
            cout << "Kelvin: " << kelvin << endl;
            break;
        case 2:
            cout << "Masukkan suhu dalam Reamur: ";
            cin >> reamur;
            celcius = reamur * 1.25;
            fahrenheit = (celcius * 9 / 5) + 32;
            kelvin = celcius + 273.15;
            cout << "Celcius: " << celcius << endl;
            cout << "Fahrenheit: " << fahrenheit << endl;
            cout << "Kelvin: " << kelvin << endl;
            break;
        case 3:
            cout << "Masukkan suhu dalam Fahrenheit: ";
            cin >> fahrenheit;
            celcius = (fahrenheit - 32) * 5 / 9;
            reamur = celcius * 0.8;
            kelvin = celcius + 273.15;
            cout << "Celcius: " << celcius << endl;
            cout << "Reamur: " << reamur << endl;
            cout << "Kelvin: " << kelvin << endl;
            break;
        case 4:
            cout << "Masukkan suhu dalam Kelvin: ";
            cin >> kelvin;
            celcius = kelvin - 273.15;
            reamur = celcius * 0.8;
            fahrenheit = (celcius * 9 / 5) + 32;
            cout << "Celcius: " << celcius << endl;
            cout << "Reamur: " << reamur << endl;
            cout << "Fahrenheit: " << fahrenheit << endl;
            break;
        default:
            cout << "Pilihan tidak valid!" << endl;
    }
}