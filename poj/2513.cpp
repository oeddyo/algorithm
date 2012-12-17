#include <iostream>
#include <string>
#define MAXN 250001
using namespace std;

char left_strs[MAXN][12];
char right_strs[MAXN][12];
int ptr; 

typedef struct my_node{
    int words;
    struct my_node *sons[26];
}node;

node* build_trie(){
    node *root = (node *)malloc(sizeof(node));
    root->words = 0;
    for(int i=0; i<26; i++)root->sons[i] = NULL;
    return root;
}

void add_word(node *root, int pos){
    int str_sz = strlen(right_strs[pos]);
    char *word = right_strs[pos];
    cout<<"inserting "<<word<<" with len "<<strlen(right_strs[pos])<<endl;
    node *cur = root;
    for(int i=0; i<str_sz; i++){
        int pos = word[i]-'a';
        if(cur->sons[pos]==NULL){
            //create
            node *t = build_trie();
            cur->sons[pos] = t;
        }
        cur = cur->sons[pos];
    }
    cur->words+=1;
}

int count_words(node *root, int pos){
    int str_sz = strlen(left_strs[pos]);
    char *word = left_strs[pos];
    node *cur = root;
    for(int i=0; i<str_sz; i++){
        int pos = word[i]-'a';
        if(cur->sons[pos] == NULL){
            return 0;
        }else{
            cur = cur->sons[pos];
        }
    }
    int t = cur->words;
    cout<<"count is "<<t<<" for "<<left_strs[pos]<<endl;
    cur->words-=1;
    return t;
}


int main(){
    ptr = 0;

    while(scanf("%s %s",left_strs[ptr], right_strs[ptr])!=EOF){
        ptr++;
    }
    
    node *root = build_trie();
    for(int i=0; i<ptr;i++){
        //build the trie using right
        add_word(root, i);
    }
    int sum = 0;
    int empty = 1;
    
    for(int i=0; i<ptr; i++){
        int res = count_words(root, i);
        cout<<"res is "<<res<<endl;
        if(res<=0){
            sum+=1;
        }
        empty=0;
    }
    if(empty){
        cout<<"Possible"<<endl;
        return 0;
    }


    if(sum<=1){
        cout<<"Possible"<<endl;
    }else{
        cout<<"Impossible"<<endl;
    }
    
    return 0;
}

