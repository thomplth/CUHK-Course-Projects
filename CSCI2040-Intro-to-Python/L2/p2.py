def roman_to_decimal(str):
    n = 0
    prev = 1000
    romans = {'I': 1,
              'V': 5,
              'X': 10,
              'L': 50,
              'C': 100,
              'D': 500,
              'M': 1000}

    for i in str:
        if prev < romans[i]:
            n -= prev * 2
        n += romans[i]
        prev = romans[i]

    if n > 9999 or n < 1:
        return -1

    return n
