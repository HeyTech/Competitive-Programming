# https://open.kattis.com/problems/qaly
s = 0
for _ in range(int(input())):
    q,y = map(float, input().split())
    s += q * y
print("%0.3f" % s)