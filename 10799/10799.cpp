
#include <iostream>

using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string buf;
    int res = 0;
    int ba = 0;
    int state = 0;
    getline(cin, buf);
    for (int i = 0; i < buf.size(); i++)
    {
        if (buf[i] == '(')
        {
            ba++;
            if (buf[i + 1] == ')')
            {
                ba--;
                res += ba;
                i++;
            }
        }
        else if(buf[i] == ')')
        {
            ba--;
            res++;
       
        }
    }
    cout << res;
}  