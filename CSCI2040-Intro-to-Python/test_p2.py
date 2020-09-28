import pexpect

ok = 0

child = pexpect.spawn('python3 p2.py')

child.sendline('4')
child.readline()

child.sendline('1')
child.readline()

flag = True
for i in range(1, 5):
	line = child.readline().rstrip()
	if not (line == (4-i)*' '+'1'*i or line.decode() == (4-i)*' '+'1'*i):
		flag = False
if (flag == True):
	print ('TEST 1 OK!')
	ok += 1
else:
	print ('TEST 1 FAIL.')


child.sendline('2')
child.readline()

child.sendline('^_^')
child.readline()

flag = True
for i in [1,2]:
	line = child.readline().rstrip()
	if not (line == (2-i)*'   '+'^_^'*i or line.decode() == (2-i)*'   '+'^_^'*i):
		flag = False
if (flag == True):
	print ('TEST 2 OK!')
	ok += 1
else:
	print ('TEST 2 FAIL.')


child.sendline('-1')
child.readline()
test3 = child.readline().rstrip()
if (test3 == 'Program ends.' or test3.decode() == 'Program ends.'):
	print ('TEST 3 OK!')
	ok += 1
else:
	print ('TEST 3 FAIL.')


if ok == 3:
	print ('You pass all the tests!')
