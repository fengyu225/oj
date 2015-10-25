import sys

def f(n):
    lst = [float(0)]
    for i in range(n):
        lst.append(lst[-1]+float(1)/float(2*(i+1)))
    return "%.3f" % lst[-1]

print "# Cards  Overhang"
for l in sys.stdin:
    print "{0:>5}".format(l.strip())+"     "+f(int(l.strip()))
