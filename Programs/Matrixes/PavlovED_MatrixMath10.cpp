#include<iostream>
using namespace std;

int main(){
setlocale(LC_ALL,"Rus");
int n,m;
cin>>n>>m;
float *a = new float [n + 1];   //массивы под многочлены P(x),Q(x) и P(x)*Q(x);
float *b = new float [m + 1];
float *c = new float [m + n + 1];
for (int i=0;i<=n;i++)
    cin>>a[i];
for (int i=0;i<=m;i++)
    cin>>b[i];
for (int k = 0; k < m + n + 1; k++){
    float S = 0;
    for (int i = 0; i < n + 1; i++)
        for (int j = 0; j < m + 1; j++)
            if (i + j == k) S += a[i]*b[j];
    c[k] = S;                   //вычисление значений многочлена P(x)*Q(x)
}
int j=m+n;
for (int i=0;i<=(m+n);i++,j--){
    if (c[i]*j!=0)
        cout<<c[i]*j<<" "; //вывод производной P(x)*Q(x)
}
return 0;
}
