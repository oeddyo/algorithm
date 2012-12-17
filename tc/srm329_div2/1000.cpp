#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <sstream>
using namespace std;

class ProbabilisticTranslator {
    public:
        int maximumFidelity(vector <string>, vector <string>, vector <string>);
};

const int MAXN = 2000;
int dp[MAXN][MAXN];
int matrix[MAXN][MAXN];
int ProbabilisticTranslator::maximumFidelity(vector <string> text, vector <string> dictionary, vector <string> frequencies) {
    map<string, int> mymap;
    map<string, int> words_mapping;
    int cnt = 0;
    int dic_sz = dictionary.size();
    vector<string> mytext;
    for(int i=0; i<text.size(); i++){
        istringstream is(text[i]);
        string t;
        while(is>>t){
            mytext.push_back(t);
        }
    }
    int text_size = mytext.size();;
    set<string> words;
    for(int i =0; i<mytext.size(); i++){
        if(words.find(mytext[i])==words.end()){
            words.insert(mytext[i]);
        }
    }
    vector< vector<int> > my_v;


    int cnt2=0;
    for(int i=0; i<dic_sz; i++){
        istringstream in(dictionary[i]);
        string left, comma, t;
        in>>left;
        if(words_mapping.find(left)==words_mapping.end()){
            cout<<"mapping "<<left<<" to "<<cnt2<<endl;
            words_mapping[left] = cnt2++;
            
        }

        in>>comma;
        vector<int> t_v;
        while(in>>t){
            if(mymap.find(t)==mymap.end()){
                cout<<t<<"-> "<<cnt<<endl;
                t_v.push_back(cnt);
                mymap[t]=cnt++;
            }else{
                t_v.push_back(mymap[t]);
            }
        }
        //set<int> tmp(t_v.begin(), t_v.end());
        //vector<int> ok(tmp.begin(), tmp.end());
        //my_v.push_back(ok);
        my_v.push_back(t_v);
    }
    memset(dp,0,sizeof(dp));
    memset(matrix,0,sizeof(matrix));
    for(int i=0; i<frequencies.size(); i++){
        istringstream in(frequencies[i]);
        string left, right;
        int value;
        in>>left;
        in>>right;
        in>>value;
        cout<<"value is "<<value<<endl;
        if(mymap.find(left)!=mymap.end()&&mymap.find(right)!=mymap.end()){
            matrix[ mymap[left] ][ mymap[right] ] = value;
        }
        cout<<"matrix["<<left<<"]["<<right<<"] = "<<value<<endl;
    }
    cout<<"text size is "<<text_size<<endl;
    
    for(int number_i=1; number_i<text_size; number_i++){
        cout<<"want to see "<<mytext[number_i]<<endl;
        int i = words_mapping[ mytext[number_i] ];
        cout<<"now i is "<<i<<endl;
        for(int j=0; j<my_v[i].size(); j++){
            int cur_num = my_v[i][j];
            for(int k=0; k<cnt; k++){
                dp[number_i][cur_num] = max(dp[number_i][cur_num], dp[number_i-1][k]+matrix[k][cur_num]);
                //if(dp[number_i][cur_num]!=0){
                    cout<<"now adding "<<" "<<number_i<<" "<<k<<" "<<cur_num<<" "<<matrix[k][cur_num]<<" pre is "<<dp[number_i-1][k]<<" and dp[i][cur_num]= "<<dp[number_i][cur_num]<<endl;;
                //}
            }
        }
    }
    int ans = 0;
    for(int i=0; i<cnt; i++){
        ans = max(ans, dp[text_size-1][i]);
    }
    cout<<"words size "<<words.size()<<endl;
    cout<<"dic size "<<dic_sz<<endl;
    cout<<"mymap.size "<<mymap.size()<<endl;
    return ans;
}
double test0() {
    string t0[] ={"iagvzyndsdeb l bnswxxfazsfqflna riarqwm iupjz", "iupjz iagvzyndsdeb pkqghj iupjz chgbdfjzecpqyifj", "pkqghj pkqghj njvuzozxnrba ref ref pkqghj iupjz", "krusdsgjoxooeil njvuzozxnrba chgbdfjzecpqyifj", "krusdsgjoxooeil iagvzyndsdeb pkqghj njvuzozxnrba", "iupjz iupjz bnswxxfazsfqflna pkqghj pkqghj", "chgbdfjzecpqyifj njvuzozxnrba l l bnswxxfazsfqflna", "krusdsgjoxooeil bnswxxfazsfqflna pkqghj", "chgbdfjzecpqyifj chgbdfjzecpqyifj iagvzyndsdeb"};
    vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
    string t1[] = {"qnob : psgkltmwsfjuduzyam v vrehmdtzubhipo", "bbtcrfylrjmbaprtll : v vrehmdtzubhipo", "iwdeeklzqvudtkxj : vrehmdtzubhipo v vrehmdtzubhipo", "ref : v vrehmdtzubhipo v v v v v vrehmdtzubhipo", "qauounqmywvljpkevm : v vrehmdtzubhipo", "tt : psgkltmwsfjuduzyam vrehmdtzubhipo v", "znqwgl : v vrehmdtzubhipo psgkltmwsfjuduzyam", "luhnburwyuv : v vrehmdtzubhipo psgkltmwsfjuduzyam", "riarqwm : psgkltmwsfjuduzyam v psgkltmwsfjuduzyam", "yzodvmhsyajsx : psgkltmwsfjuduzyam vrehmdtzubhipo", "plxfisxxpccwuidcih : psgkltmwsfjuduzyam v", "avnur : vrehmdtzubhipo v vrehmdtzubhipo", "xhshyvdmuktqj : psgkltmwsfjuduzyam vrehmdtzubhipo", "kqmc : psgkltmwsfjuduzyam v vrehmdtzubhipo v", "pkqghj : v vrehmdtzubhipo vrehmdtzubhipo", "bnswxxfazsfqflna : v psgkltmwsfjuduzyam", "bighdwbpgmajwy : psgkltmwsfjuduzyam vrehmdtzubhipo", "leguqliwduf : vrehmdtzubhipo v vrehmdtzubhipo v", "gyvmicizuf : v psgkltmwsfjuduzyam", "iupjz : psgkltmwsfjuduzyam v vrehmdtzubhipo", "ygvroq : v psgkltmwsfjuduzyam v psgkltmwsfjuduzyam", "xknhwrgb : v vrehmdtzubhipo vrehmdtzubhipo v", "lceq : v v psgkltmwsfjuduzyam vrehmdtzubhipo", "fw : vrehmdtzubhipo psgkltmwsfjuduzyam", "pjfxbwtveyegxroc : v v psgkltmwsfjuduzyam", "kbyydazhybaetu : vrehmdtzubhipo v", "zy : psgkltmwsfjuduzyam v v vrehmdtzubhipo v v v", "p : vrehmdtzubhipo v psgkltmwsfjuduzyam v v v", "l : psgkltmwsfjuduzyam psgkltmwsfjuduzyam", "fxd : psgkltmwsfjuduzyam psgkltmwsfjuduzyam", "chgbdfjzecpqyifj : vrehmdtzubhipo v v", "iagvzyndsdeb : psgkltmwsfjuduzyam", "hypsjgbcu : v psgkltmwsfjuduzyam", "vpkwzfvyitqa : v v vrehmdtzubhipo vrehmdtzubhipo v", "nsqkdfbncsscgkyefl : psgkltmwsfjuduzyam", "dhjcpxmsgjbtj : v psgkltmwsfjuduzyam", "krusdsgjoxooeil : vrehmdtzubhipo vrehmdtzubhipo v", "hlzrwfvegxqwrt : v v psgkltmwsfjuduzyam v", "jfe : psgkltmwsfjuduzyam vrehmdtzubhipo v", "erppr : vrehmdtzubhipo v v vrehmdtzubhipo", "yzjoeb : psgkltmwsfjuduzyam psgkltmwsfjuduzyam v v", "g : vrehmdtzubhipo vrehmdtzubhipo v", "njvuzozxnrba : vrehmdtzubhipo psgkltmwsfjuduzyam", "nkoon : vrehmdtzubhipo psgkltmwsfjuduzyam", "rzyvjtzumtn : vrehmdtzubhipo v v", "lvqibpsmzbylin : v vrehmdtzubhipo vrehmdtzubhipo v", "tlsntgbihjmhzmrsngc : psgkltmwsfjuduzyam v", "dklrnuijzvercfpdic : v psgkltmwsfjuduzyam v", "arqjufk : v psgkltmwsfjuduzyam psgkltmwsfjuduzyam", "gsbxeujgcwvgzxpsqf : v v v vrehmdtzubhipo"};
    vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
    string t2[] = {"psgkltmwsfjuduzyam psgkltmwsfjuduzyam 829", "v v 55", "v vrehmdtzubhipo 320", "psgkltmwsfjuduzyam v 422", "v psgkltmwsfjuduzyam 287", "vrehmdtzubhipo vrehmdtzubhipo 688"};
    vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
    ProbabilisticTranslator * obj = new ProbabilisticTranslator();
    clock_t start = clock();
    int my_answer = obj->maximumFidelity(p0, p1, p2);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p3 = 23258;
    cout <<"Desired answer: " <<endl;
    cout <<"\t" << p3 <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t" << my_answer <<endl;
    if (p3 != my_answer) {
        cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
        return -1;
    }
    else {
        cout <<"Match :-)" <<endl <<endl;
        return (double)(end-start)/CLOCKS_PER_SEC;
    }
}
double test1() {
    string t0[] = {"a b c"};
    vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
    string t1[] = {"a : x y", "b : p q", "c : x y"};
    vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
    string t2[] = {"x p 100", "x q 10", "q x 10"};
    vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
    ProbabilisticTranslator * obj = new ProbabilisticTranslator();
    clock_t start = clock();
    int my_answer = obj->maximumFidelity(p0, p1, p2);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p3 = 100;
    cout <<"Desired answer: " <<endl;
    cout <<"\t" << p3 <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t" << my_answer <<endl;
    if (p3 != my_answer) {
        cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
        return -1;
    }
    else {
        cout <<"Match :-)" <<endl <<endl;
        return (double)(end-start)/CLOCKS_PER_SEC;
    }
}
double test2() {
    string t0[] = {"a b", "c"};
    vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
    string t1[] = {"a : x y", "b : p q", "c : x y"};
    vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
    string t2[] = {"x p 100", "x q 97", "q x 97"};
    vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
    ProbabilisticTranslator * obj = new ProbabilisticTranslator();
    clock_t start = clock();
    int my_answer = obj->maximumFidelity(p0, p1, p2);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p3 = 194;
    cout <<"Desired answer: " <<endl;
    cout <<"\t" << p3 <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t" << my_answer <<endl;
    if (p3 != my_answer) {
        cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
        return -1;
    }
    else {
        cout <<"Match :-)" <<endl <<endl;
        return (double)(end-start)/CLOCKS_PER_SEC;
    }
}
double test3() {
    string t0[] = {"a", "bb c"};
    vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
    string t1[] = {"a : a a", "bb : b", "c : c", "ccc : a"};
    vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
    string t2[] = {"y z 2", "x y 10", "z x 5"};
    vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
    ProbabilisticTranslator * obj = new ProbabilisticTranslator();
    clock_t start = clock();
    int my_answer = obj->maximumFidelity(p0, p1, p2);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p3 = 0;
    cout <<"Desired answer: " <<endl;
    cout <<"\t" << p3 <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t" << my_answer <<endl;
    if (p3 != my_answer) {
        cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
        return -1;
    }
    else {
        cout <<"Match :-)" <<endl <<endl;
        return (double)(end-start)/CLOCKS_PER_SEC;
    }
}
int main() {
    
    int time;
    bool errors = false;
    time = test0();
    if (time < 0)
        errors = true;
    time = test1();
    if (time < 0)
        errors = true;

    time = test2();
    if (time < 0)
        errors = true;
    time = test3();
    if (time < 0)
        errors = true;

    if (!errors)
        cout <<"You're a stud (at least on the example cases)!" <<endl;
    else
        cout <<"Some of the test cases had errors." <<endl;
}

