#include <iostream>
#include <stack>

using namespace std;

int main()
{
    stack<int> s;
    int n;
    while (cin >> n)
    {
        s.push(n);
    }
    s.pop();
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
    return 0;
}
