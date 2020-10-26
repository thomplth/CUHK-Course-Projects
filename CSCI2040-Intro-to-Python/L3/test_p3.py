import os

if os.path.isfile('p3.py'):
    try:
        from p3 import load_data
        print('Successfully load p3.py and function load_data, we will manually grade the function')
    except:
        print('Cannot load query_following, please check the function name or syntax')
    print()

    try:
        from p3 import query_following
        print('Successfully load p3.py and function query_following')
        test_case = ['Laura Murray', 'Theresa Vale', 'Anne Smelcer']
        expected = [48, 41, 0]
        try:
            print('Testing...')
            answer = list(map(query_following, test_case))
            if answer == expected:
                print('You passed the tests!')
            else:
                print('Wrong answer, you failed some of the tests!')
        except:
            print('Runtime error when testing query, please check your code')
    except:
        print('Cannot load query, please check the function name or syntax')

    print()

    try:
        from p3 import update
        print('Successfully load p3.py and function update, we will manually grade the function')
    except:
        print('Cannot load update, please check the function name or syntax')
    print()

    try:
        from p3 import get_num_of_followers
        print('Successfully load p3.py and function get_num_of_followers')
        test_case = ['Laura Murray', 'Theresa Vale', 'Anne Smelcer']
        expected = [81, 38, 3]

        try:
            print('Testing...')
            answer_dict = get_num_of_followers()
            answer = [answer_dict[name] for name in test_case]
            if answer == expected:
                print('You passed the tests!')
            else:
                print('Wrong result!')
        except:
            print('Runtime error when testing get_num_of_followers, please check your code')
    except:
        print('Cannot load get_num_of_followers, please check the function name or syntax')

else:
    print("Cannot find p3.py, please put p3.py and this test script in the same folder.")
