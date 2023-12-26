#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    int res=0;
    int j;
    for (int i = 1; i <= N; i++)
    {
        j = i;
        while (1)
        {
            if (j % 5 != 0)
                break;
            res++;
            j = j / 5;
        }
    }
    cout << res;
}