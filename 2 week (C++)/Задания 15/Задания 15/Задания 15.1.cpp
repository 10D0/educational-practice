/*
Разработать спецификации и написать функцию для определения принадлежит 
ли точка с координатами x, y половинке круга радиуса R с центром в начале 
координат, и какой половинке (правой или левой относительно оси OY)
принадлежит точка. Организовать вызов функции для проверки.
*/
#include <iostream>
#include <clocale>
using namespace std;

void InsideOrOutside(float X, float Y, float R) {
	float rad = sqrt(X*X + Y*Y);
	if (rad > R)
		cout<< "Точка НЕ В  пределах окружности\n";
	else if(rad < R) cout<< "Точка В пределах окружности\n";
	else "Точка лежит на окружности\n";
}
void InWhichPart(float X, float Y, float R) {
	if (X > 0 && Y > 0)
		cout << "Точка находится СПРАВА от оси OY и НАД осью OX (I четверть)\n";
	else if (X < 0 && Y>0)
		cout << "Точка находится СЛЕВА от оси OY и НАД осью OX (II четверть)\n";
	else if (X < 0 && Y < 0)
		cout << "Точка находится СЛЕВА от оси OY и ПОД осью OX (III четверть)\n";
	else if (X > 0 && Y < 0)
		cout << "Точка находится СПРАВА от оси OY и ПОД осью OX (IV четверть)\n";
	else if(X==0 && Y>0)
		cout << "Точка находится НА оси OY и НАД осью OX\n";
	else if(X<0 && Y==0)
		cout << "Точка находится СЛЕВА от оси OY и НА оси OX\n";
	else if(X==0 && Y<0)
		cout << "Точка находится НА оси OY и ПОД осью OX\n";
	else if (X>0 && Y==0)
		cout << "Точка находится СПРАВА от оси OY и НА оси OX\n";
	else 
		cout << "Точка находится НА НАЧАЛЕ КООРДИНАТ\n";
}
int main()
{
	setlocale(LC_ALL, "Russian");
	float x, y, r;
	cout << "Введите X и Y для точки и R окружности\n";
	cin >> x >> y >> r;
	InsideOrOutside(x, y, r);
	InWhichPart(x, y, r);
	cin.get(); cin.get();
}
