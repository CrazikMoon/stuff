#include <set>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include<cstdlib>
using namespace std;

int count = 0;
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


void print(people x){//вывод в файл
out << setw(10) << left << x.Surname << " ";//по левому краю, 10 позиций дл€ фамилии
out << setw(10) << left << x.Job;//по левому краю, 10 позиций дл€ фамилии
if (x.DateOfBirth.dd < 10) out << left << '0' << x.DateOfBirth.dd << '.';//добавл€ем 0
else out << left << x.DateOfBirth.dd << '.';
if (x.DateOfBirth.mm < 10) out << '0' << x.DateOfBirth.mm << '.';
else out << x.DateOfBirth.mm << '.';
out << left << setw(6) << x.DateOfBirth.yy;//на год 6 позиций
out << x.JobTime ;//запрлата
out << " " << x.Salary << endl;//запрлата
}

void merge(vector<people> &a, int l, int r, int m) {
    int i = l, j = m + 1;
    vector<people> buf;
    buf.resize(r - l + 1);
    int cur = 0;
    while ((i <= m) && (j <= r)) {
        if ((a[i].Salary < a[j].Salary)||((a[i].Salary == a[j].Salary) && (a[i].DateOfBirth.yy < a[j].DateOfBirth.yy))) {
            buf[cur++] = a[i++];
        }
        else buf[cur++] = a[j++];
    }

    while (i <= m) {
        buf[cur++] = a[i++];
    }
    while (j <= r) {
        buf[cur++] = a[j++];
    }
    for (int x = 0; x < buf.size(); ++x) {
        a[l + x] = buf[x];

	}
}

void merge_sort(vector<people>& a, int l, int r) {
    if (l < r) {
    int m = (l + r) / 2;
    merge_sort(a, l, m);
    merge_sort(a, m + 1, r);
    merge(a, l, r, m);
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    vector<people> x;
    x = inFile();
    merge_sort(x, 0, x.size() - 1);
    for (int i = 0; i < x.size(); ++i) {
        print(x[i]);
    }
    return 0;
}
