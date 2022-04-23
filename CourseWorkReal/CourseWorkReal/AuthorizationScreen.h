#pragma once

const char ACCOUNTS_FILE_NAME[64] = { "accounts.txt" };
const char ENTER_YOUR_DATA[64] = { "-------------Введите ваши данные------------\n" };
const char ENTER_LOGIN[64] = { "Введите логин: " };
const char ENTER_PASSWORD[64] = { "Введите пароль: " };
const char ENTER_ROLE[64] = { "Введите роль(а - админ; п - пользователь): " };
const char ERROR_WRONG_DATA[64] = { "Введённые вами данные неверны!\n\nПовторите попытку!\n\n\n" };
const char GET_ADMIN_ROLE[64] = { "\nВы вошли в аккаунт администратора!\n\n\n" };
const char GET_USER_ROLE[64] = { "\nВы вошли в аккаунт пользователя!\n\n\n" };
const char LOGIN[20] = { ". Логин: " };
const char PASSWORD[20] = { "   Пароль: " };
const char ROLE[20] = { "   Роль: " };
const char ADMIN[20] = { "Админисратор" };
const char USER[20] = { "Пользователь" };
const char STATUS[20] = { "   Статус: " };
const char STATUS_LOCKED[20] = { "Заблокирован" };
const char STATUS_UNLOCKED[20] = { "Разблокирован" };
const char YOUR_ACCOUNT_IS_LOCKED[64] = { "Ваш аккаунт заблокирован!\nОбратитесь к администратору!" };

struct authorizationForm
{
	char login[128];
	char password[128];
	char role;
	bool isLocked;
};

void enterData(authorizationForm* form);
void enterPassword(authorizationForm* form);
void enterRole(authorizationForm* form);
void errorOutput();
bool checkData(authorizationForm* form);
bool compareStrings(char str1[128], char str2[128]);
bool isLockedCheck(authorizationForm* form);