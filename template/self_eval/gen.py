#!/usr/bin/env python3

from random import *
from string import *

def gen():
    n = randint(1, 200)
    m = randint(1, n)
    print(n, m)
    s = ''.join(choice(ascii_lowercase) for _ in range(n))
    print(s)

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
