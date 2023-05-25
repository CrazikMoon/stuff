#include<iostream>

using namespace std;

#include <iostream>

int sum(int a, int b)     //ÔÓÍÊÖÈß C++ ÊÀÊ ÏÎÄÏÐÎÃÐÀÌÌÀ
{                         //
    int result = a + b;   //
    return result;        //ÔÓÍÊÖÈß C++ ÊÀÊ ÏÎÄÏÐÎÃÐÀÌÌÀ
}

int main()
{
    int a,b;
    cin>>a>>b;
    int result = sum(a, b);
    cout<<result;
}
