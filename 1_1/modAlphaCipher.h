#ifndef MODALPHACIPHER_H
#define MODALPHACIPHER_H

#include <string>
#include <vector>

class modAlphaCipher
{
private:
    const std::string numAlpha = "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";
    std::vector<int> key;

    std::vector<int> textToIndices(const std::string& text) const;
    std::string indicesToText(const std::vector<int>& indices) const;

public:
    modAlphaCipher() = delete;
    modAlphaCipher(const std::string& skey);
    std::string encrypt(const std::string& open_text);
    std::string decrypt(const std::string& cipher_text);
};

#endif
