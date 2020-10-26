def check_sublist(list1, d1, d2):
    lista = [x for x in list1 if x > d1 * d2]
    listb = [y for y in list1 if y < d1 * d2]
    listc = [z for z in list1 if z < d1 or z < d2]

    return lista, listb, listc
