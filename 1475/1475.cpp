#include <iostream>
using namespace std;
int s[10];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string a;
    cin >> a;
    for (int i = 0; i < a.length(); i++)
        s[a[i] - '0']++;
    int j = 0;
    for (int i = 0; i < 10; i++)
    {
        if (i == 6 || i == 9)
            continue;
        if (j < s[i])
            j = s[i];
    }
    if (j > (s[6] + s[9] + 1) / 2)
    {
        cout << j;
    }
    else
    {
        cout << (s[6] + s[9] + 1) / 2 ;
    }   
}
