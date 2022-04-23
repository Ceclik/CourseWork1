#pragma once

#include "AuthorizationScreen.h"

//admin main menu
const char ADMIN_MENU_HEAD[64] = { "--------���� ��������������--------\n" };
const char ACCOUNTS_CONTROL[64] = { "1. ���������� �������� ��������" };
const char ADMIN_WORK_WITH_DATA[64] = { "2. ������ � �������" };

//admin work with accaunts menu
const char WORK_WITH_ACCOUNTS_MENU_HEAD[64] = { "--------������ � �������� ��������--------\n" };
const char WATCH_ALL_NOTES[64] = { "1. �������� ���� ������� �������" };
const char ADD_NEW_ACCOUNT[64] = { "2. ���������� ����� ������� ������" };
const char EDIT_ACCOUNTS[64] = { "3. �������������� ������� ������" };
const char ACCEPTING_USERS_CHANGES[64] = { "4. ������������� ���������������� ���������" };
const char BLOCK_ACCOUNT[64] = { "5. ��������� ������� ������� �������" };
const char DELETE_ACCOUNT[64] = { "6. �������� ������� �������" };
const char EXIT_TO_MAIN_MENU[64] = { "7. ����� � ������� ����" };

//first admin data menu
const char HEAD_OF_FIRTS_ADMIN_DATA_MENU[64] = { "--------����������������� ���� ������ � �������--------" };
const char EDIT_MODE[64] = { "1. ����� �������������� ������" };
const char PROCESSING_MODE[64] = { "2. ����� ��������� ������" };

//edit menu 
const char HEAD_OF_EDIT_MENU[64] = { "--------����� �������������� ������--------" };
const char WATCH_ALL_KINDS_OF_TICKET[64] = { "1. �������� ���� ����� �������" };
const char ADD_NEW_KIND_OF_TICKET[64] = { "2. ���������� ���� ������" };
const char DELETE_KIND_OF_TICKET[64] = { "3. �������� ���� ������" };
const char EDIT_KIND_OF_TICKET[64] = { "4. �������������� ���� ������" };

//processing menu
const char HEAD_OF_PROCESSING_MENU[64] = {"--------����� ��������� ������--------"};
const char ENTER_DAILY_DATA[64] = { "1. ������ ������ � �������� �� ����" };
const char ALL_INCOME_PER_GIVEN_MONTH[64] = { "3. ��������� ����� ����� �� ��������� �����" };
const char WATCH_ALL_DATA[64] = { "2. ����������� ��� �����" };
const char LIST_OF_MOST_DEMANDED_TRANSPORT_PER_GIVEN_MONTH[128] = { "4. ���������� ������ ����� �������������� ����� ���������� �� ��������� �����" };
const char SEARCH_DATA[64] = { "5. ����� ������" };
const char SORT[64] = { "6. ���������� ������" };
const char WIPE_ALL_DATA[64] = { "7. �������� ������" };

//data search menu
const char HEAD_OF_SEARCH_MENU[64] = { "--------����� ������--------" };
const char BY_DATE[64] = { "1. �� ����" };
const char BY_TRANSPORT[64] = { "2. �� ���� ����������" };
const char BY_ROUTE[64] = { "3. �� ������ ��������" };

//data sort menu
const char HEAD_OF_SORT_MENU[64] = { "--------���������� ������--------" };
const char SORT_BY_MONTH[64] = { "1. �� ������" };

const char ALL_DATA[64] = { "--------��� ������--------" };

const char BACK[15] = { "\nEsc: �����" };

void adminMainMenuChoice(authorizationForm* form);
void adminAccountControlMenuChoice(authorizationForm* form);
void firstAdminDataMenuChoice();
void editModeMenuChoice();
void processingMenuChoice();
void searchMenuChoice();
void sortMenuChoice();
void pause();