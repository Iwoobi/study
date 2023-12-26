#include <iostream>
using namespace std;
int lc[30];
int rc[30];
void func1s(int a)
{
    cout << char('A' + a);
    if(lc[a] != 0) func1s(lc[a] - 1);
    if(rc[a] != 0) func1s(rc[a] - 1);
}
void func2s(int a)
{
    if(lc[a] != 0) func2s(lc[a] - 1);
    cout << char('A' + a);
    if(rc[a] != 0) func2s(rc[a] - 1);
}
void func3s(int a)
{
    if(lc[a] != 0) func3s(lc[a] - 1);
    if(rc[a] != 0) func3s(rc[a] - 1);
    cout << char('A' + a);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N ;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        char a,b,c;
        cin >> a >> b >> c;
        if (b != '.')
        {
            lc[a - 'A'] = b - 'A' + 1;
        }
        if (c != '.')
        {
            rc[a - 'A'] = c - 'A' + 1;
        }
        
    }
    func1s(0);
    cout << "\n";
    func2s(0);
    cout << "\n";
    func3s(0);
    cout << "\n";
}