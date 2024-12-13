# Today is python! :(
from z3 import *
import fileinput

a, b, want = [], [], []
i = 0
for line in fileinput.input():
    if i % 4 == 0:
        words = line.split(" ");
        x, y = int(words[2][2:-1]), int(words[3][2:-1])
        a += [(x, y)]
    if i % 4 == 1:
        words = line.split(" ");
        x, y = int(words[2][2:-1]), int(words[3][2:-1])
        b += [(x, y)]
    if i % 4 == 2:
        words = line.split(" ");
        x, y = int(words[1][2:-1]), int(words[2][2:-1])
        x += 10000000000000
        y += 10000000000000
        want += [(x, y)]
    i += 1

res = 0
for i in range(len(a)):
    A = Int('A')
    B = Int('B')
    cost = Int('cost')

    opt = Optimize()

    opt.add(A >= 0)
    opt.add(B >= 0)
    opt.add(a[i][0]*A + b[i][0]*B == want[i][0])
    opt.add(a[i][1]*A + b[i][1]*B == want[i][1])
    opt.add(cost == 3*A + B)

    opt.minimize(cost)
    if opt.check() == sat:
        res += opt.model()[cost].as_long()
print(res)
