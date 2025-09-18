
def transferPoint(card):
    pork = ['A', '2', '3', '4', '5', '6', '7', '8', '9', '10', 'J', 'Q', 'K']
    points =[0.5,2,3,4,5,6,7,8,9,10,0.5, 0.5,0.5]
    index = pork.index(card)
    return points[index]
def getSum(x):
    x_pt = transferPoint(x[0])
    y_pt = transferPoint(x[1])
    z_pt = transferPoint(x[2])
    sum = x_pt + y_pt + z_pt
    if sum > 10.5:
        return 0
    else:
        return sum
def compare1(a,b, player, royal):
    if a==0:
        print(royal + ' Win')
    elif a>b:
        print(player + ' Win')
    elif a<b:
        print(royal + ' Win')
    else:
        print('Tie')

def compare2(a,b, player, royal):
    if a>b:
        print(player + ' Win')
    elif a<b:
        print(royal + ' Win')
    else:
        print('Tie')
def main():
    playerName = input()
    playerCard1 = input()
    playerCard2 = input()
    playerCard3 = input()
    royalName = input()
    royalCard1 = input()
    royalCard2 = input()
    royalCard3 = input()
    player = [playerCard1, playerCard2, playerCard3]
    royal = [royalCard1, royalCard2, royalCard3]
    a_pt = getSum(player)
    b_pt = getSum(royal)
    compare1(a_pt, b_pt, playerName, royalName)
    compare2(a_pt, b_pt, playerName, royalName)

main()