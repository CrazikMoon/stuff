#include<iostream>
#include<cmath>
using namespace std;
void print (int n, char a){ //������ n �������� a
    for (int i = 0; i < n; i++)
    cout << a;
}
void F(int p, int n,int m,int i){ // p - ��������, n - ��������
    if (n > 0){
        print(p,' '); //������ ��������
        print(m,'*'); //������ ����
        cout << endl; //������� �� ��������� ������
        if (n!=0){
            if (m>=1){
                F(p+1,n,m-2,i); //����� ������� ��� ��������� ������
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
        F(n,n,3,3); //����� �������
    return 0;
}
