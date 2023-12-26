#include <iostream>
using namespace std;
int arr[202];
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int a;
    int b;
    cin >> a;
    for (int i = 0; i < a; i++)
    {
        cin >> b;
        arr[b + 100]++;
    }
    cin >> b;
    cout << arr[b + 100];
}