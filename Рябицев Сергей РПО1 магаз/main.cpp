#include <iostream>
#include <Windows.h>
#include <ctime>
#include "users.h"
#include "storage.h"
#include "sales.h"
#include "utils.h"

void Start();
bool Login();
bool Logout();
void ShowSuperAdminMenu();
void ShowAdminMenu();
void ShowUserMenu();

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(time(NULL));

    InitDefaultUsers();
    Start();

    delete[] loginArr;
    delete[] passArr;
    delete[] statusArr;
    delete[] awardArr;
    delete[] userIdArr;

    if (staticStorageCreated) {
        delete[] idArr;
        delete[] nameArr;
        delete[] countArr;
        delete[] priceArr;
    }

    return 0;
}

bool Login() {
    std::string login, pass;
    while (true) {
        std::cout << "\n\n\n\t\t\tMOTHRON\n\n\n";
        std::cout << "Введите логин - ";
        Getline(login);
        std::cout << "Введите пароль - ";
        Getline(pass);
        if (login == "exit" && pass == "exit") {
            currentStatus = "";
            return false;
        }
        for (size_t i = 0; i < userSize; i++) {
            if (login == loginArr[i] && pass == passArr[i]) {
                system("cls");
                std::cout << "Пользователь - " << loginArr[i] << "\n\nДобро пожаловать!\n";
                std::cout << "Ваш статус - " << statusArr[i] << "\n\n";
                currentStatus = statusArr[i];
                currentId = userIdArr[i];
                return true;
            }
        }
        Err();
    }
    return false;
}

bool Logout() {
    std::string choose;
    while (true) {
        system("cls");
        std::cout << "Для подтверждения выхода введите свой пароль или \"exit\" для возврата в меню - ";
        Getline(choose);
        if (choose == "exit") {
            system("cls");
            return false;
        }
        else if (choose == passArr[currentId - 1] || choose == passArr[0]) {
            system("cls");
            return true;
        }
        else {
            Err();
        }
    }
    return false;
}

void ShowSuperAdminMenu() {
    std::string choose;

    while (true) {
        std::cout << "1 - Начать продажу\n";
        std::cout << "2 - Показать склад\n";
        std::cout << "3 - Пополнить склад\n";
        std::cout << "4 - Списать товар\n";
        std::cout << "5 - Изменить цену\n";
        std::cout << "6 - Редактировать склад\n";
        std::cout << "7 - Редактировать персонал\n";
        std::cout << "8 - Отчёт о прибыли\n";
        std::cout << "0 - Закрыть смену\n";
        std::cout << "Ввод - ";
        Getline(choose);

        if (choose == "1" && storageSize > 0) {
            Selling();
        }
        else if (choose == "2" && storageSize > 0) {
            ShowStorage();
            system("pause");
            system("cls");
        }
        else if (choose == "3" && storageSize > 0) {
            AddStorageItem();
        }
        else if (choose == "4" && storageSize > 0) {
            RemoveStorageItem();
        }
        else if (choose == "5" && storageSize > 0) {
            ChangePrice();
        }
        else if (choose == "6") {
            ChangeStorage();
        }
        else if (choose == "7") {
            ChangeUsers();
        }
        else if (choose == "8") {
            ShowIncome();
        }
        else if (choose == "0") {
            if (Logout()) {
                break;
            }
        }
        else {
            if (storageSize <= 0) {
                std::cout << "Склад пустой!\n";
            }
            Err();
        }
    }
}

void ShowAdminMenu() {
    std::string choose;

    while (true) {
        std::cout << "1 - Начать продажу\n";
        std::cout << "2 - Показать склад\n";
        std::cout << "3 - Пополнить склад\n";
        std::cout << "4 - Списать товар\n";
        std::cout << "5 - Редактировать склад\n";
        std::cout << "6 - Редактировать персонал\n";
        std::cout << "7 - Отчёт о прибыли\n";
        std::cout << "0 - Закрыть смену\n";
        std::cout << "Ввод - ";
        Getline(choose);

        if (choose == "1" && storageSize > 0) {
            Selling();
        }
        else if (choose == "2" && storageSize > 0) {
            ShowStorage();
            system("pause");
            system("cls");
        }
        else if (choose == "3" && storageSize > 0) {
            AddStorageItem();
        }
        else if (choose == "4" && storageSize > 0) {
            RemoveStorageItem();
        }
        else if (choose == "5") {
            ChangeStorage();
        }
        else if (choose == "6") {
            ChangeUsers();
        }
        else if (choose == "7") {
            ShowIncome();
        }
        else if (choose == "0") {
            if (Logout()) {
                break;
            }
        }
        else {
            if (storageSize <= 0) {
                std::cout << "Склад пустой!\n";
            }
            Err();
        }
    }
}

void ShowUserMenu() {
    std::string choose;

    while (true) {
        std::cout << "1 - Начать продажу\n";
        std::cout << "2 - Показать склад\n";
        std::cout << "3 - Отчёт о прибыли\n";
        std::cout << "0 - Закрыть смену\n";
        std::cout << "Ввод - ";
        Getline(choose);

        if (choose == "1" && storageSize > 0) {
            Selling();
        }
        else if (choose == "2" && storageSize > 0) {
            ShowStorage();
            system("pause");
            system("cls");
        }
        else if (choose == "3") {
            ShowIncome();
        }
        else if (choose == "0") {
            if (Logout()) {
                break;
            }
        }
        else {
            if (storageSize <= 0) {
                std::cout << "Склад пустой!\n";
            }
            Err();
        }
    }
}

void Start() {
    std::string choose;

    while (true) {
        if (Login()) {
            if (currentStatus == userStatus[0]) {
                while (true) {
                    std::cout << "Выберите склад\n1 - Готовый\n2 - Создать новый\nВвод - ";
                    Getline(choose);
                    if (choose == "1") {
                        if (staticStorageCreated == false) {
                            CreateStorage();
                        }
                        system("cls");
                        ShowSuperAdminMenu();
                        break;
                    }
                    else if (choose == "2") {
                        if (staticStorageCreated == false) {
                            AddNewStorage();
                        }
                        system("cls");
                        ShowSuperAdminMenu();
                        break;
                    }
                    else {
                        Err();
                    }
                }
            }
            else if (currentStatus == userStatus[1]) {
                if (staticStorageCreated == false) {
                    CreateStorage();
                }
                system("cls");
                ShowAdminMenu();
            }
            else if (currentStatus == userStatus[2]) {
                if (staticStorageCreated == false) {
                    CreateStorage();
                }
                system("cls");
                ShowUserMenu();
            }
        }
        else {
            system("cls");
            std::cout << "Введите пароль супер администратора для закрытия смены - ";
            Getline(choose);
            if (choose == passArr[0]) {
                system("cls");
                std::cout << "Итоговая прибыль за смену - " << cashIncome + bankIncome << " рублей";
                Sleep(1500);
                std::cout << "\n\n\tЗавершение работы магазина\n\n";
                Sleep(2000);
                break;
            }
            else {
                Err();
            }
        }
    }
}