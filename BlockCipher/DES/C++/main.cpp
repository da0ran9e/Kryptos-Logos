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

    cout << "Original data: " << hex << data.to_ullong() << endl;
    cout << "Original key: " << hex << originalKey.to_ullong() << endl;
    cout << "Encrypted data: " << hex << encryptedData.to_ullong() << endl;
    cout << "Decrypted data: " << hex << decryptedData.to_ullong() << endl;

    return 0;
}
