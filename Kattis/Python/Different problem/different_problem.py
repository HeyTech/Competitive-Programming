import operator
for _ in range(3):
    print(abs(operator.sub(*map(int, input().split()))))

