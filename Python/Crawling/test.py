# aa = input()
# a = int(aa)


def func(a):
    print('*'+(' '*a) + '*'+(' '*a) + '*')
    if(a % 2 == 0):
        print((' '*a)+'*'+(' '*(a-1))+'*'+(' '*a))
    else:
        print((' '*(a-1))+'*'+(' '*a)+'*'+(' '*(a-1)))


for i in range(3, 7):
    func(i)
    print('\n')
