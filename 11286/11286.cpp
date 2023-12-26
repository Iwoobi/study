#include <iostream>
#include <queue>
#include <vector>
using namespace std;


class cmp{
    public:
    bool operator() (int a, int b){
        if (abs(a) != abs(b)) return abs(a) > abs(b);
        return a > 0 && b < 0;
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    priority_queue<int, vector<int>, cmp> pq;
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        if (num != 0)
            pq.push(num);
        else
        {
            if (!pq.empty())
            {
                cout << pq.top() << "\n";
                pq.pop();
            }
            else
                cout << "0\n";
        }
    }
}