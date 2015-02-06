num, shift = map(lambda string: int(string), input().split())
seq = input().split()
shift %= num
print(" ".join(seq[len(seq) - shift:] + seq[:len(seq) - shift]))
