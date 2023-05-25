#include<iostream>
using namespace std;

int main() {
    setlocale(LC_ALL,"RUS");
	double a1 = 0.1, a2 =-0.1; // ввод изначальных значений
	double n;
	cin >> n; //ввод числа
	double a;
	cout << a1 <<endl;
	cout << a2 <<endl;
	for (double i = 3; i <= n; i++) { // рекурентность
		a = (a1*a1*i/3) + ((i+1)/2 * a2 * a2); //уравнение из задачи
		cout<< a << endl;
		a1 = a2;
		a2 = a;
	}
}
