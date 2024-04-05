// This is aes based on FIPS 197

#include<iostream>
#include<string>
#include<vector>

// addRoundKey() is a transformation of the state in which a round key is combined with the state by applying the bitwise XOR operation
void addRoundKey(std::string* input, std::string key){

}

// subBytes() is an invertible, non-linear transformation of the state in which a substitution table, called an S-box, is applied independently to each byte in the state
void subBytes(std::string* input){

}

// shiftRows() is a transformation of the state in which the bytes in the last three rows of the state are cyclically shifted. 
void shiftRows(std::string* input){

}

// mixColumns() is a transformation of the state that multiplies each of the four columns of the state by a single fixed matrix
void mixColumns(std::string* input){

}

// The function Cipher() is general and can be applied to 128,192, and 256 bit aes
// Cipher() takes a message string to encrypt, the number of rounds to repeat a procedure, and an encryption key.
// It them outputs cipherText based on the message
std::string cipher(std::string message, int numRounds, std::string key){
    std::string cipherText = message;

    addRoundKey(&cipherText, key.substr(0,4));

    for (int i = 0; i < numRounds - 1; i++){
        subBytes(&cipherText);
        shiftRows(&cipherText);
        mixColumns(&cipherText);
        addRoundKey(&cipherText, key.substr(4 * i, 4));
    }

    subBytes(&cipherText);
    shiftRows(&cipherText);
    addRoundKey(&cipherText, key.substr(4 * numRounds, 4));

    return cipherText;
}


int main(){
    return 0;
}