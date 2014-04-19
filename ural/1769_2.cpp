#include <iostream>
#include <string>
#include <string.h>
#include <vector>

using namespace std;

//typedef vector<int> VI;
int idx;
const int MAXN = 1000000;
int VI[MAXN];
int sz;
int sz_w;


int s_2_i(string &tmp){
    int sz = tmp.size();
    int c = 0;
    for(int i=0; i<sz; i++){
        c*= 10;
        c += tmp[i]-'0';
    }
    return c;
}


int main()
{
    string a, b;

    cin>>a;
    memset(VI, 0, sizeof(VI));
    sz = a.size();;

    for(int i=0; i<sz; i++){
        for(int l = 0; l<=6; l++){
            string s = a.substr(i, l);
            int c = s_2_i(s);
            VI[c] = 1;
        }
    }
    for(int i=1; i<MAXN; i++){
        if(VI[i] == 0){
            cout<<i<<endl;
            break;
        }

    }
    return 0;


}

