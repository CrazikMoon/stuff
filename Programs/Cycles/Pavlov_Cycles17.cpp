#include<iostream>
using namespace std;

int main(){
const int N = 4;                // ����� ������
for (int i = 1; i <= N; i++){   // �����
for (int j = i; j >= 1; j=j-1)  // �������� ������
cout << j << " ";
cout << endl;
for (int j = i; j >= 1; j=j-1)   // ������ ������
cout << 2*j << " ";
cout << endl;
}
return 0;
}
