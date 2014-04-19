


import random

s = ""
for i in range(50000):
    #s += str(random.randint(1, 20)%10)
    s += str(i)
    if len(s)>=100000:
        break


print s
