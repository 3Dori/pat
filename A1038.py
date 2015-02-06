import functools

@functools.total_ordering
class NumberStr(object):
    def __init__(self, string):
        self.string = string

    def __lt__(self, other):
        return self.string + other.string < other.string + self.string

    def __eq__(self, other):
        return self.string + other.string == other.string + self.string

    def __int__(self):
        return int(self.string)

    def __repr__(self):
        return self.string

numbers = input().split()[1:]
numbers = sorted([NumberStr(number) for number in numbers], reverse=True)
head = True
while numbers:
    smin = numbers.pop()
    if head:
        if int(smin) == 0:
            if not numbers:
                print(0, end="")
        else:
            print(int(smin), end="")
            head = False
    else:
        print(smin, end="")
