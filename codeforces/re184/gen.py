#!/usr/bin/env python3

from random import *
from string import *

def gen():
    n = randint(1, 10)
    print(n)
    for i in range(n):
        print(randint(0, 100), end=' ')
    print()
    for i in range(n):
        print(randint(0, 100), end=' ')
    print()
    for i in range(n):
        print(randint(0, 100), end=' ')
    print()

if __name__ == '__main__':
    T = 1
    print(T)
    for _ in range(T):
        gen()
