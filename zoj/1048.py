import sys

result = float(0)

for i in sys.stdin:
    s=float(i.strip())
    result += s

print "$%.2f" % (result/float(12),)
