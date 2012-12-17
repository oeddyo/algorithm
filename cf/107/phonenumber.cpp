#include <iostream>
#include <stdio.h>
#include <string>
#define MAX_SIZE 400
using namespace std;

int n;
int n_phonenumber;
string friends[MAX_SIZE];
string phone_number;

int girls[MAX_SIZE];
int pizza[MAX_SIZE];
int taxi[MAX_SIZE];

int judge(string phone){
    string t = "";
    for(int i=0; i<phone.size();i++){
        if(phone[i]<='9' && phone[i]>='0'){
            t+=phone[i];
        }
    }
    if(t.size()==6){
        int eq = 1;
        for(int i=1; i<6; i++){
            if(t[i]!=t[i-1]){
                eq = 0;
                break;
            }
        }
        if(eq==1){
            return 1;
        }
        
        int sm = 1;
        for(int i=1; i<6; i++){
            if(t[i]<t[i-1]){
                continue;
            }else{
                sm = 0;
            }
        }
        if(sm==1){
            return 2;
        }
    }
    return 3;
}


int main(){
    for(int i=0; i<MAX_SIZE; i++){
        taxi[i]=0;
        pizza[i]=0;
        girls[i]=0;
    }
    cin>>n;
    int max_taxi=-1, max_girl=-1, max_pizza = -1;
    for(int i=0; i<n; i++){
        cin>>n_phonenumber>>friends[i]; 
        for(int j = 0; j<n_phonenumber; j++){
            cin>>phone_number;
            int t = judge(phone_number);
            if(t==1){
                taxi[i]++;
            }else if(t==2){
                pizza[i]++;
            }else{
                girls[i]++;
            }
        }
        if(taxi[i]>max_taxi){
            max_taxi = taxi[i];
        }
        if(pizza[i]> max_pizza){
            max_pizza = pizza[i];
        }
        if(girls[i] > max_girl){
            max_girl = girls[i];
        }
    }
    int there_are = 0;
    cout<<"If you want to call a taxi, you should call:";
    for(int i=0; i<n; i++){
        if(taxi[i]==max_taxi){
            if(there_are){
                cout<<",";
            }
            there_are = 1;
            cout<<" "<<friends[i];
        }
    }cout<<"."<<endl;

    there_are = 0;
    cout<<"If you want to order a pizza, you should call:";
    for(int i=0; i<n; i++){
        if(pizza[i]==max_pizza){
            if(there_are){
                cout<<",";
            }
            there_are = 1;
            cout<<" "<<friends[i];
        }
    }cout<<"."<<endl;

    there_are = 0;
    cout<<"If you want to go to a cafe with a wonderful girl, you should call:";
    for(int i=0; i<n; i++){
        if(girls[i]==max_girl){
            if(there_are){
                cout<<",";
            }
            there_are = 1;
            cout<<" "<<friends[i];
        }
    }cout<<"."<<endl;
    return 0;
}
