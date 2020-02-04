F = open('230.txt', 'w')

s = [" 1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679",
     " 8214808651328230664709384460955058223172535940812848111745028410270193852110555964462294895493038196"]

q = []
for i in range(18):
    q.append((127 + 19 * i) * pow(7, i))


f = []
f.append(100)
f.append(100)

for i in range(3, 100):
    f.append(f[-1] + f[-2])

p = [0 for i in range(20)]

for i in range(18):
    for j in range(100):
        if f[j] >= q[i]:
            p[i] = j
            break

ans = ""

for i in range(18):
    x, y = p[i], q[i]

    while x > 1:
        if (y > f[x - 2]):
            y -= f[x - 2]
            x -= 1
        else:
            x -= 2


    ans = ans + str(s[x][y])

F.write(ans[::-1] + '\n')
F.close()


















