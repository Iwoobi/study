#include <iostream>
using namespace std;
#include <list>
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    string word;
    list<char> ans;
    list<char>::iterator iter;
    for (int j = 0; j < n; j++)
    {
        iter = ans.end();
        cin >> word;
        for (int i = 0; i < word.length(); i++)
        {
            if (word[i] == '<')
            {
                if (iter != ans.begin())
                    iter--;
            }
            else if (word[i] == '>')
            {
                if (iter != ans.end())
                    iter++;
            }
            else if (word[i] == '-')
            {
                if (iter != ans.begin())
                {
                    iter--;
                    iter = ans.erase(iter);
                }
            }
            else
            {
                ans.insert(iter, word[i]);
            }
        }
        for (auto iter = ans.begin(); iter != ans.end(); iter++)
        {
            cout << *iter;
        }
        cout << "\n";
        ans.clear();
    }

}