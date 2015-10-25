import sys

s = int(sys.stdin.readline().rstrip())

for i in range(1,s+1,1):
    print "Scenario #%d:" % (i,)
    l = sys.stdin.readline().rstrip().split(" ")
    r = int(l[0])*int(l[1])
    if r%2==0:
        result = r
    else:
        result = r-1+1.41
    print "%.2f" % result
    print ""
