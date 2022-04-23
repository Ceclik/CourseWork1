#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <corecrt_io.h>
#include <iomanip>

#include "AdminDataFunctionality.h"
#include "AuthorizationScreen.h"

using namespace std;

FILE* File;

int watchAllKindsOfTicket()
{
	ticketData* ticket = new ticketData;
	int number = 1;
	File = fopen(KINDS_OF_TICKET_FILE_NAME, "r");
	while (fread(ticket, sizeof(ticketData), 1, File))
	{
		printTicketData(ticket, number);
		cout << endl;
		number++;
	}
	return number;
}

void addNewKindOfTicket()
{
	cout << ADDING_KIND_OF_TICKET << endl;
	ticketData* ticket = new ticketData;
	enterTicketData(ticket);
	File = fopen(KINDS_OF_TICKET_FILE_NAME, "a");
	if(File == NULL)
		File = fopen(KINDS_OF_TICKET_FILE_NAME, "w");
	fwrite(ticket, sizeof(ticketData), 1, File);
	fclose(File);
	delete ticket;
	cout << endl << endl << NEW_KIND_SUCCESSFULLY_ADDED;
}

void enterTicketData(ticketData* ticket)
{
	cout << endl << ENTER_KIND_OF_TRANSPORT;
	cin >> ticket->kindOfTransport;
	cout << ENTER_ROUTE_NUMBER;
	cin >> ticket->routeNumber;
	cout << ENTER_PRICE;
	cin >> ticket->price;
}

void editKindOfTicket()
{
	watchAllKindsOfTicket();
	cout << WHAT_TYPE_OF_TICKET_YOU_WANT_TO_CHANGE;
	int numberOfType;
	cin >> numberOfType;
	ticketData* bufferForChange = new ticketData;
	File = fopen(KINDS_OF_TICKET_FILE_NAME, "r+");
	fseek(File, (numberOfType - 1) * sizeof(ticketData), SEEK_SET);
	enterTicketData(bufferForChange);
	fwrite(bufferForChange, sizeof(ticketData), 1, File);
	fclose(File);
	delete bufferForChange;
	cout << endl << TICKET_KIND_WAS_SUCCESSFULLY_CHANGED;
}

void deleteKindOfTicket()
{
	int amountOfTicketTypes = watchAllKindsOfTicket();
	if (amountOfTicketTypes == 2)
	{
		cout << CANT_DELETE_LAST_TYPE;
		return;
	}
	cout << WHAT_TYPE_OF_TICKET_YOU_WANT_TO_DELETE;
	int numberOfType;
	cin >> numberOfType;
	ticketData* bufferForMove = new ticketData;
	File = fopen(KINDS_OF_TICKET_FILE_NAME, "r+");
	fseek(File, numberOfType * sizeof(ticketData), SEEK_SET);
	while (fread(bufferForMove, sizeof(ticketData), 1, File))
	{
		fseek(File, (numberOfType - 1) * sizeof(ticketData), NULL);
		fwrite(bufferForMove, sizeof(ticketData), 1, File);
		fseek(File, (++numberOfType) * sizeof(ticketData), NULL);
	}
	_chsize(_fileno(File), _filelength(_fileno(File)) - sizeof(ticketData));
	delete bufferForMove;
	fclose(File);
	cout << endl << TICKET_TYPE_HAS_BEEN_SUCCESSFULLY_DELETED << endl;
}

void printTicketData(ticketData* ticket, int number)
{
	cout << number << KIND_OF_TRANSPORT << ticket->kindOfTransport << endl;
	cout << ROUTE_NUMBER << ticket->routeNumber << endl;
	cout << PRICE << ticket->price << endl;
}

