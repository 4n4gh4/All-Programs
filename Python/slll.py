class Node:
    def __init__(self, value):
        self.value= value
        self.next= None

class SLL:
    def __init__(self):
        self.head = None

    def isempty(self):
        current = self.head
        if current:
            return False
        else:
            return True

    def add_last(self, value):
        new_node = Node(value)
        current = self.head
        if not current:
            self.head = new_node
            return
        
        while current:
            if current.next == None:
                current.next = new_node
                return
            current = current.next

    def find(self,value):
        search = Node(value)
        current = self.head

        position = 0
        while current:
            position += 1
            current = current.next
            if current == search:
                break
        
        if position == 0:
            print("Element not found")
        else:
            print("Element found in position {}".format(position))
        
    def ins_after(self, value, x):
        new_node = Node(value)
        current = self.head

        while current:
            if current.value == x:
                new_node.next = current.next
                current.next = new_node
                break
        current = current.next

    def int_after_pos(self, value, x):
        new_node = Node(value)
        current = self.head
        position = 0

        while current:
            position +=1
            if position == x:
                new_node.next = current.next
                current.next = new_node
                break
            current = current.next

    def del_first(self):

        if self.isempty():
            print("Empty list")
        else:
            current = self.head
            self.head = current.next


        




            

    def add_first(self, value):
        new_node = Node(value)
        self.head = new_node

    def display(self):
        current = self.head
        while current:
            print(current.value, end=" -> ")
            current = current.next
        print("None")


x = SLL()
x.add_first(450)
x.add_last(5)
x.display()

x.find(5)

x.ins_after(4,450)
x.display()

x.int_after_pos(36,2)
x.display()

x.del_first()
x.display()

print("Linked list is empty: {}".format(x.isempty()))
        
