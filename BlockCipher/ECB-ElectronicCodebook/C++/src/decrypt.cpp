#include "../cbc/final_permutation.hpp"
#include "../cbc/initial_permutation.hpp"
#include "../cbc/key_scheduler.hpp"
#include "../cbc/f_function.hpp"
#include "../cbc/decrypt.hpp"
#include "../cbc/permutations.hpp"

std::bitset<64> decryptDES(std::bitset<64> data, std::bitset<64> originalKey) {
    data = finalPermutation(data);
    // Mã hóa khóa ban đầu để lấy được khóa vòng cuối
    std::bitset<48> subKeys[16];
    generate_subkeys(originalKey, subKeys);

    // Phân chia dữ liệu 64 bit thành hai nửa
    std::bitset<32> leftHalf, rightHalf;
    for (int i = 0; i < 32; ++i) {
        leftHalf[i] = data[i];
        rightHalf[i] = data[i + 32];
    }

    // Thực hiện 16 vòng giải mã
    for (int round = 15; round >= 0; --round) {
        std::bitset<32> tempLeft = leftHalf;

        // Thực hiện hàm F trên nửa phải và XOR với nửa trái
        std::bitset<32> fResult = f(rightHalf, subKeys[round]);
        leftHalf = rightHalf ^ fResult;
        rightHalf = tempLeft;
    }

    // Kết hợp lại nửa trái và nửa phải
    std::bitset<64> decryptedData;
    for (int i = 0; i < 32; ++i) {
        decryptedData[i] = rightHalf[i];
        decryptedData[i + 32] = leftHalf[i];
    }

    decryptedData = initialPermutation(decryptedData);

    // std::bitset<64> permutedData;
    // for (int i = 0; i < 64; ++i) {
    //     permutedData[i] = decryptedData[initialPermutationTable[i] - 1];
    // }

    return decryptedData;
}