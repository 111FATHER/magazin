#include "storage.h"
#include "utils.h"
#include <iostream>
#include <Windows.h>
#include <iomanip>

size_t storageSize = 0;
bool staticStorageCreated = false;
int* idArr = nullptr;
std::string* nameArr = nullptr;
unsigned int* countArr = nullptr;
double* priceArr = nullptr;

void CreateStorage() {
    const int staticSize = 10;
    int id[staticSize]{ 1,2,3,4,5,6,7,8,9,10 };
    std::string name[staticSize]{
        "Не паленая кепка от Демьяна","Личная шапка владельца магазина",
        "Верхняя одежда клянусь","Футболка для не футболистов","Толстая толстовка","Штаны для трех ног",
        "Перчатки на три пальца","Ботинки Сереги(не владельца)","Кроссовки для уверенных в себе","Тапочки"
    };
    unsigned int count[staticSize]{ 32,54,188,65,23,88,77,42,66,99 };
    double price[staticSize]{ 545.5, 666.6, 3222.2, 500.0, 1222.9, 333.3, 4666.3, 50.5, 4334.3, 111 };

    if (staticStorageCreated) {
        delete[] idArr;
        delete[] nameArr;
        delete[] countArr;
        delete[] priceArr;
    }

    storageSize = staticSize;
    idArr = new int[storageSize];
    nameArr = new std::string[storageSize];
    countArr = new unsigned int[storageSize];
    priceArr = new double[storageSize];
    staticStorageCreated = true;

    SwapArr(idArr, id, storageSize);
    SwapArr(priceArr, price, storageSize);
    SwapArr(countArr, count, storageSize);
    SwapArr(nameArr, name, storageSize);
}

void ShowStorage(int mode) {
    system("cls");

    if (mode == 0) {
        std::cout << "ID\t" << std::left << std::setw(25) << "Название товара\t\t" << "Цена\t" << "Кол-во\n";
        for (size_t i = 0; i < storageSize; i++) {
            std::cout << idArr[i] << "\t" << std::left << std::setw(25) << nameArr[i] << "\t" << priceArr[i] << "\t" << countArr[i] << "\n";
        }
    }
    else if (mode == 1) {
        std::cout << "ID\t" << std::left << std::setw(25) << "Название товара\t\t" << "Кол-во\n";
        for (size_t i = 0; i < storageSize; i++) {
            std::cout << idArr[i] << "\t" << std::left << std::setw(25) << nameArr[i] << "\t" << countArr[i] << "\n";
        }
    }
    else if (mode == 2) {
        std::cout << "ID\t" << std::left << std::setw(25) << "Название товара\t\t" << "Цена\n";
        for (size_t i = 0; i < storageSize; i++) {
            std::cout << idArr[i] << "\t" << std::left << std::setw(25) << nameArr[i] << "\t" << priceArr[i] << "\n";
        }
    }
    else if (mode == 3) {
        std::cout << "ID\t" << std::left << std::setw(25) << "Название товара\t\t" << "\n";
        for (size_t i = 0; i < storageSize; i++) {
            std::cout << idArr[i] << "\t" << std::left << std::setw(25) << nameArr[i] << "\n";
        }
    }
}

void AddStorageItem() {
    std::string chooseId, chooseCount, choose;
    int id = 0;
    unsigned int count = 0;
    while (true) {
        system("cls");
        ShowStorage(1);
        std::cout << "\nВведите ID товара или \"exit\" для выхода - ";
        Getline(chooseId);
        if (chooseId == "exit") {
            std::cout << "Отмена операции пополнения\n";
            Sleep(1500);
            system("cls");
            break;
        }
        std::cout << "Введите кол-во товара для пополнения - ";
        Getline(chooseCount);
        if (IsNumber(chooseId) && IsNumber(chooseCount)) {
            id = std::stoi(chooseId) - 1;
            count = std::stoi(chooseCount);

            if (id < 0 || id > storageSize - 1 || count < 0 || count > 199) {
                std::cout << "Некорректный ID или кол-во\nМаксимальное кол-во 199\n";
                Sleep(1500);
            }
            else {
                std::cout << std::left << std::setw(25) << nameArr[id] << "\t" << countArr[id] << " --> " << countArr[id] + count << "\n\n";
                std::cout << "Подтвердить?\n1 - Да\n2 - Нет\nВвод - ";
                Getline(choose);
                if (choose == "1") {
                    countArr[id] += count;
                    std::cout << "Товар успешно пополнен\n\n";
                    Sleep(1500);
                    system("cls");
                    break;
                }
                else if (choose == "2") {
                    std::cout << "Отмена пополнения товара\n";
                    Sleep(1500);
                }
                else {
                    Err();
                }
            }
        }
    }
}

