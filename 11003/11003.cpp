#include <iostream>
#include <deque>
using namespace std;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n,m;
    deque<pair<int, int>> deq;
    cin >> n >> m;
    int tmp;
    int min;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        if (!deq.empty() && deq.front().second == i - m)
        {
            deq.pop_front();
        }
        while (!deq.empty())
        {
            if (deq.back().first > tmp)
                deq.pop_back();
            else
                break;
        }
        deq.push_back(make_pair(tmp, i));
        cout << deq.front().first << ' ';
        
    }
}