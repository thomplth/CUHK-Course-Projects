def quicksort(a):
    if not a:
        return []

    p = a.pop((0 + len(a) - 1) // 2)

    low = quicksort([x for x in a if x < p])
    high = quicksort([y for y in a if y >= p])
    result = low + [p] + high

    return result

# quicksort = lambda a: quicksort([x for x in a[1:] if x <= a[0]]) + [a[0]] + quicksort([x for x in a if x > a[0]]) if a else []