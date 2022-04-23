#pragma once
#include "AuthorizationScreen.h"

const char CREATING_NEW_ACCOUNT[64] = { "------�������� ������ ���������------" };
const char SUCCESS_ACCOUNT_ADD[64] = { "������� ������� ������!" };
const char FAILED_TO_ADD_ACCOUNT[64] = { "��������� ������� �������!" };
const char ALL_REGISTERED_ACCOUNTS[64] = { "--------��� ������������������ ��������--------" };
const char WHAT_ACCOUNT_YOU_WANT_TO_ENDIT[64] = {"����� ������� ������ ������ ���������������: "};
const char ACCOUNT_DATA_CHANGED[64] = { "������ �������� ������� ���������������!" };
const char WHAT_ACCOUNT_TO_DELETE[64] = { "����� ������� ������ ������ �������: " };
const char SUCCESSFUL_DELETE[64] = { "������� ������� �����!" };
const char WHAT_ACCOUTN_TO_CHANGE[64] = { "������ ����� ������� ������ ������ ��������: " };
const char DO_YOU_WANT_TO_LOCK[64] = { "������ ������������� ��� ������� ������?\n1. ��\n2. ���" };
const char DO_YOU_WANT_YO_UNLOCK[64] = { "������ �������������� ��� ������� ������?\n1. ��\n2. ���" };
const char WRONG_OUTPUT_TRY_AGAIN[64] = { "�������� ����!\n\n���������� ������!\n\n\n" };
const char STATUS_CHANGED_SUCCESSFULLY[64] = { "������ ������� ������ ������� ������" };
const char CANT_CHANGE_YOUR_ACCOUNT[64] = { "�� �� ������ �������� ������ ����� ������� ������!" };
const char CANT_DELETE_YOUR_ACCOUNT[64] = { "�� �� ������ ������� ���� ������� ������!" };

void addAccount();
bool writeNewAccountToFile(authorizationForm* registerForm);
void adminErrorOutput();
void watchAllAccounts();
void printAccounts(authorizationForm* bufferFormForRead, int counter);
void editAccount();
void deleteAccount(authorizationForm* form);
void changeAccontStatus(authorizationForm* form);
bool isEqual(authorizationForm* form, authorizationForm* bufferForm);