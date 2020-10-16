def check_sublist(list1, d1, d2):
    d = d1 * d2
    lista, listb, listc = [], [], []

    for i in list1:
        if i > d:
            lista.append(i)
        elif i < d:
            listb.append(i)
        if i < d1 or i < d2:
            listc.append(i)

    return lista, listb, listc
