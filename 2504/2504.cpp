#include <iostream>
#include <stack>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	stack<char> s;
	stack<int> si;
	stack<int> sii;
	string a;
	getline(cin, a);
	int val = 1;
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] == '(')
		{
			if (i + 1 < a.size())
			{
				if (a[i + 1] == ']')
				{
					cout << '0';
					return 0;
				}
				else if (a[i + 1] == '(' || a[i + 1] == '[')
				{
					val *= 2;
				}
			}
			s.push('(');
			sii.push(i);
		}
		else if(a[i] == ')')
		{
			if (s.empty())
			{
				cout << '0';
				return 0;
			}
			else
			{
				if (s.top() == '(')
				{
					if (a[i - 1] == '(')
					{
						si.push(2 * val);
					}
					else
					{
						val /= 2;
					}
					s.pop();
					sii.pop();
				}
			}
		}
		else if (a[i] == '[')
		{
			if (i + 1 < a.size())
			{
				if (a[i + 1] == ')')
				{
					cout << '0';
					return 0;
				}
				else if(a[i + 1] == '(' || a[i + 1] == '[')
				{
					val *= 3;
				}
			}
			s.push('[');
			sii.push(i);
		}
		else if (a[i] == ']')
		{
			if (s.empty())
			{
				cout << '0';
				return 0;
			}
			else
			{
				if (s.top() == '[')
				{
					if (a[i - 1] == '[')
					{
						si.push(3 * val);
					}
					else
					{
						val /= 3;
					}
					s.pop();
					sii.pop();
				}
			}
		}
	}
		if (!s.empty())
		{
			cout << "0";
			return 0;
		}
		int res = 0;
		while (!si.empty())
		{
			res += si.top();
			si.pop();
		}
		cout << res;
}	