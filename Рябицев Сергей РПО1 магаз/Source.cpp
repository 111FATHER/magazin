#include <iostream>
#include <Windows.h>
#include <ctime>
#include <iomanip>
#include <string>
#include <unordered_set>


// ---------------------------------------- Учетные записи ------------------------------------------------

size_t userSize = 2;
size_t staffCount = 1;
std::string userStatus[3]{ "Супер администратор", "Администратор","Сотрудник" };
std::string* loginArr = new std::string[userSize]{ "stoodin","111" };
std::string* passArr = new std::string[userSize]{ "stoodin","111" };
std::string* statusArr = new std::string[userSize]{userStatus[0], userStatus[2]};
double* awardArr = new double[userSize] {0.0, 0.0};
unsigned int* userIdArr = new unsigned int[userSize] {1, 2};
std::string currentStatus;
int currentId = 0;

void ChangeUsers();
void ShowUsers(int mode = 0);
void AddNewUsers();
void ChangePass();
void DeleteUser();

// --------------------------------------------------------------------------------------------------------

// ---------------------------------------------- Склад ---------------------------------------------------
size_t storageSize = 0;
bool staticStorageCreated = false;

int* idArr;
std::string* nameArr;
unsigned int* countArr;
double* priceArr;


void CreateStorage();
void ShowStorage(int mode = 0);
void AddStorageItem();
void RemoveStorageItem();
void ChangePrice();

void ChangeStorage();
void AddNewItem();
void ChangeName();
void DeleteItem();



template<typename T> void SwapArr (T* Arr, T* Arr2, size_t SizeArr);
// --------------------------------------------------------------------------------------------------------

// ---------------------------------------------- Продажи -------------------------------------------------

size_t checkSize = 0;
int* idArrCheck;
std::string* nameArrCheck;
unsigned int* countArrCheck;
double* priceArrCheck;
double* totalPriceArrCheck;

double cash = 10000 + rand() % 7000;
double cashIncome = 0.0;
double bankIncome = 0.0;

void Selling();
void CheckArrAppend();
void PrintCheck(double &totalSum);
void StorageReturner();

// --------------------------------------------------------------------------------------------------------

// ---------------------------------------------- Служебные -----------------------------------------------
void Start();
bool Login();
void ShowSuperAdminMenu();
bool IsNumber(const std::string& str);
bool CheckLogin(const std::string& str);
bool CheckPass(const std::string& str);

inline void Getline(std::string& str);
inline void Err(int time = 1500);



int main()
{

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));




	Start();
	delete[]loginArr, passArr, statusArr;
	if (staticStorageCreated)
	{
		delete[]idArr, nameArr, countArr, priceArr;
	}





	return 0;
}

void ChangeUsers()
{
	std::string choose;
	while (true)
	{
		system("cls");
		std::cout << "1 - Добавить нового пользователя\n";
		std::cout << "2 - Показать пользователей\n";
		std::cout << "3 - Изменить пароль пользователя\n";
		std::cout << "4 - Удалить пользователя\n";
		std::cout << "0 - Выйти из редактора\n";
		std::cout << "Ввод - ";
		Getline(choose);

		if (choose == "1")
		{
			AddNewUsers();
		}
		else if (choose == "2" && userSize > 1)
		{
			ShowUsers();
		}
		else if (choose == "3" && userSize > 1)
		{
			ChangePass();
		}
		else if (choose == "4" && userSize > 1)
		{
			DeleteUser();
		}
		else if (choose == "0")
		{
			system("cls");
			break;
		}
		else
		{
			if (userSize <= 1)
			{
				std::cout << "Пользователей нет!\n";
			}
			Err();
		}
	}
}

void ShowUsers(int mode)
{
	if (mode == 0)
	{
		system("cls");
		std::cout << "\t" << std::left << std::setw(10) << "Логин\t\t" << "Пароль\t\t\t" << "Роль\n";
		for (size_t i = 1; i < userSize; i++)
		{
			std::cout << i << "\t" << std::left << std::setw(8) << loginArr[i] << "\t\t"
				<< passArr[i] << "\t\t\t" << statusArr[i] << "\n";
		}
		Sleep(1500);
	}
	else if (mode == 1)
	{
		system("cls");
		std::cout << "\t" << std::left << std::setw(10) << "Логин\t\t" << "Пароль\t\t\t" << "Роль\n";
		for (size_t i = 0; i < userSize; i++)
		{
			std::cout << i << "\t" << std::left << std::setw(8) << loginArr[i] << "\t\t"
				<< passArr[i] << "\t\t\t" << statusArr[i] << "\n";
		}
		Sleep(1500);
	}
	
}

