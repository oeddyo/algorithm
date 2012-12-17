#include <iostream>
#include <vector>
#include <string>
using namespace std;

int K;
vector <int> L;
string letter;
int sz;
void work(){
    sz = L.size();
    bool out = false;
    for(int v = sz-1; v>=0; v--){
        if(out)break;
        for(int w = sz-1; w>=0; w--){
            if(out)break;
            for(int x = sz-1; x>=0; x--){
                if(out)break;
                for(int y=sz-1; y>=0; y--){
                    if(out)break;
                    for(int z=sz-1; z>=0; z--){
                        if(out)break;
                        if(v==w||v==x||v==y||v==z||w==x||w==y||w==z||x==y||x==z||y==z){
                            continue;
                        }

                        if(L[v] -L[w]*L[w]+L[x]*L[x]*L[x]-L[y]*L[y]*L[y]*L[y]+L[z]*L[z]*L[z]*L[z]*L[z]==K){
                            out = true;
                            cout<<char(L[v]+'A'-1)<<char(L[w]+'A'-1)<<char(L[x]+'A'-1)<<char(L[y]+'A'-1)<<char(L[z]+'A'-1)<<endl;
                            break;
                        }
                    }
                }
            }
        }
    }
    if(out==false){
        cout<<"no solution"<<endl;
    }

}


int main(){
    while(1){
    cin>>K;
    cin>>letter;
    if(K==0 && letter=="END"){
        break;
    }
    L.clear();
    for(int i=0; i<letter.size(); i++){
        L.push_back(letter[i]-'A'+1);
    }
    sort(L.begin(), L.end());
    work();
    }

    return 0;
}