void enterDailyData()
{
	int amountOfTicketKinds = watchAllKindsOfTicket();
	cout << CHOOSE_TYPE_OF_TICKET;
	int chosenType;
	cin >> chosenType;
	while (chosenType > amountOfTicketKinds || chosenType < 1)
	{
		cout << WRONG_TICKET_TYPE;
		cin >> chosenType;
	}
	File = fopen(KINDS_OF_TICKET_FILE_NAME, "r");
	fseek(File, (chosenType - 1) * sizeof(ticketData), SEEK_SET);
	ticketData* bufferType = new ticketData;
	fread(bufferType, sizeof(ticketData), 1, File);
	fclose(File);
	dataNote* note = new dataNote;
	for (int i = 0; i < strlen(bufferType->kindOfTransport-1); i++)
		note->ticket.kindOfTransport[i] = bufferType->kindOfTransport[i];
	note->ticket.kindOfTransport[strlen(note->ticket.kindOfTransport)] = '\0';
	note->ticket.price = bufferType->price;
	note->ticket.routeNumber = bufferType->routeNumber;
	delete bufferType;
	bool correctEnter = false;
	do
	{
		cout << endl << endl;
		cout << ENTER_MONTH;
		cin >> note->month;
		if (note->month > 12 || note->month < 1)
		{
			cout << endl << WRONG_MONTH << endl;
			system("pause");
			continue;
		}
		cout << ENTER_DAY;
		cin >> note->day;
		if (note->day < 1 || ((note->month == 1 || note->month == 3 || note->month == 5 || note->month == 7
			|| note->month == 8 || note->month == 10 || note->month == 12) && note->day > 31)
			|| ((note->month == 4 || note->month == 6 || note->month == 9 || note->month == 10) && note->day > 30)
			|| (note->month == 2 && note->day > 28))
		{
			cout << endl << WRONG_DAY << endl;
			system("pause");
			continue;
		}
		cout << ENTER_AMOUNT;
		cin >> note->amount;
		if (note->amount < 0)
		{
			cout << endl << WRONG_AMOUNT << endl;
			system("pause");
			continue;
		}
		correctEnter = true;
	} while (correctEnter == false);

	File = fopen(DATA_FILE_NAME, "a");
	if(File == NULL)
		File = fopen(DATA_FILE_NAME, "w");
	fwrite(note, sizeof(dataNote), 1, File);
	fclose(File);
	delete note;
	cout << endl << DAILY_DATA_HAS_BEEN_SUCCESSSFULLY_ADDED << endl;
}

void watchAllSellingData()
{
	dataNote* bufferNote = new dataNote;
	File = fopen(DATA_FILE_NAME, "r");
	if (!fread(bufferNote, sizeof(dataNote), 1, File))
	{
		cout << NO_WRITTEN_DATA << endl;
		return;
	}
	fclose(File);
	cout << HEAD_OF_TABLE << endl;
	cout << LINE << endl;
	File = fopen(DATA_FILE_NAME, "r");
	int noteNumber = 1;
	while (fread(bufferNote, sizeof(dataNote), 1, File))
	{
		printDataNote(bufferNote, noteNumber);
		//cout << LINE << endl;
		noteNumber++;
	}
	fclose(File);
	delete bufferNote;
}

void clearData()
{
	File = fopen(DATA_FILE_NAME, "w");
	fclose(File);
	cout << DATA_HAS_BEEN_CLEARED << endl;
}

void printDataNote(dataNote* note, int number)
{
	cout << setw(3) << number << VLINE;
	cout << setw(11) << note->ticket.kindOfTransport << " " << VLINE;
	cout << setw(8) << note->ticket.routeNumber << " " << VLINE;
	cout << setw(5) << note->ticket.price << " " << VLINE;
	cout << setw(5) << note->day << " " << VLINE;
	cout << setw(6) << note->month << " " << VLINE;
	cout << setw(12) << note->amount << " " << VLINE << endl;
}

void allIncomePerGivenMonth()
{
	cout << ENTER_MONTH;
	int month; bool correctInput = false;
	do
	{
		cin >> month;
		if (month < 0 || month > 12)
		{
			cout << WRONG_MONTH << endl;
			system("pause");
			continue;
		}
		correctInput = true;
	} while (correctInput == false);
	dataNote* note = new dataNote;
	File = fopen(DATA_FILE_NAME, "r");
	int amountOfmaches = 1; double totalRevenue = 0;

	cout << endl << HEAD_OF_TABLE << endl;
	cout << LINE << endl;
	while (fread(note, sizeof(dataNote), 1, File))
		if (note->month == month)
		{
			printDataNote(note, amountOfmaches);
			amountOfmaches++;
			totalRevenue += (note->ticket.price * note->amount);
		}
	delete note;
	fclose(File);
	cout << endl << TOTAL_REVENUE_PER_GIVEN_MONTH << totalRevenue;
}

