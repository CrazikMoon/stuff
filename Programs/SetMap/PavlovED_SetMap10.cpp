#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>
using namespace std;
int main() {
	int pos=0;
	int pos1 = 0;
	int k = 0;
	int k1=0;
	char x;
	cout << "Put the text" << endl;
	string str,signs,pred,word;
	set <string> other,quex;
	vector <string> answer;
	getline(cin, str);//инициализируем нужные переменные и спрашиваем текст
	signs = ".?!";//строка со знаками препинания
	k = str.find_first_of(signs,pos);//находим первый знак препинания
	do
        {k = str.find_first_of(signs, pos);//теперь в цикле находим все последующие знаки
		pred = str.substr(pos, k - pos);//в pred заносим всё между двумя знаками, то есть предложение
		pos1 = 0;
		k1 = pred.find_first_of(' ', pos1);//находим в предложении первый пробел
		pred.push_back(' ');
		do {k1 = pred.find_first_of(' ', pos1);
			word = pred.substr(pos1, k1 - pos1);//заносим в word всё слово между двумя пробелами
			for (int i = 0; i < word.size(); i++) {
				x = tolower(word[i]);//делаем все регистры в слове нижними
				word[i] = x;
			}
			if ((str[k] == '?')or(str[k]=='!')) quex.insert(word);
			else other.insert(word);//если знак препинания в предложении вопрос или воск.знак то заносим слово в quex иначе в other
			pos1 = k1+1;//ставим ограничение на поиск первого вхождения пробела, чтобы найти следующий пробел

		} while (k1 != (pred.size() - 1));//идём до конца
		pos = k+1;//такое же ограничение и для знаков
	} while (k != (str.size() - 1));//выходим из цикла после нахождения последнего знака
	cout <<"Answer is" << endl;
	set_difference(quex.begin(), quex.end(), other.begin(), other.end(), inserter(answer,answer.end()));//находим разницу между множествами повествовательных и прочих слов, записываем разницу в вектор answer
	for (int i = 0; i < answer.size();i++) cout << answer[i] << " ";//выводим ответ
}
