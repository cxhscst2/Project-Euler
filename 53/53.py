c = [ [0] * 105 for i in range(105)]

c[0][0] = 1
for i in range(1, 101):
    c[i][0] = c[i][i] = 1
    for j in range(1, i):
        c[i][j] = c[i - 1][j - 1] + c[i - 1][j]

ans = 0

for i in range(101):
    for j in range(101):
        if c[i][j] > 1000000:
            ans += 1

print(ans)

