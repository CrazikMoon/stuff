#include <iostream>
#include <cmath>
using namespace std;


void Cin(double** arr, int nows, int cols) {            //���� ������� ��� ����������
	cout << "������� ������� " << endl;
	for (int i = 0; i < nows; ++i) {
		for (int j = 0; j < cols; ++j) {
			cin >> arr[i][j];
		}
	}
	cout << endl;

}

void Cout(double** arr, int nows, int cols) {
	for (int i = 0; i < nows; ++i, cout << endl) {
		for (int j = 0; j < cols; ++j) {
			cout << arr[i][j] << " ";                   //����� ������� ����� ����������
		}
	}
	cout << endl;
}

void Delete(double** arr, int nows) {
	for (int i = 0; i < nows; ++i) {                    //�������� �������
		delete[] arr[i];
	}
	delete[] arr;
}
void skalproiz(double x1, double y1, double z1, double x2, double y2, double z2) {
	cout << "��������� ������������ ���� �������� :  " << x1 * x2 + y1 * y2 + z1 * z2 << endl;      //���������� ���������� ������������ ��������
}

void vekproiz(double x1, double y1, double z1, double x2, double y2, double z2) {
	cout << "��������� ������������ ���� �������� : (" << y1 * z2 - z1 * y2 << ") * i - (" << x1 * z2 - x2 * z1 << ") * j + (" << x1 * y2 - x2 * y1 << ") * k" << endl; //���������� ���������� ������������ ��������
}

void matrproiz(double** arr1, double** arr2, int nows1, int cols2, int nows2) { //������� ������������ ������
	double** arr = new double* [nows1];
	for (int i = 0; i < nows1; i++) {
		arr[i] = new double[cols2];
	}
	for (int i = 0; i < nows1; i++) {
		for (int j = 0; j < cols2; j++) {
			arr[i][j] = 0;
		}
	}
	for (int i = 0; i < nows1; i++) {
		for (int j = 0; j < cols2; j++) {
			for (int z = 0; z < nows2; z++) {
				arr[i][j] += arr1[i][z] * arr2[z][j];
			}
		}
	}
	Cout(arr, nows1, cols2);
}

void trans(double** arr1, int nows1, int cols1) { // ������� ���������������� ������
	for (int i = 0; i < nows1; ++i) {
		for (int j = i; j < cols1; ++j) {
			double t = arr1[i][j];
			arr1[i][j] = arr1[j][i];
			arr1[j][i] = t;
		}
	}
	Cout(arr1, nows1, cols1);
}

double det(double** arr1, int n) { // ������� ���������� ����������� �������
	if (n == 1) {
		return arr1[0][0];
	}
	else {
		if (n == 2) {
			return arr1[0][0] * arr1[1][1] - arr1[0][1] * arr1[1][0];
		}
		else {
			double d = 0;
			for (int k = 0; k < n; k++) {
				double** m = new double* [n - 1];
				for (int i = 0; i < n - 1; i++) {
					m[i] = new double[n - 1];
				}
				for (int i = 1; i < n; i++) {
					int t = 0;
					for (int j = 0; j < n; j++) {
						if (j == k)
							continue;
						m[i - 1][t] = arr1[i][j];
						t++;
					}
				}
				d += pow(-1, k + 2) * arr1[0][k] * det(m, n - 1);
				Delete(m, n - 1);
			}
			return d;
		}
	}
}

int main() {
	char a;
	setlocale(LC_ALL, "RUS");
	cout << "1. ��������� ������������ ���� �������� " << endl;
	cout << "2. ��������� ������������ ���� �������� " << endl;
	cout << "3. ������������ ���� ������" << endl;
	cout << "4. ���������������� �������" << endl;
	cout << "5. ���������� �������." << endl;
	cin >> a;                                                   //����� ������� ����������
	if ((a == '1') || (a == '2')) {
		double x1, y1, z1, x2, y2, z2;
		cout << "������� ���������� ������� ������� " << endl;
		cin >> x1 >> y1 >> z1;
		cout << "������� ���������� ������ ������� " << endl;
		cin >> x2 >> y2 >> z2;
		if (a == '1') {
			skalproiz(x1, y1, z1, x2, y2, z2);                  //���� ����������� ������� ��� ���������� � ����������� ������������
		}
		if (a == '2') {
			vekproiz(x1, y1, z1, x2, y2, z2);
		}
	}
	if ((a == '3') || (a == '4') || (a == '5')) {
		int nows1, cols1, nows2, cols2;
		cout << "������� ����������� ������ ������� " << endl;
		cin >> nows1 >> cols1;
		double** arr1 = new double* [nows1];
		for (int i = 0; i < nows1; i++) {
			arr1[i] = new double[cols1];
		}
		Cin(arr1, nows1, cols1);                                    //���� ������� ��� ����������
		if (a == '3') {
			cout << "������� ����������� ������ ������� " << endl;
			cin >> nows2 >> cols2;
			double** arr2 = new double* [nows2];
			for (int i = 0; i < nows2; i++) {
				arr2[i] = new double[cols2];
			}
			Cin(arr2, nows2, cols2);
			if (cols1 == nows2) {
				matrproiz(arr1, arr2, nows1, cols2,nows2);
			}
			else {
				cout << "����������" << endl;
			}
			Delete(arr2, nows2);
		}
		if (a == '4') {
			if (nows1 == cols1) {
				trans(arr1, nows1, cols1);;
			}
			else cout << "����������" << endl;
		}
		if (a == '5') {
			if (nows1 == cols1) {
				cout << "���������� ������� : " << det(arr1, nows1) << endl;;
			}
			else cout << "����������" << endl;
		}
		Delete(arr1, nows1);
	}
	return 0;
}
