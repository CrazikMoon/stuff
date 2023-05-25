#include<iostream>
using namespace std;

int main(){
const int N = 4;                // число блоков
for (int i = 1; i <= N; i++){   // блоки
for (int j = i; j >= 1; j=j-1)  // нечетные строки
cout << j << " ";
cout << endl;
for (int j = i; j >= 1; j=j-1)   // четные строки
cout << 2*j << " ";
cout << endl;
}
return 0;
}
