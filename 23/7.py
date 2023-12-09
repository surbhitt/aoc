from collections import defaultdict, Counter

# part1 'J'=10
map = {'A': 13, 'K': 12, 'Q': 11, 'T': 9, '9': 8, '8': 7, '7': 6, '6': 5, '5': 4, '4': 3, '3': 2, '2' :1, 'J': 0};

rules = {7:'5', 6:'41', 5:'32', 4:'311', 3:'221', 2:'2111', 1:'11111'}

group = defaultdict(list)

def cardCounter(cards) :
    # part1 
    # return sorted(cardCounter(list(Counter(cards).values())), reverse=True)
    # part2
    count = Counter(cards)
    counted = []
    cnt_j = 0
    for card in count:
        if card == "J":
            cnt_j = count[card]
        else:
            counted.append(count[card])
    counted = sorted(counted, reverse=True)
    print("card ", cards, " ", counted)
    if counted: counted[0] += cnt_j
    else: counted = [cnt_j]
    return counted

def value(cards: str) -> tuple:
    l = []
    for c in cards:
        l.append(map[c])
    return tuple(l)

with open('7.in', 'r') as f:
    for l in f.readlines():
        cards, bet = l.split(' ')
        rep = "".join([str(i) for i in cardCounter(cards)])
        for rule in rules:
            if rules[rule] == rep:
                group[rule].append((value(cards), cards, int(bet.replace('\n', ''))))
                break
group = sorted(group.items(), key=lambda x: x[0])
group = [x[1] for x in group]

inc = 1
ans = 0
for g in group:
    g.sort()
    for _, _, bet in g:
        print(bet, inc)
        ans+=bet*inc
        inc+=1;

print(ans)

# write a sort function 
# create a decorated array with the first elem as a tuple of cards value
# then sort
    
