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
    int k=0;
    for(int j=n;j<0;j--){
        if (j%2!=0){
            for (int i=n;i<0;i--){
                a[i][j]=k;
                k++;
            }
        }
        else{
            for (int i=0;i<n;i++){
                a[i][j]=k;
                k++;
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
    cout<<endl;
    task(a,n);
    cout<<endl;
    output(a,n);


}
