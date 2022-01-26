//15.Given two library versions of an executable: for example, “10.1.1.3” and “10.1.1.9” or “10” and “10.1”.
// Find out which one is more recent? Strings can be empty also.
#include <bits/stdc++.h>
using namespace std;
int main() {
    string s1,s2;

    cin >> s1 >> s2;

    int i=0,j=0;
    while(i<s1.length() && j<s2.length()){
        if(s1[i]!=s2[j])
            break;
        i++;
        j++;
    }
    if(i<s1.length()){
        if(j<s2.length()){
            if(s1[i]<s2[j])
                cout << s2 << "\n";
            else
                cout << s1 << "\n";
        }
        else
            cout << s1 << "\n";
    }
    else{
        cout << s2 << "\n";
    }


}
