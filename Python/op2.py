class Linear:
    def __init__(self, a,b,c):
        self.a = a
        self.b = b
        self.c=c
    
    def __add__(x,y):
        return Linear(x.a+y.a,x.b+y.b,x.c+y.c)
    def __sub__(x,y):
        return Linear(x.a-y.a,x.b-y.b,x.c-y.c)
    def __mul__(x,y):
        return Linear(x.a*y.a,x.b*y.b,x.c*y.c)
    
print("for 1st equation: ")

a = int(input("Enter coefficient of x: "))
b = int(input("Enter coefficient of y: "))
c = int(input("Enter coefficinet of z: "))

l1 = Linear(a,b,c)

print("for 2nd equation: ")

a = int(input("Enter coefficient of x: "))
b = int(input("Enter coefficient of y: "))
c = int(input("Enter coefficinet of z: "))

l2 = Linear(a,b,c)

choice = 0

while(choice != 5):

    choice = int(input("\nWhat operation to perform?\n1.Print both lines\n2.Add both lines\n3.Subtract both lines\n4.Multiply both lines\n5.Exit menu\n"))


    if choice == 1:
        print(f"{l1.a}x + {l1.b}y + {l1.c} = 0")
        print(f"{l2.a}x + {l2.b}y + {l2.c} = 0")

    elif choice == 2:
        l3 = l1+l2
        print(f"{l3.a}x + {l3.b}y + {l3.c} = 0")
    elif choice == 3:
        l3 = l1-l2
        print(f"{l3.a}x + {l3.b}y + {l3.c} = 0")
    elif choice == 4:
        l3 = l1*l2
        print(f"{l3.a}x + {l3.b}y + {l3.c} = 0")
    elif choice != 5:
        print("Invalid choice. Try again.")