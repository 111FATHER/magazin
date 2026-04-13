#include "sales.h"
#include "storage.h"
#include "discounts.h"
#include "users.h"
#include "utils.h"
#include <iostream>
#include <windows.h>
#include <iomanip>

size_t checkSize = 0;
int* idArrCheck = nullptr;
std::string* nameArrCheck = nullptr;
unsigned int* countArrCheck = nullptr;
double* priceArrCheck = nullptr;
double* totalPriceArrCheck = nullptr;

double cash = 10000 + rand() % 7000;
double cashIncome = 0.0;
double bankIncome = 0.0;

void CheckArrAppend() {
    checkSize++;

    int* idArrCheckTemp = new int[checkSize];
    std::string* nameArrCheckTemp = new std::string[checkSize];
    unsigned int* countArrCheckTemp = new unsigned int[checkSize];
    double* priceArrCheckTemp = new double[checkSize];
    double* totalPriceArrCheckTemp = new double[checkSize];

    if (checkSize - 1 > 0) {
        SwapArr(idArrCheckTemp, idArrCheck, checkSize - 1);
        SwapArr(nameArrCheckTemp, nameArrCheck, checkSize - 1);
        SwapArr(countArrCheckTemp, countArrCheck, checkSize - 1);
        SwapArr(priceArrCheckTemp, priceArrCheck, checkSize - 1);
        SwapArr(totalPriceArrCheckTemp, totalPriceArrCheck, checkSize - 1);
    }

    std::swap(idArrCheck, idArrCheckTemp);
    std::swap(nameArrCheck, nameArrCheckTemp);
    std::swap(countArrCheck, countArrCheckTemp);
    std::swap(priceArrCheck, priceArrCheckTemp);
    std::swap(totalPriceArrCheck, totalPriceArrCheckTemp);

    delete[] idArrCheckTemp;
    delete[] nameArrCheckTemp;
    delete[] countArrCheckTemp;
    delete[] priceArrCheckTemp;
    delete[] totalPriceArrCheckTemp;
}

void PrintCheck(double& totalSum) {
    std::cout << "№\t" << "ID\t" << std::left << std::setw(25) << "Название товара\t\t" << "Цена за ед\t" << "Кол-во\t" << "Итого\n";

    for (size_t i = 0; i < checkSize; i++) {
        std::cout << i + 1 << "\t" << idArrCheck[i] << "\t" << std::left << std::setw(25) << nameArrCheck[i] << "\t" << priceArrCheck[i] << "\t\t" << countArrCheck[i] << "\t" << totalPriceArrCheck[i] << "\n";
    }
}

void StorageReturner() {
    for (size_t i = 0; i < checkSize; i++) {
        countArr[idArrCheck[i] - 1] += countArrCheck[i];
    }

    delete[] idArrCheck;
    delete[] nameArrCheck;
    delete[] countArrCheck;
    delete[] priceArrCheck;
    delete[] totalPriceArrCheck;

    idArrCheck = nullptr;
    nameArrCheck = nullptr;
    countArrCheck = nullptr;
    priceArrCheck = nullptr;
    totalPriceArrCheck = nullptr;

    checkSize = 0;
}

void ShowIncome() {
    std::cout << "Текущая прибыль за смену\n\n";
    std::cout << "Наличный расчет - " << cashIncome << "\n";
    std::cout << "Безналичный расчет - " << bankIncome << "\n";
    std::cout << "Итого - " << cashIncome + bankIncome << "\n\n";
    std::cout << "Сумма ваших продаж - " << awardArr[currentId] << "\n";
    system("pause");
    system("cls");
}

