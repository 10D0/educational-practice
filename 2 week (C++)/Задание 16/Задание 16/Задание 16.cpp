/*
Создать перечисляемый тип Month (названия месяцев). 
Создать структуру Date (дата), в составе которой присутствуют поля: день, месяц, год. 
Создать методы для ввода даты, вывода даты на экран, получение «счастливой цифры» по дате рождения человека. 
«Счастливая цифра» вычисляется путем сложения всех цифр даты до тех пор, пока не останется одна цифра. 
Использовать перегрузку операций: ввода, вывода, сравнения двух дат. В основной программе продемонстрировать работу с массивом дат.
*/
#include <iostream>
#include<clocale>
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
istream& operator >> (istream& in, Month& m)
{
	int myMonth;
	in >> myMonth;
	m = static_cast<Month>(myMonth);
	return in;
}
ostream& operator << (ostream& out, const Month& m)
{
	if (static_cast<int>(m) < 10)
		out << 0;
	out << static_cast<int>(m);
	return out;
}
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
void Num(Date A) {
	int number;
	number = (int)A.day + (int)A.month + (int)A.year;
	for (;number>=10;) 
		number = number / 10 + number % 10;
	cout <<"Счастливая цифра: "<< number<<" для даты: "<<A<<"\n";
}
int main()
{
	setlocale(LC_ALL, "Rus");
	cout<<"Введите 2 даты";
	Date FirstDate, SecondDate;
	cin >> FirstDate>>SecondDate;
	Num(FirstDate);
	Num(SecondDate);
	cout << "Сравнение дат:\n" << FirstDate << "и\n" << SecondDate << "\nРезультат: ";
	if (FirstDate == SecondDate)
		cout << "Даты одинаковые";
	else
		cout << "Даты разные";
	cout << "Сравнение дат:\n" << FirstDate << "и\n" << FirstDate << "\nРезультат: ";
	if (FirstDate == FirstDate)
		cout << "Даты одинаковые";
	else
		cout << "Даты разные";
	cin.get(); cin.get();
}
