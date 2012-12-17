/*
ID: xieke.b1
PROB: transform
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>
#include <vector>
#include <string.h>

using namespace std;
int N;
ifstream fin("transform.in");
ofstream fout("transform.out");

const int INF = 999999999;
typedef vector<string> vs;
vector <string> origion;
vs after;


vector <string> ninty( vector<string> p){
    vector <string> tmp = p;
    
    for(int j=p.size()-1; j>=0; j--){
        for(int i=0; i<p.size(); i++){
            tmp[i][j] = p[p.size()-1-j][i];
        }
    }
    return tmp;
}
void print(vs s){
    for(int i=0; i<s.size(); i++){
        cout<<s[i]<<endl;
    }
}

vector <string> oneeighty(vector <string> p){
    vs t = p;
    t = ninty(t);
    t = ninty(t);
    return t;
}
vs twosenventy(vs p){
    vs t = p;
    t = ninty(t);
    t = ninty(t);
    t = ninty(t);
    return t;
}

vs reflect( vector <string> p){
    vs tmp = p;
    for(int i=0; i<p.size(); i++){
        int front=0, rear=p.size()-1;
        while(front<rear){
            swap(tmp[i][front], tmp[i][rear]);
            front++,rear--;
        }
    }
    return tmp;
}

vs comb(vs s){
    vs t = reflect(s);

}

void work(){

    if( ninty(origion) == after ){
        fout<<"1"<<endl;
        return ;
    }else if(oneeighty(origion) == after){
        fout<<"2"<<endl;
        return ;
    }else if(twosenventy(origion) == after){
        fout<<"3"<<endl;
        return ;
    }else if(reflect(origion) == after){
        fout<<"4"<<endl;
        return ;
    }

    if( ninty(reflect(origion)) == after || oneeighty(reflect(origion))==after || twosenventy(reflect(origion))==after){
        fout<<"5"<<endl;
        return ;
    }
    if( origion==after){
        fout<<"6"<<endl;
        return ;
    }
    fout<<"7"<<endl;
    return;
    
   /* 
    cout<<"90"<<endl;
    print(ninty(origion));
    cout<<"180"<<endl;

    print (oneeighty(origion) );
    cout<<"270"<<endl;
    print (twosenventy(origion));
    cout<<"reflect"<<endl;
    print(reflect(origion));
   */ 
}

int main(){
    while(fin>>N){
        string s;
        for(int i=0; i<N; i++){
            fin>>s;
            origion.push_back(s);
        }
        for(int i=0; i<N; i++){
            fin>>s;
            after.push_back(s);
        }

        work(); 
    }

    return 0;
}