void Selling() {
    std::string chooseId, chooseCount, choose, chooseCash;
    unsigned int id = 0, count = 0, index = -1;
    double totalSum = 0.0, money = 0.0;
    bool isFirst = false;

    if (checkSize > 0) {
        delete[] idArrCheck;
        delete[] nameArrCheck;
        delete[] countArrCheck;
        delete[] priceArrCheck;
        delete[] totalPriceArrCheck;
        idArrCheck = nullptr;
        nameArrCheck = nullptr;
        countArrCheck = nullptr;
        priceArrCheck = nullptr;
        totalPriceArrCheck = nullptr;
        checkSize = 0;
    }

    while (true) {
        ShowStorage();

        std::cout << "\nВведите ID товара для покупки или \"exit\" для завершения покупок - ";
        Getline(chooseId);

        if (chooseId == "exit") {
            if (isFirst == false) {
                std::cout << "Выход без покупок\n";
                Sleep(1500);
                break;
            }

            system("cls");
            PrintCheck(totalSum);

            double originalSum = totalSum;
            totalSum = Discounts(totalSum);

            if (totalSum < originalSum) {
                std::cout << "\n----------------------------------\n";
                std::cout << "Сумма до скидок: " << originalSum << " руб.\n";
                std::cout << "Сумма после скидок: " << totalSum << " руб.\n";
                std::cout << "Экономия: " << (originalSum - totalSum) << " руб.\n";
                std::cout << "------------------------------------\n";
            }

            std::cout << "\nПодтвердите покупку?\n1 - Да\n2 - Добавить ещё товар\n3 - Отмена\nВвод - ";
            Getline(choose);

            if (choose == "1") {
                while (true) {
                    system("cls");
                    std::cout << "Выберите способ оплаты\n1 - Наличными\n2 - Безнал\nВвод - ";
                    Getline(choose);

                    if (choose == "1") {
                        std::cout << "Введите кол-во наличных - ";
                        Getline(chooseCash);
                        if (IsNumber(chooseCash)) {
                            money = std::stod(chooseCash);
                            if (money < totalSum) {
                                std::cout << "Недостаточно средств!\n";
                                Sleep(1500);
                                continue;
                            }
                            else if (money - totalSum > cash) {
                                std::cout << "Нет возможности дать сдачу. Повторите попытку\n";
                                Sleep(1500);
                                continue;
                            }
                            else {
                                std::cout << "Ваши " << money << "\n";
                                Sleep(400);
                                std::cout << "Оплата прошла успешно. Сдача " << money - totalSum << " рублей\n";
                                Sleep(1800);
                                cash -= money - totalSum;
                                cashIncome += totalSum;
                                awardArr[currentId] += totalSum;
                                system("cls");
                                break;
                            }
                        }
                    }
                    else if (choose == "2") {
                        system("cls");
                        std::cout << "Приложите карту\n\n";
                        Sleep(1000);
                        if (rand() % 10 <= 2) {
                            for (size_t i = 0; i < 5; i++) {
                                std::cout << i + 1 << "\t";
                                Sleep(800);
                            }
                            std::cout << "\nСоединение не установлено. Повторите попытку\n";
                            Sleep(1500);
                        }
                        else {
                            for (size_t i = 0; i < 5; i++) {
                                std::cout << i + 1 << "\t";
                                Sleep(800);
                            }
                            std::cout << "\nОплата прошла успешно\n\nСпасибо за покупку!\n\n";
                            Sleep(2500);
                            bankIncome += totalSum;
                            awardArr[currentId] += totalSum;
                            system("cls");
                            break;
                        }
                    }
                    else if (choose == "Raze" || choose == "raze") {
                        std::cout << "Raze оплатил вам чек. Всего хорошего\n";
                        Sleep(1500);
                        system("cls");
                        break;
                    }
                    else {
                        Err();
                    }
                }
            }
            else if (choose == "2") {
                continue;
            }
            else if (choose == "3") {
                std::cout << "Отмена покупки!\n";
                StorageReturner();
                Sleep(1500);
                system("cls");
                return;
            }
            else {
                Err();
                continue;
            }

            delete[] idArrCheck;
            delete[] nameArrCheck;
            delete[] countArrCheck;
            delete[] priceArrCheck;
            delete[] totalPriceArrCheck;

            idArrCheck = nullptr;
            nameArrCheck = nullptr;
            countArrCheck = nullptr;
            priceArrCheck = nullptr;
            totalPriceArrCheck = nullptr;
            checkSize = 0;

            system("cls");
            break;
        }

        if (!IsNumber(chooseId)) {
            continue;
        }

        id = std::stoi(chooseId) - 1;
        if (id < 0 || id > storageSize - 1) {
            std::cout << "Ошибка ID!\n";
            Sleep(1500);
            continue;
        }

        std::cout << "\nВведите кол-во товара или \"exit\" для выбора другого товара - ";
        Getline(chooseCount);

        if (chooseCount == "exit") {
            std::cout << "Отмена покупки товара - " << nameArr[id] << "\n";
            Sleep(1500);
            continue;
        }

        if (!IsNumber(chooseCount)) {
            continue;
        }

        count = std::stoi(chooseCount);
        if (count < 1 || count > countArr[id]) {
            std::cout << "Ошибка кол-ва! Максимум - " << countArr[id] << "\n";
            Sleep(1500);
            continue;
        }

        CheckArrAppend();
        index++;

        idArrCheck[index] = idArr[id];
        nameArrCheck[index] = nameArr[id];
        priceArrCheck[index] = priceArr[id];
        countArrCheck[index] = count;
        totalPriceArrCheck[index] = count * priceArr[id];

        countArr[id] -= count;
        totalSum += totalPriceArrCheck[index];

        std::cout << "\nТовар добавлен в чек\n\n";
        isFirst = true;
        Sleep(1000);
    }
}