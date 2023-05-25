#include <iostream>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    cout << "0.";
    int r=1;
    for(int i = 0; i < k; ++i)
    {
        r *= 10;
        cout << r / n;
        r %= n;
    }

    return 0;
}
