def count_alphabet(test_string):
    n = 0
    for i in test_string:
        if i.isalpha():
            n += 1
    return n


def vowel_capitalization(test_string):
    v = ('a', 'e', 'i')
    c = ''
    for i in test_string:
        if i in v:
            c += i.upper()
        else:
            c += i
    return c


def concat(test_string, new_string):
    return test_string + new_string


def search(test_string, sub):
    return test_string.rfind(sub)


def letter_count(test_string):
    count = {}
    alpha = ('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z')
    print(test_string)

    for c in alpha:
        for i in test_string:
            if i == c or i == c.upper():
                if c not in count.keys():
                    count[c] = 0
                count[c] += 1

    return [(k, v) for k, v in count.items()]