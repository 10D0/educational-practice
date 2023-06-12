/*
Задача 14.1.
Составить программу, которая находит периметр многоугольника, 
заданного при помощи координат вершин. Координаты вершин многоугольника 
должны задаваться последовательно по периметру, и храниться 
в тестовом файле, каждая точка с новой строки.
*/
#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

int main()
{
	ofstream Vivod;
	int Lenght;
	float P=0, mod,mod2;
	cin >> Lenght;
	/*выделение памяти*/
	int** XY = new int*[Lenght];
	for (int i = 0; i < Lenght; i++) {
		XY[i] = new int[2];
	}
	/*Ввод координат*/
	for (int i = 0; i < Lenght; i++) {
		cin >> XY[i][0] >> XY[i][1];
	}
	/*подсчеты*/
	for (int i = 0; i < Lenght-1; i++) {
		mod = abs(XY[i][0] - XY[i + 1][0])*abs(XY[i][0] - XY[i + 1][0]);
		mod2 = abs(XY[i][1] - XY[i + 1][1])*abs(XY[i][1] - XY[i + 1][1]);
		P += sqrt(mod+mod2);
		//cout<<"lenght of line = "<<sqrt(mod + mod2)<< "	a2 = "<<mod <<" x1 = "<< XY[i][0]<<" x2 = "<< XY[i + 1][0]<<"	"<< XY[i][0] - XY[i + 1][0] << "	b2 = " << mod2 << " y1 = " << XY[i][1] << " y2 = " << XY[i + 1][1] <<endl;
	}
	mod = abs(XY[Lenght - 1][0] - XY[0][0])*abs(XY[Lenght - 1][1] - XY[0][0]); // соединение
	mod2 = abs(XY[Lenght - 1][1] - XY[0][1])*abs(XY[Lenght - 1][1] - XY[0][1]);//			последней точки
	P += sqrt((mod + mod2));												   //							и первой
	cout <<"Perimetr = "<<P(3)<<"\n";
	Vivod.open("DOTAS.txt");//начало записи      
	if (Vivod.is_open())
		for (int i = 0; i < Lenght; i++)
			Vivod<<"X"<<i+1<<": "<<XY[i][0]<<"	Y"<<i+1<< ": "<<XY[i][1]<<"\n";
	Vivod.close();			//конец записи
	cin.get(); cin.get();
	/*очистка памяти*/
	for (int i = 0; i < Lenght; i++) {
		delete[] XY[i];
	}
	delete[] XY;
}