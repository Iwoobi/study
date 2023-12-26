#include <iostream>
#include <deque>
using namespace std;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n,m;
    deque<int> deq;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        deq.push_back(i);
    }
    int tmp;
    int res = 0;
    int count;
    for (int i = 0; i < m; i++)
    {
        count = 0;
        cin >> tmp;
        while (deq.front() != tmp)
        {
            int aa = deq.front();
            deq.pop_front();
            deq.push_back(aa);
            count++;
        }
        if (count > deq.size()/ 2)
            count = deq.size() - count;
        res += count;
        deq.pop_front();
    }
    cout << res;
}