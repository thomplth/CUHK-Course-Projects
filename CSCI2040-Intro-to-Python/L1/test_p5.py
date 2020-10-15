import pexpect

ok = 0

child = pexpect.spawn('python3 p5.py')

child.sendline('210')
child.readline()

child.sendline('012')
test1 = child.readline().rstrip()
cmp_str = 'No, you must input a palindrome: 012'
print(test1)
if (test1 == cmp_str or test1.decode() == cmp_str):
	print ('TEST 1 OK!')
	ok += 1
else:
	print ('TEST 1 FAIL.')


child.sendline('Nba A B n')
test2 = child.readline().rstrip()
cmp_str = 'No, you must input a palindrome: Nba A B n'
if (test2 == cmp_str or test2.decode() == cmp_str):
	print ('TEST 2 OK!')
	ok += 1
else:
	print ('TEST 2 FAIL.')

child.sendline('NBa a B N')
test3 = child.readline().rstrip()
cmp_str = 'No, you must input a palindrome: NBa a B N'
if (test3 == cmp_str or test3.decode() == cmp_str):
	print ('TEST 3 OK!')
	ok += 1
else:
	print ('TEST 3 FAIL.')

test4 = child.readline().rstrip()
cmp_str = 'Welcome to the wonderland!'
if (test4 == cmp_str or test4.decode() == cmp_str):
	print ('TEST 4 OK!')
	ok += 1
else:
	print ('TEST 4 FAIL.')

if ok == 4:
	print ('You pass all the tests!')
