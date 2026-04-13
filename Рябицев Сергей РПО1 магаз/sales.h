#pragma once
#include <string>

extern size_t checkSize;
extern int* idArrCheck;
extern std::string* nameArrCheck;
extern unsigned int* countArrCheck;
extern double* priceArrCheck;
extern double* totalPriceArrCheck;
extern double cash;
extern double cashIncome;
extern double bankIncome;

void Selling();
void CheckArrAppend();
void PrintCheck(double& totalSum);
void StorageReturner();
void ShowIncome();