#include <iostream>
using namespace std;

int r, x,y;
int pow_2(int a)
{
	int res = 1;
	while (a){
		res *= 2;
		a--;
	}
	return (res);
		 
}
int	func(int r, int a, int b)
{
	if (r == 0)
		return 0;
	int val = pow_2(r - 1);
	if (a < val)
	{
		if (b < val)
			return func(r - 1, a, b);
		else
			return val * val + func(r - 1, a, b - val);
	}
	else
	{
		if (b < val)
			return  2 * val * val  + func(r - 1, a - val, b);
		else
			return 3 * val * val + func(r - 1, a - val, b - val);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> r >> x >> y;
	cout << func(r, x,y);
}