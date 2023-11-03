from Crypto.Cipher import DES

# Define the 64-bit plaintext and 64-bit key in binary format
plaintext_binary = "0000000001010110011101010100010001110101011000110100000101101110"
key_binary = "0101010101010010011011010111100101001100011011110111011001100101"

# Convert binary strings to bytes
plaintext = int(plaintext_binary, 2).to_bytes(len(plaintext_binary) // 8, byteorder='big')
key = int(key_binary, 2).to_bytes(len(key_binary) // 8, byteorder='big')

# Initialize the DES cipher in ECB mode with the 8-byte key
cipher = DES.new(key, DES.MODE_ECB)

# Encrypt the plaintext
ciphertext = cipher.encrypt(plaintext)

# Decrypt the ciphertext
decipher = DES.new(key, DES.MODE_ECB)
decrypted_data = decipher.decrypt(ciphertext)

# Print the results
print("Original plaintext (binary):", plaintext_binary)
print("Encrypted ciphertext (hex):", format(int.from_bytes(ciphertext, byteorder='big'), '064b'))
print("Decrypted plaintext (binary):", format(int.from_bytes(decrypted_data, byteorder='big'), '064b'))