void RemoveStorageItem() {
    std::string chooseId, chooseCount, choose;
    int id = 0;
    unsigned int count = 0;
    while (true) {
        system("cls");
        ShowStorage(1);
        std::cout << "\nВведите ID товара или \"exit\" для выхода - ";
        Getline(chooseId);
        if (chooseId == "exit") {
            std::cout << "Отмена операции списания товара\n";
            Sleep(1500);
            break;
        }
        std::cout << "Введите кол-во товара для списания - ";
        Getline(chooseCount);
        if (IsNumber(chooseId) && IsNumber(chooseCount)) {
            id = std::stoi(chooseId) - 1;
            count = std::stoi(chooseCount);

            if (id < 0 || id > storageSize - 1 || count < 0 || count > countArr[id]) {
                std::cout << "Некорректный ID или кол-во\n";
                Sleep(1500);
            }
            else {
                std::cout << std::left << std::setw(25) << nameArr[id] << "\t" << countArr[id] << " --> " << countArr[id] - count << "\n\n";
                std::cout << "Подтвердить?\n1 - Да\n2 - Нет\nВвод - ";
                Getline(choose);

                if (choose == "1") {
                    countArr[id] -= count;
                    std::cout << "Товар успешно списан\n\n";
                    Sleep(1500);
                    system("cls");
                    break;
                }
                else if (choose == "2") {
                    std::cout << "Отмена списания товара\n";
                    Sleep(1500);
                }
                else {
                    Err();
                }
            }
        }
    }
}

void ChangePrice() {
    std::string chooseId, newPrice, choose;
    int id = 0;
    double price = 0.0;
    while (true) {
        system("cls");
        ShowStorage(2);
        std::cout << "\nВведите ID товара или \"exit\" для выхода - ";
        Getline(chooseId);
        if (chooseId == "exit") {
            std::cout << "Отмена операции изменения цены\n";
            Sleep(1500);
            break;
        }
        std::cout << "Введите новую цену товара - ";
        Getline(newPrice);
        if (IsNumber(chooseId) && IsNumber(newPrice)) {
            id = std::stoi(chooseId) - 1;
            price = std::stod(newPrice);

            if (id < 0 || id > storageSize - 1 || price < 0.0 || price > 99999.9) {
                std::cout << "Некорректный ID или цена\n";
                Sleep(1500);
            }
            else {
                std::cout << std::left << std::setw(25) << nameArr[id] << "\t" << priceArr[id] << " --> " << price << "\n\n";
                std::cout << "Подтвердить?\n1 - Да\n2 - Нет\nВвод - ";
                Getline(choose);

                if (choose == "1") {
                    priceArr[id] = price;
                    std::cout << "Цена успешно изменена\n\n";
                    Sleep(1500);
                    system("cls");
                    break;
                }
                else if (choose == "2") {
                    std::cout << "Отмена изменения цены\n";
                    Sleep(1500);
                }
                else {
                    Err();
                }
            }
        }
    }
}

void ChangeStorage() {
    std::string choose;
    while (true) {
        system("cls");
        std::cout << "1 - Добавить новый товар\n";
        std::cout << "2 - Изменить имя товара\n";
        std::cout << "3 - Удалить товар\n";
        std::cout << "0 - Выйти из редактора\n";
        std::cout << "Ввод - ";
        Getline(choose);

        if (choose == "1") {
            AddNewItem();
        }
        else if (choose == "2" && storageSize > 0) {
            ChangeName();
        }
        else if (choose == "3" && storageSize > 0) {
            DeleteItem();
        }
        else if (choose == "0") {
            system("cls");
            break;
        }
        else {
            if (storageSize <= 0) {
                std::cout << "Склад пустой!\n";
            }
            Err();
        }
    }
}

