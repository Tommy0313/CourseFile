
def remove_append_list(list, score):
    list.pop(0)
    list.append(score)
    return list

round_score = 0

first_strike = False
second_strike = False
score_list = [0,0]
for _ in range(10):
    first_score = int(input())
    if(score_list[0] == 10):
        score_list[1] = first_score
    else:
        score_list = remove_append_list(score_list,first_score)
    if(first_score != 10):
        second_score = int(input())
        score_list = remove_append_list(score_list, second_score)
        round_score += first_score + second_score
        if (first_strike == True):
            round_score += sum(score_list)
            first_strike = False
        elif (second_strike == True):
            round_score += score_list[0]
            second_strike = False
        if(first_score+second_score == 10):
            second_strike = True
    else:
        if(sum(score_list) != 20):
            score_list = remove_append_list(score_list, 0)
        if (first_strike == True):
            round_score += sum(score_list)
            first_strike = False
        elif (second_strike == True):
            round_score += score_list[0]
            second_strike = False
        second_score = 0
        round_score += first_score
        first_strike = True

if(first_strike == True):
    first_score = int(input())
    score_list = remove_append_list(score_list, first_score)
    second_score = int(input())
    score_list = remove_append_list(score_list, second_score)
    round_score += first_score + second_score

elif(second_strike == True):
    first_score = int(input())
    score_list = [first_score,0]
    round_score += first_score

print(round_score)


