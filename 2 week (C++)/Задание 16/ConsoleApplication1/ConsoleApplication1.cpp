/*
Создать перечисляемый тип Month (названия месяцев).
Создать структуру Date (дата), в составе которой присутствуют поля: день, месяц, год.
Создать методы для ввода даты, вывода даты на экран, получение «счастливой цифры» по дате рождения человека.
«Счастливая цифра» вычисляется путем сложения всех цифр даты до тех пор, пока не останется одна цифра.
Использовать перегрузку операций: ввода, вывода, сравнения двух дат. В основной программе продемонстрировать работу с массивом дат.
*/

#include <iostream>
using namespace std;
enum class Month
{
	January = 1,
	February,
	March,
	April,
	May,
	June,
	July,
	August,
	September,
	October,
	Novemver,
	December
};

struct Date
{
	int year;
	Month month;
	int day;
};
istream& operator >> (istream& in, Date& d)
{
	in >> d.day >> d.month >> d.year;
	return in;
}

ostream& operator << (ostream& out, const Date& d)
{
	if (d.day < 10)
		out << 0;
	out << d.day << "." << d.month << "." << d.year << endl;
	return out;
}

bool operator == (const Date &lhs, const Date &rhs)
{
	return lhs.day == rhs.day && lhs.month == rhs.month && lhs.year == rhs.year;
}
bool operator != (const Date &lhs, const Date &rhs)
{
	return lhs.day != rhs.day || lhs.month != rhs.month || lhs.year != rhs.year;
}


int main()
{
	Month a = Month::Novemver;
	Date ab;
	cin >> ab;
	cout << ab;
	cin.get(); cin.get();
}
