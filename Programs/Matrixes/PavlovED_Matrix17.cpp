#include<iostream>// библиотека потока ввода-вывода
#include<limits.h>// прдельные значения INT_MIN и INT_MAX
#include<stdlib.h>//cодержит в себе функции, занимающиеся выделением памяти,
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
    cout << "Введите размер квадратного массива n:";
    cin >> n;
    int** a = new int* [n]; //выделение памяти под массив указателей
    for (int i = 0; i < n; i++)
        a[i] = new int[n];  //выделение памяти для каждого указателя
    cout<<endl;
    task(a,n);
    cout<<endl;
    output(a,n);


}
