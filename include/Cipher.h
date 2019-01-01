#ifndef CIPHER_H
#define CIPHER_H
#include <random>
#include <time.h>
#include <string>

class Cipher
{
    public:
        Cipher();
        virtual ~Cipher();

        int key = 0;

        std::string encryptMessage (std::string message);

        std::string decryptMessage (std::string message, int key);

    protected:

    private:
        char alphabet [26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

        int returnAlphabetIndexOfCharacter (char character);

        int returnShiftedAlphabetIndex (int index);

        int returnNormalAlphabetIndex (int index, int key);

        void setKeyEqualToCharacter (int characterIndex);
};

#endif // CIPHER_H
