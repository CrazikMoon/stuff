#include<iostream>
#include<cmath>
using namespace std;

int main() {
    setlocale(LC_ALL,"RUS");
    int a1, b1, c1, a2, b2, c2;
    cout << "Введите координаты прямых..." << endl;
    cout << "A1:";
    cin >> a1;
    cout << "B1:";
    cin >> b1;
    cout << "C1:";
    cin >> c1;
    cout << "A2:";
    cin >> a2;
    cout << "B2:";
    cin >> b2;
    cout << "C2:";
    cin >> c2;
    if (((a1 == 0) and (b1 == 0)) and ((a2 == 0) and (b2 == 0)))
        cout << "НЕ ПРЯМЫЕ";
    else
    {
        if ((a1 == 0) and (b1 == 0))
            cout << "ПЕРВОЕ УРАВНЕНИЕ - НЕ ПРЯМАЯ";
        else
        {
            if ((a2 == 0) and (b2 == 0))
                cout << "ВТОРОЕ УРАВНЕНИЕ - НЕ ПРЯМАЯ";
            else
            {
                if (((a1 * b2)==(b1 * a2)) and ((b1 * c2)==(c1 * b2)) and ((a1 * c2)==(c1 * a2)))
                    cout << "ПРЯМЫЕ СОВПАДАЮТ";
                else
                {
                    if ((a1 * b2) == (a2 * b1))
                        cout << "ПРЯМЫЕ ПАРАЛЛЕЛЬНЫ";
                    else
                    {
                        cout << "ПРЯМЫЕ ПЕРЕСЕКАЮТСЯ" << endl;
                        cout << "КООРДИНАТЫ ТОЧКИ ПЕРЕСЕЧЕНИЯ: " << -double(((c1 * b2 - b1 * c2) / (a1 * b2 - b1 * a2))) << " ; " << -double(((a1 * c2 - a2 * c1) / (a1 * b2 - b1 * a2)));

                    }
                }
            }
        }
    }
}
