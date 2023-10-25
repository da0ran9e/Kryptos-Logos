#include <iostream>
#include "cbc/plaintext_processor.hpp"
#include "cbc/CBC.hpp"
#include "cbc/keys.hpp"

using namespace std;

int main() {
    bitset<124> data(0x0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ);
    bitset<64> originalKey(0x0123456789ABCDEF); // 64-bit original key

    // Perform DES encryption
    bitset<64> encryptedData = encryptCBC(data, originalKey, initialVector);

    cout << "Data: \t\t" << hex << data.to_ullong() << "\t\t" << data << endl;
    cout << "Key: \t\t" << hex << originalKey.to_ullong() << "\t\t" << originalKey << endl;
    cout << "Encrypted: \t" << hex << encryptedData.to_ullong() << "\t" << encryptedData << endl;
    cout << "Decrypted: \t" << hex << decryptedData.to_ullong() << "\t" << decryptedData << endl;

    return 0;
}
