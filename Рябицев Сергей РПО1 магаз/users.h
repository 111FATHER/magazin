#pragma once
#include <string>

extern size_t userSize;
extern size_t staffCount;
extern std::string userStatus[3];
extern std::string* loginArr;
extern std::string* passArr;
extern std::string* statusArr;
extern double* awardArr;
extern unsigned int* userIdArr;
extern std::string currentStatus;
extern int currentId;

void InitDefaultUsers();
void ChangeUsers();
void ShowUsers(int mode = 0);
void AddNewUsers();
void ChangePass();
void DeleteUser();