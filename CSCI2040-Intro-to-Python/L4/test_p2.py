import os

if os.path.isfile('p2.py'):
    try:
        from p2 import low_freq_word_count
        print('Successfully load p2.py')
        test_case = [
            (['python is boring',
            'pythom is a large heavy-bodied snake',
            'The python course is worse taking',
            'The python course is worth taking',
            'python python python python'], 'python', 20, 3),
            (['python is boring',
              'pythom is a large heavy-bodied snake',
              'The python course is worse taking',
              'The python course is worth taking'], 'python', 10, 2),
            (['aba', 'bca', 'baba', 'ab'], 'ab', 2, 1)
                     ]
        expected = [2, 3, 0]
        try:
            print('Testing...')
            answer = [low_freq_word_count(x, str, n, m) for (x, str, n, m) in test_case]
            print(answer)
            print(expected)
            if answer == expected:
                print('You passed all the tests!')
            else:
                print('Wrong answer, you failed some of the tests!')
        except:
            print('Runtime error when testing low_freq_word_count, please check your code')
    except:
        print('Cannot load low_freq_word_count, please check the function name or syntax')
else:
    print("Cannot find p2.py, please put p2.py and this test script in the same folder.")
