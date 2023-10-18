#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    int *D = new int[N];
    D[0] = 1;
    D[1] = 2;
    int i = 0;
    while (i < N)
    {
        if (i > 1)
        {
            D[i] = D[i - 1] + D[i - 2];
            D[i] %= 10007;
        }
        i++;
    }
    cout << D[i - 1];
}