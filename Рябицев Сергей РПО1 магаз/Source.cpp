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
std::string* statusArr = new std::string[userSize]{ };
std::string currentStatus = statusArr[0];

// --------------------------------------------------------------------------------------------------------
void Start();
bool Login();
inline void Getline(std::string& str);
inline void Err(int time = 1500);



int main()
{

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));




	Start();
	delete[]loginArr, passArr, statusArr;






	return 0;
}

void Start()
{
	std::cout << "\n\n\n\t\t\tMOTHRON\n\n\n";
	if (Login());
	{

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
			std::cout << "Пользватель - " << loginArr[0] << "\n\nДобро пожаловать!\n";
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
				return true;
			}
		}
		Err();
	}
}

inline void Getline(std::string& str)
{
	std::getline(std::cin, str, '\n');
}

inline void Err(int time = 1500)
{
	std::cout << "Некорректный ввод\n";
	Sleep(1500);
	system("cls");
}





