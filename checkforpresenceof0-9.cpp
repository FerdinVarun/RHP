#include <iostream>
using namespace std;

void solve()
{
    string s;
    cin >> s;

    int flag = 0;

    for(char ch : s)
    {
        if (ch>='0' && ch <= '9'){

            flag |= (1 << (ch - '0'));

        }
    }   

    int allNumbers = (1 << 10) - 1;

    if(flag == allNumbers)
        cout << "Yes";
    else
        cout << "No";
}

int main()
{
    solve();
    return 0;
}
