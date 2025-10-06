#include "modAlphaCipher.h"

modAlphaCipher::modAlphaCipher(const std::string& skey)
{
    key = textToIndices(skey);
}

std::vector<int> modAlphaCipher::textToIndices(const std::string& text) const
{
    std::vector<int> indices;
    size_t i = 0;
    while (i < text.size()) {
        if (i + 1 >= text.size()) break;
        std::string letter = text.substr(i, 2);

        // Ищем букву в алфавите
        for (size_t pos = 0; pos < numAlpha.size(); pos += 2) {
            if (numAlpha.substr(pos, 2) == letter) {
                indices.push_back(static_cast<int>(pos / 2));
                break; // нашли — выходим из цикла
            }
        }
        i += 2;
    }
    return indices;
}

std::string modAlphaCipher::indicesToText(const std::vector<int>& indices) const
{
    std::string result;
    for (int idx : indices) {
        if (idx >= 0 && idx < static_cast<int>(numAlpha.size() / 2)) {
            result += numAlpha.substr(idx * 2, 2);
        }
    }
    return result;
}

std::string modAlphaCipher::encrypt(const std::string& open_text)
{
    std::vector<int> work = textToIndices(open_text);
    int alphabetSize = static_cast<int>(numAlpha.size() / 2); // 33
    for (size_t i = 0; i < work.size(); ++i) {
        work[i] = (work[i] + key[i % key.size()]) % alphabetSize;
    }
    return indicesToText(work);
}

std::string modAlphaCipher::decrypt(const std::string& cipher_text)
{
    std::vector<int> work = textToIndices(cipher_text);
    int alphabetSize = static_cast<int>(numAlpha.size() / 2); // 33
    for (size_t i = 0; i < work.size(); ++i) {
        work[i] = (work[i] - key[i % key.size()] + alphabetSize) % alphabetSize;
    }
    return indicesToText(work);
}
