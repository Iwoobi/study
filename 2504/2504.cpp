#include <deque>
#include <iostream>

using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    deque<char> s;
    string a;
    getline(cin, a);
    int z = -1;
    for (int i =0; i < a.size(); i++)
    {
        if (a[i] == '(')
        {
            if (z == 3)
            {
                s.push_back('+');
            }
            z = 0;
            s.push_back('(');
        }
        else if(a[i] == ')')
        {
            if (z == 0)
            {
                s.pop_back();
                s.push_back('2');
            }
            else
                s.push_back(')');
            z = 1;
        }
        else if(a[i] == '[')
        {
            if (z == 1)
            {
                s.push_back('+');
            }
            s.push_back('[');
            z = 2;
        }
        else if(a[i] == ']')
        {
            if (z == 2)
            {
                s.pop_back();
                s.push_back('3');
            }
            else
                s.push_back(']');
            z = 3;
        }
    }
    while (!s.empty())
    {
        cout << s.front();
        s.pop_front();       
    }
}