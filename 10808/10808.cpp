#include <iostream>
int a[26];
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s; 
    cin >> s;
    for (int i = 0; i < s.length(); i++)
    {
        a[s[i] - 'a']++;
    }
    for (int i = 0; i < 26; i++)
        cout << a[i] << ' ';
}