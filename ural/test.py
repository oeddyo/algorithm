

import math

def get_ending_zero(N):
    cnt = 0
    while(N%10==0 and N>0):
        cnt += 1
        N/=10
    return cnt



for n in range(1, 100):
    s = 1 + pow(2, n) + pow(3, n) + pow(4, n)

    #print pow(4, n)%100
    #print 'n = ', n, 'sum = ', s
    print get_ending_zero(s)%100

