/*
ID: xieke.b1
PROG: frac1
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

ofstream fout("frac1.out");
ifstream fin ("frac1.in");
int N;

typedef pair<int, int> pii;
#define all(c) (c).begin(), (c).end()
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++) 


vector< pii > fracs;
map< pii, int> mymap; 

int gcd(int a, int b){
    if(b>a)swap(a,b);
    if(b==0){
        return a;
    }
    return gcd(b, a%b);
}

bool mycmp(const pii &a, const pii &b){
    int dif = a.first*b.second - a.second*b.first;
    return dif<0;
}


void work(){
    for(int d=1; d<=N; d++){
        for(int n=0; n<=d; n++){
            fracs.push_back( pii(n, d) );
        }
    }
    int sz = fracs.size();
    for(int i=0; i<sz; i++){
        int num = fracs[i].first;
        int de = fracs[i].second;
        int g = gcd(num, de);
        cout<<"gcd of "<<num<<" "<<de<<" is: "<<g<<endl;
        num/=g;
        de/=g;
        pii tmp(num, de);
        if(mymap.find(tmp) == mymap.end()){
            mymap[tmp] = 1;
        }else{
            continue;
        }
    }
    vector < pii > V;
    //map< pii, int>::iterator it;
    tr(mymap, it){
        V.push_back(it->first);
    }
    //vector< <pii,int> > V( all(mymap) );
    sort(V.begin(), V.end(), mycmp);
    for(int i=0; i<V.size(); i++){
        fout<<V[i].first<<"/"<<V[i].second<<endl;
    }

}

int main(){
    fin>>N;
    work();
    return 0;
}

