from fractions import gcd
cases = input()

for i in range(cases):
    num = raw_input()
    flag = False
    print "Ticket #%d:" % (i+1)

    for k in range(1, len(num)):
        left, right = num[:k], num[k:]
        i_left = int(left)
        i_right = int(right)
        if gcd(i_left, i_right) == 1:
            print "%s %s" % (i_left, i_right)
            flag = True
            break
    
    if not flag:
        print "Not relative"
