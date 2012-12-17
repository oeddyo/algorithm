import random

print 100

for i in range(100):
    N = random.randint(3,7);
    M = random.randint(3,7);
    K = random.randint(4,10);
    print "%d %d %d"%(N,M,K)
    for k in range(K):
        print "%d %d"%(random.randint(1,N),random.randint(1,M));
        


