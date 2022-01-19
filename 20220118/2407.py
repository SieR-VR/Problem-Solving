n, m = input().split()
n = int(n)
m = int(m)

dp = [[0 for _ in range(m+1)] for _ in range(n+1)]

for i in range(0, n+1):
    for j in range(0, m+1):
        if j == 0 or i == j:
            dp[i][j] = 1
        else:
            dp[i][j] = dp[i-1][j-1] + dp[i-1][j]

print(dp[n][m])