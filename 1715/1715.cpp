#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    int tmp;
    priority_queue<int, vector<int>, greater<int> > q;
    for (int i = 0; i < N; i++)
    {
        cin >> tmp;
        q.push(tmp);        
    }
    int S =0;
    while(q.size() != 1)
    {
        int a;
        int b;
        a = q.top();
        q.pop();
        b = q.top();
        q.pop();
        S += a+b;
        q.push(a + b);
    }
    cout << S;
    
}