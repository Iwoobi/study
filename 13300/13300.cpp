#include <iostream>
using namespace std;
int arr[6][2];
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    int k;
    int mg;
    int lev;
    int sum = 0;
    cin >> n >> k;
    for (int i = 0 ; i < n; i++)
    {
        cin >> mg >> lev;
        arr[lev - 1][mg]++;    
    }
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            sum += (arr[i][j] + k - 1) / k;           
        }
    }
    cout << sum;
}