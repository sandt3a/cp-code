#!/usr/bin/env python3

from random import *
from string import *

def gen():
    n = randint(500, 500)
    m = randint(250, 250) * 2 - 1
    print(n, m)
    x = ' '.join(str(-randint(1, 10 ** 9)) for _ in range(n))
    print(x)
    v = ' '.join(str(randint(1, 10 ** 9)) for _ in range(m))
    print(v)

def gen_tree():
    n = randint(1, 100)
    print(n)
    for i in range(2, n):
        print(i, randint(1, i-1))

if __name__ == '__main__':
    T = 1
    # print(T)
    for _ in range(T):
        gen()
