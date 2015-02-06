a1 = map(int, input().split())
a2 = map(int, input().split())
n1 = next(a1)
n2 = next(a2)
mid_index = (n1 + n2 - 1) // 2
a1 = list(a1)
a2 = list(a2)
n = 0
i = j = 0
c = 0
while i < n1 and j < n2:
    if a1[i] < a2[j]:
        c = a1[i]
        i += 1
    else:
        c = a2[j]
        j += 1
    if (n == mid_index):
        print(c, end='')
        break
    n += 1
else:
    if i < n1:
        print(a2[mid_index - i - j], end='')
    else:
        print(a1[mid_index - i - j], end='')
