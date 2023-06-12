/*
Динамически выделить память под N элементов целого типа int.
Разработать алгоритм и программу обработки данных с использованием указателей:
переставить в обратном порядке все четные по значениям элементы массива и
выделить их при выводе зеленым цветом.
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
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	int *a, N, j1 = 1;
	cout << "Введите n: "; cin >> N;
	a = new int[N];
	cout << "\nмассив изначальный: " << endl;
	srand(time(NULL));
	for (int i = 0; i < N; i++) {
		*(a + i) = rand() % 10 + 0;	// (a+i) = a[i]
		if (*(a + i) % 2 == 0) {
			SetConsoleTextAttribute(hStdOut, 2);
			cout << "a[" << i << "] = " << *(a + i) << endl;
			SetConsoleTextAttribute(hStdOut, 7);
			continue;
		}
		cout << "a[" << i << "] = " << *(a + i) << endl;
	}
	cin.get(); cin.get();
	for (int i = 0; i <= N-j1; i++) {
		if (*(a + i) % 2 == 0) {
			for (int j = j1; j < N-i; j++) {
				if (*(a + (N-j)) % 2 == 0) {
					int abeb = *(a + i);
					*(a + i) = *(a + (N-j));
					*(a + (N - j)) = abeb;
					j1 = j+1;
					break;
				}
			}
		}
	}
	cout << "\nмассив конечный: " << endl;
	for (int i = 0; i < N; i++) {
		if (*(a + i) % 2 == 0) {
			SetConsoleTextAttribute(hStdOut, 2);
			cout << "a[" << i << "] = " << *(a + i) << endl;
			SetConsoleTextAttribute(hStdOut, 7);
			continue;
		}
		cout << "a[" << i << "] = " << *(a + i) << endl;
	}
	cin.get(); cin.get();
	delete[] a;
}

//cout<<"*(a + i) = "<<*(a + i)<< "			*(a + (N - j)) = "<< *(a + (N - j))<< "		i = "<< i<<"		 j = "<<N-j <<endl;