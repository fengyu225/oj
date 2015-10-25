import sys

digits = [
        "0", "1", "2", "3", "4", "5", "6", "7", "8", "9",
        "a", "b", "c", "d", "e", "f", "g", "h", "i", "j"
        ]

def sum(a, b):
    i = 1
    result = ""
    k = 0
    while i<=len(a) or i<=len(b):
        left = digits.index(a[-i]) if i<=len(a) else 0
        right = digits.index(b[-i]) if i<=len(b) else 0
        t = left+right+k
        result = digits[t%20]+result
        k = (t-t%20)/20
        i+=1
    while k>0:
        result = digits[k%20] + result
        k = k/20
    print result


while True:
    l = sys.stdin.readline().strip()
    r = sys.stdin.readline().strip()
    if l != "" and r != "":
        sum(l,r)
    else:
        break
