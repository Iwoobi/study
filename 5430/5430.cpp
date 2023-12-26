#include <iostream>
#include <sstream>
#include <deque>
using namespace std;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n,m;
    bool mod;
    string cmd;
    string number;
    int end;
    
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        deque<int> deq;
        mod = false;
        end = 0;
        cin >> cmd;
        cin >> m;
        cin >> number;
        stringstream aa(number);
        for (int j = 0; j < m; j++)
        {
            int Num;
            char aaa;
            aa >> aaa;
            aa >> Num;
            deq.push_back(Num);
        }
        for (int j = 0; j < cmd.length(); j++)
        {
            if (cmd[j] == 'R')
            {
                mod = !mod;
            }
            else if (cmd[j] == 'D')
            {
                if (deq.empty())
                {
                    cout << "error\n";
                    end = 1;
                    break;
                }
                if (mod)
                    deq.pop_back();
                else
                    deq.pop_front();
            }
        }
        if (end == 1)
        {
            continue;
        }
        cout << "[";
        while (!deq.empty())
        {
            if (mod)
            {
                cout << deq.back();
                deq.pop_back();
                if (!deq.empty())
                    cout << ',';
            }
            else
            {
                cout << deq.front();
                deq.pop_front();
                if (!deq.empty())
                    cout << ',';
            }
        }
        cout << "]\n";
    }
}