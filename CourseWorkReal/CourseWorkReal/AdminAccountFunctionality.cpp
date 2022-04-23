#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include <corecrt_io.h>

#include "AuthorizationScreen.h"
#include "AdminAccountFunctionality.h"
#include "MenuTexts.h"

using namespace std;

FILE* file;

void watchAllAccounts()
{
	file = fopen(ACCOUNTS_FILE_NAME, "r");
	cout << ALL_REGISTERED_ACCOUNTS << endl << endl;
	authorizationForm* bufferFormForRead = new authorizationForm;
	int counter = 1;
	while (fread(bufferFormForRead, sizeof(authorizationForm), 1, file))
	{
		printAccounts(bufferFormForRead, counter);
		cout << endl << endl;
		counter++;
	}
	fclose(file);
}

void printAccounts(authorizationForm* bufferFormForRead, int counter)
{
	cout << counter << LOGIN << bufferFormForRead->login << endl;
	cout << PASSWORD << bufferFormForRead->password << endl;
	cout << ROLE;
	if (bufferFormForRead->role == -32)
		cout << ADMIN << endl;
	else
		cout << USER << endl;
	cout << STATUS;
	if (isLockedCheck(bufferFormForRead))
		cout << STATUS_LOCKED;
	else
		cout << STATUS_UNLOCKED;
}
void addAccount()
{
	authorizationForm* registerForm = new authorizationForm;
	cout << CREATING_NEW_ACCOUNT << endl << endl;
	enterData(registerForm);
	if (writeNewAccountToFile(registerForm))
	{
		cout << SUCCESS_ACCOUNT_ADD << endl << endl << endl;
	}
	system("pause");
}

bool writeNewAccountToFile(authorizationForm* registerForm)
{
	file = fopen(ACCOUNTS_FILE_NAME, "a");
	if (file == NULL)
		file = fopen(ACCOUNTS_FILE_NAME, "w");
	if (fwrite(registerForm, sizeof(authorizationForm), 1, file))
	{
		fclose(file);
		return true;
	}
	else 
	{ 
		fclose(file); 
		return false;
	}
}

void editAccount()
{
	authorizationForm* formForChange = new authorizationForm;
	cout << endl;
	cout << WHAT_ACCOUNT_YOU_WANT_TO_ENDIT;
	int numberOfAccountToEdit;
	cin >> numberOfAccountToEdit;
	file = fopen(ACCOUNTS_FILE_NAME, "r+");
	fseek(file, (numberOfAccountToEdit - 1) * sizeof(authorizationForm), NULL);
	enterData(formForChange);
	fwrite(formForChange, sizeof(authorizationForm), 1, file);
	fclose(file);
	delete formForChange;
	cout << endl;
	cout << ACCOUNT_DATA_CHANGED << endl;
}

void adminErrorOutput()
{
	system("cls");
	cout << WRONG_OUTPUT_TRY_AGAIN;
	system("pause");
}

void deleteAccount(authorizationForm* form)
{
	authorizationForm* bufferForMove = new authorizationForm;
	cout << WHAT_ACCOUNT_TO_DELETE;
	int numberOfAccountToDelete;
	cin >> numberOfAccountToDelete;
	file = fopen(ACCOUNTS_FILE_NAME, "r+");
	fseek(file, (numberOfAccountToDelete - 1) * sizeof(authorizationForm), NULL);
	fread(bufferForMove, sizeof(authorizationForm), 1, file);
	if (isEqual(bufferForMove, form))
	{
		cout << endl;
		cout << CANT_DELETE_YOUR_ACCOUNT << "\n\n\n";
		return;
	}
	fseek(file, numberOfAccountToDelete * sizeof(authorizationForm), NULL);
	while (fread(bufferForMove, sizeof(authorizationForm), 1, file))
	{
		fseek(file, (numberOfAccountToDelete - 1) * sizeof(authorizationForm), NULL);
		fwrite(bufferForMove, sizeof(authorizationForm), 1, file);
		fseek(file, (++numberOfAccountToDelete) * sizeof(authorizationForm), NULL);
	}
	_chsize(_fileno(file), _filelength(_fileno(file)) - sizeof(authorizationForm));
	delete bufferForMove;
	fclose(file);
	cout << endl << SUCCESSFUL_DELETE;
}

void changeAccontStatus(authorizationForm* form)
{
	authorizationForm* bufferForChange = new authorizationForm;
	cout << endl;
	cout << WHAT_ACCOUTN_TO_CHANGE;
	int numberOfAccountToChange;
	cin >> numberOfAccountToChange;
	file = fopen(ACCOUNTS_FILE_NAME, "r+");
	fseek(file, (numberOfAccountToChange - 1) * sizeof(authorizationForm), SEEK_SET);
	fread(bufferForChange, sizeof(authorizationForm), 1, file);
	if (isEqual(bufferForChange, form))
	{
		cout << endl;
		cout << CANT_CHANGE_YOUR_ACCOUNT << "\n\n\n";
		return;
	}
	if (isLockedCheck(bufferForChange))
	{
		cout << DO_YOU_WANT_YO_UNLOCK;
		char choice = _getch();
		if (choice == '1')
			bufferForChange->isLocked = false;
		if (choice == '2')
			return;
	}
	else
	{
		cout << DO_YOU_WANT_TO_LOCK;
		char choice = _getch();
		if (choice == '1')
			bufferForChange->isLocked = true;
		if (choice == '2')
			return;
	}
	fseek(file, (numberOfAccountToChange - 1) * sizeof(authorizationForm), SEEK_SET);
	fwrite(bufferForChange, sizeof(authorizationForm), 1, file);
	cout << endl << STATUS_CHANGED_SUCCESSFULLY;
	fclose(file);
	delete bufferForChange;
}

bool isEqual(authorizationForm* form, authorizationForm* bufferForm)
{
	if (compareStrings(bufferForm->login, form->login) && compareStrings(bufferForm->password, form->password) && bufferForm->role == form->role)
		return true;
	else
		return false;
}