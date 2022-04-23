#pragma once

using namespace std;


const char KINDS_OF_TICKET_FILE_NAME[40] = { "kindsOfTicketfile.txt" };
const char DATA_FILE_NAME[40] = { "dataFile.txt" };

const char ADDING_KIND_OF_TICKET[64] = { "--------Добавление нового типа билетов--------" };
const char ENTER_PRICE[64] = { "Введите цену за проезд: " };
const char ENTER_KIND_OF_TRANSPORT[64] = { "Введите вид транспорта: " };
const char ENTER_ROUTE_NUMBER[64] = { "Введите номер маршрута: " };
const char NEW_KIND_SUCCESSFULLY_ADDED[64] = { "Новый тип билета успешно добавлен!" };

const char KIND_OF_TRANSPORT[20] = { ". Вид транспорта: " };
const char ROUTE_NUMBER[20] = { "   Номер маршрута: " };
const char PRICE[20] = { "   Цена: " };
const char ALL_KINDS_OF_TICKETS[64] = { "--------Все типы билетов--------" };

const char EDITING_KIND_OF_TICKET[64] = { "--------Изменение типа билета--------" };
const char WHAT_TYPE_OF_TICKET_YOU_WANT_TO_CHANGE[64] = { "Какой тип билетов вы хотите изменить: " };
const char TICKET_KIND_WAS_SUCCESSFULLY_CHANGED[64] = { "Тип билета был успешно изменён!" };

const char DELETING_KIND_OF_TICKET[64] = { "--------Удаление типа билета--------" };
const char CANT_DELETE_LAST_TYPE[64] = { "Вы не можете удалить единственный тип\nЛучше отредактируйте его!" };
const char WHAT_TYPE_OF_TICKET_YOU_WANT_TO_DELETE[64] = { "Какой тип билета хотите удалить: " };
const char TICKET_TYPE_HAS_BEEN_SUCCESSFULLY_DELETED[64] = { "Тип билета был успешно удалён!" };

const char WRITING_DAILY_NOTE[64] = { "--------Внесение данных о продажах за день--------" };
const char CHOOSE_TYPE_OF_TICKET[64] = { "Выберите вид билета: " };
const char ENTER_DAY[64] = { "Введите день месяца: " };
const char ENTER_MONTH[64] = { "Введите текущий месяц: " };
const char ENTER_AMOUNT[64] = { "Введите колличество проданных билетов этого типа: " };
const char DAILY_DATA_HAS_BEEN_SUCCESSSFULLY_ADDED[64] = { "Данные были успешно внесены!" };

const char NO_WRITTEN_DATA[64] = { "Данные не внесены!" };
const char DATA_HAS_BEEN_CLEARED[64] = { "Данные очищены!" };
const char WRONG_MONTH[64] = { "Месяц введён некорректно\n\nПопробуйте ввести данные заново!" };
const char WRONG_DAY[64] = { "День введён некорректно\n\nПопробуйте ввести данные заново!" };
const char WRONG_AMOUNT[67] = { "Колличество введёно некорректно\n\nПопробуйте ввести данные заново!" };
const char WRONG_TICKET_TYPE[64] = { "Нет типа билета под таким номером\n\nПовторите ввод: " };
const char TOTAL_REVENUE_PER_GIVEN_MONTH[64] = { "Общая выручка за данный месяц: " };

const char DATE_SEARCH[64] = { "--------Поиск по дате--------" };
const char TRANSPORT_SEARCH[64] = { "--------Поиск по виду транспорта--------" };
const char ROUTE_SEARCH[64] = { "--------Поиск по номеру маршрута--------" };

const char SORT_BY_MONTH_HEAD[64] = { "--------Сортировка по месяцу--------" };

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

const char HEAD_OF_TABLE[64] = { "№  |  Транспорт | Маршрут | Цена | День | Месяц | Колличество |" };
const char LINE[66] = { "---------------------------------------------------------------" };
const char VLINE = '|';


const char RESULT[64] = { "Результат: " };