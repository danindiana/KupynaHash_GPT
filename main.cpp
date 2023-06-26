#include "kupyna.h"
#include <iostream>
#include <iomanip>

int main() {
    // Define the message to be hashed
    const uint8_t message[] = "This is a test message for Kupyna hashing algorithm.";
    const size_t message_length = sizeof(message) - 1;  // Exclude null terminator

    // Define the size of the hash output (can be from 8 to 512 bits)
    const size_t hash_size = 256; // Kupyna-256 (in bits)

    // Calculate the hash of the message
    uint8_t hash[hash_size / 8];
    kupyna_hash(message, message_length, hash, hash_size);

    // Output the hash in hexadecimal format
    std::cout << "Hash of the message: ";
    for (size_t i = 0; i < hash_size / 8; ++i) {
        std::cout << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(hash[i]);
    }
    std::cout << std::dec << std::endl;

    return 0;
}
