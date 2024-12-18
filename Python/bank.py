class bankaccount:
    def __init__(self, account_number, account_name, balance):
        self.account_number = account_number
        self.account_name = account_name
        self.balance = balance


    def deposit(self,cash):
        balance = cash + balance
        return balance

    def withdraw(self, cash):
        if balance < cash:
            return "Insufficient balance"
        else:
            balance = balance - cash
            return balance
    

print("Welcome to bank!")
a=int(input("Enter  your account number: "))
b=str(input("Enter your account name:"))
c=float(input("Enter current balance: "))

a1 = bankaccount(a,b,c)

choice = 0

while(choice != 4):

    choice = int(input("\nWhat operation to perform?\n1.View account details\n2.Deposit money\n3.Withdraw money\n4.Exit menu\n"))


    if choice == 1:
        print("Account Number: ", a1.account_number)
        print("Account Name: ", a1.account_name)
        print("Account Balance: ", a1.balance)
    elif choice == 2:
        dep=float(input("Enter cash to deposit: "))
        a1.deposit(dep)
    elif choice == 3:
        withd=float(input("Enter cash to withdraw: "))
        a1.withdraw(withd)
    elif choice != 4:
        print("Invalid choice. Try again.")



