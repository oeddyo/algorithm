import sys

nums = []
for line in sys.stdin:
    nums.append(int(line))

N = nums[0]
K = nums[1]


MAXN = 1801
MAXK = 20
dp = [[0 for y in xrange(MAXK)] for x in xrange(MAXN)]

for i in range(1, K):
    dp[0][i] = 1

for i in range(N-1):
    for j in range(K):
        if dp[i][j] != 0:
            if j==0:
                for k in range(1, K):
                    dp[i+1][k] += dp[i][j]
            else:
                for k in range(K):
                    dp[i+1][k] += dp[i][j]

my_ans = 0
for i in range(K):
    my_ans += dp[N-1][i]

print(my_ans)
