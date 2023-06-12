/*
Задача 13.1.
Разработать функцию, которая возвращает сумму кодов символов строки S.
*/
#include <iostream>
#include <string>
using namespace std;
int main()
{
	string S;
	int sum = 0;
	getline(cin, S);
	for (int i = 0; i < S.length(); i++) {
		cout <<S[i]<<" - "<<int(S[i])<<"\n";
		sum += int(S[i]);
	}
	cout << "sum = " << sum;
	cin.get(); 
}
