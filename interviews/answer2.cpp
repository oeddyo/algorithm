#include <iostream>
#include <string>
using namespace std;

string number;


int helper(string num){
    int sz = num.size();

    bool should_double = true;

    int check_sum = 0;

    for(int i=sz-1; i>=0; i--){
        int cur_digit = num[i]-'0'; //assume all are number digits

        if(should_double==1){
            cur_digit *= 2;
        }
        should_double = !should_double;
        if(cur_digit>=10){
            int tmp = cur_digit%10;
            tmp += (cur_digit/10)%10;
            cur_digit = tmp;
        }
        check_sum += cur_digit;
    }
    
    return check_sum;
}

int getFullAccountNumber(string number){
    int current_check_sum = helper(number);
    //cout<<"current checksum = "<<current_check_sum<<endl;
    int tmp = (10 - current_check_sum%10)%10;
    return tmp;
}


int main(){
    while(cin>>number){
        int ans = getFullAccountNumber(number);
        string whole_number = number;
        number += (ans + '0');
        cout<<"OUTPUT: "<<number<<endl;
    }
    return 0;
}

