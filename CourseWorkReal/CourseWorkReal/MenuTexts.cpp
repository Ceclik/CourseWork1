#include <iostream>
#include <conio.h>

#include "MenuTexts.h"
#include "AdminAccountFunctionality.h"
#include "AdminDataFunctionality.h"

using namespace std;

void adminMainMenuChoice(authorizationForm* form) 
{
	do
	{
		system("cls");
		cout << ADMIN_MENU_HEAD << endl;
		cout << ACCOUNTS_CONTROL << endl;
		cout << ADMIN_WORK_WITH_DATA << endl;
		cout << BACK << endl;
		char choice = _getch();
		switch (choice)
		{
		case'1':
			system("cls");
			adminAccountControlMenuChoice(form);
			break;
		case'2':
			system("cls");
			firstAdminDataMenuChoice();
			break;
		case 27:
			return;
			break;
		default:
			system("cls");
			adminErrorOutput();
			break;
		}
	} while (true);
}

void adminAccountControlMenuChoice(authorizationForm* form)
{
	do
	{
		system("cls");
		cout << WORK_WITH_ACCOUNTS_MENU_HEAD << endl;
		cout << WATCH_ALL_NOTES << endl;
		cout << ADD_NEW_ACCOUNT << endl;
		cout << EDIT_ACCOUNTS << endl;
		cout << ACCEPTING_USERS_CHANGES << endl;
		cout << BLOCK_ACCOUNT << endl;
		cout << DELETE_ACCOUNT << endl;
		cout << BACK << endl;
		char choice = _getch();
		switch (choice)
		{
		case'1':
			system("cls");
			watchAllAccounts();
			pause();
			break;
		case'2':
			system("cls");
			addAccount();
			break;
		case'3':
			system("cls");
			watchAllAccounts();
			editAccount();
			pause();
			break;
		case'4':

			break;
		case'5':
			system("cls");
			watchAllAccounts();
			changeAccontStatus(form);
			pause();
			break;
		case'6':
			system("cls");
			watchAllAccounts();
			deleteAccount(form);
			pause();
			break;
		case 27:
			return;
			break;
		default:
			system("cls");
			adminErrorOutput();
			break;
		}
	} while (true);
}

void firstAdminDataMenuChoice()
{
	do
	{
		system("cls");
		cout << HEAD_OF_FIRTS_ADMIN_DATA_MENU << endl << endl;
		cout << EDIT_MODE << endl;
		cout << PROCESSING_MODE << endl;
		cout << BACK;
		char choice = _getch();
		switch (choice)
		{
		case'1':
			system("cls");
			editModeMenuChoice();
			break;
		case '2':
			system("cls");
			processingMenuChoice();
			break;
		case 27:
			return;
			break;
		default:
			adminErrorOutput();
			break;
		}
	} while (true);
}

void editModeMenuChoice()
{
	do
	{
		system("cls");
		cout << HEAD_OF_EDIT_MENU << endl << endl;
		cout << WATCH_ALL_KINDS_OF_TICKET << endl;
		cout << ADD_NEW_KIND_OF_TICKET << endl;
		cout << DELETE_KIND_OF_TICKET << endl;
		cout << EDIT_KIND_OF_TICKET << endl;
		cout << BACK;
		char choice = _getch();
		switch (choice)
		{
		case '1':
			system("cls");
			cout << ALL_KINDS_OF_TICKETS << endl << endl;
			watchAllKindsOfTicket();
			pause();
			break;
		case '2':
			system("cls");
			addNewKindOfTicket();
			pause();
			break;
		case '3':
			system("cls");
			cout << DELETING_KIND_OF_TICKET << endl << endl;
			deleteKindOfTicket();
			pause();
			break;
		case '4':
			system("cls");
			cout << EDITING_KIND_OF_TICKET << endl << endl;
			editKindOfTicket();
			pause();
			break;
		case 27:
			return;
			break;
		default:
			adminErrorOutput();
			break;
		}
	} while (true);
}

void processingMenuChoice()
{
	do
	{
		system("cls");
		cout << HEAD_OF_PROCESSING_MENU << endl << endl;
		cout << ENTER_DAILY_DATA << endl;
		cout << WATCH_ALL_DATA << endl;
		cout << ALL_INCOME_PER_GIVEN_MONTH << endl;
		cout << LIST_OF_MOST_DEMANDED_TRANSPORT_PER_GIVEN_MONTH << endl;
		cout << SEARCH_DATA << endl;
		cout << SORT << endl;
		cout << WIPE_ALL_DATA << endl;
		cout << BACK;
		char choice = _getch();
		switch (choice)
		{
		case '1':
			system("cls");
			 cout << WRITING_DAILY_NOTE << endl << endl;
			 enterDailyData();
			 pause();
			break;
		case '2':
			system("cls");
			cout << ALL_DATA << endl << endl;
			watchAllSellingData();
			pause();
			break;
		case '3':
			system("cls");
			allIncomePerGivenMonth();
			pause();
			break;
		case '4':

			break;
		case '5':
			system("cls");
			searchMenuChoice();
			break;
		case '6':
			system("cls");
			sortMenuChoice();
			pause();
			break;
		case '7':
			system("cls");
			clearData();
			pause();
			break;
		case 27:
			return;
			break;
		default:
			adminErrorOutput();
			break;
		}
	} while (true);
}

void searchMenuChoice()
{
	do
	{
		system("cls");
		cout << HEAD_OF_SEARCH_MENU;
		cout << endl << endl << BY_DATE << endl;
		cout << BY_TRANSPORT << endl;
		cout << BY_ROUTE << endl << endl;
		cout << BACK;
		char choice = _getch();
		switch (choice)
		{
		case '1':
			system("cls");
			searchByDate();
			pause();
			break;
		case '2':
			system("cls");
			searchByTransport();
			pause();
			break;
		case '3':
			system("cls");
			searchByRouteNumber();
			pause();
			break;
		case 27:
			return;
			break;
		default:
			adminErrorOutput();
			break;
		}
	} while (true);
}

void sortMenuChoice()
{
	do
	{
		system("cls");
		cout << HEAD_OF_SORT_MENU;
		cout << endl << endl << SORT_BY_MONTH << endl;
		cout << BY_TRANSPORT << endl;
		cout << BY_ROUTE << endl << endl;
		cout << BACK;
		char choice = _getch();
		switch (choice)
		{
		case 27:
			return;
			break;
		case '1':
			system("cls");

			sortByMonth();
			pause();
			break;
		case '2':

			break;
		case '3':

			break;
		default:
			adminErrorOutput();
			break;
		}

	} while (true);
}

void pause()
{
	cout << "\n\n\n";
	system("pause");
}