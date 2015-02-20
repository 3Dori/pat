import bisect
tree_size = [2 ** i - 1 for i in range(10)]    # max tree size: 1000
def print_tree(seq):
    if len(seq) == 0:
        return
    elif len(seq) == 1:
        print(seq[0], end='')
    else:
        size_fit = bisect.bisect_left(tree_size, len(seq))
        size = tree_size[size_fit]
        smaller_size = tree_size[size_fit - 1]
        even_smaller = tree_size[size_fit - 2]
        if len(seq) - smaller_size - 1 < even_smaller:
            pos = len(seq) - even_smaller - 1
        else:
            pos = smaller_size
        if pos != len(seq) - 1:
            print('{} '.format(seq[pos]), end='')
            print_tree(seq[:pos])
            print_tree(seq[pos+1:])
        else:
            print('{}'.format(seq[pos]), end='')
            print_tree(seq[:pos])

size = int(input())
seq = sorted(map(int, input().split()))
print_tree(seq)
