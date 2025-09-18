N = int(input())

school_condition_dict = {}

for _ in range(N):
    sentence = input()
    school_condition_dict[sentence[:sentence.find(" ")]] = sentence[sentence.find(" ")+1:].split(" ")

N = int(input())

logic_condition_list = []

for _ in range(N):
    sentence = input()
    logic_condition_list.append(sentence)

if (input() == "0"):
    for i in range(len(logic_condition_list)):
        logic_condition_list[i] = logic_condition_list[i].split(" + ")


    for logic_condition in logic_condition_list:
        print_sentence= ""
        for logic in logic_condition:
            for key in school_condition_dict.keys():
                TorF = ([True for x in logic.split(" ") if x not in school_condition_dict[key]])
                if TorF:
                    TorF = False
                else:
                    TorF = True
                if(TorF and (key not in print_sentence.split(" "))):
                    if(print_sentence == ""):
                        print_sentence += key
                    else:
                        print_sentence += " " + key
        for school in school_condition_dict.keys():
            if(school in print_sentence.split(" ")):
                print(school, end=" ")
        print()
else:
    for i in range(len(logic_condition_list)):
        logic_condition_list[i] = logic_condition_list[i].replace(" + "," ")

    for logic_condition in logic_condition_list:
        print_sentence_dict = {}
        for key in school_condition_dict.keys():
            condition_number = 0
            for logic in logic_condition.split(" "):
                if(logic in school_condition_dict[key]):
                    condition_number += 1

            if(condition_number not in print_sentence_dict.keys()):
                print_sentence_dict[condition_number] = key
            else:
                print_sentence_dict[condition_number] += " " + key

        print(print_sentence_dict[max(print_sentence_dict.keys())])
