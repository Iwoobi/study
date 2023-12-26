#include <iostream>
#include <algorithm>

int func(int *a, int *b)
{
    if (a[0] < b[0])
        return 1;
    if (a[0] == b[0])
    {
        if (a[1] < b[1])
            return 1;
    }
    return (0);
}
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    int **a = new int*[N];
    for (int i =0; i < N; i++)
    {
        a[i] = new int[2];
        cin >> a[i][0] >> a[i][1];
    }
    
    sort(a, a + N, func);
    for (int i = 0; i < N; i++)
        cout << a[i][0] << " " << a[i][1] << "\n";
}