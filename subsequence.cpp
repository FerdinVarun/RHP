#include <iostream>
using namespace std;

void solve(){
    string s;
    cin >> s;

    int n = s.length();

    for(int mask = 1; mask < (1 << n); mask++){
        
        for(int i = 0; i < n; i++){
            
            if((mask & (1 << i))>0){
                
                cout << s[i];
            }
        }
        cout << endl;
    }
}
int main()
{
    solve();
    return 0;
}
