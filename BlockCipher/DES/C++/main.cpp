#include <iostream>
#include "des/encrypt.hpp"
#include "des/decrypt.hpp"

using namespace std;

int main() {
    bitset<64> data(0x0123456789ABCDEF); // 64-bit data
    bitset<64> originalKey(0x0123456789ABCDEF); // 64-bit original key

    // Perform DES encryption
    bitset<64> encryptedData = encryptDES(data, originalKey);
    bitset<64> decryptedData = decryptDES(encryptedData, originalKey);

    cout << "Data: \t\t" << hex << data.to_ullong() << "\t\t" << data << endl;
    cout << "Key: \t\t" << hex << originalKey.to_ullong() << "\t\t" << originalKey << endl;
    cout << "Encrypted: \t" << hex << encryptedData.to_ullong() << "\t" << encryptedData << endl;
    cout << "Decrypted: \t" << hex << decryptedData.to_ullong() << "\t" << decryptedData << endl;

    return 0;
}
