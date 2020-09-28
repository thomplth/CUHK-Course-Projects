import getpass

p = getpass.getpass(prompt="Player 1, write down your number secretly: ")

while True:
    try:
        n = int(p)
        if n < -100 or n > 100:
            raise ValueError
        break
    except ValueError:
        p = getpass.getpass(prompt="Player 1, invalid input, write down your number secretly: ")

for count in range(1, 7):
    guess = int(input("Player 2, input your guess: "))
    if guess == n:
        print("You are right after trying for {} times.Program ends.".format(count))
        break
    elif guess < n:
        print("Your guess is too low!")
    elif guess > n:
        print("Your guess is too high!")

    if count == 6:
        print("You have tried 6 times and it is still wrong!The answer is {} and program ends.".format(n))