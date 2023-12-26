#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int comp(string a, string b)
{
    if (a.length() == b.length())
        return a < b;
    else
        return a.length() < b.length();
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<string> a;
    int val;
    string aa;
    cin >> val;
    a.size();
    for (int i = 0; i < val; i++)
    {
        cin >> aa;
        a.push_back(aa);
    }
    sort(a.begin(), a.end(), comp);
    for (int i = 0; i < val; i++)
    {
        if (i > 0)
        {
            if (a[i -1] == a[i])
                continue;
        }
        cout << a[i] << "\n";
    }
}