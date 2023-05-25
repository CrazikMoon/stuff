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
    string Surname; //фамилия
    string Job;
    date DateOfBirth; //дата рождения
    int JobTime;
    int Salary; //зарплата
};

date Str_to_Date(string str){//из строки в дату
date x;
string temp = str.substr(0, 2);//день
x.dd = atoi(temp.c_str() );
temp = str.substr(3, 2);//месяц
x.mm = atoi(temp.c_str());
temp = str.substr(6, 4);//год
x.yy = atoi(temp.c_str() );
return x;
}

vector<people> inFile(){//ввод из файла
    vector<people> x;
    people temp;
    while(in.peek() != EOF){
    in >> temp.Surname;//фамилия
    in >> temp.Job;
    string tmp;//дата рождения
    in >> tmp;
    temp.DateOfBirth = Str_to_Date(tmp);
    in >> temp.JobTime;
    in >> temp.Salary;//зарплата
    x.push_back(temp);
    }
    return x;
}


void print(people x){//вывод в файл
cout << setw(10) << left << x.Surname;//по левому краю, 10 позиций для фамилии
cout << setw(10) << left << x.Job;//по левому краю, 10 позиций для фамилии
if (x.DateOfBirth.dd < 10) out << left << '0' << x.DateOfBirth.dd << '.';//добавляем 0
else out << left << x.DateOfBirth.dd << '.';
if (x.DateOfBirth.mm < 10) out << '0' << x.DateOfBirth.mm << '.';
else out << x.DateOfBirth.mm << '.';
cout << left << setw(6) << x.DateOfBirth.yy;//на год 6 позиций
cout << left << setw(10) << x.JobTime << endl;//запрлата
cout << left << setw(10) << x.Salary << endl;//запрлата
}

void radixSortAlgo(vector<people>& x, int sizex){
    int maximumNumber = x[0].Salary; // находим максимальное значение в массиве
    for(int i=1;i<sizex;i++){
        maximumNumber = max(maximumNumber, x[i].Salary);
    }
    int digitsCount = 0;
    while(maximumNumber > 0){ // находим количество цифр в максимальном значении в массиве
        digitsCount++;
        maximumNumber /= 10;
    }
    vector<vector<people>> a(10);
    vector<people> new_x;
    for (int i=0;i<sizex;i++)
        new_x[i]=x[i];
        for(int i=0;i<digitsCount;i++){  // Создание нового массива
        for(int j=0;j<sizex;j++){
            int s = (new_x[j].Salary/int(pow(10,i))%10);
            a[s].push_back(new_x[j]);
        }
        new_x.clear();
        for (int k=0;k<10;k++){
            for(int m=0;m<sizex;m++){
                if ((a[k][m].Salary>0) and (a[k][m].Salary<=300000))
                new_x.push_back(a[k][m]);
            }
        }
        a.clear();
    }
    for (int l=0;l<sizex;l++)
        print(new_x[l]);
}
int main(){
    vector<people> x;
    x = inFile();
    int sizex = sizeof(x);
    radixSortAlgo(x,sizex);//вызываем алгоритм
    return 0;
}
