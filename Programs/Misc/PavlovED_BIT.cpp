#include<iostream>
#include<cmath>
using namespace std;

int main() {
	setlocale(LC_ALL, "RUS");
	int i, n;
	int f = 1;
	cout << "������� ����� n:";
	cin >> n;
	cout << "������� ����� i:";
	cin >> i;
	for (int j = 0; j < i; j++)
		f = f << 1;
	cout << "����� � ������� ������: " << f << endl;
	cout << "����� � ������� ������: " << (f | n) << endl;
	cout << "����� � �������� ������: " << n^(f ^ n) << endl;
	cout << "����� � ��������� ������: " << (n ^ f) << endl;
	if ((n ^ 1)==(n-1)){
        cout << "����� � ������ ������: ����� n �������";
	}
    else{
        cout << "����� � ������ ������: ����� n �����";
    }
	return 0;
}
