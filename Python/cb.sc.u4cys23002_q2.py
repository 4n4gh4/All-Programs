class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def print_point(self):
        return f"({self.x}, {self.y})"

    def __eq__(self, other):
        if isinstance(other, Point):
            return self.x == other.x and self.y == other.y
        return False


class Line:
    def __init__(self, point1: Point, point2: Point):
        self.point1 = point1
        self.point2 = point2

    def print_line(self):
        return f"Line: {self.point1.print_point()} to {self.point2.print_point()}"

    def __add__(self, other):
        if self.point2 == other.point1:
            return Line(self.point1, other.point2)
        else:
            print("Cannot be concatenated")
            return None  # Return None if lines cannot be concatenated

    def __str__(self):
        return self.print_line()


point_start = Point(1, 2)
point_end = Point(3, 4)

line1 = Line(point_start, point_end)
line2 = Line(Point(3, 4), Point(5, 6))
line3 = Line(Point(5, 6), Point(20, 30))

print(line1)
print(line2)

concatenated_line1 = line1 + line2
concatenated_line2 = line2 + line3

if concatenated_line1:
    print("Sum of Line 1 and 2: ")
    print(concatenated_line1)

if concatenated_line2:
    print("Sum of Line 2 and 3: ")
    print(concatenated_line2)