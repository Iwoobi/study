#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N,M;
    cin >> N >> M;
    unordered_map<string, int> b;
    string *a = new string[N];
    for(int i = 0; i < N; i++)
    {
        cin >> a[i];
        b[a[i]] = i; 
    }
    string tmp;
    for (int i = 0; i < M; i++)
    {
        cin >> tmp;
        if (isdigit(tmp[0]))
            cout << a[stoi(tmp) - 1] << "\n";
        else
            cout << b[tmp] + 1 << "\n";
    }
}