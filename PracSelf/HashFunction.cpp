#include <iostream>
#include <string>
#include <vector>

// A simple custom hash function
// input: The string to hash
// tableSize: The maximum range of the hash (e.g., for an array size)
unsigned long long simpleHash(const std::string& key, int tableSize) {
    unsigned long long hashValue = 0;
    
    // 1. Iterate through each character in the string
    for (char c : key) {
        // 2. MIXING:
        // Multiply current hash by a prime number (33 is a classic choice)
        // and add the ASCII value of the character.
        // The bitwise shift (hashValue << 5) is equivalent to hashValue * 32.
        // So (hashValue << 5) + hashValue is equivalent to hashValue * 33.
        
        hashValue = ((hashValue << 5) + hashValue) + c; 
    }

    // 3. COMPRESSING:
    // Use Modulo (%) to ensure the result fits within our desired range
    return hashValue % tableSize;
}

int main() {
    // Define a "table size" (the range of our output)
    const int TABLE_SIZE = 1000;

    std::string input1;
    std::string input2; // Only one letter difference

    std::cout<<"Enter your input: ";
    std::cin>>input1;
    std::cin>>input2;

    std::cout << "--- Simple Hash Demonstration ---" << std::endl;
    
    unsigned long long hash1 = simpleHash(input1, TABLE_SIZE);
    unsigned long long hash2 = simpleHash(input2, TABLE_SIZE);

    std::cout << "Input: " << input1 << " | Hash: " << hash1 << std::endl;
    std::cout << "Input: " << input2 << " | Hash: " << hash2 << std::endl;

    return 0;
}