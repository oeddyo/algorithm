#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>

using namespace std;

const int MAXN = 100000;

int N;
char str[MAXN];

typedef struct trieNode{
    bool mark;
    struct trieNode* nextNode[27];
}tN;

tN *root;

void insert_trie(string s, tN* root){
    tN* cur = root;
    for(int i=0; i<s.size(); i++){
        int nc = s[i]-'a';
        if(root->nextNode[nc]==NULL){
            tN* tmpNode = new tN();
            memset(tmpNode->nextNode, 0, sizeof(tmpNode->nextNode));
            cur->nextNode[nc] = tmpNode;
            cur = tmpNode;
        }else{
            cur = root->nextNode[nc];
        }
        cout<<"here -> "<<s[i]<<" "<<cur<<endl;
    }
    cur->mark = true;
}

void build_trie(){
    vector<string> dic;
    dic.push_back("out");
    dic.push_back("output");
    dic.push_back("puton");
    dic.push_back("in");
    dic.push_back("input");
    dic.push_back("one");
    
    root = new tN();
    for(int i=0; i<dic.size(); i++){
        insert_trie(dic[i], root);
    }
}

void work(){
    build_trie();
    
}

int main(){
    scanf("%d",&N);
    while(N--){
        scanf("%s",str);
        work();
    }
    
    return 0;
}
