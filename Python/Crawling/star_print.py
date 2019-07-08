aa = input()
a = int(aa)

str1 = ''
str2 = ''

# 윗줄
for i in range(3):
    str1 += '*'+(' '*a)

# 아랫줄
if(a % 2 == 0):
    for i in range(2):
        str2 += (' '*(a-1)) + '*'
        str2 += ' '*(a-1)
else:
    for i in range(2):
        str2 += (' '*a) + '*'
        str2 += ' '*a

print(str1)
print(str2)
