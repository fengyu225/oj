import sys

n = int(sys.stdin.readline().strip())

for i in range(1, n+1, 1):
    l = sys.stdin.readline().strip().split(" ")
    x=float(l[0])
    y=float(l[1])
    result = int((x*x+y*y)*3.1415*0.5/50.0)+1
    print "Property %d: This property will begin eroding in year %d." % (i,result)
print "END OF OUTPUT."
