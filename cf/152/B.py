import sys
import math

def digit(num):
    cnt = 0
    while(num):
        cnt += 1
        num/=10
    return cnt

def work():
    n = int(raw_input())
    print type(pow(10,100))
    low = (pow(10, n-1))/210
    high = (pow(10,n) -1 )/210
    



work()

