#!/usr/bin/env python3

class LargeInt():

    def __init__(self, n):
        self.v = []
        self.setint(n)

    def setint(self, n):
        self.v = []
        self.v.append(n%10)
        n //= 10
        while (n > 0):
            self.v.append(n%10)
            n //= 10

    def getint(self):
        integer = 0
        for i, z in enumerate(self.v):
            integer += 10**i * z
        return integer

    def __iadd__(self, x):
        if not isinstance(x, LargeInt):
            x = LargeInt(x)
        while (len(x)>=len(self.v)):
            self.v.append(0)
        for n, x_n in enumerate(x.v):
            self.v[n] += x_n
            if self.v[n] > 10:
                self.v[n+1] = self.v[n]//10
                self.v[n] %= 10
        return self

    def __add__(self, x):
        result = LargeInt(0)
        result.v = self.v[:]
        result += x
        return result

    def __isub__(self, x):
        if not isinstance(x, LargeInt):
            x = LargeInt(x)
        if (len(x)>len(self.v)):
            self.v += [0 for i in range(len(x)-len(self.v))]
        for n, x_n in enumerate(x.v):
            self.v[n] -= x_n
            while self.v[n] < 0:
                self.v[n+1] -= 1
                self.v[n] += 10
        return self

    def __sub__(self, x):
        result = LargeInt(0)
        result.v = self.v[:]
        result += x
        return result

    def __len__(self):
        return len(self.v)

    def __mul__(self, x):
        if not isinstance(x, LargeInt):
            x = LargeInt(x)
        if (len(x)==1 and len(self.v)==1):
            prod = x.v[0] * self.v[0]
            return LargeInt(prod)
        else:
            k = max(len(self.v), len(x.v))//2
            print(k)
            self_1 = LargeInt(0)
            self_2 = LargeInt(0)
            x_1 = LargeInt(0)
            x_2 = LargeInt(0)
            self_1.v = self.v[:k]
            self_2.v = self.v[k:]
            x_1.v = x.v[:k]
            x_2.v = x.v[k:]
            for num in [self_1, self_2, x_1, x_2]:
                if len(num.v) == 0:
                    num.v = [0]
            p = x_1 * self_1
            q = x_2 * self_2
            r = (x_1+x_2)*(self_1+self_2)
            return q.timesten(2*k) + (r-p-q).timesten(k) + q

    def timesten(self, n):
        result = LargeInt(0)
        result.v = self.v[:]
        result.v += [0 for x in range(n)]
        return result

if __name__ == "__main__":
    pass

