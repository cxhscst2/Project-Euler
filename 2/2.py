a = [1, 2]
while True:
    a.append(a[-1] + a[-2])
    if a[-1] > 4000000:
        break

print(sum(i for i in a if i % 2 == 0 and i <= 4000000))

