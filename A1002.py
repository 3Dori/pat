def input_poly():
    p = {}
    raw = input().split()
    expv = map(int, raw[1::2])
    coev = map(float, raw[2::2])
    for exp, coe in zip(expv, coev):
        p[exp] = coe
    return p

p1 = input_poly()
p2 = input_poly()
p = {}
for exp in p1:
    coesum = p1[exp] + p2.get(exp, 0)
    if round(coesum) != 0:
        p[exp] = '{:.1f}'.format(coesum)
    p2.pop(exp, None)
for exp in p2:
    p[exp] = '{:.1f}'.format(p2[exp])
p = list(p.items())
p.sort(key=lambda t: t[0], reverse=True)
if len(p) == 0:
    print('0', end='')
else:
    print(len(p), end=' ')
    print(' '.join(map(str, sum(p, ()))))
