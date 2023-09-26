#include <string>
#include <iostream>
#include <stack>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    string buf;
    int error = 0;
    stack<char> total;
    while(getline(cin, buf, '.') )
    {
        if (buf.size() == 1 && buf[0] == '\n')
            break;
        for (int i = 0; i < buf.size(); i++)
        {
            if (buf[i] == '(')
            {
                total.push(buf[i]);
            }
            else if (buf[i] == ')')
            {
                if (total.size() != 0 && total.top() == '(')
                    total.pop();
                else
                {
                    error = 1;
                    break;
                }
            }
            else if (buf[i] == '[')
            {
                total.push(buf[i]);
            }
            else if (buf[i] == ']')
            {
                if (total.size() != 0 && total.top() == '[')
                    total.pop();
                else
                {
                    error = 1;
                    break;
                }
            }
        }
        if (total.size() == 0 && error != 1)
            cout << "yes\n";
        else
        {  
            error = 0;
            cout << "no\n";
            while( !total.empty() ) 
            total.pop();
        }
    }
}