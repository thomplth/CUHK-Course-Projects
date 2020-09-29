# [0]: total grade points, [1]: total units taken, [2]: CGPA
overall, major = [0, 0, 0], [0, 0, 0]
# [0]: grade, [1]: units, [2]: is major or not
course = [0.0, 0, 0]

while 1:
    line = input()

    if line == "-1":
        break

    # check and process inputs
    line = line.split()
    try:
        course[0] = float(line[0])
        course[1] = int(line[1])
        course[2] = int(line[2])
    except ValueError:
        print("Wrong input!")
        continue
    if course[0] < 0 or course[0] >= 5.0:
        print("Wrong input!")
        continue
    if course[1] < 0 or course[2] < 0:
        print("Wrong input!")
        continue

    # save and calculate inputs
    overall[0] += course[0] * course[1]
    overall[1] += course[1]
    overall[2] = overall[0] / overall[1]
    if course[2]:
        major[0] += course[0] * course[1]
        major[1] += course[1]
        major[2] = major[0] / major[1]

    print("Current GPA: {:.2f}".format(overall[2]))
    print("Current major GPA: {:.2f}".format(major[2]))

print("Program ends.")
