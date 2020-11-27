from functools import reduce


def low_freq_word_count(x, str, n, m):
    lenCheck = lambda s: len(s) > n
    freqCheck = lambda s: s.count(str) < m
    occur = lambda acc, s: acc + 1 if s.count(str) > 0 else acc
    l = list(filter(lenCheck, x))
    l = list(filter(freqCheck, l))
    return reduce(occur, l, 0)
