#include<iostream>
#include<algorithm>
#include<string>
#include<fstream>
#include<iomanip>
#include<vector>
#include<bits/stdc++.h>
#include<cmath>
using namespace std;
ifstream in("input.txt");
ofstream out("output.txt");

struct date{//дата
    int dd, mm, yy;
};

struct people{//данные о человеке
    string Surname; //фамили€
    string Job;
    date DateOfBirth; //дата рождени€
    int JobTime;
    int Salary; //зарплата
};

date Str_to_Date(string str){//из строки в дату
date x;
string temp = str.substr(0, 2);//день
x.dd = atoi(temp.c_str() );
temp = str.substr(3, 2);//мес€ц
x.mm = atoi(temp.c_str());
temp = str.substr(6, 4);//год
x.yy = atoi(temp.c_str() );
return x;
}

vector<people> inFile(){//ввод из файла
    vector<people> x;
    people temp;
    while(in.peek() != EOF){
    in >> temp.Surname;//фамили€
    in >> temp.Job;
    string tmp;//дата рождени€
    in >> tmp;
    temp.DateOfBirth = Str_to_Date(tmp);
    in >> temp.JobTime;
    in >> temp.Salary;//зарплата
    x.push_back(temp);
    }
    return x;
}

bool operator > (people a, people b) {//переопредел€ем оператор >
    if (a.Surname > b.Surname) return true;
    if (a.DateOfBirth.yy > b.DateOfBirth.yy && a.Surname == b.Surname) return true;
    if (a.Surname == b.Surname && a.DateOfBirth.yy == b.DateOfBirth.yy && a.Salary > b.Salary) return true;
    return false;
}

void print(people x){//вывод в файл
cout << setw(10) << left << x.Surname << " ";//по левому краю, 10 позиций дл€ фамилии
cout << setw(10) << left << x.Job;//по левому краю, 10 позиций дл€ фамилии
if (x.DateOfBirth.dd < 10) cout << left << '0' << x.DateOfBirth.dd << '.';//добавл€ем 0
else cout << left << x.DateOfBirth.dd << '.';
if (x.DateOfBirth.mm < 10) cout << '0' << x.DateOfBirth.mm << '.';
else cout << x.DateOfBirth.mm << '.';
cout << left << setw(6) << x.DateOfBirth.yy;//на год 6 позиций
cout << x.JobTime ;//запрлата
cout << " " << x.Salary << endl;//запрлата
}

void evenoddsort(vector<people> &x){
    int n = x.size();
    for (int i = 0; i < n - 1; ++i) {
        if (i%2==0){
            for(int j = 2;j < n - 1;j+=2){
                if (x[j-1]>x[j]) swap(x[j-1],x[j]);
            }
        }
        else{
            for(int j = 1;j < n - 1;j+=2)
                if (x[j-1]>x[j]) swap(x[j-1],x[j]);
        }
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    vector<people> x;
    x = inFile();
    evenoddsort(x);

    for (int i = 0; i < x.size(); ++i) {
        print(x[i]);
    }

    return 0;
}
