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
    int min = INT_MAX;
    int max = INT_MIN;
    for (int i = 0; i < n; i++) { // ����� �������� �������� ��������
        for (int j = 0; j <= i; j++) {
            if (a[i][j] < min && a[i][j] % 2 == 0) {
                min = a[i][j];
            }
        }
    }
    for (int j = 0; j < n; j++) { // ����� ��������� �������� ��������
        for (int i = j + 1; i < n; i++) {
            if (a[j][i] > max && a[j][i] % 2 != 0) {
                max = a[j][i];
            }
        }
    }
    for (int i = 0; i < n; ++i) { // ������ ������������ �� ������������
        for (int j = 0; j < n; ++j) {
            if (a[i][j] == min) {
                a[i][j] = max;
            }
        }
    }
    for (int i = 0; i < n; ++i) { // ������ ������������� �� �����������
        for (int j = i + 1; j < n; ++j) {
            if (a[i][j] == max) {
                a[i][j] = min;
            }
        }
    }
    if (min == INT_MAX)
        cout << "��� ������� ��������"<<endl;
    if (max == INT_MIN)
        cout << "��� ��������� ��������"<<endl;
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
