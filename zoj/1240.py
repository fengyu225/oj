import sys

c = [chr(ord('A')+i) for i in range(26)]

n = int(sys.stdin.readline().strip())

for i in range(n):
    s = sys.stdin.readline().strip()
    print "String #%d" % (i+1)
    print "".join([c[(ord(j)-ord('A')+1)%26] for j in s])
    print ""
