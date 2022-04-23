#pragma once
#include "AuthorizationScreen.h"

const char CREATING_NEW_ACCOUNT[64] = { "------Создание нового акккаунта------" };
const char SUCCESS_ACCOUNT_ADD[64] = { "Аккаунт успешно создан!" };
const char FAILED_TO_ADD_ACCOUNT[64] = { "Неудалось создать аккаунт!" };
const char ALL_REGISTERED_ACCOUNTS[64] = { "--------Все зарегистрированные аккаунты--------" };
const char WHAT_ACCOUNT_YOU_WANT_TO_ENDIT[64] = {"Какую учётную запись хотите отредактировать: "};
const char ACCOUNT_DATA_CHANGED[64] = { "Данные аккаунта успешно отредактированы!" };
const char WHAT_ACCOUNT_TO_DELETE[64] = { "Какую учётную запись хотите удалить: " };
const char SUCCESSFUL_DELETE[64] = { "Аккаунт успешно удалён!" };
const char WHAT_ACCOUTN_TO_CHANGE[64] = { "Статус какой учётной записи хотите изменить: " };
const char DO_YOU_WANT_TO_LOCK[64] = { "Хотите заблокировать эту учётную запись?\n1. Да\n2. Нет" };
const char DO_YOU_WANT_YO_UNLOCK[64] = { "Хотите разблокировать эту учётную запись?\n1. Да\n2. Нет" };
const char WRONG_OUTPUT_TRY_AGAIN[64] = { "Неверный ввод!\n\nПопробуйте заново!\n\n\n" };
const char STATUS_CHANGED_SUCCESSFULLY[64] = { "Статус учётной записи успешно изменён" };
const char CANT_CHANGE_YOUR_ACCOUNT[64] = { "Вы не можете изменить статус вашей учётной записи!" };
const char CANT_DELETE_YOUR_ACCOUNT[64] = { "Вы не можете удалить вашу учётную запись!" };

void addAccount();
bool writeNewAccountToFile(authorizationForm* registerForm);
void adminErrorOutput();
void watchAllAccounts();
void printAccounts(authorizationForm* bufferFormForRead, int counter);
void editAccount();
void deleteAccount(authorizationForm* form);
void changeAccontStatus(authorizationForm* form);
bool isEqual(authorizationForm* form, authorizationForm* bufferForm);