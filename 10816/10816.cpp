#include <iostream>
#include <algorithm>
using namespace std;

int func(int a, int b)
{
    if (a < b)
        return 1;
    else    
        return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    int *arr = new int[N];
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    sort(arr, arr + N, func);
    int M;
    cin >> M;
    int num;
    for (int i = 0; i < M; i++)
    {
        cin >> num;
        int begin = 0;
        int end = N - 1;
        int mid;
        while (1)
        {
            if (num == arr[begin] || num == arr[end])
            {
                cout << "1\n";
                break;
            }
            if (num < arr[begin] || num > arr[end])
            {
                cout << "0\n";
                break;
            }
            mid = (end + begin) / 2;
            if (num > arr[mid])
                begin = mid + 1;
            else if (num < arr[mid])
                end = mid - 1;
            else
            {
                cout << "1\n";
                break;
            }
        }
    }
    
    
}