#include <iostream>

using namespace std;
int map[2][3];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int val;
    cin >> val;
    for (int i = 0; i < val; i++)
    {
        for (int j = 0; j < 3; j++)
            cin >> map[0][j];
        if (i > 0)
        {
            map[0][0] += min(map[1][1],map[1][2]); 
            map[0][1] += min(map[1][0], map[1][2]); 
            map[0][2] += min(map[1][1],map[1][0]);
        }
        for (int j = 0; j < 3; j++)
            map[1][j] = map[0][j];
    }
    cout << min(map[1][0],min(map[1][1],map[1][2]));

}