import sys
sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")

from decimal import Decimal

A, B = input().split()

print(int(Decimal(A)*Decimal(B)))