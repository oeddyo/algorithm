#include <iostream>

using namespace std;



const int MAXN = 1000001;
//long long int sums_row[MAXN];
//long long int sums_col[MAXN];

long long int cummu_row[MAXN];
long long int cummu_col[MAXN];
const long long int INF = 99999999999999999LL;
int equi_2d_count ( int **A, int N, int M ) {

    for(int i=0; i<N; i++){
        long long int tmp = 0;
        for(int j=0; j<M; j++){
            tmp+=A[i][j];
        }
        if(i>=1){
            cummu_row[i] += cummu_row[i-1]+tmp;
        }else{
            cummu_row[i] = tmp;
        }
    }

    for(int i=0; i<M; i++){
        long long int tmp = 0;
        for(int j=0; j<N; j++){
            tmp+=A[j][i];
        }
        if(i>=1){
            cummu_col[i] += cummu_col[i-1]+tmp;
        }else{
            cummu_col[i] = tmp;
        }
    }

    int ans = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            long long int up_row = INF, down_row=INF, left_col=INF, right_col=INF;
            if(i==0){
                up_row = 0;
            }
            if(i==N-1){
                down_row = 0;
            }
            if(j=0){
                left_col = 0;
            }
            if(j==M-1){
                right_col=0;
            }

            if(up_row==INF){
                up_row = cummu_row[i-1];
            }
            if(down_row==INF){
                down_row = cummu_row[N-1]-cummu_row[i];
            }
            if(left_col==INF){
                left_col = cummu_col[j-1];
            }
            if(right_col==INF){
                right_col = cummu_row[M-1] - cummu_row[j];
            }
            if(up_row==down_row && left_col==right_col){
                ans++;
            }
        }
    }
    return ans;

}



int main(){


return 0;
}

