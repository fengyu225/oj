import sys

def print_inverse_table(arr):
    result = [-1 for i in range(len(arr))]
    for idx,i in enumerate(arr):
        result[i-1]=len(filter(lambda x:x>i, arr[:idx]))
    print " ".join([str(i) for i in result])

def print_perm(arr):
    result = []
    result.append(arr.index(0)+1)
    for i in range(1, len(arr)):
        for idx,j in enumerate(arr):
            c = len(filter(lambda x:x>idx+1, result))
            if c == j and idx+1 not in result:
                result.append(idx+1)
                break
    print " ".join([str(i) for i in result])


while True:
    l = sys.stdin.readline().strip()
    if l=="0":
        break
    n = int(l)
    l = sys.stdin.readline().strip().split(" ")
    mode = l[0]
    arr = [int(i) for i in l[1:]]
    if mode == "P":
        print_inverse_table(arr)
    if mode == "I":
        print_perm(arr)