void AddNewStorage() {
    std::string choose;
    while (true) {
        std::cout << "Введите 1 - Чтобы начать, 2 - Чтобы выйти\nВвод - ";
        Getline(choose);
        if (choose == "1") {
            AddNewItem();
        }
        else if (choose == "2") {
            break;
        }
        else {
            Err();
        }
    }
}

void AddNewItem() {
    std::string newName, newPrice, newCount, choose;
    double price = 0.0;
    unsigned int count = 0;
    bool exit = true;
    while (true) {
        while (true) {
            system("cls");
            std::cout << "\tДобавление нового товара!\n\nВведите \"exit\" для прекращения операции\n\n";
            std::cout << "Введите название нового товара - ";
            Getline(newName);
            if (newName == "exit") {
                std::cout << "Операция добавления товара прервана!\n\n";
                Sleep(1500);
                exit = false;
                break;
            }
            if (newName.size() <= 0 || newName.size() >= 100) {
                std::cout << "Ошибка имени. Максимальная длина 100 символов\n";
                Sleep(1500);
            }
            else {
                break;
            }
        }

        while (exit) {
            system("cls");
            std::cout << "\tДобавление нового товара!\n\nВведите\"exit\"для прекращения операции\n\n";
            std::cout << "Введите кол-во нового товара - ";
            Getline(newCount);
            if (newCount == "exit") {
                std::cout << "Операция добавления товара прервана!\n\n";
                Sleep(1500);
                exit = false;
                break;
            }
            if (IsNumber(newCount)) {
                count = std::stoi(newCount);
                if (count > 199) {
                    std::cout << "Ошибка количества. Не более 199\n";
                    Sleep(1500);
                }
                else {
                    break;
                }
            }
        }

        while (exit) {
            system("cls");
            std::cout << "\tДобавление нового товара!\n\nВведите\"exit\"для прекращения операции\n\n";
            std::cout << "Введите цену нового товара - ";
            Getline(newPrice);
            if (newPrice == "exit") {
                std::cout << "Операция добавления товара прервана!\n\n";
                Sleep(1500);
                exit = false;
                break;
            }
            if (IsNumber(newPrice)) {
                price = std::stod(newPrice);
                if (price > 99999.9) {
                    std::cout << "Ошибка цены. Не более 99999.9 руб.\n";
                    Sleep(1500);
                }
                else {
                    break;
                }
            }
        }

        while (exit) {
            std::cout << "Новый товар - " << newName << "\n";
            std::cout << "Кол-во - " << count << "\n";
            std::cout << "Цена - " << price << "\n\n";
            std::cout << "Подтвердить?\n1 - Да\n2 - Нет\nВвод - ";
            Getline(choose);
            if (choose == "1") {
                storageSize++;
                int* idArrTemp = new int[storageSize];
                std::string* nameArrTemp = new std::string[storageSize];
                unsigned int* countArrTemp = new unsigned int[storageSize];
                double* priceArrTemp = new double[storageSize];

                SwapArr(idArrTemp, idArr, storageSize - 1);
                SwapArr(nameArrTemp, nameArr, storageSize - 1);
                SwapArr(countArrTemp, countArr, storageSize - 1);
                SwapArr(priceArrTemp, priceArr, storageSize - 1);

                idArrTemp[storageSize - 1] = storageSize;
                nameArrTemp[storageSize - 1] = newName;
                countArrTemp[storageSize - 1] = count;
                priceArrTemp[storageSize - 1] = price;

                std::swap(idArr, idArrTemp);
                std::swap(nameArr, nameArrTemp);
                std::swap(countArr, countArrTemp);
                std::swap(priceArr, priceArrTemp);

                delete[] idArrTemp;
                delete[] nameArrTemp;
                delete[] countArrTemp;
                delete[] priceArrTemp;
                std::cout << "Идет подготовка... ";
                Sleep(2000);
                std::cout << "Товар успешно добавлен!\n\n";
                Sleep(1500);
                break;
            }
            else if (choose == "2") {
                std::cout << "Отмена\n\n";
                Sleep(1500);
                break;
            }
            else {
                Err();
            }
        }

        if (exit == false) {
            break;
        }
    }
}

