#pragma once

const char ACCOUNTS_FILE_NAME[64] = { "accounts.txt" };
const char ENTER_YOUR_DATA[64] = { "-------------������� ���� ������------------\n" };
const char ENTER_LOGIN[64] = { "������� �����: " };
const char ENTER_PASSWORD[64] = { "������� ������: " };
const char ENTER_ROLE[64] = { "������� ����(� - �����; � - ������������): " };
const char ERROR_WRONG_DATA[64] = { "�������� ���� ������ �������!\n\n��������� �������!\n\n\n" };
const char GET_ADMIN_ROLE[64] = { "\n�� ����� � ������� ��������������!\n\n\n" };
const char GET_USER_ROLE[64] = { "\n�� ����� � ������� ������������!\n\n\n" };
const char LOGIN[20] = { ". �����: " };
const char PASSWORD[20] = { "   ������: " };
const char ROLE[20] = { "   ����: " };
const char ADMIN[20] = { "������������" };
const char USER[20] = { "������������" };
const char STATUS[20] = { "   ������: " };
const char STATUS_LOCKED[20] = { "������������" };
const char STATUS_UNLOCKED[20] = { "�������������" };
const char YOUR_ACCOUNT_IS_LOCKED[64] = { "��� ������� ������������!\n���������� � ��������������!" };

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