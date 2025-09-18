N = int(input())

relationship = {}

for i in range(1, N+1):
    relationship[chr(i+ 64)] = {}

while True:
    sentence = input()
    if(sentence == "-1"):
        break
    word_one, word_two, relationship_number = sentence.split(" ")

    relationship[word_one][word_two] = int(relationship_number)


for relationship_layer2 in relationship.keys():
    for relationship_layer3 in relationship[relationship_layer2].keys():
        if(relationship_layer2 in relationship[relationship_layer3].keys()):
            minize = min(relationship[relationship_layer2][relationship_layer3], relationship[relationship_layer3][relationship_layer2])
            relationship[relationship_layer2][relationship_layer3] = minize
            relationship[relationship_layer3][relationship_layer2] = minize


def route_function(word,relationship,have_been_through_words,route='A',number=0):
    if (word == 'B'):
        route_number_list.append(number)
        route_words_list.append(route)
    elif ([key for key in relationship[word].keys() if key not in have_been_through_words.split(" ")] == []):
        pass
    else:
        for new_word in [key for key in relationship[word].keys() if key not in have_been_through_words.split(" ")]:
            route_function(new_word,relationship,have_been_through_words+" "+new_word,route+" "+new_word,number+relationship[word][new_word])




route_number_list = []
route_words_list = []

route_function('A',relationship,'A')

print(len(route_words_list[route_number_list.index(min(route_number_list))].split(" "))-1)
print(route_words_list[route_number_list.index(min(route_number_list))])
print(max(route_number_list))
print(route_words_list[route_number_list.index(max(route_number_list))])

route_list = []
route_number = []