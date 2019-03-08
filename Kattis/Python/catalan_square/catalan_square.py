# https://en.wikipedia.org/wiki/Catalan_number

n = int(input())
c = {0: 1}

for i in range(1, n+1):
    c[i] =  c[i-1] * 2*(2*i+1) // (i+2)  #  The Catalan numbers satisfy the recurrence relations

print(int(c[n]))

