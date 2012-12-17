#include <iostream>

using namespace std;
void nothing(int (*p)[10]){
    cout<<"do nothing"<<endl;
}


int main(){


    int a [20][10];
    nothing(a);
    return 0;
}

