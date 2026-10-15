#!/usr/bin/env python3

from random import *
from string import *

def gen():
    n = randint(1, 2000)
    print(n)
    for i in range(n):
        print(randint(1, n+1),end='\n' if i == n - 1 else ' ')

def gen_tree():
    n = randint(1, 100)
    print(n)
    for i in range(2, n):
        print(i, randint(1, i-1))

if __name__ == '__main__':
    T = 10
    print(T)
    for _ in range(T):
        gen()
