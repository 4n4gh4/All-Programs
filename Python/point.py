class Point:
    def __init__(self,x,y):
        self.x = x
        self.y=y
    def __add__(self, other):
        return Point(self.x+other.x, self.y+other.y)
    def __sub__(self,other):
        return Point(self.x-other.x, self.x-other.y)
    def display(self):
        print(f"({self.x},{self.y})")


p1 = Point(4,5)
p2 = Point(-4,0)
p3 = p1+p2

p1.display()
p2.display()
p3.display()
    