#include<iostream>// ���������� ������ �����-������
#include<limits.h>// ��������� �������� INT_MIN � INT_MAX
#include<stdlib.h>//c������� � ���� �������, ������������ ���������� ������,
using namespace std;
void output(int** a, int n){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
}
void task(int** a,int n){
    int* x = new int[n];
	cout << "������� �������� ������� X:" << endl;
	for (int i = 0; i < n; i++) {
		cin >> x[i];
	}
	int min = INT_MAX;
	for (int i = 0; i < n; i++) { // ����� ��������
        for (int j = 0; j <= n; j++) {
            if (a[i][j] < min) {
                min = a[i][j];
            }
        }
	}
    for (int j = 0; j < n; j++) { // �������� �������
        for (int i = 0; i < n; i++){
                if (a[i][j]==min){
                    for (int m=0;m<n;m++){
                        a[m][j]=x[m];
                    }
                    break;
                }
            }
    }
}
int main(){
    setlocale(LC_ALL, "Rus");
    int n;
    cout << "������� ������ ����������� ������� n:";
    cin >> n;
    int** a = new int* [n]; //��������� ������ ��� ������ ����������
    for (int i = 0; i < n; i++)
        a[i] = new int[n];  //��������� ������ ��� ������� ���������
    cout<<"������� �������� �������� �������:"<<endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    cout<<endl;
    task(a,n);
    cout<<endl;
    output(a,n);


}
