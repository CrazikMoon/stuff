#include<iostream>
#include<cmath>
using namespace std;

int main() {
	setlocale(LC_ALL, "RUS");
	int i, n;
	int f = 1;
	cout << "Введите число n:";
	cin >> n;
	cout << "Введите число i:";
	cin >> i;
	for (int j = 0; j < i; j++)
		f = f << 1;
	cout << "Ответ к первому номеру: " << f << endl;
	cout << "Ответ к второму номеру: " << (f | n) << endl;
	cout << "Ответ к третьему номеру: " << n^(f ^ n) << endl;
	cout << "Ответ к четвёртому номеру: " << (n ^ f) << endl;
	if ((n ^ 1)==(n-1)){
        cout << "Ответ к пятому номеру: Число n нечётно";
	}
    else{
        cout << "Ответ к пятому номеру: Число n чётно";
    }
	return 0;
}
