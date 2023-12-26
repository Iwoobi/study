#include <iostream>
#include <tuple>
#include <algorithm>
using namespace std;
int *p;

int find(int x)
{
    if (p[x] == x) return x;
    return p[x] = find(p[x]);
}


int diff_f(int a, int b)
{
    a = find(a); b = find(b);
    if (p[a] == p[b]) p[a]--;
    if (a == b) return 0;
    if (p[a] < p[b]) p[b] = a;
    else p[a] = b;
    return 1;
}   
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    int cost[N];
    p = new int[N + 1];
    for (int i = 0; i < N + 1; i++)
        p[i] = i;
    tuple<int, int, int> tp[N * N];
    for (int i = 0; i < N; i++)
    {
        cin >> cost[i];
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int a;
            cin >> a;
            if (a != 0)
            {
                tp[i * N + j] = {a, i, j};
            }
            else
                tp[i * N + j] = {cost[i], i, N};
        }
    }
    sort(tp, tp + N * N);
    int cost1 = 0;
    int cnt = 0;
    for (int i = 0; i < N * N; i++)
    {
        int a, b, c;
        tie(c, a, b) = tp[i];
        if (diff_f(a,b))
            continue;
        cnt++;
        cost1 += c;
        if (cnt == N)
            break;
    }
    cout << cost1;
}