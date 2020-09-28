key = input("Please input a palindrome: ")
isPalindrome = False

while not isPalindrome:
    key = key.replace(" ", "")
    if len(key) % 2 == 0:
        a = int(len(key) / 2) - 1
        b = a + 1
    else:
        a = int(len(key) / 2) - 1
        b = a + 2

    while a >= 0 and b < len(key):
        if key[a] != key[b]:
            isPalindrome = False
            break
        else:
            isPalindrome = True
        a -= 1
        b += 1

    if not isPalindrome:
        key = input("No, you must input a palindrome: ")

print("Welcome to the wonderland!")