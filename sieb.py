#!/usr/bin/env python3

import sys

if __name__ == "__main__":
    n = int(sys.argv[1])

    is_prime = [True for x in range(n)]
    is_prime[0] = False
    is_prime[1] = False
    for x in range(n):
        if is_prime[x]:
            print(x)
            for i in range(2*x, n, x):
                is_prime[i] = False
