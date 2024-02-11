#!/usr/bin/env python3

import sys

def factorize(n):
    # Attempt to find a factorization n=p*q where p<=q and p starts from 2
    p = 2
    while p * p <= n:
        if n % p == 0:
            return p, n // p
        p += 1
    return n, 1

def main(file_path):
    with open(file_path, 'r') as file:
        for line in file:
            n = int(line.strip())
            p, q = factorize(n)
            print(f"{n}={p}*{q}")

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: factors <file>")
        sys.exit(1)
    main(sys.argv[1])
