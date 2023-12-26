#include <iostream>
using namespace std;
int arr[26];
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    int n;
    cin >> n;
    string tmp_a, tmp_b;
    int flag =0;
    for (int i = 0; i < n; i++)
    {
        flag = 0;
        cin >> tmp_a >> tmp_b;


        if (tmp_a.length() != tmp_b.length())
        {
            cout << "Impossible\n";
            continue;
        }
        for (int j = 0; j < tmp_a.length(); j++)
            arr[tmp_a[j] - 'a']++;
        for (int j = 0; j < tmp_b.length(); j++)
        {
            if (arr[tmp_b[j] - 'a'])
                arr[tmp_b[j] - 'a']--;
            else
            {
                cout << "Impossible\n";
                flag = 1;
                break;
            }
        }
        fill_n(arr, 26, 0);
        if (!flag)
            cout << "Possible\n"; 
    }
}