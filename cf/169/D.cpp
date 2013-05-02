#include <iostream>

using namespace std;

typedef long long int ll;

ll my_left, my_right;

bool in_range(ll next){
    if(next>=my_left && next<=my_right){
        return true;
    }
    return false;
}


int main(){
    cin>>my_left>>my_right;


    ll up=0, down=0;

    for(int i=63; i>=0; i--){
        ll next_up = (1<<i)|up;
        ll next_down = (0<<i)|down;
        if(in_range(next_up) && in_range(next_down)){
            cout<<"at "<<i<<" 1 0"<<endl;
            up = next_up;
            down = next_down;
        }else if(in_range(next_up) && !in_range(next_down)){
            up = (0<<i)|up;
            down = (1<<i)|down;
        }else if(!in_range(next_up) && in_range(next_down)){
            up = (0<<i)|up;
            down = (1<<i)|down;
        }else{
            up = (0<<i)|up;
            down = (0<<i)|down;
        }
    }
    cout<<"up = "<<up<<endl;
    cout<<"do = "<<down<<endl;
    cout<<(up^down)<<endl;


    return 0;
}

