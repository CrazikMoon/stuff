#include<iostream>
#include<cmath>
using namespace std;
float F(int x){
    return sqrt(x - 5)/sqrt(x * x - 9) + log(x * x + 2 * x + 1);

}
int main() {
	setlocale(LC_ALL, "RUS");
	int n;
	cout<<"Введите число x: "<<endl;
    cin>>n;
	if (((n>3) and (n<5)) or (n<-3))
        cout<<"Корень из отрицательного числа";
    else
    {
        if ((n==3) or (n==-3))
            cout<<"Деление на ноль";
        else
        {
            if (n<=-1)
                cout<<"Логарифм из неположительного числа";
            else
                cout<<F(n)<<endl;
        }
    }

    return 0;
}
