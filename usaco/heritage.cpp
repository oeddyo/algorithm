/*
ID: xieke.b1
PROB: heritage
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>
#include <stack>
#include <vector>
#include <string.h>
#include <queue>


using namespace std;
ifstream fin("heritage.in");
ofstream fout("heritage.out");

int INF = 999999999;
const int MAXN = 25;

string in_ord, pre_ord;

typedef struct _node{
    char c;
    _node *left, *right;
}node;


node *all_root;

node* build_tree( int in_left, int in_right, int pre_left, int pre_right){
    if(in_left==in_right){
        node *t = new node();
        t->c = in_ord[in_left];
        t->left = NULL;
        t->right = NULL;
        cout<<"building "<<t->c<<endl;
        return t;
    }
    char sp = pre_ord[pre_left];
    int pos = -1;
    for(int i=in_left; i<=in_right; i++){
        if(sp==in_ord[i]){
            pos = i;break;
        }
    }
    int lc_p_left = pre_left+1;
    int lc_p_right = pre_left+pos-in_left;
    int rc_p_left = lc_p_right+1;
    int rc_p_right = pre_right;
    
    cout<<"at "<<sp<<endl;
    cout<<lc_p_left<<"->"<<lc_p_right<<" and "<<rc_p_left<<"->"<<rc_p_right<<endl;

    node *root = new node();
    root->c = sp;
    root->left = NULL;
    root->right = NULL;
    
    if(lc_p_left<=lc_p_right)
        root->left = build_tree( in_left, pos-1, lc_p_left, lc_p_right);
    if(rc_p_left<=rc_p_right)
        root->right = build_tree(pos+1, in_right, rc_p_left, rc_p_right);
    return root;
}

void post(node *r){
    if(r->left!=NULL){
        post(r->left);
    }
    if(r->right!=NULL){
        post(r->right);
    }
    fout<<r->c;
}


void work(){
    all_root = build_tree( 0, in_ord.size()-1, 0, pre_ord.size()-1);
    post(all_root);
    fout<<endl;
}


int main(){
    fin>>in_ord;
    fin>>pre_ord;
    work();
    
    
    return 0;
}

