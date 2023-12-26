#include <iostream>
#include <set>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie();
    int N,M;
    cin >> N;
    multiset<int> *a = new multiset<int>[N];
    for (int i = 0; i < N; i++)
    {
        cin >> M;
        string cmd;
        int num;
        for (int j = 0; j < M; j++)
        {
            cin >> cmd;
            cin >> num;
            if (cmd == "I")
                a[i].insert(num);
            else
            {
                if (a[i].empty()) continue;
                if (num == 1)
                    a[i].erase(prev(a[i].end()));
                else
                    a[i].erase(a[i].begin());
            }
        }
        if (a[i].empty())
            cout << "EMPTY\n";
        else
        {
            cout << *prev(a[i].end()) << " " << *a[i].begin() << "\n";
        }
    }
}