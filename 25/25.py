f = []
f.append(0)
f.append(1)

for i in range(10000):
    f.append(f[-1] + f[-2])


l = 0
for i in range(10000):
    if len(str(f[i])) >= 1000:
        print(i)
        break

