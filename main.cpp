#include <iostream>
#include "Cipher.h"

int main()
{
    Cipher test; test.key = 5;

    std::string testMessage = test.encryptMessage ("this is classified and anyone reading this message is a monkey");
    std::cout << "ENCRYPTED: " << testMessage << std::endl;
    std::cout << "DECRYPTED: " << test.decryptMessage (testMessage, 5);
    return 0;
}
