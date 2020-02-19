s = 1
for i in range(1, 101):
        s = s * i

print(sum((int(i) for i in str(s))))