#include <iostream>
using namespace std;

int main() {
	int n,x,mid,cnt = 0,opr = 1;
	cout << "Numbers' range from 0 to ";
	cin >> n;                               //������� �����
	cout << "Enter the intended number: ";
	cin >> x;                               //���������� �����
	int m = 0;                              //������ �����
	while (opr != 0) {
        mid=(n-m)/2;                        //�������� ��������� �����
		cout << "The number is " << m+mid << endl;
		cnt++;
		cin >> opr;
		if (opr == -1) {
			n = n - mid;                    //���������� ������� �������, �.�. ���������� ����� ������ ��������
		}
		if (opr == 1) {
			m = m + mid;                    //���������� ������ �������, �.�. ���������� ����� ������ ��������
		}
	}
	cout << "Number of guesses - " << cnt << endl;// ����� ���-�� ��������(����������)
	return 0;
}
