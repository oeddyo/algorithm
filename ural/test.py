

import random
import copy




ans = 0
all_len = 0
for kk in range(100):
    s = ""
    for i in range(255):
        if random.randint(0, 1):
            s += '>'
        else:
            s += '<'
    
    print s
    all_len += len(s)
    while True:
        n_s = ""
        indexes = iter(range(len(s) ))
        c_change = 0
        for i in indexes:
            if i+1 < len(s) and (s[i] == '>' and s[i+1] == '<'):
                n_s += '<>'
                c_change += 1
                try:
                    next(indexes)
                except:
                    break
            else:
                n_s += s[i]
        
        if c_change == 0:
            break
        s = copy.deepcopy(n_s)
        ans += c_change

    #print 'ans = ', ans
    #print s


print all_len
print ans
