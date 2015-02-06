org = input().upper()
brk = input().upper()
s = set()
i = j = 0
while i < len(org) and j < len(brk):
    if org[i] == brk[j]:
        i += 1
        j += 1
    else:
        if org[i] not in s:
            s.add(org[i])
            print(org[i], end='')
        i += 1
