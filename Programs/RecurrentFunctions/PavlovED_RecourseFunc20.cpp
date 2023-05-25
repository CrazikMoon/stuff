#include<iostream>
#include<cmath>
using namespace std;
void print (int n, char a){ //печать n символов a
    for (int i = 0; i < n; i++)
    cout << a;
}
void F(int p, int n,int m,int i){ // p - пробелов, n - символов
    if (n > 0){
        print(p,' '); //печать пробелов
        print(m,'*'); //печать звёзд
        cout << endl; //переход на следующую строку
        if (n!=0){
            if (m>=1){
                F(p+1,n,m-2,i); //вызов функции для следующей строки
                }
            else {
                i+=2;
                F(n-1,n-1,i,i);
            }
        }
    }
}
int main(){
    int n;
        cin >> n;
        F(n,n,3,3); //вызов функции
    return 0;
}
