#include<iostream>
#include<string>
using namespace std;
struct hotel{
    string fio;
    int start_day;
    int start_month;
    int start_year;
    int end_day;
    int end_month;
    int end_year;
};
hotel STR_hotel(string str){//ïåğåâîä èç ñòğîêè â äàòó
    hotel hotel;
    //—–day———————-
    string str1 = str.substr (0, 2);
    const char *sd = str1.c_str();
    int dd = atoi(sd);
    hotel.start_day = dd;
    //———month—————-
    str1 = str.substr (3, 2);
    sd = str1.c_str();
    dd = atoi(sd);
    hotel.start_month = dd;
    //———year—————–
    str1 = str.substr (6, 4);
    sd = str1.c_str();
    dd = atoi(sd);
    hotel.start_year = dd;
    //—–day———————-
    str1 = str.substr (11, 2);
    sd = str1.c_str();
    dd = atoi(sd);
    hotel.end_day = dd;
    //———month—————-
    str1 = str.substr (14, 2);
    sd = str1.c_str();
    dd = atoi(sd);
    hotel.end_month = dd;
    //———year—————–
    str1 = str.substr (17, 4);
    sd = str1.c_str();
    dd = atoi(sd);
    hotel.end_year = dd;
    return hotel;
}
bool vis(int y){//âèñîêîñíûé ãîä
    return (y%4 == 0 && y%100 != 0) || y%400 == 0;
}
int eom(int m, int y){//êîíåö ìåñÿöà
    switch (m) {
    case 1: case 3: case 5:
    case 7: case 8: case 10: case 12: return 31;
    case 4: case 6: case 9: case 11: return 30;
    case 2: if(vis(y)) return 29;
    else return 28;
    }
}
int length(hotel x){//ñëåäóşùèé äåíü
    int l=0;
    if((x.end_year-x.start_year)==0){
        if((x.end_month-x.start_month)==0){
            l+=x.end_day-x.start_day;
            }

        else{
            l+=eom(x.start_month,x.end_year)-x.start_day+x.end_day;
            for (int i=x.start_month+1;i<x.end_month;i++){
            l+=eom(i,x.end_year);
            }
        }
    }
    else{
           l+=eom(x.start_month,x.end_year)-x.start_day+x.end_day;
            for(int i=x.start_month+1;i<=12;i++)
                l+=eom(i,x.start_year);
            for (int i=1;i<x.end_month;i++)
                l+=eom(i,x.end_year);
            for (int i=x.start_year+1;i<x.end_year;i++){
                l+=(365+vis(i));
            }
        }
        return l;
}

int correct(string str){//ïğîâåğêà êîğğåêòíîñòè äàííûõ
    if (str.length()!=21) cout<<"INPUT ERROR"<<endl;
    for(string::size_type i = 0; i < str.length() ; i++)
    if (i != 2 && i != 5 && i!= 10 && i!=13 && i!=16){
        if (!isdigit(str[i])) cout<<"INPUT ERROR"<<endl;
    }
    hotel x = STR_hotel(str);
    if ((x.end_year-x.start_year<0) or (x.end_year==0) or (x.start_year==0))
        cout<<"YEAR ERROR"<<endl;
    if (((x.end_month-x.start_month<0) and(x.end_year-x.start_year==0)) or (x.start_month<1) or (x.start_month>12) or (x.end_month<1) or (x.end_month>12))
        cout<<"MONTH ERROR"<<endl;
    if (((x.end_day-x.start_day<0) and (x.end_month-x.start_month==0))or(x.end_day>31)or(x.end_day<=0)or(x.start_day>31)or(x.start_day<=0))
        cout<<"DAY ERROR"<<endl;;
    return 0;
}
int main(){
    int n;
    cin>>n;
    for (int i=0;i<n;i++){
    string fio;
    cout<<"Input FIO:\n";
    getline(cin,fio);
    cin.ignore();
    string str;
    cout << "Input the start and end dates as dd.mm.yyyy-dd.mm.yyyy\n";
    cin.sync();
    getline(cin,str);
    correct(str);
    hotel hotel = STR_hotel(str);
    hotel.fio = fio;
    cout<<"The amount of days "<<fio<<" spent in the hotel is "<<length(hotel)<<endl;
    }
return 0;
}
