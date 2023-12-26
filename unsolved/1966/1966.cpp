#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int num,find;
        cin >> num >> find;
        int *arr = new int[num];
        for (int j = 0; j < num; j++)
        {
            cin >> arr[j];
        }
        int count =0;
        for (int k = 0; k < num;k++)
        {
            if (arr[k] > arr[find])
                count++;
            
        }
        delete[] arr
    }

}