void ChangeName() {
    std::string newName, choose, chooseId;
    unsigned int id = 0;
    while (true) {
        system("cls");
        ShowStorage(3);
        std::cout << "\nВведите ID товара или \"exit\" для выхода - ";
        Getline(chooseId);
        if (chooseId == "exit") {
            std::cout << "Отмена операции изменения имени\n";
            Sleep(1500);
            break;
        }
        std::cout << "Введите новое имя товара - ";
        Getline(newName);

        if (newName.size() <= 0 || newName.size() >= 199) {
            std::cout << "Ошибка имени\n";
            Sleep(1500);
        }
        else if (IsNumber(chooseId)) {
            id = std::stoi(chooseId) - 1;
            if (id < 0 || id > storageSize - 1) {
                std::cout << "Ошибка ID!\n";
                Sleep(1500);
            }
            else {
                std::cout << std::left << std::setw(25) << nameArr[id] << " --> " << newName << "\n\n";
                std::cout << "Подтвердить?\n1 - Да\n2 - Нет\nВвод - ";
                Getline(choose);
                if (choose == "1") {
                    nameArr[id] = newName;
                    std::cout << "Смена имени завершена\n";
                    Sleep(1500);
                    break;
                }
                else if (choose == "2") {
                    std::cout << "Отмена операции\n";
                    Sleep(1500);
                }
                else {
                    Err();
                }
            }
        }
    }
}

void DeleteItem() {
    std::string chooseId, choose;
    unsigned int id = 0;
    while (true) {
        system("cls");
        ShowStorage(3);
        std::cout << "\nВведите ID товара для удаления или \"exit\" для выхода - ";
        Getline(chooseId);
        if (chooseId == "exit") {
            std::cout << "Отмена операции удаления\n";
            Sleep(1500);
            break;
        }

        if (IsNumber(chooseId)) {
            id = std::stoi(chooseId) - 1;

            if (id < 0 || id > storageSize - 1) {
                std::cout << "Ошибка ID!\n";
                Sleep(1500);
            }
            else {
                std::cout << "Удаляемый товар - " << std::left << std::setw(25) << nameArr[id] << "\n\n";
                std::cout << "Подтвердить?\n1 - Да\n2 - Нет\nВвод - ";
                Getline(choose);
                if (choose == "1") {
                    storageSize--;
                    int* idArrTemp = new int[storageSize];
                    std::string* nameArrTemp = new std::string[storageSize];
                    unsigned int* countArrTemp = new unsigned int[storageSize];
                    double* priceArrTemp = new double[storageSize];
                    for (size_t i = 0, c = 0; i < storageSize; i++, c++) {
                        if (id == c) {
                            c++;
                        }
                        idArrTemp[i] = i + 1;
                        nameArrTemp[i] = nameArr[c];
                        countArrTemp[i] = countArr[c];
                        priceArrTemp[i] = priceArr[c];
                    }
                    std::swap(idArr, idArrTemp);
                    std::swap(nameArr, nameArrTemp);
                    std::swap(countArr, countArrTemp);
                    std::swap(priceArr, priceArrTemp);

                    delete[] idArrTemp;
                    delete[] nameArrTemp;
                    delete[] countArrTemp;
                    delete[] priceArrTemp;
                    std::cout << "Идет подготовка... ";
                    Sleep(2000);
                    std::cout << "Товар успешно удалён!\n\n";
                    Sleep(1500);
                    break;
                }
                else if (choose == "2") {
                    std::cout << "Отмена операции удаления!\n";
                    Sleep(1500);
                }
                else {
                    Err();
                }
            }
        }
    }
}