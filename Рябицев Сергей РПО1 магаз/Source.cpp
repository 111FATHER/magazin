#include <iostream>
#include <Windows.h>
#include <ctime>
#include <iomanip>
#include <string>


// ---------------------------------------- Учетные записи ------------------------------------------------

size_t userSize = 2;
std::string userStatus[3]{ "Супер администратор", "Администратор","Сотрудник" };
std::string* loginArr = new std::string[userSize]{ "stoodin","111" };
std::string* passArr = new std::string[userSize]{ "stoodin","111" };
std::string* statusArr = new std::string[userSize]{userStatus[0], userStatus[2]};
std::string currentStatus = statusArr[0];

// --------------------------------------------------------------------------------------------------------

// ---------------------------------------------- Склад ---------------------------------------------------
size_t storageSize = 0;
bool staticStorageCreated = false;

int* idArr;
std::string* nameArr;
unsigned int* countArr;
double* priceArr;


void CreateStorage();
void ShowStorage();
template<typename T> void SwapArr (T* Arr, T* Arr2, size_t SizeArr);
// --------------------------------------------------------------------------------------------------------

// ---------------------------------------------- Служебные -----------------------------------------------
void Start();
bool Login();
void ShowSuperAdminMenu();

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

void Start()
{
	std::string choose;
	std::cout << "\n\n\n\t\t\tMOTHRON\n\n\n";
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
					CreateStorage();
					/*ShowStorage();
					system("pause");*/
					break;
				}
				else if (choose == "2")
				{

					break;
				}
				else Err();
			}
		}
		else if (currentStatus == userStatus[1])
		{
			CreateStorage();
		}
		else if (currentStatus == userStatus[2])
		{
			CreateStorage();
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
		std::cout << "Введите логин - ";
		Getline(login);
		std::cout << "Введите пароль - ";
		Getline(pass);
		if (login == "exit" && pass == "exit")
		{
			currentStatus = "";
			return false;
		}
		if (login == loginArr[0] && pass == passArr[0])
		{
			std::cout << "Пользователь - " << loginArr[0] << "\n\nДобро пожаловать!\n";
			std::cout << "Ваш статус - " << statusArr[0] << "\n\n";
			currentStatus = statusArr[0];
			return true;
		}
		for (size_t i = 1; i < userSize; i++)
		{
			if (login == loginArr[i] && pass == passArr[i])
			{
				std::cout << "Пользватель - " << loginArr[i] << "\n\nДобро пожаловать!\n";
				std::cout << "Ваш статус - " << statusArr[i] << "\n\n";
				currentStatus = statusArr[i];
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
		system("cls");
		std::cout << "1 - Начать продажу\n";
		std::cout << "2 - Показать склад\n";
		std::cout << "3 - Пополнить склад\n";
		std::cout << "4 - Списать товар\n";
		std::cout << "5 - Изменить цену\n";
		std::cout << "6 - Редактировать склад\n";
		std::cout << "7 - Редактировать персонал\n";
		std::cout << "8 - Отчёт о прибыли\n";
		std::cout << "0 - Закрыть магазин\n";
		std::cout << "Ввод - ";
		Getline(choose);
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
		"Перчатки","Ботинки Сереги(не владельца)","Кроссовки для уверенных в себе"

	};
	unsigned int count[staticSize]{ 32,54,213,65,23,88,433,42,66 };
	double price[staticSize]{ 545.5, 666.6, 3222.2, 500.0, 1222.9, 333.3, 4666.3, 50.5, 4334.3 };

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

void ShowStorage()
{
	std::cout << "ID\t" << std::left << std::setw(25) << "Название товара\t\t" <<
		"Цена\t" << "Кол-во\n";

	for (size_t i = 0; i < storageSize; i++)
	{
		std::cout << idArr[i] << "\t" << std::left << std::setw(25) << nameArr[i]
			<< "\t" << priceArr[i] << "\t" << countArr[i] << "\n";
	}
	std::cout << "\n\n";
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
	Sleep(1500);
	system("cls");
}





