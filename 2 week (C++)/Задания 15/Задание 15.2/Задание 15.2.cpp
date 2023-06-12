/*
Разработать программу для вычисления интеграла с заданной точностью 
методом правых прямоугольников, оформив вычисление подинтегрального 
выражения и вычисление интеграла в виде отдельных функций.
*/

#include <iostream>
#include <clocale>
using namespace std;

double Function(double x) {
	return round(((sin(x) * tan(x)) / sqrt(x + 1)) * 10000) / 10000;
}
void RectMethod(double A, double B, int N){
	double w=(B-A)/10, x=A, S = 0, f = 0;
	for (int i = 1; i <= N; i++)
	{
		x = A+i*w;
		f += w*Function(x);
		cout <<"Прямоугольник №"<<i<<"	 h = "<<Function(x) << "	 S = " << w*Function(x) << endl;
	}
	cout << "\nRect Integral = " << f << endl;
}
int main()
{
	setlocale(LC_ALL, "Russian");
	int n;
	cout << "Введите точность для вычисления интеграла: ";
	cin >> n; cout << endl;
	RectMethod(0, 1, n);
	cin.get(); cin.get();
}
