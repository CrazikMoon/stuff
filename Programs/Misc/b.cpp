#include<iostream>

using namespace std;

#include <iostream>

int sum(int a, int b)     //������� C++ ��� ������������
{                         //
    int result = a + b;   //
    return result;        //������� C++ ��� ������������
}

int main()
{
    int a,b;
    cin>>a>>b;
    int result = sum(a, b);
    cout<<result;
}
