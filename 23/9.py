from functools import reduce
ans = 0
with open('9.in') as f:
    for l in f.readlines():
        print("-----")
        ar = [int(x) for x in l.split()]
        endvals = [ar[0]]
        # endvals = [ar[-1]]
        while True:
            tmp = []
            for a in range(len(ar)-1):
                tmp.append(ar[a+1]-ar[a])
            print(tmp)
            # didnt work
            # if tmp[0] + (tmp[1]-tmp[0])*(len(tmp)-1) == tmp[-1]:
            #     ans += sum(endvals) + tmp[-1] + (tmp[1] - tmp[0])
            #     break
            if all(j == 0 for j in tmp):
                # ans += sum(endvals)
                ans+=reduce(lambda x,y: y-x, endvals[::-1], 0)
                break
            # endvals.append(tmp[-1])
            endvals.append(tmp[0])
            # part 2

            ar = tmp
        print("end - ", endvals)
print(ans)



