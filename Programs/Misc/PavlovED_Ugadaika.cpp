#include <iostream>
using namespace std;

int main() {
	int n,x,mid,cnt = 0,opr = 1;
	cout << "Numbers' range from 0 to ";
	cin >> n;                               //верхняя грань
	cout << "Enter the intended number: ";
	cin >> x;                               //загаданное число
	int m = 0;                              //нижняя грань
	while (opr != 0) {
        mid=(n-m)/2;                        //середина диапазона чисел
		cout << "The number is " << m+mid << endl;
		cnt++;
		cin >> opr;
		if (opr == -1) {
			n = n - mid;                    //уменьшение верхней границы, т.к. загаданное число меньше середины
		}
		if (opr == 1) {
			m = m + mid;                    //увеличение нижней границы, т.к. загаданное число больше середины
		}
	}
	cout << "Number of guesses - " << cnt << endl;// вывод кол-ва запросов(угадываний)
	return 0;
}