void searchByDate()
{
	cout << DATE_SEARCH << endl << endl;
	int month, day;
	bool correctInput = false;
	do
	{
		cout << ENTER_MONTH;
		cin >> month;
		if (month > 12 || month < 1)
		{
			cout << WRONG_MONTH << endl << endl;
			system("pause");
			continue;
		}
		cout << ENTER_DAY;
		cin >> day;
		if (day < 1 || ((month == 1 || month == 3 || month == 5 || month == 7
			|| month == 8 || month == 10 || month == 12) && day > 31)
			|| ((month == 4 || month == 6 || month == 9 || month == 10) && day > 30)
			|| (month == 2 && day > 28))
		{
			cout << WRONG_DAY << endl << endl;
			system("pause");
			continue;
		}
		correctInput = true;
	} while (correctInput == false);

	cout << endl << RESULT << endl;
	cout << endl << HEAD_OF_TABLE << endl;
	cout << LINE << endl;
	int amountOfMaches = 1;
	dataNote* note = new dataNote;
	File = fopen(DATA_FILE_NAME, "r");
	while (fread(note, sizeof(dataNote), 1, File))
		if (day == note->day && month == note->month)
		{
			printDataNote(note, amountOfMaches);
			amountOfMaches++;
		}
	fclose(File);
	delete note;
}

void searchByTransport()
{
	cout << TRANSPORT_SEARCH << endl << endl;
	cout << KIND_OF_TRANSPORT;
	char kindOFTransport[64];
	cin >> kindOFTransport;
	dataNote* note = new dataNote;
	File = fopen(DATA_FILE_NAME, "r");
	int amountOfMaches = 1;
	cout << endl << RESULT << endl;
	cout << endl << HEAD_OF_TABLE << endl;
	cout << LINE << endl;
	while (fread(note, sizeof(dataNote), 1, File))
		if (compareStrings(kindOFTransport, note->ticket.kindOfTransport))
		{
			printDataNote(note, amountOfMaches);
			amountOfMaches++;
		}
	delete note;
	fclose(File);
}

void searchByRouteNumber()
{
	cout << ROUTE_SEARCH << endl << endl;
	cout << ROUTE_NUMBER;
	int routeNumber;
	cin >> routeNumber;
	dataNote* note = new dataNote;
	File = fopen(DATA_FILE_NAME, "r");
	int amountOfMaches = 1;
	cout << endl << RESULT << endl;
	cout << endl << HEAD_OF_TABLE << endl;
	cout << LINE << endl;
	while (fread(note, sizeof(dataNote), 1, File))
		if (routeNumber == note->ticket.routeNumber)
		{
			printDataNote(note, amountOfMaches);
			amountOfMaches++;
		}
	delete note;
	fclose(File);
}

void sortByMonth()
{
	File = fopen(DATA_FILE_NAME, "r");
	int amountOFNotes = _filelength(_fileno(File)) / sizeof(dataNote);
	dataNote* bufferNote = new dataNote;
	dataNote** arrayForSort = new dataNote*[amountOFNotes];
	int i = 0;
	while (fread(bufferNote, sizeof(dataNote), 1, File))
	{
		arrayForSort[i] = bufferNote;
		i++;
	}
	fclose(File);
	directChoiceSort((&arrayForSort), amountOFNotes);
	cout << RESULT << endl;
	cout << endl << HEAD_OF_TABLE << endl;
	cout << LINE << endl;
	i = 0;
	while (amountOFNotes > 0)
	{
		printDataNote((arrayForSort[i]), i);
		amountOFNotes--;
		i++;
	}
}

void directChoiceSort(dataNote** arrayForSort[], int amountOfNotes)
{
	dataNote* temp = new dataNote;
	int max = 0;
	for (int i = 0; i < amountOfNotes; i++)
	{
		max = i;
		for (int j = i + 1; j < amountOfNotes; j++)
			if ((*arrayForSort[j])->month > (*arrayForSort[max])->month) max = j;
		temp = (*arrayForSort[i]);
		(*arrayForSort[i]) = (*arrayForSort[max]);
		(*arrayForSort[max]) = temp;
	}
	delete temp;
	return;
}