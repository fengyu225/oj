import sys

n = int(sys.stdin.readline().strip())

for i in range(n):
    sys.stdin.readline()
    m = int(sys.stdin.readline().strip())
    for j in range(m):
        print " ".join(["".join(reversed(word)) for word in sys.stdin.readline().strip().split(" ")])
    if i<n-1:
        print ""
