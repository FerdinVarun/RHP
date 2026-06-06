#include<iostream>

using namespace std;


void solve(string s){


   int l=s.size();

   for(int c=1;c<=(1<<l)-1;c++){

    string st="";

    for(int i=0;i<l;i++){

        if(c&(1<<i)){

            st+=s[i];

        }

    }

    cout << st << endl;

   }

}


int main(){


    string s;


    cout << "Enter the string: ";

    cin >> s;


    solve(s);


    return 0;

}