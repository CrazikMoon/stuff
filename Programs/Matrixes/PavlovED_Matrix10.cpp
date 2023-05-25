#include<iostream>// библиотека потока ввода-вывода
#include<stdlib.h>//cодержит в себе функции, занимающиес€ выделением пам€ти,
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
	cout << "¬ведите элементы строки X:" << endl;
	for (int i = 0; i < n; i++) {
		cin >> x[i];
	}
	int k=0;
	for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if(a[i][j]%2!=0)
                k++;
                cout<<i<<" "<<j<<" "<<k<<endl;
        }
        if (k==5){
            for (int m = 0; m < n; m++){
                a[i][m]=x[i];
            }
        }
        k=0;
    }
}
int main(){
    setlocale(LC_ALL, "Rus");
    int n;
    cout << "¬ведите размер квадратного массива n:";
    cin >> n;
    int** a = new int* [n]; //выделение пам€ти под массив указателей
    for (int i = 0; i < n; i++)
        a[i] = new int[n];  //выделение пам€ти дл€ каждого указател€
    cout<<"¬ведите элементы главного массива:"<<endl;
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
