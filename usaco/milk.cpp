/*
ID: xieke.b1
PROG: milk
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

ofstream fout("milk.out");
ifstream fin ("milk.in");

int N,M;

typedef struct my_node{
    int price, num;
}node;
const int MAXN = 5001;
node data[MAXN];

bool my_cmp(const node &a, const node &b){
    return a.price<b.price;
}


int main(){
    fin>>N>>M;
    for(int i=0; i<M; i++){
        fin>>data[i].price>>data[i].num;
    }
    sort(data,data+M, my_cmp);
    for(int i=0; i<M;i++){
        cout<<data[i].price<<" "<<data[i].num<<endl;
    }
    int total = 0;
    int milk_need = N;
    for(int i=0; i<M; i++){
        int actual_num = min(milk_need, data[i].num);
        milk_need-=actual_num;
        total+=data[i].price*actual_num;
        if(milk_need<=0)break;
    }
    fout<<total<<endl; 
    return 0;
}

