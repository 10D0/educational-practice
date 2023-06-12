/*
Задача 13.2.
Разработать функцию, которая преобразует исходную строку S1, удаляя из неё каждый k-ый символ.
*/
#include <iostream>
#include <string>
using namespace std;
int main()
{
	string S,S1;
	int sum = 0, k;
	getline(cin, S);
	cin >> k;
	for (int i = 0; i < S.length(); i++) 
		if ((i+1)%k != 0) 
			S1+= S[i];
	cout << S1<<"\n";
	cin.get(); cin.get();
}
