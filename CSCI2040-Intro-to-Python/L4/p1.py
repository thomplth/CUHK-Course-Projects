a = list(range(1, 11))
l1 = list(map(lambda x: int(x ** 0.5), a))
l2 = list(map(lambda x: x + 1, a))
l3 = [x for x in a if x <= 7]
l4 = [x ** 2 for x in a if x % 2 != 0]
