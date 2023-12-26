#include <iostream>
#include <queue>
using namespace std;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    queue<int> qu;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {  
        qu.push(i);
    }
    int tmp;
    while (qu.size() > 1)
    {
        qu.pop();
        if (qu.size() == 1)
            break;
        tmp = qu.front();
        qu.pop();
        qu.push(tmp);
    }
    cout << qu.front();
}