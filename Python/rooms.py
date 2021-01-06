def rooms():
    n = int(input())
    staircases = input()
    counter = 1
    staircases_indexes = []
    for i in staircases:
        if i == "1":
            if counter <= int(n / 2):
                staircases_indexes.append(n - counter + 1)
            else:
                staircases_indexes.append(counter)
        counter += 1

    if staircases_indexes == []:
        print(n)
    else:
        staircase_to_be_considered = max(staircases_indexes)
        print(2 * staircase_to_be_considered)


test_cases = int(input())
while test_cases:
    rooms()
    test_cases -= 1
