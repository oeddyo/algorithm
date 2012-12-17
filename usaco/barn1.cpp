/*
ID: xieke.b1
PROG: barn1
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;
ofstream fout("barn1.out");
ifstream fin ("barn1.in");

int M,S,C;
typedef struct my_n{
    int left, right, len;
}node;

const int MAXN = 1500;

int points[MAXN];
node data[MAXN];

bool my_cmp(const node &a, const node &b){
    return a.len>b.len;
}


int main(){
    fin>>M>>S>>C;
    int pre = 1;
    for(int i=0; i<C; i++){
        fin>>points[i];
    }
    sort(points, points+C);
    for(int i=0; i<C;i++){
        cout<<points[i]<<endl;
    }
    int total_len = points[C-1]-points[0]+1;
    cout<<"total "<<total_len<<endl;
    pre = points[0]; 
    int limit = M-1;

    for(int i=1; i<C; i++){
        int k = points[i];;
        data[i].left = pre;
        data[i].right = k;
        data[i].len = k-pre-1;
        cout<<k-pre-1<<" ";
        pre = k;
    }
    sort(data,data+C, my_cmp);
    cout<<endl;
    
    for(int i=0; i<C&&limit>0; i++){
        total_len -= data[i].len;
        cout<<"extracting "<<data[i].left<<" "<<data[i].right<<" len: "<<data[i].len<<endl;;
        limit--;
    }
    fout<<total_len<<endl;

    return 0;
}

