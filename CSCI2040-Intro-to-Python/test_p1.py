import pexpect

ok = 0

child = pexpect.spawn('python3 p1.py')

child.sendline('10.15')
child.readline()

child.sendline('33.2')
child.readline()

child.sendline('abc')
child.readline()
test1 = child.readline().rstrip()
if (test1 == 'Your input is not a number!' or test1.decode() == 'Your input is not a number!'):
	print ('TEST 1 OK!')
	ok += 1
else:
	print ('TEST 1 FAIL.')

child.sendline('13.1')
child.readline()

child.sendline('-2.01')
child.readline()
test2 = child.readline()
second_minimum = float(test2.split()[5])

test2 = child.readline()
second_maximum = float(test2.split()[5])

if ((second_maximum == 13.1) & (second_minimum == 10.15)):
	print ('TEST 2 OK!')
	ok += 1
elif ((second_maximum == 13.1) | (second_minimum == 10.15)):
	print("TEST 2 partially OK")
else:
	print ('TEST 2 FAIL.')

if ok == 2:
	print ('You pass all the tests!')
