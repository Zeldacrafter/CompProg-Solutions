def modinv(a, m):
    # Works because m is prime
    return pow(a, m - 2, m)

lines = list(reversed(open("input").read().splitlines()))
CARDS = 119315717514047
TIMES = 101741582076661

def next(n):

    for line in lines:
        assert(0 <= n < CARDS)
        tokens = line.split()
        if tokens[0] == 'cut':
            k = int(tokens[1])
            n = (n + k + CARDS) % CARDS
    
        elif tokens[1] == 'into':
            n = CARDS - 1 - n

        elif tokens[1] == 'with':
            k = int(tokens[3])
            n = (modinv(k, CARDS) * n) % CARDS

        else:
            assert(False)
        assert(0 <= n < CARDS)
    return n

p0 = 2020
p1 = next(p0)
p2 = next(p1)
incr = ((p1 - p2) * modinv(p0 - p1 + CARDS, CARDS)) % CARDS
offs = (p1-incr*p0) % CARDS
print(incr, offs)

assert((incr*p0 + offs) % CARDS == next(p0))
assert((incr*p1 + offs) % CARDS == next(p1))

res = pow(incr, TIMES, CARDS)*p0 + (pow(incr, TIMES, CARDS) - 1) * modinv(incr - 1, CARDS) * offs
print(res % CARDS)