/*
Разработать алгоритм и программу для заполнения двоичного файла числами арифметической прогрессии 
с первым элементом, равным x и разностью r, число компонент по желанию пользователя. 
Программа должна также выводить два ближайших члена арифметической прогрессии, между которыми 
находится заданное число, и вставлять это число в файл на найденное место (при этом часть элементов файла 
сдвигается вперёд). Массив не использовать.
*/
#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Rus");
	int x, r, detx, ultraX, n = 10;//n - количество чисел
	cin >> x >> r;
	detx = r - x;
	fstream file("first.txt", ios::binary | ios::out | ios::in);
	cout <<"\nАрифметическая последовательность\n";
	file.write((char*)&x, sizeof(int));
	for (int i = 1; i < n; i++) {
		x += detx;
		file.write((char*)&x, sizeof(int));
	}
	file.seekp(0, file.beg);// переход к началу файла
	for (int i = 0; i < n; i++)
	{
		file.read((char*)&x, sizeof(int));
		cout<<x<<" ";
	}
	cout << "\nДобавляемое число: ";	cin >> ultraX;	cout << "\n";//Ввод добавляемого числа
	cout << "запись файла\n";
	fstream file2("second.txt", ios::binary | ios::out | ios::in);//Запись во 2ой файл
	file.seekp(0, file.beg);//чтение 1го файла с самого начала
	r= -0x3F3F3F3F;// если число будет меньше первого числа
	for (int i = 0; i <= n; i++)//1ый элемент уже считан начинается со 2го
	{
		file.read((char*)&x, sizeof(int));
		if (i == n)
			x = 0x3F3F3F3F;
		if (ultraX > r && ultraX < x) {
			file2.write((char*)&ultraX, sizeof(int));
			cout << ultraX << " ";
		}
		r = x;
		if (i < n) {
			file2.write((char*)&x, sizeof(int));
			cout << x << " ";
		}
	}
	cout << "\n\nЧтение файла\n"; 
	file2.seekp(0, file.beg);// переход к началу файла
	for (int i = 0; i < n+1; i++)
	{
		file2.read((char*)&x, sizeof(int));
		cout << x << " ";
	}
	cout << endl;
	file.close(); //закрытие потока
	file2.close();
	cin.get(); cin.get();
}
