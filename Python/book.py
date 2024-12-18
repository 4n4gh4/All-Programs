class Book:
    def _init_(self, author, name, edition, year, ISBN):
        self.author=author
        self.name=name
        self.edition=edition
        self.year=year
        
        
        if self.validISBN(ISBN):
            self.ISBN=ISBN
            
        else:
            print("Invalid ISBN")
            self.ISBN=None
            
    def validISBN(self, ISBN):
        sum=0
        temp=ISBN
        
        if 1000000000 <= ISBN <= 9999999999:
            for i in range(1, 11):
                sum += (temp % 10) * i
                temp //= 10

            return sum % 11 == 0
        return False        
    def display(self):
        if self.ISBN is None:
            print("No valid book")
            return
        
        print(f"Author: {self.author}")
        print(f"Name: {self.name}")
        print(f"Edition: {self.edition}")
        print(f"Year: {self.year}")
        print(f"ISBN: {self.ISBN}")
        
print("Welcome to GayLussacs BookClub")
author=input("Enter author name:")
name=input("Enter book name:")
edition=input("Enter book edition:")
year=input("Enter book year:")
ISBN=int(input("Enter book ISBN:"))


book=Book(author, name, edition, year, ISBN)
book.display()