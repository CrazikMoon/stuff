#include<iostream>
using namespace std;

int main() {
    setlocale(LC_ALL,"RUS");
	double a1 = 0.1, a2 =-0.1; // ���� ����������� ��������
	double n;
	cin >> n; //���� �����
	double a;
	cout << a1 <<endl;
	cout << a2 <<endl;
	for (double i = 3; i <= n; i++) { // �������������
		a = (a1*a1*i/3) + ((i+1)/2 * a2 * a2); //��������� �� ������
		cout<< a << endl;
		a1 = a2;
		a2 = a;
	}
}
