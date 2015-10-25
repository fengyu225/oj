import sys

def digit_r(i):
    r = i
    while r>9:
        x=0
        while r>9:
            x+=r-r/10*10
            r=r/10
        x+=r
        r=x
    return r

while True:
    l = sys.stdin.readline().strip()
    if l=="0":
        break
    print digit_r(int(l))
