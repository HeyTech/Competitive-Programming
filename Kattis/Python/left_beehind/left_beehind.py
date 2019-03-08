# https://open.kattis.com/problems/leftbeehind
import operator

while 1:
    x, y = map(int, input().split())

    if(not x and not y):
        break

    if operator.eq(operator.add(x, y), 13): print("Never speak again.")
    elif operator.gt(x, y): print("To the convention.")
    elif operator.lt(x, y): print("Left beehind.")
    elif operator.eq(x, y): print("Undecided.")

