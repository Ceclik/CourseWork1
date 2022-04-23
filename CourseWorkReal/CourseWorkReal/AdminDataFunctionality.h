#pragma once

using namespace std;


const char KINDS_OF_TICKET_FILE_NAME[40] = { "kindsOfTicketfile.txt" };
const char DATA_FILE_NAME[40] = { "dataFile.txt" };

const char ADDING_KIND_OF_TICKET[64] = { "--------���������� ������ ���� �������--------" };
const char ENTER_PRICE[64] = { "������� ���� �� ������: " };
const char ENTER_KIND_OF_TRANSPORT[64] = { "������� ��� ����������: " };
const char ENTER_ROUTE_NUMBER[64] = { "������� ����� ��������: " };
const char NEW_KIND_SUCCESSFULLY_ADDED[64] = { "����� ��� ������ ������� ��������!" };

const char KIND_OF_TRANSPORT[20] = { ". ��� ����������: " };
const char ROUTE_NUMBER[20] = { "   ����� ��������: " };
const char PRICE[20] = { "   ����: " };
const char ALL_KINDS_OF_TICKETS[64] = { "--------��� ���� �������--------" };

const char EDITING_KIND_OF_TICKET[64] = { "--------��������� ���� ������--------" };
const char WHAT_TYPE_OF_TICKET_YOU_WANT_TO_CHANGE[64] = { "����� ��� ������� �� ������ ��������: " };
const char TICKET_KIND_WAS_SUCCESSFULLY_CHANGED[64] = { "��� ������ ��� ������� ������!" };

const char DELETING_KIND_OF_TICKET[64] = { "--------�������� ���� ������--------" };
const char CANT_DELETE_LAST_TYPE[64] = { "�� �� ������ ������� ������������ ���\n����� �������������� ���!" };
const char WHAT_TYPE_OF_TICKET_YOU_WANT_TO_DELETE[64] = { "����� ��� ������ ������ �������: " };
const char TICKET_TYPE_HAS_BEEN_SUCCESSFULLY_DELETED[64] = { "��� ������ ��� ������� �����!" };

const char WRITING_DAILY_NOTE[64] = { "--------�������� ������ � �������� �� ����--------" };
const char CHOOSE_TYPE_OF_TICKET[64] = { "�������� ��� ������: " };
const char ENTER_DAY[64] = { "������� ���� ������: " };
const char ENTER_MONTH[64] = { "������� ������� �����: " };
const char ENTER_AMOUNT[64] = { "������� ����������� ��������� ������� ����� ����: " };
const char DAILY_DATA_HAS_BEEN_SUCCESSSFULLY_ADDED[64] = { "������ ���� ������� �������!" };

const char NO_WRITTEN_DATA[64] = { "������ �� �������!" };
const char DATA_HAS_BEEN_CLEARED[64] = { "������ �������!" };
const char WRONG_MONTH[64] = { "����� ����� �����������\n\n���������� ������ ������ ������!" };
const char WRONG_DAY[64] = { "���� ����� �����������\n\n���������� ������ ������ ������!" };
const char WRONG_AMOUNT[67] = { "����������� ������ �����������\n\n���������� ������ ������ ������!" };
const char WRONG_TICKET_TYPE[64] = { "��� ���� ������ ��� ����� �������\n\n��������� ����: " };
const char TOTAL_REVENUE_PER_GIVEN_MONTH[64] = { "����� ������� �� ������ �����: " };

const char DATE_SEARCH[64] = { "--------����� �� ����--------" };
const char TRANSPORT_SEARCH[64] = { "--------����� �� ���� ����������--------" };
const char ROUTE_SEARCH[64] = { "--------����� �� ������ ��������--------" };

const char SORT_BY_MONTH_HEAD[64] = { "--------���������� �� ������--------" };

struct ticketData
{
	double price;
	char kindOfTransport[15];
	int routeNumber;
};

struct dataNote
{
	ticketData ticket;
	int day;
	int month;
	int amount;
};

void addNewKindOfTicket();
void enterTicketData(ticketData* ticket);
void printTicketData(ticketData* ticket, int number);
int watchAllKindsOfTicket();
void editKindOfTicket();
void deleteKindOfTicket();
void enterDailyData();
void watchAllSellingData();
void printDataNote(dataNote* note, int number);
void clearData();
void allIncomePerGivenMonth();
void searchByDate();
void searchByTransport();
void searchByRouteNumber();
void sortByMonth();
void directChoiceSort(dataNote** arrayForSort[], int amountOfNotes);


//drawingTable

const char HEAD_OF_TABLE[64] = { "�  |  ��������� | ������� | ���� | ���� | ����� | ����������� |" };
const char LINE[66] = { "---------------------------------------------------------------" };
const char VLINE = '|';


const char RESULT[64] = { "���������: " };