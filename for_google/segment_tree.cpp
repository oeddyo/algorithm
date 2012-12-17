#include <iostream>
#include <algorithm>
#include <map>

#define MAXN 45000
using namespace std;

int N;

struct node{
    int left, right, mid;
    int height;
};
node s_tree[MAXN*4];

map<int, int > mapping;
map<int, int > mb;


void build_segtree(int left, int right, int index){
    s_tree[index].left = left;
    s_tree[index].right = right;
    s_tree[index].mid = (left+right)/2;
    s_tree[index].height = 0;
    if(left+1!=right){
        build_segtree(left, s_tree[index].mid, 2*index);
        build_segtree(s_tree[index].mid, right, 2*index+1);
    }
}

void insert(int left, int right,int height, int index){
    //cout<<"insert "<<left<<" "<<right<<" "<<height<<endl;
    if(left==s_tree[index].left && right==s_tree[index].right){
        if(height > s_tree[index].height)
            s_tree[index].height = height;
        return ;
    }
    int mid = s_tree[index].mid;
    if( right<=mid ){
        insert(left, right, height, index*2);
    }else if(left>=mid){
        insert(left, right, height, index*2+1);
    }else{
        insert(left, mid, height, index*2);
        insert(mid, right, height, index*2+1);
    }
}

long long int count(int h,int left, int right, int index){
    if(left>=right){
        return 0;
    }
    if(h>s_tree[index].height){
        s_tree[index].height=h;
    }
    if(s_tree[index].left+1 == s_tree[index].right){
        //cout<<"left right height are "<<" "<<mb[s_tree[index].left]<<" "<<mb[s_tree[index].right]<<" "<<h<<endl;
        //cout<<"left right height "<<s_tree[index].left<<" "<<s_tree[index].right<<" "<<h<<endl;
        return  s_tree[index].height*-(mb[s_tree[index].left] - mb[s_tree[index].right]);
    }
    int mid = s_tree[index].mid;
    //int left_value = count(s_tree[index].height, index*2);
    //int right_value = count(s_tree[index].height, index*2+1);
    long long int ans1 = count(s_tree[index].height, left, mid, index*2);
    long long int ans2 = count(s_tree[index].height, mid, right, index*2+1);
    long long int ans = ans1+ans2;
    return ans;
}

int main(){
    cin>>N;
    //dis-continuify
    int cnt=1;
    int a[MAXN*2];      //
    int h[MAXN];        //height
    int b[MAXN*2];      //keep array
    for(int i=0; i<N;i++){
        cin>>a[i]>>a[i+N]>>h[i];;
        b[i] = a[i];
        b[i+N] = a[i+N];
    }
    sort(a ,a+ N*2);
    int prev = -1;
    for(int i=0; i<2*N; i++){
        if(prev!=a[i]){
            mapping[a[i]] = cnt;
            mb[cnt] = a[i];
            //cout<<"mapping back "<<cnt<<" to "<<mb[cnt]<<endl;
            cnt++;
            prev = a[i];
        }
    }
    //cout<<"cnt is "<<cnt<<endl;
    build_segtree(1,cnt-1, 1); 
    for(int i=0; i<N; i++){
        //cout<<"inserting "<<mapping[b[i]]<<" "<<mapping[b[i+N]]<<" "<<h[i]<<endl<<" "<<b[i]<<" "<<b[i+N]<<endl;;
        insert(mapping[b[i]], mapping[b[i+N]], h[i],1);
    }
    cout<<s_tree[1].left<<" "<<s_tree[1].right<<endl;
    long long int ans = count(-100000, 1,cnt-1, 1);
    cout<<ans<<endl; 
    
    return 0;
}

