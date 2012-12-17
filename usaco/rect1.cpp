/*
ID: xieke.b1
PROB: rect1
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#include <string.h>
#include <set>

using namespace std;

ifstream fin("rect1.in");
ofstream fout("rect1.out");


#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)

typedef pair<int, int> pii;
//typedef pair< pii, pii > rec;

const int MAXN = 1001*100;
const int INF = 2100000000;

int A,B,N;

typedef struct _node{
    int x1,y1, x2,y2;
    int color;
}rect;

rect rec[MAXN];
int cnt = 0;

bool inter(int x1, int x2, int x3, int x4){
    if( x2<=x3 || x1>=x4 )return false;
    return true;
}

bool deleted[MAXN];
void add(int x1, int y1, int x2, int y2, int color){
    rect tmp;
    //cout<<"adding "<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;
    tmp.x1 = x1, tmp.y1 = y1, tmp.x2 = x2, tmp.y2 = y2, tmp.color = color;
    rec[cnt++] = tmp;

}

void insert(rect &cur){
    for(int i=0; i<cnt; i++){
        rect tmp = rec[i];
        if(deleted[i]==false && inter( tmp.x1, tmp.x2, cur.x1, cur.x2 ) && inter(tmp.y1, tmp.y2, cur.y1, cur.y2) ){
            //cout<<"in "<<i<<endl;
            int k1 = max(tmp.x1, cur.x1);
            int k2 = min(tmp.x2, cur.x2);

            if( k1>tmp.x1 ){
                //cout<<"first"<<endl;
                add(tmp.x1, tmp.y1, k1, tmp.y2, tmp.color);
            }
            if( k2<tmp.x2 ){
                //cout<<"second"<<endl;
                add(k2, tmp.y1, tmp.x2, tmp.y2, tmp.color);
            }
            //cut y here
            int k3 = max(tmp.y1, cur.y1);
            int k4 = min(tmp.y2, cur.y2);
            
            if( k3 > tmp.y1){
                //cout<<"third"<<endl;
                add(k1, tmp.y1, k2, k3, tmp.color);
            }
            if( k4 < tmp.y2){
                //cout<<"fourth"<<endl;
                add(k1, k4, k2, tmp.y2, tmp.color);
            }
            deleted[i] = true;
        }
    }
    add(cur.x1, cur.y1, cur.x2, cur.y2, cur.color);
}
int count(int ptr){
    return (rec[ptr].y2-rec[ptr].y1 )* (rec[ptr].x2-rec[ptr].x1);
}

void work(){
    rect tmp_rec;
    for(int i=0; i<N; i++){
        fin>>tmp_rec.x1>>tmp_rec.y1>>tmp_rec.x2>>tmp_rec.y2>>tmp_rec.color;
        //cout<<"---"<<endl;
        insert(tmp_rec);
    }
    map< int, int> mymap;
    for(int i=0; i<cnt; i++){
        if(deleted[i]==false){
            int col = rec[i].color;
            if( mymap.find( col )==mymap.end()){
                mymap[col] = 0;
            }
            mymap[col] += count( i );
        }
    }
    for(int i=0; i<cnt; i++){
        if(deleted[i]==false){
            //cout<<"rect "<<rec[i].x1<<" "<<rec[i].y1<<" "<<rec[i].x2<<" "<<rec[i].y2<<endl;
        }
    }

    for(int i=1; i<=2500; i++){
        if(mymap.find(i)!=mymap.end()){
            if(mymap[i]!=0){
                fout<<i<<" "<<mymap[i]<<endl;
            }
        }
    }
}

int main(){
    fin>>A>>B>>N;
    rec[0].x1 = 0, rec[0].y1 = 0, rec[0].x2 = A, rec[0].y2 = B, rec[0].color = 1; 
    cnt++;
    work();

    return 0;
}

