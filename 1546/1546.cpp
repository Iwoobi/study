#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    double sum = 0;
    double max =-1;
    int N;
    cin >> N;
    double num;
    for (int i = 0; i < N; i++)
    {
        cin >> num;
        sum += num;
        if (num > max)
            max = num;
    }
    double result = sum * 100 / max/ N;
    cout << result;

    

}