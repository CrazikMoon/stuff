#include<iostream>
#include<limits.h>
using namespace std;
template <typename X>
    X **create(X c, int n, int m){//создание
    X **a = new X *[n]; //выделение памяти
    for (int i = 0; i < n; i++)
        a[i] = new X [m];
    for (int i = 0; i < n; i++) //ввод массива
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    return a;
}
template <typename X>
    void print(X **a, int n, int m){ //печать
    for (int i = 0; i < n; i++,cout << endl)
        for (int j = 0; j < m; j++)
            cout << a[i][j] << " ";
}
template<typename X>
    X ** change(X **a, int n, int m){//замена
        int k=0;
        int *x= new int [m];
        cout<<"Enter the X line:/n";
        for (int j=0;j<m;j++)
            cin>>x[j];
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                if (a[i][j]%2!=0)
                    k+=1;
            }
            if (k==n){
                for (int s=0;s<m;s++){
                    a[i][s]=x[s];
                }
            }
        }
    }
int main(){
    setlocale (LC_ALL, "rus");
    int n,m;
    cout << "Input dimension\n";
    cin >> n >> m;
    char c;
    do{
        cout << "Введите тип:\n1 - int\n2 - double\n3 - float\n";
        int k;
        cin >> k;
        switch(k){//вызываем различные типы
        case 1:
        {
            int c = 1;
            int **a = create(c,n,m);
            cout << "INT:\n";
            print (a,n,m);
            a = change(a,n,m);
            cout << "New:\n";
            print (a, n, m);
            break;
        }
        case 2:
        {
            double c1 = 1;
            double **a1 = create(c1, n, m);
            cout << "DOUBLE:\n";
            print (a1, n, m);
            a1 = change(a1, n, m);
            cout << "New:\n";
            print (a1, n, m);
            break;
        }
        case 3:
        {
            float c3 = 1;
            float **a3 = create(c3, n, m);
            cout << "FLOAT:\n";
            print (a3, n, m);
            a3 = change(a3, n, m);
            cout << "New:\n";
            print (a3, n, m);
            break;
        }
        default: cout << "Неправильно введены данные\n";
    }
 cout << "Еще раз? Y - да, N - нет\n";
 cin >> c; // повторяем запуск программы пока не введем N
 }
 while(c != 'N');
 return 0;
}
