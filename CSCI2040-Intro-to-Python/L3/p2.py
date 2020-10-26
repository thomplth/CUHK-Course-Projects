def quicksort(a):
    if not a:
        return []

    p = (0 + len(a) - 1) // 2
    n = a.pop(p)

    low = quicksort([x for x in a if x < n])
    high = quicksort([y for y in a if y >= n])
    result = low + [n] + high

    return result
