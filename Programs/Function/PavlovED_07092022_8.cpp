#include<iostream>                    // ���������� ��� ������ �����-������
#include<cmath>                       // ���������� �������������� �������
using namespace std;
const float e=2.71828182845904523536; // ����������� ��������� e
float F(int x,int y){
return sqrt((sqrt(cos(x)+sin(y))+pow(e,x+y))/(sqrt(x+y+log(x)*log(x))));  //� ������� �������� ��������� �� ������� �8
}
int main (){
setlocale(LC_ALL,"");                 // ������������� ������� ����������
int x,y;
cout<<"������� ������ ����� x:";
cin>>x;                               // ���� ������ ����������
cout<<endl;
cout<<"������� ������ ����� y:";
cin>>y;                               // ���� ������ ����������
cout<<endl;
cout<<"�����:"<<F(x,y);               // ����� ���������� ���������� �������
return 0;
}
