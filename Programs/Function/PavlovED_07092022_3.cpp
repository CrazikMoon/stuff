#include<iostream>                        // ���������� ��� ������ �����-������
#include<cmath>                           // ���������� �������������� �������
using namespace std;
const float e=2.71828182845904523536; 	  // ����������� ��������� e
float F(int x,int y){
	return 2*sin(sqrt((pow(x,2)-pow(y,2))/pow(e,x+y)+pow(x,2)*pow(y,2)))/3+(cos(x)+sin(y))/2; //� ������� �������� ��������� �� ������� �3
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
