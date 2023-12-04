allGames = []
with open('2.in', 'r') as f:
    for line in f.readlines():
        um = {'r':0,'g':0,'b':0}
        game = line.split(': ')[1]
        print(game)
        for c in range(len(game)):
            if game[c].isnumeric():
                num = game[c]
                c+=1
                while game[c].isnumeric():
                    num+=game[c]
                    c+=1
                um[game[c+1]] = max(um[game[c+1]], int(num))
        print("um", um)
        allGames.append(um)
print(allGames)


ans = 0
for i in range(len(allGames)):
    if allGames[i]['r'] <=12  and allGames[i]['g'] <= 13  and allGames[i]['b'] <=14:
        print("this ", i+1)
        ans+=i+1
print("___________", ans)


