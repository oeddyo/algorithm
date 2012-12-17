#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
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

#define MAX_SIZE 100
#define INF 999999999
using namespace std;


class WordPuzzle {
    public:
        map<string, int> word_to_num;
        vector <string> dic;
        
        int n_words;
        int graph[MAX_SIZE][MAX_SIZE];
        int dp[MAX_SIZE][MAX_SIZE];

        bool has_edge(string a, string b){
            if(a==b)
                return true;
            string tmp = a;
            int len = a.size();
            for(int i = 0; i < len -1; i++){
                char t = tmp[i];
                tmp[i] = tmp[i+1];
                tmp[i+1] = t;
                if(tmp==b){
                    return true;
                }else{
                    tmp = a;
                }
            }
            for(int i = 0; i < len -1; i++){
                tmp = a;
                for(char w = 'a'; w <= 'z'; w++){
                    tmp[i] = w;
                    if(tmp == b){
                        return true;
                    }
                }
            }
            return false;
        }

        void graph_constructor(){
            memset(graph,0,sizeof(graph));
            for(int i=0; i<n_words; i++){
                for(int j=i+1; j<n_words; j++){
                    if(has_edge(dic[i],dic[j])){
                        graph[i+2][j+2] = 1;
                        graph[j+2][i+2] = 1;
                    }
                }
                if(has_edge(source, dic[i])){
                        graph[0][i+2] = 1;
                        graph[i+2][0] = 1;
                }
                if(has_edge(target, dic[i])){
                    graph[1][i+2] = 1;
                    grpah[i+2][1] = 1;
                }
            }
        }

        void shortest_path(){
            for(int i=0; i<MAX_SIZE; i++){
                for(int j = 0; j < MAX_SIZE; j++){
                    dp[i][j] = graph[i][j];
                }
            }
            for(int i=0; i<n_words+2; i++){
                for(int j=0; j<n_words+2; j++){
                    for(int k=0; k<n_words+2; k++){
                        if(dp[i][k]+dp[k][j] <= dp[i][j]){
                            dp[i][j] = dp[i][k]+dp[k][j];
                        }
                    }
                }
            }
        }
        
        vector <string> getConversions(vector <string> dictionary, string source, string target) {
            dic = dictionary;
            word_to_num[source] = 0;
            word_to_num[target] = 1;
            for(int i=0; i<dictionary.size();i++){
                word_to_num[dictionary[i]] = i+2;
            }
        
        }
};


<%:testing-code%>
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
