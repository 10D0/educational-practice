/*
Динамически выделить память под N*M элементов вещественного типа float.
Разработать алгоритм и программу обработки двумерного динамического
массива с использованием указателей. Вычислить сумму элементов каждого столбца массива.
Упорядочить столбцы массива по убыванию сумм элементов столбцов.
*/
#include <iostream>
#include <stdlib.h>
#include <clocale>
#include <windows.h>
#include <ctime>
using namespace std;

void main()
{
	setlocale(LC_ALL, "Russian");
	float **a;
	int N = 1, M = 1, j1 = 1, c;
	cout << "Введите N,M: "; cin >> N >> M;
	/*Выделение папати*/
	float *Sum = new float[M] {0};//массив сумм (Изначально весь по нулям)

	a = new float*[N];
	for (int i = 0; i < N; i++)
		a[i] = new float[M];
	/*конец выделения мамати*/
	cout << "\nмассив двумерный изначальный: " << endl;
	srand(time(NULL));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			a[i][j] = round(rand() / static_cast<float>(RAND_MAX) * 10) / 10;
			//a[i][j] = round(((float)(rand() % 10 + 0) / (float)(rand() % 10 + 0)) * 10) / 10;
			cout << "a[" << i << ", " << j << "] = " << a[i][j] << "	"; 
			Sum[j] += a[i][j];
		}
		cout << "\n";
	}
	for (int i = 0, j = 0; i < M; i++) 
		cout << Sum[i] << "               ";
	/*перемена столбцов*/
	do {
			c = 0;
		for (int i = 0; i < M - 1; i++) 
			if (Sum[i] < Sum[i + 1]) {
				for (int j = 0; j < N; j++) 
					swap(a[j][i], a[j][i + 1]);
				swap(Sum[i], Sum[i + 1]);
				c++;
			}
	} while (c != 0);
	
	cin.get(); cin.get();
	cout << "\nконечный двумерный массив : " << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) 
			cout << "a[" << i << ", " << j << "] = " << a[i][j] << "	";
		cout << "\n";
	}
	for (int i = 0, j = 0; i < M; i++) 
		cout << Sum[i] << "               ";
	cin.get(); cin.get();
	/*очищение мамати*/
	for (int i = 0; i < N; i++)
		delete[] a[i];
	delete[] a;
	delete[] Sum;
}
