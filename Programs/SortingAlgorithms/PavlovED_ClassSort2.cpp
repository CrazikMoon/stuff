#include <fstream>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include<cmath>

using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");

struct date {
    int dd, mm, yy;
};

struct people {
    string surname;
    string jobtitle;
    date dateofbirth;
    int workexperience;
    int Salary;
};
date str_to_date(string str) {
    date x;
    string temp = str.substr(0, 2);
    x.dd = atoi(temp.c_str());
    temp = str.substr(3, 2);
    x.mm = atoi(temp.c_str());
    temp = str.substr(6, 4);
    x.yy = atoi(temp.c_str());
    return x;
}

vector<people> inFile() {
    vector<people> x;
    people temp;
    while (in.peek() != EOF) {
        in >> temp.surname;
        in >> temp.jobtitle;
        string tmp, workexp1, workexp2;
        in >> tmp;
        temp.dateofbirth = str_to_date(tmp);
        in >> temp.workexperience;
        in >> temp.Salary;
        x.push_back(temp);

    }
    return x;
}
void print(people x) {
    out << x.surname << ' ';
    out << x.jobtitle << ' ';
    if (x.dateofbirth.dd < 10) out << right << '0' << x.dateofbirth.dd << '.';
    else out << right << x.dateofbirth.dd << '.';
    if (x.dateofbirth.mm < 10) out << right << '0' << x.dateofbirth.mm << '.';
    else out << right << x.dateofbirth.mm << '.';
    out << x.dateofbirth.yy << ' ';
    out << x.workexperience << ' ';
    out << x.Salary << ' '<<endl;
}

void radixSortAlgo(vector<people>& x, int sizex) {
    int maximumNumber = x[0].Salary;
    for (int i = 1; i < sizex; i++) {
        maximumNumber = max(maximumNumber, x[i].Salary);
    }
    int digitsCount = 0;
    while (maximumNumber > 0) {
        digitsCount++;
        maximumNumber /= 10;
    }
    for (int i = 0; i < digitsCount; i++) {
        vector<int> count(10, 0); // инициализируем вектор нулями
        vector<people> sortedArray(sizex);
        int exp = pow(10, i);
        for (int j = 0; j < sizex; j++) {
            int digit = (x[j].Salary / exp) % 10;
            count[digit]++;
        }
        for (int j = 1; j < 10; j++) {
            count[j] += count[j - 1];
        }
        for (int j = sizex - 1; j >= 0; j--) {
            int digit = (x[j].Salary / exp) % 10;
            sortedArray[count[digit] - 1] = x[j];
            count[digit]--;
        }
        for (int j = 0; j < sizex; j++) {
            x[j] = sortedArray[j];
        }
    }
}

int main() {
    vector<people> x;
    x = inFile();
    int sizex = x.size();
    radixSortAlgo(x, sizex);
    for (int i = 0; i < x.size(); ++i) {
        print(x[i]);
    }
    return 0;
}
