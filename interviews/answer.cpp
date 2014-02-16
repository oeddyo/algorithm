#include <iostream>
#include <string>
using namespace std;

string number;



bool isValid(string num){
    int sz = num.size();

    bool should_double = true;

    int check_sum = 0;

    for(int i=sz-2; i>=0; i--){
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
        cout<<"adding digit "<<cur_digit<<endl;
    }
    check_sum += num[sz-1]-'0';
    
    cout<<"debug: check sum = "<<check_sum<<endl;
    if(check_sum % 10 == 0){
        return true;
    }else{
        return false;
    }
}

int main(){

        if(isValid("")){
            cout<<"Number "<<number<<" is valid!"<<endl;
        }else{
            cout<<"not valid"<<endl;
        }
    return 0;
}

