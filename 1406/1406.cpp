#include <iostream>
using namespace std;
#include <list>
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    string word;
    cin >> word;
    list<char> ans;
    for (int i = 0; i < word.length(); i++)
    { 
        ans.push_back(word[i]);
    }
    int n;
    cin >> n;
    auto iter = ans.end();
    for (int i = 0; i < n; i++)
    {
        char cmd;
        cin >> cmd;
        if (cmd == 'P')
        {
            char tmp;
            cin >> tmp;
            ans.insert(iter, tmp);
        }
        else if (cmd == 'L')
        {
            if (iter != ans.begin())
                iter--;
        }
        else if (cmd == 'B')
        {
            if (iter != ans.begin())
            {
                iter--;
                iter = ans.erase(iter);
            }
        }
        else if (cmd == 'D')
        {
            if (iter != ans.end())
                iter++;
        }
    }
    for (auto iter = ans.begin(); iter != ans.end(); iter++)
    {
        cout << *iter;
    }



}