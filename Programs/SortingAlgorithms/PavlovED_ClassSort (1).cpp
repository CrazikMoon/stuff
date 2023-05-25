#include<iostream>
#include<algorithm>
#include<string>
#include<fstream>
#include<iomanip>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
ifstream in("input.txt");
ofstream out("output.txt");

struct date{//дата
    int dd, mm, yy;
};

struct people{//данные о человеке
    string Surname; //фамилия
    date DateOfBirth; //дата рождения
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
    string tmp;//дата рождения
    in >> tmp;
    temp.DateOfBirth = Str_to_Date(tmp);
    in >> temp.Salary;//зарплата
    x.push_back(temp);
    }
    return x;
}


bool operator < (people a, people b){//переопределяем оператор < в соотвествии с условием
if (a.Surname < b.Surname) return true;
if (a.Surname == b.Surname && a.DateOfBirth.yy < b.DateOfBirth.yy) return true;
if (a.Surname == b.Surname && a.DateOfBirth.yy == b.DateOfBirth.yy && a.Salary < b .Salary) return true;
return false;
}

void print(people x){//вывод в файл
out << setw(10) << left << x.Surname;//по левому краю, 10 позиций для фамилии
if (x.DateOfBirth.dd < 10) cout << left << '0' << x.DateOfBirth.dd << '.';//добавляем 0
else cout << left << x.DateOfBirth.dd << '.';
if (x.DateOfBirth.mm < 10) cout << '0' << x.DateOfBirth.mm << '.';
else cout << x.DateOfBirth.mm << '.';
out << left << setw(6) << x.DateOfBirth.yy;//на год 6 позиций
out << left << setw(10) << x.Salary << endl;//запрлата
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
    for(int i=0;i<digitsCount;i++){  // Создание нового массива
        int pwr = pow(10, i);
        int new_x[sizex];
        int count_array[10]; // Это массив count_array для сортировки подсчётом цифр от 0 до 9
        memset(count_array, 0, sizeof(count_array)); //заполнение нового массива частотами цифр
        for(int j=0;j<sizex;j++){
            int num = (x[j].Salary/pwr) % 10;
            count_array[num]++;
        }
        // This is a cumulative frequency
        for(int j=1;j<10;j++){
            count_array[j] += count_array[j-1];
        }
        // We are mapping the frequency array with each element
        // of the array to find out desired position in the updated array
        for(int j=sizex-1;j>=0;j--){
            int num = (x[j].Salary/pwr) % 10;
            new_x[count_array[num]-1] = x[j].Salary;
            count_array[num]--;
        }
        // Now, we are updating the array with the new array
        for(int j=0;j<sizex;j++)
            x[j].Salary = new_x[j];
    }
    // Finally,we print the sorted array result
    for(int j=0;j<sizex;j++)
        print(x[j]);
}
int main(){
    vector<people> x;
    x = inFile();
    int sizex = sizeof(x)/sizeof(sizex);
    cout<<sizex;
    radixSortAlgo(x,sizex);//вызываем алгоритм
    return 0;
}
