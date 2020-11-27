def get_average_grades(filename='grades.csv'):
    grades = [[] for _ in range(4)]

    with open(filename) as file:
        for line in file:
            asgn = list(map(float, line.split(',')))

            for i in range(4):
                grades[i].append(asgn[i]) if 0 <= asgn[i] <= 100 else None

    average_grades_list = [sum(x) / len(x) for x in grades]

    return average_grades_list
