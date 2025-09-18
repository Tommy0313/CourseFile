def findLastdna(dna_str, last_dna_list, index):
    for index in range(index+4, len(dna_str)):
        if (dna_str[index:index + len(last_dna_list[0])] in last_dna_list):
            return index
        index += 1

    return -1


head_dna = input()
last_dna_list = input().split()
dna_str = input()

index = 0

dna_output_list = []

for index in range(len(dna_str)):
    if(dna_str[index:index+len(head_dna)] == head_dna):
        find_last_index = findLastdna(dna_str, last_dna_list, index)
        if(find_last_index != -1):
            dna_output_list.append(dna_str[index+len(head_dna):find_last_index])


dna_output_list = sorted(dna_output_list)
dna_output_list = sorted(dna_output_list, key=len)

if(dna_output_list == []):
    print("No gene")
else:
    for str in dna_output_list:
        print(str)