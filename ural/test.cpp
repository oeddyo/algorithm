//g++ 4.7.2 提交
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main()
{
    int n;
    scanf("%d", &n);
    int a[n+1], count[n+1];
    memset(count, 0, sizeof(count));
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; ++i)            
    {
        int t  = (i-a[i]+n+1)%n;   //for循环里可以直接++count[((i - a[i] + 1) % N + N) % N]
        if (t == 0)
           t = n;
        ++count[t];
    }
    int maxnum = 0, maxindex;
    for (int i = 1; i <= n; ++i)
        if (count[i] > maxnum)
        {
            maxnum = count[i];
            maxindex = i;
        }
    printf("%d\n", maxindex);
    return 0;
}

