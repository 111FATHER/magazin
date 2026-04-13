#pragma once
#include <string>

bool IsNumber(const std::string& str);
bool CheckLogin(const std::string& str);
bool CheckPass(const std::string& str);
void Getline(std::string& str);
void Err(int time = 1500);

template<typename T>
void SwapArr(T* Arr, T* Arr2, size_t SizeArr) {
    for (size_t i = 0; i < SizeArr; i++) {
        Arr[i] = Arr2[i];
    }
}
