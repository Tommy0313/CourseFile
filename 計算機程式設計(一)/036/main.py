N, X, Z = input().split(" ")

relationship = {}

for i in range(1, int(N)+1):
    relationship[str(i)] = {}

break_point_list = input().split(" ")

for _ in range(int(N)):
    sentence = input()
    word_one, word_two = sentence.split(" ")
    if(word_one not in relationship):
        relationship[word_one] = {}
    if (word_two not in relationship):
        relationship[word_two] = {}

    relationship[word_one][word_two] = 1
    relationship[word_two][word_one] = 1


def route_function(word,relationship, have_been_through_words, route, end, break_point, number=0):
    if (word == end and break_point in route):
        route_number_list.append(number)
        route_words_list.append(route)
        route_break_point_list.append(break_point)
    elif ([key for key in relationship[word].keys() if key not in have_been_through_words.split(" ")] == []):
        pass
    else:
        for new_word in [key for key in relationship[word].keys() if key not in have_been_through_words.split(" ")]:
            route_function(new_word, relationship, have_been_through_words+" "+new_word, route+" "+new_word, end, break_point, number+relationship[word][new_word])




route_number_list = []
route_words_list = []
route_break_point_list = []


for break_point in break_point_list:
    route_function(X, relationship, X, X, Z, break_point)

if(route_number_list == []):
    print("NO")
else:
    print(route_number_list)
    print(route_words_list)
    print(route_break_point_list)
    print(route_break_point_list[route_number_list.index(min(route_number_list))])
    print(route_words_list[route_number_list.index(min(route_number_list))])