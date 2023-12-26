#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int ans;
    sort(arr, arr + n);
    cin >> ans;
    int sum = 0;
    int l = 0;
    int r = n - 1;
    while (l < r)
    {
        if (arr[l] + arr[r] == ans)
        {
            sum++;
            l++;
        }
        else if (arr[l] + arr[r] < ans)
        {
            l++;
        }
        else if (arr[l] + arr[r] > ans)
            r--;
    }
    cout << sum;
}