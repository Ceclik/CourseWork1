#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>

#include "AuthorizationScreen.h"

using namespace std;

FILE* f;

void enterData(authorizationForm* form)
{
	cout << ENTER_LOGIN;
	cin >> form->login;
	cout << ENTER_PASSWORD;
	enterPassword(form);
	cout << "\n" << ENTER_ROLE;
	enterRole(form);
	form->isLocked = false;
	cout << endl;
}

void enterPassword(authorizationForm* form)
{
	char key;
	int i = 0;
	while (key = _getch())
	{
		if (key != 13 && key != 8)
		{
			form->password[i] = key;
			i++;
			cout << "*";
		}
		if (key == 13)
			break;
		if (key == 8)
		{
			cout << "\r";
			for (int k = 0; k < 64; k++)
				cout << " ";
			cout << "\r" << "¬ведите пароль: ";
			for (int k = 0; k < i - 1; k++)
				cout << "*";
			form->password[i] = ' ';
			i--;
		}
	}
	form->password[i] = '\0';
}

void enterRole(authorizationForm* form)
{
	char key2;
	int j = 0;
	while (key2 = _getch())
	{
		if (key2 != 13 && key2 != 8 && key2 != 'п' && key2 != 'а')
			continue;
		if ((key2 != 13 && key2 != 8) && j == 0)
		{
			form->role = key2;
			cout << key2;
			j++;
		}
		else if (key2 == 8)
		{
			j--;
			cout << "\r";
			for (int i = 0; i < 64; i++)
				cout << " ";
			cout << "\r";
			cout << ENTER_ROLE;
		}
		else if (key2 == 13 && j > 0)
			break;
	}
}

bool checkData(authorizationForm* form)
{
	authorizationForm* bufferForm = new authorizationForm;
	f = fopen(ACCOUNTS_FILE_NAME, "r+");
	if (f == NULL)
	{
		cout << "file not found!";
		system("pause");
		return false;
	}
	int counter = 0;
	while (fread(bufferForm, sizeof(authorizationForm), 1, f))
	{
		if (compareStrings(bufferForm->login, form->login) && compareStrings(bufferForm->password, form->password) && bufferForm->role == form->role)
		{
			counter++;
			break;
		}
	}
	if (counter == 0)
	{
		delete bufferForm;
		fclose(f);
		return false;
	}
	else
	{
		if (isLockedCheck(bufferForm))
		{
			form->isLocked = true;
			cout << endl;
			cout << YOUR_ACCOUNT_IS_LOCKED;
			cout << "\n\n\n";
			system("pause");
			return false;
		}
		delete bufferForm;
		fclose(f);
		return true;
	}
}

void errorOutput()
{
	cout << endl << ERROR_WRONG_DATA;
}

bool compareStrings(char str1[128], char str2[128])
{
	if (strlen(str1) == strlen(str2))
	{
		int counter = 0;
		for (int i = 0; i < strlen(str1); i++)
		{
			if (str1[i] == str2[i])
				counter++;
		}
		if (counter == strlen(str2))
			return true;
		else return false;
	}
	else return false;
}

bool isLockedCheck(authorizationForm* form)
{
	if (form->isLocked)
		return true;
	else 
		return false;
}