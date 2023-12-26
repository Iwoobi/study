#include <iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N,M;
    int a = 0;
    int b = 0;
    char tmp;
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> tmp;
            if ( (i%2 + j%2) == 1 )
            {
                if (tmp == 'W')
                    a++;
                else
                    b++;
            }
            else
            {
                if (tmp == 'B')
                    a++;
                else
                    b++;
            }
            
        }
    }

    // if (a > b)
        cout << b << " ";
    // else
        cout << a;
}