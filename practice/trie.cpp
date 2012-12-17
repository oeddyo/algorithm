#include <iostream>
#include <string>

using namespace std;

typedef struct my_node{
    int words, prefix;
    struct my_node *sons[26];
}node;

node* build_trie(){
    node *root = (node *)malloc(sizeof(node));
    root->words = 0, root-> prefix = 0;
    for(int i=0; i<26; i++)root->sons[i] = NULL;
    return root;
}

void add_word(node *root, string word){
    int str_sz = word.size();
    node *cur = root;
    for(int i=0; i<str_sz; i++){
        int pos = word[i]-'a';
        if(cur->sons[pos]==NULL){
            //create
            node *t = build_trie();
            cur->sons[pos] = t;
        }
        cur->prefix+=1;
        cur = cur->sons[pos];
    }
    cur->words+=1;
}

int count_words(node *root, string word){
    int str_sz = word.size();
    node *cur = root;
    for(int i=0; i<str_sz; i++){
        int pos = word[i]-'a';
        if(cur->sons[pos] == NULL){
            return 0;
        }else{
            cur = cur->sons[pos];
        }
    }
    return cur->words;
}

int prefix_count(node *root, string word){
    int str_sz = word.size();
    node *cur = root;
    for(int i=0; i<str_sz; i++){
        int pos = word[i]-'a';
        if(cur->sons[pos] == NULL){
            return 0;
        }else{
            cur = cur->sons[pos];
        }
    }
    return cur->prefix;
}


int main(){
    int N;
    cin>>N;
    node *root = build_trie();
    string str;
    for(int i=0; i<N;i++){
        cin>>str;
        add_word(root, str);
    }
    cout<<"now enter search word"<<endl;
    string key_words;
    cin>>key_words;
    cout<<count_words(root,key_words); 
    return 0;
}

