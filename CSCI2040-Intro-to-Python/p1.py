nums = [0, 0, 0, 0]
index = ['first', 'second', 'third', 'fourth']

for i, n in enumerate(index):
    nums[i] = input(f"Please input the {n} number: ")
    while 1:
        try:
            nums[i] = float(nums[i])
            break
        except ValueError:
            print("Your input is not a number!")
            nums[i] = input(f"Please input the {n} number: ")

nums.sort()
print(f"The second smallest value is {nums[1]}")
print(f"The second biggest value is {nums[2]}")
print("Program ends.")
