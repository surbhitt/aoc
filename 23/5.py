from collections import defaultdict 

seeds = []
d = defaultdict(list)
fl = False
k = ""
with open('5.in', 'r') as f:
    for l in f.readlines():
        if fl:
            if " " in l:
                d[k].append([int(i) for i in l.split(" ")])
            else:
                fl = False
        else:
            if "-to-" in l:
                fl = True
                k = l.split(" ")[0]
            elif l.startswith("seeds"):
                seeds = [int(val) for val in l.split(': ')[1].split(' ')]


ans = []
## Part 1
# for seed in seeds:
#     print("______________")
#     hold = seed
#     print("we start with seed ", hold)
#     for k in d:
#         print("working with key", k)
#         print(hold)
#         for idx in range(len(d[k])):
#             print(" go the ", idx, " taht is", d[k][idx])
#             if d[k][idx][1] <= hold <= d[k][idx][1]+d[k][idx][2]:
#                 print("it was in the range equal")
#                 hold = d[k][idx][0] + (hold - d[k][idx][1])
#                 print("becomes",hold)
#                 break
#     ans.append(hold)

## Part2
rngs = []
for i in range(0, len(seeds), 2):
    rngs.append([seeds[i], seeds[i+1]])
print(rngs)
for rng in rngs:
    print("this => ", rng)
    for seed in range(rng[0], rng[0]+rng[1]):
        hold = seed
        for k in d:
            print("ke = ", k)
            for idx in range(len(d[k])):
                print("idx ", idx)
                if d[k][idx][1] <= hold <= d[k][idx][1]+d[k][idx][2]:
                    hold = d[k][idx][0] + (hold - d[k][idx][1])
                    break
        ans.append(hold)

print("------------")
print(min(ans))
print("------------")