void AddNewUsers()
{
	std::string newLogin, newPass, newRole, choose;
	bool exit;
	while (true)
	{
		exit = true;
		while (true)
		{
			system("cls");
			std::cout << "\tСоздание нового пользователя!\n\n";
			std::cout << "Введите логин нового пользователя или \"exit\" для выхода - ";
			Getline(newLogin);
			if (newLogin == "exit")
			{
				std::cout << "Создание нового пользователя прервано!\n\n";
				Sleep(1500);
				exit = false;
				break;
			}
			if (CheckLogin(newLogin))
			{
				break;
			}
		}

		while (exit)
		{
			system("cls");
			std::cout << "\tСоздание пароля для нового пользователя!\n\n";
			std::cout << "Введите пароль для нового пользователя или \"exit\" для выхода - ";
			Getline(newPass);
			if (newPass == "exit")
			{
				std::cout << "Создание нового пользователя прервано!\n\n";
				Sleep(1500);
				exit = false;
				break;
			}
			if (CheckPass(newPass))
			{
				break;
			}
		}
		
		while (exit)
		{
			system("cls");
			std::cout << "\tСоздание нового пользователя!\n\n";
			std::cout << "Введите роль нового пользователя или \"exit\" для выхода - ";
			std::cout << "1 - Администратор\n2 - Сотрудник\nВвод - ";
			Getline(choose);
			if (choose == "exit")
			{
				std::cout << "Создание нового пользователя прервано!\n\n";
				Sleep(1500);
				exit = false;
				break;
			}
			if (choose == "1")
			{
				newRole = userStatus[1];
			}
			else if (choose == "2")
			{
				newRole = userStatus[2];
				break;
			}
			else
			{
				Err();
			}
		}

		while (exit)
		{
			std::cout << "Пользователь - " << newLogin << "\n";
			std::cout << "Пароль - " << newPass << "\n";
			std::cout << "Роль - " << newRole << "\n\n";
			std::cout << "Подтвердить?\n1 - Да\n2 - Нет\nВвод - ";
			Getline(choose);

			if (choose == "1")
			{
				if (newRole == userStatus[2])
				{
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
				std::swap(awardArrTemp, awardArr);
				std::swap(userIdArrTemp, userIdArr);

				delete[] loginArrTemp, passArrTemp, statusArrTemp, awardArrTemp, userIdArrTemp;
				std::cout << "Идет подготовка... ";
				Sleep(2000);
				std::cout << "Пользователь успешно добавлен!\n\n";
				Sleep(1500);
				exit = false;
				break;
			}
			else if (choose == "2")
			{
				std::cout << "Отмена\n";
				Sleep(1500);
			}
			else
			{
				Err();
			}
		}
		
		if (exit == false)
		{
			break;
		}
	}
}

// АДМИН НЕ МОЖЕТ МЕНЯТЬ ПАРОЛЬ ДРУГИМ АДМИНАМ <------------------------
void ChangePass()
{
	std::string newPass1, newPass2, choose;
	int userNumber = 0;
	int isAdmin = 0;

	while (true)
	{
		if (currentStatus == userStatus[0])
		{
			ShowUsers(1);
			isAdmin = 0;
		}
		else
		{
			ShowUsers();
			isAdmin = 1;
		}

		std::cout << "\nВыберите номер пользователя для смены пароля или \"exit\"для выхода - ";
		Getline(choose);
		if (choose == "exit")
		{
			std::cout << "Отмена изменения пароля!\n";
			Sleep(1500);
			break;
		}
		else if (IsNumber(choose))
		{
			userNumber = std::stoi(choose);
			if (userNumber < isAdmin || userNumber > userSize - 1)
			{
				std::cout << "Пользователь с таким номером не существует!\n";
				Sleep(1500);
			}
			else
			{
				while (true)
				{
					system("cls");

					if (currentStatus == userStatus[1] && statusArr[userNumber] == userStatus[1])
					{
						std::cout << "Нельзя менять пароли Администраторам!\n";
						Sleep(1500);
						break;
					}

					std::cout << "Введите новый пароль для пользователя" << loginArr[userNumber] << " - ";
					Getline(newPass1);
					std::cout << "Подтвердите пароль для пользователя" << loginArr[userNumber] << " - ";
					Getline(newPass2);
					if (CheckPass(newPass1) && CheckPass(newPass2) && newPass1 == newPass2)
					{
						passArr[userNumber] = newPass1;
						std::cout << "Успешно\n";
						Sleep(1500);
						break;
					}
					else
					{
						std::cout << "Повторите попытку\n";
						Sleep(1500);
					}
				}
			}
		}
		else
		{
			Err();
		}
		
	}
}

void DeleteUser()
{
	std::string chooseNumber, checkPass, choose;
	int userNumber = 0, isAdmin = 0;

	while (true)
	{
		if (currentStatus == userStatus[0])
		{
			if (userSize < 2)
			{
				std::cout << "Нет доступных пользователей для удаления!\n";
				Sleep(1500);
				return;
			}
		}
		
		else if (currentStatus == userStatus[1])
		{
			if (staffCount < 1)
			{
				std::cout << "Нет доступных пользователей для удаления!\n";
				Sleep(1500);
				return;
			}
		}

		ShowUsers();
		isAdmin = 1;
		
		std::cout << "\nВыберите номер пользователя для удаления или \"exit\"для выхода - ";
		Getline(choose);
		if (choose == "exit")
		{
			std::cout << "Отмена удаления пароля!\n";
			Sleep(1500);
			break;
		}
		else if (IsNumber(choose))
		{
			userNumber = std::stoi(choose);

			if (userNumber < isAdmin || userNumber > userSize - 1)
			{
				std::cout << "Пользователя с таким номером не существует!\n";
				Sleep(1500);
				break;
			}

			while (true)
			{
				system("cls");

				if (currentStatus == userStatus[1] && statusArr[userNumber] != userStatus[2])
				{
					std::cout << "Нельзя удалять администратора\n";
					Sleep(1500);
					break;
				}

				std::cout << "Удаление пользователя - " << loginArr[userNumber] << "\n";
				std::cout << "Для подтверждения введите пароль супер администратора или\"exit\"для выхода - ";
				Getline(checkPass);

				if (checkPass == "exit")
				{
					std::cout << "Отмена удаления пользователя - " << loginArr[userNumber] << "\n\n";
					Sleep(1500);
					break;
				}

				else if (checkPass == passArr[0])
				{
					if (statusArr[userNumber] == userStatus[2])
					{
						staffCount--;
					}

					userSize--;
					std::string* loginArrTemp = new std::string[userSize];
					std::string* passArrTemp = new std::string[userSize];
					std::string* statusArrTemp = new std::string[userSize];
					double* awardArrTemp = new double[userSize];
					unsigned int* userIdArrTemp = new unsigned int[userSize];

					for (size_t i = 0, c = 0; i < userSize; i++, c++)
					{
						if (userNumber == c)
						{
							c++;
						}
						loginArrTemp[i] = loginArr[c];
						passArrTemp[i] = passArr[c];
						statusArrTemp[i] = statusArr[c];
						awardArrTemp[i] = awardArr[c];
						userIdArrTemp[i] = userIdArr[c];
					}
					std::swap(loginArrTemp, loginArr);
					std::swap(passArrTemp, passArr);
					std::swap(statusArrTemp, statusArr);
					std::swap(awardArrTemp, awardArr);
					std::swap(userIdArrTemp, userIdArr);

					delete[]loginArrTemp, passArrTemp, statusArrTemp, awardArrTemp, userIdArrTemp;
					std::cout << "Идет подготовка... ";
					Sleep(2000);
					std::cout << "Пользователь успешно удалён!\n\n";
					Sleep(1500);
					break;
				
				}
				else
				{
					std::cout << "Некорректный пароль\n";
					Sleep(1500);
				}
			}
		}
		else
		{
			Err();
		}
	}



}

void CreateStorage()
{
	const int staticSize = 10;
	int id[staticSize]{ 1,2,3,4,5,6,7,8,9,10 };
	std::string name[staticSize]
	{
		"Не паленая кепка от Демьяна","Личная шапка владельца магазина",
		"Верхняя одежда клянусь","Футболка для не футболистов","Толстая толстовка","Штаны для трех ног",
		"Перчатки на три пальца","Ботинки Сереги(не владельца)","Кроссовки для уверенных в себе","Тапочки"

	};
	unsigned int count[staticSize]{ 32,54,188,65,23,88,77,42,66,99 };
	double price[staticSize]{ 545.5, 666.6, 3222.2, 500.0, 1222.9, 333.3, 4666.3, 50.5, 4334.3, 111 };

	if (staticStorageCreated)
	{
		delete[]idArr, nameArr, countArr, priceArr;
		staticStorageCreated = false;
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

void ShowStorage(int mode)
{
	system("cls");


	if (mode == 0)
	{
		std::cout << "ID\t" << std::left << std::setw(25) << "Название товара\t\t" <<
			"Цена\t" << "Кол-во\n";

		for (size_t i = 0; i < storageSize; i++)
		{
			std::cout << idArr[i] << "\t" << std::left << std::setw(25) << nameArr[i]
				<< "\t" << priceArr[i] << "\t" << countArr[i] << "\n";
		}
	}
	else if (mode == 1)
	{
		std::cout << "ID\t" << std::left << std::setw(25) << "Название товара\t\t" <<
			"Кол-во\n";

		for (size_t i = 0; i < storageSize; i++)
		{
			std::cout << idArr[i] << "\t" << std::left << std::setw(25) << nameArr[i]
				<< "\t" << countArr[i] << "\n";
		}
	}
	else if (mode == 2)
	{
		std::cout << "ID\t" << std::left << std::setw(25) << "Название товара\t\t" <<
			"Цена\n";

		for (size_t i = 0; i < storageSize; i++)
		{
			std::cout << idArr[i] << "\t" << std::left << std::setw(25) << nameArr[i]
				<< "\t" << priceArr[i] << "\n";
		}
	}
	else if (mode == 3)
	{
		std::cout << "ID\t" << std::left << std::setw(25) << "Название товара\t\t" << "\n";

		for (size_t i = 0; i < storageSize; i++)
		{
			std::cout << idArr[i] << "\t" << std::left << std::setw(25) << nameArr[i] << "\n";
		}
	}
	else
	{
		std::cout << "StorageMode Error\n\n";
		std::invalid_argument("StorageMode Error");
	}
}

void AddStorageItem()
{
	std::string chooseId, chooseCount, choose;
	int id = 0;
	unsigned int count = 0;
	while (true)
	{
		system("cls");
		ShowStorage(1);
		std::cout << "\nВведите ID товара или \"exit\" для выхода - ";
		Getline(chooseId);
		if (chooseId == "exit")
		{
			std::cout << "Отмена операции пополнения\n";
			Sleep(1500);
			system("cls");
			break;
		}
		std::cout << "Введите кол-во товара для пополнения - ";
		Getline(chooseCount);
		if (IsNumber(chooseId) && IsNumber(chooseCount))
		{
			id = std::stoi(chooseId) - 1;
			count = std::stoi(chooseCount);

			if (id < 0 || id > storageSize - 1|| count < 0 || count > 199)
			{
				std::cout << "Некоррекстный ID или кол-во\nМаксимальное кол-во 199\n";
				Sleep(1500);
			}
			else
			{
				std::cout << std::left << std::setw(25) << nameArr[id] <<
					"\t" << countArr[id] << " --> " << countArr[id] + count << "\n\n";
				std::cout << "Подтвердить?\n1 - Да\n2 - Нет\nВвод - ";
				Getline(choose);
				if (choose == "1")
				{
					countArr[id] += count;
					std::cout << "Товар успешно пополнен\n\n";
					Sleep(1500);
					system("cls");
					break;
				}
				else if (choose == "2")
				{
					std::cout << "Отмена пополнения товара\n";
					Sleep(1500);
				}
				else
				{
					Err();
				}
			}
		}
	}
}

void RemoveStorageItem()
{
	std::string chooseId, chooseCount, choose;
	int id = 0;
	unsigned int count = 0;
	while (true)
	{
		system("cls");
		ShowStorage(1);
		std::cout << "\nВведите ID товара или \"exit\" для выхода - ";
		Getline(chooseId);
		if (chooseId == "exit")
		{
			std::cout << "Отмена операции списания товара\n";
			Sleep(1500);
			break;
		}
		std::cout << "Введите кол-во товара для списания - ";
		Getline(chooseCount);
		if (IsNumber(chooseId) && IsNumber(chooseCount))
		{
			id = std::stoi(chooseId) - 1;
			count = std::stoi(chooseCount);

			if (id < 0 || id > storageSize - 1 || count < 0 || count > countArr[id])
			{
				std::cout << "Некоррекстный ID или кол-во\n";
				Sleep(1500);
			}
			else
			{
				std::cout << std::left << std::setw(25) << nameArr[id] <<
					"\t" << countArr[id] << " --> " << countArr[id] - count << "\n\n";
				std::cout << "Подтвердить?\n1 - Да\n2 - Нет\nВвод - ";
				Getline(choose);

				if (choose == "1")
				{
					countArr[id] -= count;
					std::cout << "Товар успешно списан\n\n";
					Sleep(1500);
					system("cls");
					break;
				}
				else if (choose == "2")
				{
					std::cout << "Отмена списания товара\n";
					Sleep(1500);
				}
				else
				{
					Err();
				}
			}
		}
	}
}

void ChangePrice()
{
	std::string chooseId, newPrice, choose;
	int id = 0;
	double price = 0.0;
	while (true)
	{
		system("cls");
		ShowStorage(2);
		std::cout << "\nВведите ID товара или \"exit\" для выхода - ";
		Getline(chooseId);
		if (chooseId == "exit")
		{
			std::cout << "Отмена операции изменения цены\n";
			Sleep(1500);
			break;
		}
		std::cout << "Введите новую цену товара - ";
		Getline(newPrice);
		if (IsNumber(chooseId) && IsNumber(newPrice))
		{
			id = std::stoi(chooseId) - 1;
			price = std::stoi(newPrice);

			if (id < 0 || id > storageSize - 1 || price < 0.0 || price > 99999.9)
			{
				std::cout << "Некоррекстный ID или кол-в\nМаксимальный ценник 99999.9\n";
				Sleep(1500);
			}
			else
			{
				std::cout << std::left << std::setw(25) << nameArr[id] <<
					"\t" << priceArr[id] << " --> " << price << "\n\n";
				std::cout << "Подтвердить?\n1 - Да\n2 - Нет\nВвод - ";
				Getline(choose);

				if (choose == "1")
				{
					priceArr[id] = price;
					std::cout << "Цена успешно изменена\n\n";
					Sleep(1500);
					system("cls");
					break;
				}
				else if (choose == "2")
				{
					std::cout << "Отмена изменения цены\n";
					Sleep(1500);
				}
				else
				{
					Err();
				}
			}
		}
	}
}

void ChangeStorage()
{
	std::string choose;
	while (true)
	{
		system("cls");
		std::cout << "1 - Добавить новый товар\n";
		std::cout << "2 - Изменить имя товара\n";
		std::cout << "3 - Удалить товар\n";
		std::cout << "0 - Выйти из редактора\n";
		std::cout << "Ввод - ";
		Getline(choose);

		if (choose == "1")
		{
			AddNewItem();
		}
		else if (choose == "2"  && storageSize > 0)
		{
			ChangeName();
		}
		else if (choose == "3" && storageSize > 0)
		{
			DeleteItem();
		}
		else if (choose == "0")
		{
			system("cls");
			break;
		}
		else
		{
			if (storageSize <= 0)
			{
				std::cout << "Склад пустой!\n";
			}
			Err();
		}
	}
}

void AddNewItem()
{
	std::string newName, newPrice, newCount, choose;
	double price = 0.0;
	unsigned int count = 0;
	bool exit = true;
	while (true)
	{
		while (true)
		{
			system("cls");
			std::cout << "\tДобавление нового товара!\n\nВведите \"exit\"для прекращения операции\n\n";
			std::cout << "Введите название нового товара - ";
			Getline(newName);
			if (newName == "exit")
			{
				std::cout << "Операция добавления товара прервана!\n\n";
				Sleep(1500);
				exit = false;
				break;
			}
			if (newName.size() <= 0 || newName.size() >= 100)
			{
				std::cout << "Ошибка имени. Максимальная длина 100 символов\n";
				Sleep(1500);
			}
			else
			{
				break;
			}
		}

		while (exit)
		{
			system("cls");
			std::cout << "\tДобавление нового товара!\n\nВведите\"exit\"для прекращения операции\n\n";
			std::cout << "Введите кол-во нового товара - ";
			Getline(newCount);
			if (newCount == "exit")
			{
				std::cout << "Операция добавления товара прервана!\n\n";
				Sleep(1500);
				exit = false;
				break;
			}
			if (IsNumber(newCount))
			{
				count = std::stoi(newCount);
				if (count > 199)
				{
					std::cout << "Ошибка максимального размера товара. Не более 199 символов\n";
					Sleep(1500);
				}
				else
				{
					break;
				}
			}
		}

		while (exit)
		{
			system("cls");
			std::cout << "\tДобавление нового товара!\n\nВведите\"exit\"для прекращения операции\n\n";
			std::cout << "Введите цену нового товара - ";
			Getline(newPrice);
			if (newPrice == "exit")
			{
				std::cout << "Операция добавления товара прервана!\n\n";
				Sleep(1500);
				exit = false;
				break;
			}
			if (IsNumber(newPrice))
			{
				price = std::stod(newPrice);
				if (price > 99999.9)
				{
					std::cout << "Ошибка максимальной цены товара. Не более 99999.9 руб.\n";
					Sleep(1500);
				}
				else
				{
					break;
				}
			}
		}

		while (exit)
		{
			std::cout << "Новый товар - " << newName << "\n";
			std::cout << "Кол-во - " << count << "\n";
			std::cout << "Цена - " << price << "\n\n";
			std::cout << "Подтвердить?\n1 - Да\n2 - нет\nВвод - ";
			Getline(choose);
			if (choose == "1")
			{
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

				delete[] idArrTemp, nameArrTemp, countArrTemp, priceArrTemp;
				std::cout << "Идет подготовка... ";
				Sleep(2000);
				std::cout << "Товар успешно добавлен!\n\n";
				Sleep(1500);
				break;
			}
			else if (choose == "2")
			{
				std::cout << "Отмена\n\n";
				Sleep(1500);
				break;
			}
			else
			{
				Err();
			}
		}






		if (exit == false)
		{
			break;
		}
	}
}

void ChangeName()
{
	std::string newName, choose, chooseId;
	unsigned int id = 0;
	while(true)
	{
		system("cls");
		ShowStorage(3);
		std::cout << "\nВведите ID товара или \"exit\" для выхода - ";
		Getline(chooseId);
		if (chooseId == "exit")
		{
			std::cout << "Отмена операции изменения имени\n";
			Sleep(1500);
			break;
		}
		std::cout << "Введите новое имя товара - ";
		Getline(newName);
		
		if (newName.size() <= 0 || newName.size() >= 199)
		{
			std::cout << "Ошибка максимального размера имени товара. Не более 199 символов\n";
			Sleep(1500);
		}
		else if (IsNumber(chooseId))
		{
			id = std::stoi(chooseId) - 1;
			if (id < 0 || id > storageSize - 1)
			{
				std::cout << "Ошибка ID!\n";
				Sleep(1500);
			}
			else
			{
				std::cout << std::left << std::setw(25) << nameArr[id] <<
					" --> " << newName << "\n\n";

				std::cout << "Подтвердить?\n1 - Да\n2 - Нет\nВвод - ";
				Getline(choose);
				if (choose == "1")
				{
					nameArr[id] = newName;
					std::cout << "Смена имени завершена\n";
					Sleep(1500);
					break;
				}
				else if (choose == "2")
				{
					std::cout << "Отмена операции\n";
					Sleep(1500);
				}
				else
				{
					Err();
				}
			}
		}
	}
}

void DeleteItem()
{
	std::string chooseId, choose;
	unsigned int id = 0;
	while (true)
	{
		system("cls");
		ShowStorage(3);
		std::cout << "\nВведите ID товара для удаления или \"exit\" для выхода - ";
		Getline(chooseId);
		if (chooseId == "exit")
		{
			std::cout << "Отмена операции удаления\n";
			Sleep(1500);
			break;
		}

		if (IsNumber(chooseId))
		{
			id = std::stoi(chooseId) - 1;

			if (id < 0 || id > storageSize - 1)
			{
				std::cout << "Ошибка ID!\n";
				Sleep(1500);
			}
			else
			{
				std::cout << "Удаляемый товар - " << std::left << std::setw(25) << nameArr[id] << "\n\n";
				std::cout << "Подтвердить?\n1 - Да\n2 - Нет\nВвод - ";
				Getline(choose);
				if (choose == "1")
				{
					storageSize--;
					int* idArrTemp = new int[storageSize];
					std::string* nameArrTemp = new std::string[storageSize];
					unsigned int* countArrTemp = new unsigned int[storageSize];
					double* priceArrTemp = new double[storageSize];
					for (size_t i = 0, c = 0; i < storageSize; i++, c++)
					{
						if (id == c)
						{
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

					delete[] idArrTemp, nameArrTemp, countArrTemp, priceArrTemp;
					std::cout << "Идет подготовка... ";
					Sleep(2000);
					std::cout << "Товар успешно удалён!\n\n";
					Sleep(1500);
					break;
				}
				else if (choose == "2")
				{
					std::cout << "Отмена операции удаления!\n";
					Sleep(1500);
				}
				else
				{
					Err();
				}
			}
		}
	}
}

void Selling()
{
	std::string chooseId, chooseCount, choose, chooseCash;
	unsigned int id = 0, count = 0, index = -1;
	double totalSum = 0.0, money = 0.0;
	bool isFirst = false;

	while (true)
	{
		ShowStorage();

		std::cout << "\nВведите ID товара для покупки или \"exit\" для завершения покупок - ";
		Getline(chooseId);

		if (chooseId == "exit")
		{
			if (isFirst == false)
			{
				std::cout << "Выход без покупок\n";
				Sleep(1500);
				break;
			}
			system("cls");
			PrintCheck(totalSum);
			std::cout << "\nПодтвердите покупку?\n1 - Да\n2 - Добавить ещё товар\n3 - Отмена\nВвод - ";
			Getline(choose);
			if (choose == "1")
			{
				while (true)
				{
					system("cls");
					std::cout << "Выберите способ оплаты\n1 - Наличными\n2 - Безнал\nВвод - ";
					Getline(choose);
					if (choose == "1")
					{
						std::cout << "Введите кол-во наличных - ";
						Getline(chooseCash);
						if (IsNumber(chooseCash))
						{
							money = std::stod(chooseCash);
							if (money < totalSum)
							{
								std::cout << "Недостаточно средств!\n";
								Sleep(1500);
								continue;

							}
							else if (money - totalSum > cash)
							{
								std::cout << "Нет возможности дать сдачи. Повторите попытку\n";
								Sleep(1500);
								continue;
							}
							else
							{
								std::cout << "Ваши " << money << "\n";
								Sleep(400);
								std::cout << "Оплата прошла успешно. Сдача " << money - totalSum << " рублей\n";
								Sleep(1800);
								cash -= money - totalSum;
								cashIncome += totalSum;
								awardArr[currentId] += totalSum;
								system("cls");
								break;
							}// Проверить -------------------
						}
					}
					else if (choose == "2")
					{
						system("cls");
						std::cout << "Приложите карту\n\n";
						Sleep(1000);
						if (rand() % 10 <= 2)
						{
							for (size_t i = 0; i < 5; i++)
							{
								std::cout << i + 1 << "\t";
								Sleep(800);
							}
							std::cout << "\nСоединение не установлено. Повторите попытку\n";
						}
						else
						{
							for (size_t i = 0; i < 5; i++)
							{
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
					else if (choose == "Raze" || choose == "raze")
					{

					}
				}
			}
			else if (choose == "2")
			{
				continue;
			}
			else if (choose == "3")
			{
				std::cout << "Отмена покупки!\n";
				StorageReturner();
				Sleep(1500);
				system("cls");
				return;
			}
			else
			{
				Err();
				continue;
			}
			system("pause");
			delete[]idArrCheck, nameArrCheck, countArrCheck, priceArrCheck, totalPriceArrCheck;


			break;
		}

		if (IsNumber(chooseId))
		{
			id = std::stoi(chooseId) - 1;

			if (id < 0 || id > storageSize - 1)
			{
				std::cout << "Ошибка ID!\n";
				Sleep(1500);
				continue;
			}
		}

		std::cout << "\nВведите кол-во товара \"exit\" для выбора другого товара - ";
		Getline(chooseCount);
		if (chooseId == "exit")
		{
			std::cout << "Отмена покупки товара - " << nameArr[id] << "\n";
			Sleep(1500);
			continue;
		}

		if (IsNumber(chooseCount))
		{
			count = std::stoi(chooseCount) - 1;

			if (count < 0 || count > countArr[id])
			{
				std::cout << "Ошибка кол-ва! Максимум - " << countArr[id] << "\n";
				Sleep(1500);
				continue;
			}
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

void CheckArrAppend()
{
	checkSize++;
	int* idArrCheckTemp = new int[checkSize];
	std::string* nameArrCheckTemp = new std::string[checkSize];
	unsigned int* countArrCheckTemp = new unsigned int[checkSize];
	double* priceArrCheckTemp = new double[checkSize];
	double* totalPriceArrCheckTemp = new double[checkSize];

	// !!!!!

	SwapArr(idArrCheckTemp, idArrCheck, checkSize - 1);
	SwapArr(nameArrCheckTemp, nameArrCheck, checkSize - 1);
	SwapArr(countArrCheckTemp, countArrCheck, checkSize - 1);
	SwapArr(priceArrCheckTemp, priceArrCheck, checkSize - 1);
	SwapArr(totalPriceArrCheckTemp, totalPriceArrCheck, checkSize - 1);

	std::swap(idArrCheckTemp, idArrCheck);
	std::swap(nameArrCheckTemp, nameArrCheck);
	std::swap(countArrCheckTemp, countArrCheck);
	std::swap(priceArrCheckTemp, priceArrCheck);
	std::swap(totalPriceArrCheckTemp, totalPriceArrCheck);

	delete[]idArrCheckTemp, nameArrCheckTemp, countArrCheckTemp, priceArrCheckTemp, totalPriceArrCheckTemp;


}

void PrintCheck(double &totalSum)
{
	std::cout << "№\t" << "ID\t" << std::left << std::setw(25) << "Название товара\t\t" <<
		"Цена за ед\t" << "Кол-во\t" << "Итого\n";

	for (size_t i = 0; i < checkSize; i++)
	{
		std::cout << i + 1 << "\t" << idArrCheck[i] << "\t" << std::left << std::setw(25) << nameArrCheck[i]
			<< "\t" << priceArrCheck[i] << "\t\t" << countArrCheck[i] << "\t" << totalPriceArrCheck[i] << "\n";
	}
}

void StorageReturner()
{
	for (size_t i = 0; i < checkSize; i++)
	{
		countArr[idArrCheck[i] - 1] += countArrCheck[i];
	}
	delete[] idArrCheck;
	delete[] nameArrCheck;
	delete[] countArrCheck;
	delete[] priceArrCheck;
	delete[] totalPriceArrCheck;

}

void Start()
{
	std::string choose;
	if (Login())
	{
		if (currentStatus == userStatus[0])
		{
			while (true)
			{
				std::cout << "Выберите склад\n1 - Готовый\n2 - создать новый\nВвод - ";
				Getline(choose);
				if (choose == "1")
				{
					if (staticStorageCreated == false)
					{
						CreateStorage();
					}

					system("cls");
					ShowSuperAdminMenu();
					/*ShowStorage();
					system("pause");*/
					break;
				}
				else if (choose == "2")
				{
					if (staticStorageCreated == false)
					{
						// новый с нуля
					}
					break;
				}
				else
				{
					Err();
				}
			}
		}
		else if (currentStatus == userStatus[1])
		{
			if (staticStorageCreated == false)
			{
				CreateStorage();
			}
		}
		else if (currentStatus == userStatus[2])
		{
			if (staticStorageCreated == false)
			{
				CreateStorage();
			}
		}
	}
	else
	{
		system("cls");
		std::cout << "Завершение работы магазина\n\n";
	}

}

bool Login()
{
	std::string login, pass;
	while (true)
	{
		std::cout << "\n\n\n\t\t\tMOTHRON\n\n\n";
		std::cout << "Введите логин - ";
		Getline(login);
		std::cout << "Введите пароль - ";
		Getline(pass);
		if (login == "exit" && pass == "exit")
		{
			currentStatus = "";
			return false;
		}
		for (size_t i = 0; i < userSize; i++)
		{
			if (login == loginArr[i] && pass == passArr[i])
			{
				system("cls");
				std::cout << "Пользватель - " << loginArr[i] << "\n\nДобро пожаловать!\n";
				std::cout << "Ваш статус - " << statusArr[i] << "\n\n";
				currentStatus = statusArr[i];
				currentId = userIdArr[i];
				return true;
			}
		}
		Err();
	}
}

void ShowSuperAdminMenu()
{
	std::string choose;

	while (true)
	{
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

		if (choose == "1" && storageSize > 0)
		{
			Selling();
		}
		else if (choose == "2" && storageSize > 0)
		{
			ShowStorage();
			system("pause");
		}
		else if (choose == "3" && storageSize > 0)
		{
			AddStorageItem();
		}
		else if (choose == "4" && storageSize > 0)
		{
			RemoveStorageItem();
		}
		else if (choose == "5" && storageSize > 0)
		{
			ChangePrice();
		}
		else if (choose == "6")
		{
			ChangeStorage();
		}
		else if (choose == "7")
		{
			ChangeUsers();
		}
		else if (choose == "8")
		{

		}
		else if (choose == "0")
		{

		}
		else
		{
			if (storageSize)
			{
				std::cout << "Склад пустой!\n";
			}
			Err();
		}
	}
}

bool IsNumber(const std::string& str)
{
	if (str.size() <= 0 || str.size() >= 10)
	{
		std::cout << "Некорректный ввод\n";
		std::cout << "Ошибка длины числа. От 1 до 9 цифр включительно\n\n";
		Sleep(1500);
		return false;

	}
	for (size_t i = 0; i < str.size(); i++)
	{
		if (!std::isdigit(str[i]))
		{
			std::cout << "Некорректный ввод\n";
			std::cout << "Введенные данные не являются числом\n\n";
			Sleep(1500);
			return false;
		}
	}
	return true;
}

bool CheckLogin(const std::string& str)
{
	for (size_t i = 0; i < userSize; i++)
	{
		if (str == loginArr[i])
		{
			std::cout << "Такой пользователь существует!\n";
			Sleep(1500);
			return false;
		}
	}

	if (str.size() < 5 || str.size() >= 20) 
	{
		std::cout << "Недопустимая длина логина. От 5 до 64\n";
		Sleep(1500);
		return false;
	}
	std::unordered_set<char> specialSymbols;
	for (char i = 'A'; i <= 'Z'; i++)
	{
		specialSymbols.insert(i);
	}
	for (char i = 'a'; i <= 'z'; i++)
	{
		specialSymbols.insert(i);
	}
	for (char symb : str)
	{
		if (!specialSymbols.count(symb))
		{
			std::cout << "Некорректные символы в логине\n\n";
			Sleep(1500);
			return false;
		}
	}
	return true;
}

bool CheckPass(const std::string& str)
{
	if (str.size() < 5 || str.size() > 64)
	{
		std::cout << "Недопустимая длина пароля! От 5 до 64\n\n";
		Sleep(1500);
		return false;
	}
	std::unordered_set<char> specialSymbols;
	std::unordered_set<char> passSymbols{'!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '-', '=', '+', '/', '?', '|', '\\', '\"',
		'\'', ',', '.', '<', '>', '~', '`', ':', ';', '{', '}', '[', ']'};
	int symbolsCount = 0, maxSymbolsCount = 3;
	for (char i = '!'; i <= '~'; i++)
	{
		specialSymbols.insert(i);
	}
	for (char symb : str)
	{
		if (!specialSymbols.count(symb))
		{
			std::cout << "Некорректные символы в логине\n\n";
			Sleep(1500);
			return false;
		}
	}
	return true;

	for (char symb : str)
	{
		if(passSymbols.count(symb))
		{
			symbolsCount++;
			if (passSymbols.count(symb));
			{
				return true;
			}
		}
	}
	std::cout << "Требуется минимум 3 специальных символов\n\n";
	Sleep(1500);
	return false;
}

template<typename T> void SwapArr(T* Arr, T* Arr2, size_t SizeArr)
{
	
	for (size_t i = 0; i < SizeArr; i++)
	{
		Arr[i] = Arr2[i];
	}
}

inline void Getline(std::string& str)
{
	std::getline(std::cin, str, '\n');
}

inline void Err(int time)
{
	std::cout << "Некорректный ввод\n";
	Sleep(time);
	system("cls");
}





