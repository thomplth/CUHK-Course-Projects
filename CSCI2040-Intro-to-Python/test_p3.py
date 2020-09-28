import pexpect

ok = 0

child = pexpect.spawn('python3 p3.py')

child.sendline('3.7 3 1')
child.readline()
test1 = child.readline()
current_gpa = float(test1.split()[2])
if current_gpa == 3.7:
	print ('TEST 1 OK!')
	ok += 1
else:
	print ('TEST 1 FAIL.')

test2 = child.readline()
current_major_gpa = float(test2.split()[3])
if current_major_gpa == 3.7:
	print ('TEST 2 OK!')
	ok += 1
else:
	print ('TEST 2 FAIL.')

child.sendline('3.3 2 0')
child.readline()
test3 = child.readline()
current_gpa = float(test3.split()[2])
if current_gpa == 3.54:
	print ('TEST 3 OK!')
	ok += 1
else:
	print ('TEST 3 FAIL.')

test4 = child.readline()
current_major_gpa = float(test4.split()[3])
if current_major_gpa == 3.7:
	print ('TEST 4 OK!')
	ok += 1
else:
	print ('TEST 4 FAIL.')

child.sendline('-2.5 2 0')
child.readline()
test5 = child.readline().rstrip()
if(test5 == 'Wrong input!' or test5.decode() == 'Wrong input!'):
    print ('TEST 5 OK!')
    ok += 1
else:
    print ('TEST 5 FAIL.')

child.sendline('5.1 4 1')
child.readline()
test6 = child.readline().rstrip()
if(test6 == 'Wrong input!' or test6.decode() == 'Wrong input!'):
    print ('TEST 6 OK!')
    ok += 1
else:
    print ('TEST 6 FAIL.')

child.sendline('-1')
child.readline()
test7 = child.readline().rstrip()
if (test7 == 'Program ends.' or test7.decode() == 'Program ends.'):
	print ('TEST 7 OK!')
	ok += 1
else:
	print ('TEST 7 FAIL.')


if ok == 7:
	print ('You pass all the tests!')
