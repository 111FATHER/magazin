#include "users.h"
#include "utils.h"
#include <iostream>
#include <Windows.h>
#include <iomanip>

size_t userSize = 2;
size_t staffCount = 1;
std::string userStatus[3]{ "Супер администратор", "Администратор", "Сотрудник" };
std::string* loginArr = new std::string[userSize]{ "stoodin","111" };
std::string* passArr = new std::string[userSize]{ "stoodin","111" };
std::string* statusArr = new std::string[userSize]{ userStatus[0], userStatus[2] };
double* awardArr = new double[userSize] {0.0, 0.0};
unsigned int* userIdArr = new unsigned int[userSize] {1, 2};
std::string currentStatus;
int currentId = 0;

void InitDefaultUsers() {
}

void ChangeUsers() {
    std::string choose;
    while (true) {
        system("cls");
        std::cout << "1 - Добавить нового пользователя\n";
        std::cout << "2 - Показать пользователей\n";
        std::cout << "3 - Изменить пароль пользователя\n";
        std::cout << "4 - Удалить пользователя\n";
        std::cout << "0 - Выйти из редактора\n";
        std::cout << "Ввод - ";
        Getline(choose);

        if (choose == "1") {
            AddNewUsers();
        }
        else if (choose == "2" && userSize > 1) {
            ShowUsers();
        }
        else if (choose == "3" && userSize > 1) {
            ChangePass();
        }
        else if (choose == "4" && userSize > 1) {
            DeleteUser();
        }
        else if (choose == "0") {
            system("cls");
            break;
        }
        else {
            if (userSize <= 1) {
                std::cout << "Пользователей нет!\n";
            }
            Err();
        }
    }
}

void ShowUsers(int mode) {
    if (mode == 0) {
        system("cls");
        std::cout << "\t" << std::left << std::setw(10) << "Логин\t\t" << "Пароль\t\t\t" << "Роль\n";
        for (size_t i = 1; i < userSize; i++) {
            std::cout << i << "\t" << std::left << std::setw(8) << loginArr[i] << "\t\t"
                << passArr[i] << "\t\t\t" << statusArr[i] << "\n";
        }
        Sleep(1500);
    }
    else if (mode == 1) {
        system("cls");
        std::cout << "\t" << std::left << std::setw(10) << "Логин\t\t" << "Пароль\t\t\t" << "Роль\n";
        for (size_t i = 0; i < userSize; i++) {
            std::cout << i << "\t" << std::left << std::setw(8) << loginArr[i] << "\t\t"
                << passArr[i] << "\t\t\t" << statusArr[i] << "\n";
        }
        Sleep(1500);
    }
}

