import fileinput
import numpy as np
from functools import cmp_to_key

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

allPkgs = [ [[2]], [[6]] ]
for l in fileinput.input():
    if l != "\n":
        allPkgs += [eval(l)]

allPkgs.sort(key=cmp_to_key(comp))

print((allPkgs.index([[2]]) + 1)*(allPkgs.index([[6]]) + 1))
