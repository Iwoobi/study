#include <iostream>
using namespace std;
int arr[26];
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    int ans = 0;
    string tmp_a, tmp_b;
    cin >> tmp_a >> tmp_b;
    for (int j = 0; j < tmp_a.length(); j++)
        arr[tmp_a[j] - 'a']++;
    for (int j = 0; j < tmp_b.length(); j++)
    {
        if (arr[tmp_b[j] - 'a'])
            arr[tmp_b[j] - 'a']--;
        else 
            ans++;
    }
    for (int i = 0; i < 26; i++)
    {
        ans += arr[i];
    }
    cout << ans;
}