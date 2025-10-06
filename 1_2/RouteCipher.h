#pragma once
#include <string>
#include <vector>
#include <stdexcept>
#include <map>

class CipherError : public std::invalid_argument {
public:
    explicit CipherError(const std::string& WhatArg) : 
        std::invalid_argument(WhatArg) {}
    explicit CipherError(const char* WhatArg) : 
        std::invalid_argument(WhatArg) {}
};

class RouteCipher {
private:
    int Columns;
    std::wstring RussianAlphabet = L"АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";
    
    void ValidateKey(int Key);
    void ValidateText(const std::wstring& Text);
    std::wstring PrepareText(const std::wstring& Text);
    std::wstring RemoveSpacesAndPunctuation(const std::wstring& Text);
    std::wstring ToUpperCase(const std::wstring& Text);
    
public:
    RouteCipher() = delete;
    RouteCipher(int Key);
    
    std::wstring Encrypt(const std::wstring& Text);
    std::wstring Decrypt(const std::wstring& Text);
    
    int GetColumns() const { return Columns; }
};
