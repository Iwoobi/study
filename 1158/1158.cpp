#include <iostream>
using namespace std;

int main()
{   
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n,k;
    cin >> n >> k;
    int *arr = new int[n];
    fill_n(arr, n, 0);
    int rot = 0;
    int print = 0;
    cout << "<";
    while (print < n)
    {
        rot += k;
        while (1)
        {
            rot = rot % n;
            if (!arr[rot - 1])
            {
                cout << rot;
                arr[rot - 1] = 1;
                print++;
                if (print < n)
                    cout << ", ";
                else
                    cout << ">";
                break;
            }
            else
                rot++;
        }
    }
}
