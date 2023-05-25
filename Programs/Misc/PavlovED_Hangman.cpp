#include <iostream>
#include <vector> //Инициализируем библиотеку vector
#include <string> //Инициализируем библиотеку string
#include <fstream> //Инициализируем библиотеку fstream
#include <set> //Инициализируем библиотеку set
#include <random> //Инициализируем библиотеку random
#include <ctime>
#include<algorithm>
using namespace std;

random_device rd;
mt19937 gen(rd());

int random(int low, int high) //Функция для генерации случайных чисел
{
	uniform_int_distribution<> dist(low, high);
	return dist(gen);
}

int main() {
    setlocale(LC_ALL, "RUS");
    srand(time(0)+17);
    string unguessed; //Создаём set со всеми буквами английского языка
	unguessed="a b c d e f g h i j k l m n o p q r s t u v w x y z";
	vector<string>words; //Создаём вектор, который будет содержать все слова английского языка
	ifstream file;
	file.open("words.txt");
	if (!file.is_open()) //Проверяем, получилось ли открыть файл ввода
		cout << "Не удалось открыть файл.";
	else {
		string s;
		while (!file.eof()) //Пока мы не дошли до конца файла
		{
			getline(file, s); //Считываем строку со словом
			words.push_back(s); //Добавляем слово в вектор words
		}
	}
	file.close(); //Закрываем файл ввода
	int random_pos = random(0, words.size()); //Берём случайную позицию вектора words
	string word = words[random_pos]; //Берём слово из случайной позиции в качестве угадываемого
	string shown(word.size(), '_'); //Создаём строку shown такого же размера, что и угадываемое слово, состоящую из _
	cout << "Слово: " << shown << endl;
	bool f = 0;
	int turn = 1, max;
	cout << "Введите максимальное кол-во ходов: ";
	cin >> max;
	while (shown.find("_") != string::npos && turn <= max) { //Пока не кончатся неугаданные буквы или пока не кончатся ходы, игра продолжается
		cout << endl;
		cout << "Ход: " << turn << endl;
		cout << "Осталось ходов: " << max - turn << endl;
		cout << "Неиспользованные буквы: "<<unguessed<<endl;
		cout << endl << "Слово: " << shown << endl;
		cout << "Вы хотите угадать слово целиком (Yes/No)?";
		string choose, wordguess;
		char guess;
		cin >> choose;
		if (choose == "Yes") { //Возможность угадать слово целиком
			cout << "Ваш ответ: ";
			cin >> wordguess;
			if (wordguess == word) { //Если угаданное слово верно, то игра заканчивается
				cout << "Поздравляю, вы победили! Правильный ответ: " << word << endl;
				f = 1;
				break;
			}
			else { //Иначе продолжаем игру и увеличиваем ход на 1
				cout << "Неверно." << endl;
				turn++;
				continue;
			}
		}
		else { //Если мы не хотим угадывать всё слово сразу
			cout << "В таком случае, введите предполагаемую букву: ";
			cin >> guess; //Запрашиваем букву
			int pos = unguessed.find(guess);
			unguessed.erase(pos,2);
			if (word.find(guess) != string::npos) { //Если такая буква есть в слове
				int start = 0;
				vector<int>pos;
				while (word.find(guess, start) != string::npos) { //Этот алгоритм находит все вхождения этой буквы в слово
					pos.push_back(word.find(guess, start));
					start = word.find(guess, start) + 1;
				}
				for (int i = 0; i < pos.size(); ++i)
					shown[pos[i]] = word[pos[i]]; //Заменяем в отображаемой строке все _ на буквы из слова
				cout << "Вы угадали верно." << endl;
				turn++;
				continue;
			}
			else { //Иначе просто переходим на другой ход
				cout << "Вы угадали неверно." << endl;
				turn++;
				continue;
			}
		}
	}
	if (f == 0)
		if (shown.find("_") == string::npos) //Если к концу игры слово угадано, выводим сообщение, что игрок победил
			cout << endl << "Поздравляю, вы победили! Правильный ответ: " << word;
		else //Иначе выводим сообщение о поражении
			cout << endl << "У вас не осталось ходов, вы проиграли. Правильный ответ: " << word;
	return 0;
}


