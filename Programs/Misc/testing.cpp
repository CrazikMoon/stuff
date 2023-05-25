#include <iostream>
#include <math.h>

using namespace std;

int main() {
    setlocale(LC_ALL, "RUS");
    int N, i = 1, t = 0, n;
    cout << "N = ";
    cin >> N;
    while (i <= N) {
        n = t + i + (i - 1);
        t = n;
        cout << "i = " << i << "    N^2 = " << n << endl;
        i++;
    }
    system("pause");
    return 0;
}
