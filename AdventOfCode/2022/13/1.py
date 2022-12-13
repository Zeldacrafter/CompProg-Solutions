import fileinput


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
        if v1 == v2: return 0
        elif v1 < v2: return -1
        else: return 1

res1 = 0
for i, l in enumerate(fileinput.input()):
    if i % 3 == 0:
        arr1 = eval(l)
    elif i % 3 == 1:
        arr2 = eval(l)
        if comp(arr1, arr2) != 1:
            res1 += 1 + i//3
print(res1)
