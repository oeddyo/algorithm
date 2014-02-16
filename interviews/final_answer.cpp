#include <iostream>
#include <string>
using namespace std;

string number;


bool validNumber(string num){
    int sz = num.size();
    if(sz == 0)return true;
    for(int i=0; i<sz; i++){
        if(!(num[i]>='0' && num[i]<='9')){
            return false;   //not valid
        }
    }
    return true;
}

bool isValid(string num){
    if(!validNumber(num)){
        cout<<num<<" is not a valid number"<<endl;
        return false;
    }
    int sz = num.size();
    if(sz == 0)return true;

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
    }
    check_sum += num[sz-1]-'0';
    
    if(check_sum % 10 == 0){
        return true;
    }else{
        return false;
    }
}

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
    if(!validNumber(number)){
        return -1;  // or throw an exception but I forget the syntax
    }

    int current_check_sum = helper(number);
    int tmp = (10 - current_check_sum%10)%10;
    return tmp;
}


int main(){
    //call some function here
    
    //test here
    //
    bool all_passed = true;
    
    if(!isValid("")){
        all_passed = false;
        cout<<"didn't pass empty string"<<endl;
    }

    if(!isValid("0")){
        all_passed = false;
        cout<<"didn't pass 0"<<endl;
    }

    if(!isValid("00000000000000000000000000000000000000000000000")){
        all_passed = false;
        cout<<"didn't pass 00000000000000000000000000000000000000000000000"<<endl;
    }

    if(isValid("01")){
        all_passed = false;
        cout<<"didn't pass 01"<<endl;
    }

    if(isValid("&23")){
        all_passed = false;
        cout<<"didn't pass &23"<<endl;
    }

    if(all_passed){
        cout<<"isValid() passed all testcases!"<<endl;
    }else{
        cout<<"DID NOT PASS TEST CASES"<<endl;
    }

    if(isValid("123455")){
        cout<<"this is valid account number"<<endl;
    }
    
    cout<<"12345 should append "<<getFullAccountNumber("12345")<<endl;

    // run input validation

    return 0;
}

