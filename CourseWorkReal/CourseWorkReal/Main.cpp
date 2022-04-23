#include <iostream>
#include <Windows.h>

#include "AuthorizationScreen.h"
#include "AdminAccountFunctionality.h"
#include "MenuTexts.h"

using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	do 
	{
		authorizationForm* form = new authorizationForm;
		system("cls");
		cout << ENTER_YOUR_DATA;
		enterData(form);
		if (checkData(form))
		{
			if (form->role == -32)
			{
				cout << GET_ADMIN_ROLE;
				system("pause");
				adminMainMenuChoice(form);
			}
			else if (form->role == -17)
			{
				delete form;
				cout << GET_USER_ROLE;
				system("pause");
			}
		}
		else if (form->isLocked)
			continue;
		else
		{
			delete form;
			errorOutput();
		}
		system("pause");
		
	} while (true);
	/*authorizationForm* form = new authorizationForm;
	adminMainMenuChoice(form);*/
}