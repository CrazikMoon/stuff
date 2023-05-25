#include<iostream>
using namespace std;

int main() {
	setlocale(LC_ALL, "RUS");
	int a,y,x;
	cout << "Введите трёхзначное число a:" << endl;
	cin >> a;
    cout << "Введите цифру x:" << endl;
	cin >> x;
	cout << "Введите цифру y:" << endl;
	cin >> y;
	int n = 0;
	int r = 0;
	if (((a > 999) or (a < 100)) or ((y > 9) or (y < 0)) or ((x < 0) or (x > 4))) {
        cout<<"НЕКОРРЕКТНЫЙ ВВОД";
	}
    else{

	if (a / 100 % x == 0)
		n += 100;
	if ((a % 100 / 10) % x == 0)
		n += 10;
	if (a % 10 % x == 0)
		n += 1;
	switch (n){
			case 111:
				r = (a / 100 * y % 10) * 100 + (a % 100 / 10 * y % 10) * 10 + (a % 10 * y % 10);
					break;
			case 110:
				r = (a / 100 * 3 % 10) * 100 + (a % 100 / 10 * 3 % 10) * 10 + (a % 10 * 3 % 10);
					break;
			case 101:
				r = ((a / 100 + y) % 10) * 100 + ((a % 100 / 10 + y) % 10) * 10 + ((a % 10 + y) % 10);
					break;
			case 11:
				r = ((a / 100 - y) % 10) * 100 + ((a % 100 / 10 - y) % 10) * 10 + ((a % 10 - y) % 10);
					break;
			case 100:case 10:case 1:case 0: r = (a / 100 * 2 % 10) * 100 + (a % 100 / 10 * 2 % 10) * 10 + (a % 10 * 2 % 10);

		default:
			break;
		}
    cout<<"Получившийся результат: "<<r;
    }
}
