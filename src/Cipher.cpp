#include "Cipher.h"

Cipher::Cipher()
{
    //ctor
}

Cipher::~Cipher()
{
    //dtor
}

std::string Cipher::encryptMessage (std::string message) {

    std::string encryptedMessage = "";

    for (unsigned int i = 0; i < message.length (); i++) {

        char character = message [i];
        int characterIndex = returnAlphabetIndexOfCharacter (character);
        int shiftedIndex = returnShiftedAlphabetIndex (characterIndex);

        if (shiftedIndex != -1) { character = alphabet [shiftedIndex]; }

        encryptedMessage += character;

        if (characterIndex != -1) { setKeyEqualToCharacter (characterIndex); }

    }

    return encryptedMessage;
}

void Cipher::setKeyEqualToCharacter (int characterIndex) { key = characterIndex; }

std::string Cipher::decryptMessage (std::string message, int key) {

    std::string decryptedMessage = "";

    setKeyEqualToCharacter (key);

    for (unsigned int i = 0; i < message.length (); i++) {

        char character = message [i];
        int characterIndex = returnAlphabetIndexOfCharacter (character);
        int normalIndex = returnNormalAlphabetIndex (characterIndex, this->key);

        if (normalIndex != -1) { character = alphabet [normalIndex]; setKeyEqualToCharacter (normalIndex); }

        decryptedMessage += character;

    }

    return decryptedMessage;

}

int Cipher::returnAlphabetIndexOfCharacter (char character) {

    const int ALPHABET_SIZE = 26;
    const int CHARACTER_NOT_FOUND = -1;

    for (unsigned int i = 0; i < ALPHABET_SIZE; i++) {

        if (alphabet [i] == character) { return i; }

    }

    return CHARACTER_NOT_FOUND;

}

int Cipher::returnShiftedAlphabetIndex (int index) {

    if (index != -1) {
        int shiftedIndex = index + key;

        if (shiftedIndex > 25) { shiftedIndex -= 25; }

        return shiftedIndex;

    } else {
        return -1;

    }

}

int Cipher::returnNormalAlphabetIndex (int index, int key) {

    if (index != -1) {
        int normalIndex = index - key;

        if (normalIndex < 0) { normalIndex += 25; }

        return normalIndex;

    } else {
        return -1;

    }

}
