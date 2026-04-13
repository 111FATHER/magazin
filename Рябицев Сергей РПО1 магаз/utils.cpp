#include "utils.h"
#include <iostream>
#include <unordered_set>
#include <Windows.h>

bool IsNumber(const std::string& str) {
    if (str.size() <= 0 || str.size() >= 10) {
        std::cout << "Неверный ввод\n";
        Sleep(1500);
        return false;
    }
    for (size_t i = 0; i < str.size(); i++) {
        if (!std::isdigit(str[i])) {
            std::cout << "Неверный ввод\n";
            Sleep(1500);
            return false;
        }
    }
    return true;
}

bool CheckLogin(const std::string& str) {
    if (str.size() < 5 || str.size() >= 20) {
        std::cout << "Недопустимая длина логина. От 5 до 19\n";
        Sleep(1500);
        return false;
    }
    for (char c : str) {
        if (!((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))) {
            std::cout << "Некорректные символы в логине\n";
            Sleep(1500);
            return false;
        }
    }
    return true;
}

bool CheckPass(const std::string& str) {
    if (str.size() < 5 || str.size() > 64) {
        std::cout << "Недопустимая длина пароля! От 5 до 64\n";
        Sleep(1500);
        return false;
    }
    std::unordered_set<char> specials{ '!','@','#','$','%','^','&','*','(',')','-','=','+','/','?','|','\\','"',
        '\'',',','.','<','>','~','`',':',';','{','}','[',']' };
    int specialCount = 0;
    for (char c : str) {
        if (!((c >= '!' && c <= '~'))) {
            std::cout << "Некорректные символы в пароле\n";
            Sleep(1500);
            return false;
        }
        if (specials.count(c)) specialCount++;
    }
    if (specialCount < 3) {
        std::cout << "Требуется минимум 3 спецсимвола\n";
        Sleep(1500);
        return false;
    }
    return true;
}

void Getline(std::string& str) {
    std::getline(std::cin, str, '\n');
}

void Err(int time) {
    std::cout << "Неверный ввод\n";
    Sleep(time);
    system("cls");
}