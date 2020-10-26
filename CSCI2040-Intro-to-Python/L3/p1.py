def non_unique(list):
    result = []
    appear = {}

    for i in list:
        if i not in appear.keys():
            appear[i] = 0
        appear[i] += 1

    for i in appear.keys():
        if appear[i] > 1:
            result.extend([i, appear[i]])

    return result
