import sys

n = 1
while True:
    l = sys.stdin.readline().strip()
    if l == "0 0 0":
        break
    print "Triangle #%d" % n
    n+=1
    nums = [int(i) for i in l.split(" ")]
    a,b,c=nums[0],nums[1],nums[2]
    if a*b<0:
        m=a if a>0 else b
        if m>=c:
            print "Impossible."
            print ""
            continue
    if a == 0 or b==0 or c==0:
        print "Impossible."
        print ""
        continue
    if a<0:
        print "a = %.3f" % float((c**2-b**2)**0.5)
        print ""
        continue
    if b<0:
        print "b = %.3f" % float((c**2-a**2)**0.5)
        print ""
        continue
    if c<0:
        print "c = %.3f" % float((a**2+b**2)**0.5)
        print ""
        continue

