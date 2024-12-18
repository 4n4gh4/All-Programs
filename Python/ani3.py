class Animal:

    def __init__(self, kinda="blank",familya="blank",namea="blank"):
        self.kind=kinda
        self.family=familya
        self.name=namea

    def display(self):
        print(f"Animal name: {self.name}\nAnimal type: {self.kind}\nAnimal family: {self.family}")
    

name = input("Enter Animal name: ")
kind = input("Enter Animal type: ")
family = input("Enter Animal family: ")

one = Animal(kind,family,name)
two = Animal()

print("The animal details are: ")
one.display()
two.display()
