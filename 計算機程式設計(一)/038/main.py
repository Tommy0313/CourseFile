N, IN = input().split(" ")

relationship = {}


for _ in range(int(N)):
    sentence = input()
    word_one, gold, goto_one, goto_two = sentence.split(" ")
    if(word_one not in relationship):
        relationship[word_one] = {}
    if(goto_one == "0" or goto_two == "0" or gold == "0"):
        relationship[word_one] = 0
    else:
        relationship[word_one][goto_one] = int(gold)
        relationship[word_one][goto_two] = int(gold)
def route_function(word,relationship, have_been_through_words, route, number=0):
    if (relationship[word] == 0):
        gold_list.append(number)
        route_list.append(route)
    elif(len(route.split(" ")) == int(N) or [key for key in relationship[word].keys() if key not in have_been_through_words.split(" ")] == []):
        for temp_key in relationship[word].keys():
            pass
        gold_list.append(number + relationship[word][temp_key])
        route_list.append(route)
    else:
        for new_word in [key for key in relationship[word].keys() if key not in have_been_through_words.split(" ")]:
            route_function(new_word, relationship, have_been_through_words+" "+new_word, route+" "+new_word, number+relationship[word][new_word])


gold_list = []
route_list= []
route_function(IN, relationship, IN, IN)
print(max(gold_list))