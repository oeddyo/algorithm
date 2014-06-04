#include <iostream>
#include <string.h>

using namespace std;

int a[4];
string s;

int main(){

    cin>>a[0]>>a[1]>>a[2]>>a[3];

    cin>>s;
    long long int ans = 0;
    for(int i=0; i<s.size(); i++){
        int t = s[i]-'0';
        t -= 1;
        ans += a[t];
    }
    cout<<ans<<endl;

    return 0;
}

