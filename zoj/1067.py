import sys

color_set = []

for i in range(16):
    color_set.append([int(i) for i in sys.stdin.readline().split(" ")])

while True:
    l = sys.stdin.readline().strip()
    if l == "-1 -1 -1":
        break
    m_len = 3*512**2
    closed_p = None
    l = [int(i) for i in l.split(" ")]
    for i in color_set:
        d = (l[0]-i[0])**2+(l[1]-i[1])**2+(l[2]-i[2])**2
        if d<m_len:
            closed_p = i
            m_len = d
    print "(%d,%d,%d) maps to (%d,%d,%d)" % (l[0],l[1],l[2],closed_p[0],closed_p[1],closed_p[2])

