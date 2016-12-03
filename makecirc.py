#!/usr/bin/env python3

import sys

if (len(sys.argv)) < 3: exit(1)

n = int(sys.argv[1])
f = open(sys.argv[2], mode='w')

f.write(sys.argv[1] + '\n')

for i in range(n):
    f.write("%d %d\n" %(i, (i+1)%n))

f.close()
