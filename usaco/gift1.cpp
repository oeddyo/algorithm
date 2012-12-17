/*
ID: xieke.b1
PROB: gift1
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <vector>
#include <stdio.h>
#include <string.h>

using namespace std;

int N;

int main(){
    ifstream fin("gift1.in");
    ofstream fout("gift1.out");

    while( fin>>N ){
        map<string, int> mmap;
        vector <string> names;
        string s;
        int cnt = 0;
        int money[15];
        memset(money, 0, sizeof(money));
        for(int i=0; i<N; i++){
            fin>>s;
            names.push_back(s);
            if( mmap.find(s)==mmap.end()){
                mmap[s] = cnt++;
            }
        }
        for(int i=0; i<N; i++){
            fin>>s;
            int p = mmap[s];
            cout<<"seeing "<<s<<" "<<p<<endl;
            int initial_money, people;
            fin>>initial_money>>people;
            if( people == 0 )continue;


            int give = initial_money - initial_money%people;
            int each = initial_money/people;
            money[p] -= give;
            //money[p] += give;
            for(int j=0; j<people; j++){
                fin>>s;
                int the_other = mmap[s];
                //money[the_other] -= each;
                money[the_other] += each;
            }
        }
        for(int i=0; i<N; i++){
            fout<<names[i]<<" "<<money[i]<<endl;
            //cout<<names[i]<<" "<<money[i]<<endl;
        }
    }

    return 0;
}



