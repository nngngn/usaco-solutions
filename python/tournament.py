
# codeforces "TOURNAMENT"

# https://codeforces.com/contest/878/problem/C

import sys

n, m, k = map(int, input().split())
s = input().strip()

# initialize counts for each nucleotide
counts = {'A': [0] * (n+1), 'C': [0] * (n+1),
          'G': [0] * (n+1), 'T': [0] * (n+1)}

# precompute the counts for each prefix of the string
for i in range(n):
    counts[s[i]][i+1] = 1
    for nt in counts:
        counts[nt][i+1] += counts[nt][i]

# initialize the DP table
dp = [[0] * (m+1) for _ in range(k+1)]
for i in range(1, m+1):
    dp[0][i] = sys.maxsize

# fill in the DP table
for i in range(1, k+1):
    for j in range(1, m+1):
        dp[i][j] = min(dp[i-1][j-1] + counts[s[j-1]][i*n//k] - counts[s[j-1]][(i-1)*n//k], dp[i][j-1])

# print the minimum cost
print(dp[k][m])


# this took way too many braincells and time