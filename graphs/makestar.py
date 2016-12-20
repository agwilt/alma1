#!/usr/bin/env python3

import sys

if (len(sys.argv)) < 3: exit(1)

n = int(sys.argv[1])
f = open(sys.argv[2], mode='w')

f.write(sys.argv[1] + '\n')

for i in range(1, n):
    f.write("%d %d\n" %(0, i%n))

f.close()
