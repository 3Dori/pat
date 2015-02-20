n1, n2, tag, radix = input().split()
if tag == '1':
    n, other = int(n1, int(radix)), n2
else:
    n, other = int(n2, int(radix)), n1
for r in range(2, 37):
    try:
        if int(other, r) == n:
            print(r)
            break
    except:
        continue
else:
    print('Impossible')
