#include <iostream>
#include <string>
#include <vector>

using namespace std;

//typedef vector<int> VI;
int idx;
const int MAXN = 1000000;
int VI[MAXN];
int sz;
int sz_w;

void buildTable(string& w)
{
    //t = VI(sz_w);

    int i = 2, j = 0;
    VI[0] = -1; VI[1] = 0;

    while(i < sz_w)
    {
        if(w[i-1] == w[j]) { VI[i] = j+1; i++; j++; }
        else if(j > 0) j = VI[j];
        else { VI[i] = 0; i++; }
    }
}

int KMP(string& s, string& w)
{
    int m = 0, i = 0;

    buildTable(w);  
    while(m+i < sz)
    {
        if(w[i] == s[m+i])
        {
            i++;
            //if(i == w.length()) return m;
            if(i == sz_w) return m;
        }
        else
        {
            m += i-VI[i];
            if(i > 0) i = VI[i];
        }
    }  
    return -1;
    return s.length();
}





string convert(int num){
    string tmp;
    while(num){
        tmp += (num%10 + '0');
        num/=10;
    }
    return string(tmp.rbegin(), tmp.rend());
}


int main()
{
    string a, b;

    cin>>a;

    sz = a.size();;

    for(int i=1; i<=50000; i++){
        b = convert(i);
        sz_w = b.size();
        int p = KMP(a, b); 
        if(p != -1){
            continue;
        }else{
            cout<<i<<endl;
            break;
        }

    }

}

