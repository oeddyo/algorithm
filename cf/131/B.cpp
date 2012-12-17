#include <iostream>

using namespace std;

const int MAXN = 100001;
const int INF = 999999999;
int N;
int data[MAXN];
int mycount[10];
void print(){
    bool prefix = false;
    for(int i=9; i>0; i--){
        while(mycount[i]>0){
            cout<<i;
            mycount[i]--;
            prefix = true;
        }
    }
    if(prefix){
        while(mycount[0]>0){
            cout<<0;
            mycount[0]--;
        }
    }else{
        cout<<0;
    }
    cout<<endl;
}

void work(){
    if(mycount[0]<=0){
        cout<<-1<<endl;
        return ;
    }

    int all_sum = 0;
    for(int i=0; i<N; i++){
        all_sum += data[i];
    }
    //cout<<"all sum is "<<all_sum<<endl;
    if(all_sum <= 2){
        cout<<"0"<<endl;
        return ;
    }
    
    if(all_sum%3==0){
        print();
        return ;
    }

    for(int i=1; i<10; i++){
        //eliminate a single number
        if( mycount[i]>0 && (all_sum - i) % 3==0){
            mycount[i]-=1;
            print();
            return ;
        }
    }
    int rec_a=-1, rec_b = -1;;

    for(int i=9; i>=1; i--){
        for(int j=9; j>=i; j--){
            if(i==j && mycount[i]>=2 && (all_sum -2*i)%3==0){
                    rec_a = i, rec_b = i;
            }else if(i!=j && mycount[i]>0 && mycount[j]>0 && (all_sum - i-j)%3==0){
                    rec_a = min(i,j);
                    rec_b = max(i,j);
            }
        }
    }
    //cout<<rec_a<<" "<<rec_b<<endl;
/*

    for(int i=1; i<10; i++){
        for(int j=1; j<10; j++){
            if(i==j && mycount[i]>=2 && (all_sum -2*i)%3==0){
                mycount[i]-=2;
                if( i<rec_min){
                    rec_min = i;
                    rec_a = i, rec_b = i;
                }
                //print();
            }else if(i!=j && mycount[i]>0 && mycount[j]>0 && (all_sum - i-j)%3==0){
                if( max(i,j) < rec_min ){
                    rec_min = max(i,j);
                    rec_a = min(i,j);
                    rec_b = max(i,j);
                }else if(max(i,j) == rec_min && i+j<rec_a+rec_b){
                    rec_a = i;
                    rec_b = j;
                }
            }
        }
    }
    */
    //cout<<rec_a<<" "<<rec_b<<endl;
    if(rec_a ==-1){
        cout<<-1<<endl;
    }else{
        mycount[rec_a]-=1;
        mycount[rec_b]-=1;
        print();
    }


    //cout<<-1<<endl;

}


int main(){
    cin>>N;
    for(int i=0; i<N; i++){
        cin>>data[i];
        mycount[data[i]]++;
    }
    work();

    return 0;
}

