import os

# Exercise 1

if (os.path.isfile('p2.py')):
    try:
        from p2 import roman_to_decimal
        print('Load p2.py')
        expected = [24, 44, 49, 1324, 1234, 456, 9999]
        test_case = ['XXIV', 'XLIV', 'XLIX', 'MCCCXXIV', 'MCCXXXIV', 'CDLVI', 'MMMMMMMMMCMXCIX']
        try:
            print('Testing...')
            answer = list(map(roman_to_decimal, test_case))
            print(answer)
            if answer == expected:
                print("You passed all the tests!")
            else:
                print("Wrong answer, you failed the tests!")
        except:
            print('Runtime error when testing roman_to_decimal, please check your code!')
    except:
        print('Cannot load roman_to_decimal, please check the function name or syntax.')
else:
    print('Cannot find p2.py, please put p2.py and this test script in the same folder.')
