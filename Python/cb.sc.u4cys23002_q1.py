class Stack:
    def __init__(self, max_size):
        self.max_size = max_size
        self.stack = []

    def push(self, item):
        if self.is_full():
            print("Stack is full. Cannot push item.")
            return
        self.stack.append(item)
        print(f"Booked ticket for Passenger ID: {item}")

    def pop(self):
        if self.is_empty():
            print("Stack is empty! Cannot pop item.")
            return None
        item = self.stack.pop()
        print(f"Cancelled ticket for Passenger ID: {item}")
        return item

    def is_empty(self):
        return len(self.stack) == 0

    def is_full(self):
        return len(self.stack) == self.max_size

    def print_stack(self):
        if self.is_empty():
            print("Stack is empty.")
        else:
            print("Allocated seats (Passenger IDs):", self.stack)

    def stack_length(self):
        return len(self.stack)

# Application of Stack in sample train ticket booking system

# Available seats in train = 10
stack = Stack(10)

print("Welcome to Online Train Ticket booking system!")

choice = -1

while choice != 0:
    print("\nWhat operation to perform?")
    print("1. Check seats Available")
    print("2. Book Ticket")
    print("3. Cancel Ticket")
    print("4. Print Allocated seats")
    print("0. Exit")

    choice = int(input("Enter your choice: "))

    if choice == 1:
        print("Total seats available: ", 10 - stack.stack_length())
    elif choice == 2:
        x = int(input("Enter passenger ID: "))
        stack.push(x)
    elif choice == 3:
        if not stack.is_empty():
            stack.pop()
        else:
            print("No tickets to cancel.")
    elif choice == 4:
        stack.print_stack()
    elif choice == 0:
        print("Exiting the system.")
    else:
        print("Invalid choice. Try again.")