void AddNewUsers() {
    std::string newLogin, newPass, newRole, choose;
    bool exit;
    while (true) {
        exit = true;
        while (true) {
            system("cls");
            std::cout << "\tСоздание нового пользователя!\n\n";
            std::cout << "Введите логин нового пользователя или \"exit\" для выхода - ";
            Getline(newLogin);
            if (newLogin == "exit") {
                std::cout << "Создание нового пользователя прервано!\n\n";
                Sleep(1500);
                exit = false;
                break;
            }
            if (CheckLogin(newLogin)) {
                break;
            }
        }

        while (exit) {
            system("cls");
            std::cout << "\tСоздание пароля для нового пользователя!\n\n";
            std::cout << "Введите пароль для нового пользователя или \"exit\" для выхода - ";
            Getline(newPass);
            if (newPass == "exit") {
                std::cout << "Создание нового пользователя прервано!\n\n";
                Sleep(1500);
                exit = false;
                break;
            }
            if (CheckPass(newPass)) {
                break;
            }
        }

        while (exit) {
            system("cls");
            std::cout << "\tСоздание нового пользователя!\n\n";
            std::cout << "Введите роль нового пользователя или \"exit\" для выхода - ";
            std::cout << "1 - Администратор\n2 - Сотрудник\nВвод - ";
            Getline(choose);
            if (choose == "exit") {
                std::cout << "Создание нового пользователя прервано!\n\n";
                Sleep(1500);
                exit = false;
                break;
            }
            if (choose == "1") {
                newRole = userStatus[1];
            }
            else if (choose == "2") {
                newRole = userStatus[2];
                break;
            }
            else {
                Err();
            }
        }

        while (exit) {
            std::cout << "Пользователь - " << newLogin << "\n";
            std::cout << "Пароль - " << newPass << "\n";
            std::cout << "Роль - " << newRole << "\n\n";
            std::cout << "Подтвердить?\n1 - Да\n2 - Нет\nВвод - ";
            Getline(choose);

            if (choose == "1") {
                if (newRole == userStatus[2]) {
                    staffCount++;
                }

                userSize++;
                std::string* loginArrTemp = new std::string[userSize];
                std::string* passArrTemp = new std::string[userSize];
                std::string* statusArrTemp = new std::string[userSize];
                double* awardArrTemp = new double[userSize];
                unsigned int* userIdArrTemp = new unsigned int[userSize];

                SwapArr(loginArrTemp, loginArr, userSize - 1);
                SwapArr(passArrTemp, passArr, userSize - 1);
                SwapArr(statusArrTemp, statusArr, userSize - 1);
                SwapArr(awardArrTemp, awardArr, userSize - 1);
                SwapArr(userIdArrTemp, userIdArr, userSize - 1);

                loginArrTemp[userSize - 1] = newLogin;
                passArrTemp[userSize - 1] = newPass;
                statusArrTemp[userSize - 1] = newRole;
                awardArrTemp[userSize - 1] = 0.0;
                userIdArrTemp[userSize - 1] = userSize;

                std::swap(loginArr, loginArrTemp);
                std::swap(passArr, passArrTemp);
                std::swap(statusArr, statusArrTemp);
                std::swap(awardArr, awardArrTemp);
                std::swap(userIdArr, userIdArrTemp);

                delete[] loginArrTemp;
                delete[] passArrTemp;
                delete[] statusArrTemp;
                delete[] awardArrTemp;
                delete[] userIdArrTemp;
                std::cout << "Идет подготовка... ";
                Sleep(2000);
                std::cout << "Пользователь успешно добавлен!\n\n";
                Sleep(1500);
                exit = false;
                break;
            }
            else if (choose == "2") {
                std::cout << "Отмена\n";
                Sleep(1500);
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

void ChangePass() {
    std::string newPass1, newPass2, choose;
    int userNumber = 0;
    int isAdmin = 0;

    while (true) {
        if (currentStatus == userStatus[0]) {
            ShowUsers(1);
            isAdmin = 0;
        }
        else {
            ShowUsers();
            isAdmin = 1;
        }

        std::cout << "\nВыберите номер пользователя для смены пароля или \"exit\"для выхода - ";
        Getline(choose);
        if (choose == "exit") {
            std::cout << "Отмена изменения пароля!\n";
            Sleep(1500);
            break;
        }
        else if (IsNumber(choose)) {
            userNumber = std::stoi(choose);
            if (userNumber < isAdmin || userNumber > userSize - 1) {
                std::cout << "Пользователь с таким номером не существует!\n";
                Sleep(1500);
            }
            else {
                while (true) {
                    system("cls");

                    if (currentStatus == userStatus[1] && statusArr[userNumber] == userStatus[1]) {
                        std::cout << "Нельзя менять пароли Администраторам!\n";
                        Sleep(1500);
                        break;
                    }

                    std::cout << "Введите новый пароль для пользователя" << loginArr[userNumber] << " - ";
                    Getline(newPass1);
                    std::cout << "Подтвердите пароль для пользователя" << loginArr[userNumber] << " - ";
                    Getline(newPass2);
                    if (CheckPass(newPass1) && CheckPass(newPass2) && newPass1 == newPass2) {
                        passArr[userNumber] = newPass1;
                        std::cout << "Успешно\n";
                        Sleep(1500);
                        break;
                    }
                    else {
                        std::cout << "Повторите попытку\n";
                        Sleep(1500);
                    }
                }
            }
        }
        else {
            Err();
        }
    }
}

void DeleteUser() {
    std::string chooseNumber, checkPass, choose;
    int userNumber = 0, isAdmin = 0;

    while (true) {
        if (currentStatus == userStatus[0]) {
            if (userSize < 2) {
                std::cout << "Нет доступных пользователей для удаления!\n";
                Sleep(1500);
                return;
            }
        }
        else if (currentStatus == userStatus[1]) {
            if (staffCount < 1) {
                std::cout << "Нет доступных пользователей для удаления!\n";
                Sleep(1500);
                return;
            }
        }

        ShowUsers();
        isAdmin = 1;

        std::cout << "\nВыберите номер пользователя для удаления или \"exit\"для выхода - ";
        Getline(choose);
        if (choose == "exit") {
            std::cout << "Отмена удаления пароля!\n";
            Sleep(1500);
            break;
        }
        else if (IsNumber(choose)) {
            userNumber = std::stoi(choose);

            if (userNumber < isAdmin || userNumber > userSize - 1) {
                std::cout << "Пользователя с таким номером не существует!\n";
                Sleep(1500);
                break;
            }

            while (true) {
                system("cls");

                if (currentStatus == userStatus[1] && statusArr[userNumber] != userStatus[2]) {
                    std::cout << "Нельзя удалять администратора\n";
                    Sleep(1500);
                    break;
                }

                std::cout << "Удаление пользователя - " << loginArr[userNumber] << "\n";
                std::cout << "Для подтверждения введите пароль супер администратора или\"exit\"для выхода - ";
                Getline(checkPass);

                if (checkPass == "exit") {
                    std::cout << "Отмена удаления пользователя - " << loginArr[userNumber] << "\n\n";
                    Sleep(1500);
                    break;
                }
                else if (checkPass == passArr[0]) {
                    if (statusArr[userNumber] == userStatus[2]) {
                        staffCount--;
                    }

                    userSize--;
                    std::string* loginArrTemp = new std::string[userSize];
                    std::string* passArrTemp = new std::string[userSize];
                    std::string* statusArrTemp = new std::string[userSize];
                    double* awardArrTemp = new double[userSize];
                    unsigned int* userIdArrTemp = new unsigned int[userSize];

                    for (size_t i = 0, c = 0; i < userSize; i++, c++) {
                        if (userNumber == c) {
                            c++;
                        }
                        loginArrTemp[i] = loginArr[c];
                        passArrTemp[i] = passArr[c];
                        statusArrTemp[i] = statusArr[c];
                        awardArrTemp[i] = awardArr[c];
                        userIdArrTemp[i] = userIdArr[c];
                    }
                    std::swap(loginArr, loginArrTemp);
                    std::swap(passArr, passArrTemp);
                    std::swap(statusArr, statusArrTemp);
                    std::swap(awardArr, awardArrTemp);
                    std::swap(userIdArr, userIdArrTemp);

                    delete[] loginArrTemp;
                    delete[] passArrTemp;
                    delete[] statusArrTemp;
                    delete[] awardArrTemp;
                    delete[] userIdArrTemp;
                    std::cout << "Идет подготовка... ";
                    Sleep(2000);
                    std::cout << "Пользователь успешно удалён!\n\n";
                    Sleep(1500);
                    break;
                }
                else {
                    std::cout << "Неверный пароль\n";
                    Sleep(1500);
                }
            }
        }
        else {
            Err();
        }
    }
}