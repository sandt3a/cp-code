#!/usr/bin/env python3

from random import *
from string import *

def gen():
    n = randint(2, 10)
    m = randint(1, 200)
    print(n, m)
    for i in range(n):
        print(randint(1, 15))

def gen_tree():
    n = randint(1, 100)
    print(n)
    for i in range(2, n):
        print(i, randint(1, i-1))

if __name__ == '__main__':
    T = 1
    print(T)
    for _ in range(T):
        gen()
