import fileinput
import numpy as np


def comp(v1, v2):
    if isinstance(v1, list) and isinstance(v2, list):
        for i in range(max(len(v1), len(v2))):
            if i >= len(v1): return -1
            if i >= len(v2): return 1
            cmp = comp(v1[i], v2[i])
            if cmp != 0: return cmp
        return 0
    elif isinstance(v1, list):
        return comp(v1, [v2])
    elif isinstance(v2, list):
        return comp([v1], v2)
    else:
        return np.sign(v1 - v2)

def lt(v1, v2): return comp(v1, v2) == -1

res1 = 0
inp = list(fileinput.input())
for i in range((len(inp)+2)//3):
    if lt(eval(inp[3*i]), eval(inp[3*i+1])):
        res1 += 1 + i
print(res1)
