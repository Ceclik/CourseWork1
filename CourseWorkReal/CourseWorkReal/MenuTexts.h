#pragma once

#include "AuthorizationScreen.h"

//admin main menu
const char ADMIN_MENU_HEAD[64] = { "--------Меню администратора--------\n" };
const char ACCOUNTS_CONTROL[64] = { "1. Управление учётными записями" };
const char ADMIN_WORK_WITH_DATA[64] = { "2. Работа с данными" };

//admin work with accaunts menu
const char WORK_WITH_ACCOUNTS_MENU_HEAD[64] = { "--------Работа с учётными записями--------\n" };
const char WATCH_ALL_NOTES[64] = { "1. Просмотр всех учётных записей" };
const char ADD_NEW_ACCOUNT[64] = { "2. Добавление новой учётной записи" };
const char EDIT_ACCOUNTS[64] = { "3. Редактирование учётной записи" };
const char ACCEPTING_USERS_CHANGES[64] = { "4. Подтверждение пользовательских изменений" };
const char BLOCK_ACCOUNT[64] = { "5. Изменение статуса учётных записей" };
const char DELETE_ACCOUNT[64] = { "6. Удаление учётных записей" };
const char EXIT_TO_MAIN_MENU[64] = { "7. Выйти в главное меню" };

//first admin data menu
const char HEAD_OF_FIRTS_ADMIN_DATA_MENU[64] = { "--------Администраторское меню работы с данными--------" };
const char EDIT_MODE[64] = { "1. Режим редактирования данных" };
const char PROCESSING_MODE[64] = { "2. Реижм обработки данных" };

//edit menu 
const char HEAD_OF_EDIT_MENU[64] = { "--------Режим редактирования данных--------" };
const char WATCH_ALL_KINDS_OF_TICKET[64] = { "1. Просмотр всех типов билетов" };
const char ADD_NEW_KIND_OF_TICKET[64] = { "2. Добавление типа билета" };
const char DELETE_KIND_OF_TICKET[64] = { "3. Удаление типа билета" };
const char EDIT_KIND_OF_TICKET[64] = { "4. Редактирование типа билета" };

//processing menu
const char HEAD_OF_PROCESSING_MENU[64] = {"--------Режим обработки данных--------"};
const char ENTER_DAILY_DATA[64] = { "1. Внести данные о продажах за день" };
const char ALL_INCOME_PER_GIVEN_MONTH[64] = { "3. Вычислить общий доход за указанный месяц" };
const char WATCH_ALL_DATA[64] = { "2. Просмотреть все даные" };
const char LIST_OF_MOST_DEMANDED_TRANSPORT_PER_GIVEN_MONTH[128] = { "4. Посмотреть список самых востребованных видов транспорта за указанный месяц" };
const char SEARCH_DATA[64] = { "5. Поиск данных" };
const char SORT[64] = { "6. Сортировка данных" };
const char WIPE_ALL_DATA[64] = { "7. Очистить данные" };

//data search menu
const char HEAD_OF_SEARCH_MENU[64] = { "--------Поиск данных--------" };
const char BY_DATE[64] = { "1. По дате" };
const char BY_TRANSPORT[64] = { "2. По виду транспорта" };
const char BY_ROUTE[64] = { "3. По номеру маршрута" };

//data sort menu
const char HEAD_OF_SORT_MENU[64] = { "--------Сортировка данных--------" };
const char SORT_BY_MONTH[64] = { "1. По месяцу" };

const char ALL_DATA[64] = { "--------Все данные--------" };

const char BACK[15] = { "\nEsc: Назад" };

void adminMainMenuChoice(authorizationForm* form);
void adminAccountControlMenuChoice(authorizationForm* form);
void firstAdminDataMenuChoice();
void editModeMenuChoice();
void processingMenuChoice();
void searchMenuChoice();
void sortMenuChoice();
void pause();