#include <iostream>

// User-defined function untuk mengukur panjang string (pengganti std::string::length / strlen)
int getStringLength(const char str[]) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

// User-defined function untuk enkripsi sandi
void encryptCipher(const char input[], char output[]) {
    int len = getStringLength(input);
    int prevShift = 0;

    for (int i = 0; i < len; i++) {
        char currentChar = input[i];
        
        // Mengubah huruf 'A'-'Z' ke angka 1-26
        int val = currentChar - 'A' + 1;
        
        // Hitung pergeseran modul 26
        int newVal = (val + prevShift - 1) % 26 + 1;
        
        // Huruf saat ini (sebelum dienkripsi) menjadi penggeser untuk huruf berikutnya
        prevShift = val;
        
        // Konversi angka 1-26 kembali ke karakter 'A'-'Z'
        output[i] = (char)(newVal + 'A' - 1);
    }
    output[len] = '\0';
}

int main() {
    char inputMsg[500];
    char encryptedMsg[500];

    std::cout << "Masukkan pesan rahasia (Huruf Kapital): ";
    std::cin >> inputMsg;

    encryptCipher(inputMsg, encryptedMsg);

    std::cout << "Pesan terenkripsi: " << encryptedMsg << std::endl;

    return 0;
}