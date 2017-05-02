#!/usr/bin/env python3

import sys
import random

if (len(sys.argv)) < 3: exit(1)

n = int(sys.argv[1])
f = open(sys.argv[2], mode='w')

f.write(sys.argv[1] + '\n')

for i in range(2*n):
    # add edge from [0, n/2) to [n/2, n]
    start = random.randint(0, n//2 - 1)
    end = random.randint(n//2, n-1)
    f.write("%d %d\n" %(start, end))

f.close()
