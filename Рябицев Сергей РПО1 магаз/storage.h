#pragma once
#include <string>

extern size_t storageSize;
extern bool staticStorageCreated;
extern int* idArr;
extern std::string* nameArr;
extern unsigned int* countArr;
extern double* priceArr;

void CreateStorage();
void ShowStorage(int mode = 0);
void AddStorageItem();
void RemoveStorageItem();
void ChangePrice();
void ChangeStorage();
void AddNewStorage();
void AddNewItem();
void ChangeName();
void DeleteItem();