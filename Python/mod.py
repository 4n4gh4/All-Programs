x = int(input("Enter the base value: "))
y = int(input("Enter the power value: "))
N = int(input("Enter the mod value: "))

res = (x**y)%N
5
print(f"The value of {x} raised to {y} mod {N} is: ", res)