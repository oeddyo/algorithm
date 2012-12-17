#include <iostream>
#include <cmath>
#include <string.h>
#include <stdio.h>

using namespace std;

int T;

char buffer[1000];
int main(){
    cin>>T;
    int a,b,c,d;
    int blank = 0;
    while(T--){
        if(blank!=0){
            //cout<<endl;
            printf("\n");
        }
        blank++;
        cin>>a>>b;
        cin.getline(buffer, 256);
        double sum = 0;
        while(cin.getline(buffer, 256)){
            if(strlen(buffer)==0){    
                break;
            }
            sscanf(buffer, "%d %d %d %d",&a,&b,&c,&d);
            sum += sqrt((a-c)*(a-c)+(b-d)*(b-d))/1000;
        }
        sum*=2;
        double ans = sum/20;
        int hr = (int)(ans);
        double left = (ans - hr)*60;
        int minutes = (int)(left);
        left -= minutes;
        if(left>0.5){
            minutes+=1;
        }
        if(minutes==60){
            hr+=1;
            minutes-=60;
        }
        printf("%d:%02d\n",hr, minutes);
        //cout<<hr<<":"<<minutes<<endl;
    }

    return 0;
}

