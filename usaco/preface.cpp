/*
ID: xieke.b1
PROB: preface
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>
#include <vector>
#include <string.h>

using namespace std;
ifstream fin("preface.in");
ofstream fout("preface.out");

const int INF = 999999999;
int N;
typedef vector<int> vi;



map<char, int> my_count;

string one[10] = {"","I","II","III","IV","V","VI","VII","VIII","IX"};
string ten[10] = {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
string hun[10] = {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
string thu[10] = {"","M","MM","MMM"};

string get_string(int n){
    vi num;
    while(n){
        num.push_back(n%10);
        n/=10;
    }
    reverse(num.begin(), num.end());
    int sz = num.size();
    string res;
    for(int i=0; i<sz; i++){
        int w = (sz-i-1);
        if(w==0){
            res += one[num[i]];
        }else if(w==1){
            res += ten[num[i]];
        }else if(w==2){
            res += hun[num[i]];
        }else if(w==3){
            res += thu[num[i]];
        }
    }
    return res;
}

char list[10] = {'I','V','X','L','C','D','M'};

void work(){
    vi number;
    int t_N = N;
    reverse(number.begin(), number.end());
    for(int i=1; i<=N; i++){
        string rep = get_string(i);
        for(int j=0; j<rep.size(); j++){
            if( my_count.find(rep[j])==my_count.end()){
                my_count[rep[j]] = 1;
            }else{
                my_count[rep[j]]+= 1;
            }
        }
    }

    for(int i=0; i<7; i++){
        if( my_count.find( list[i] )!=my_count.end()){
            fout<<list[i]<<" "<<my_count[list[i]]<<endl;
        }
    }

}



int main(){
    fin>>N;
    work();
     
    return 0;
}

