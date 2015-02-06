import string
capital2day = {'A': 'MON', 'B': 'TUE', 'C': 'WED', 'D': 'THU', 'E': 'FRI', 'F': 'SAT', 'G': 'SUN'}
digit2min = {str(i): i for i in range(10)}
capital2min = {alpha: ord(alpha) - ord('A') + 10 for alpha in 'ABCDEFGHIJKLMN'}
digit2min.update(capital2min)

str1, str2, str3, str4 = input(), input(), input(), input()
day = False
for i in range(min(len(str1), len(str2))):
    if str1[i] == str2[i]:
        if day:
            if str1[i] in digit2min:
                print("{:02d}:".format(digit2min[str1[i]]), end='')
                break
        else:
            if str1[i] in capital2day:
                print("{} ".format(capital2day[str1[i]]), end='')
                day = True
for i in range(min(len(str3), len(str4))):
    if str3[i] == str4[i]:
        if str3[i] in string.ascii_letters:
            print("{:02d}".format(i))
