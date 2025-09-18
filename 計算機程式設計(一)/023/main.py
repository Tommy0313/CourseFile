def CardToPoint(card):
    if(card == "A"):
        return 1
    elif(card in ["J", "Q", "K"]):
        return 0.5
    else:
        return int(card)

player_total_point = 0
compute_total_point = 0

player_total_point += CardToPoint(input())
compute_total_point += CardToPoint(input())

iscompute_want_continue = True
isplayer_want_continue = True

while True:
    if isplayer_want_continue:
        player_want_continue = input()
        if(player_want_continue == "Y"):
            isplayer_want_continue = True
        else:
            isplayer_want_continue = False

        if isplayer_want_continue:
            player_total_point += CardToPoint(input())

    if(player_total_point > 10.5):
        print("computer win")
        break


    if(iscompute_want_continue):
        if(player_total_point > compute_total_point or compute_total_point <= 8):
            compute_total_point += CardToPoint(input())

            if (compute_total_point > 10.5):
                print("player win")
                break
            elif(isplayer_want_continue == False and compute_total_point > player_total_point):
                print("computer win")
                break
            elif(compute_total_point == player_total_point):
                print("it's a tie")
                break
            else:
                pass
        elif(isplayer_want_continue == False):
            if (player_total_point > compute_total_point):
                print("player win")
                break
            elif (player_total_point < compute_total_point):
                print("computer win")
                break
            elif (player_total_point == compute_total_point):
                print("it's a tie")
                break
        else:
            iscompute_want_continue = False
            pass

    elif(iscompute_want_continue == False and isplayer_want_continue == False):
        if (player_total_point > compute_total_point):
            print("player win")
            break
        elif (player_total_point < compute_total_point):
            print("computer win")
            break
        elif (player_total_point == compute_total_point):
            print("it's a tie")
            break