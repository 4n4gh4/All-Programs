"""

_gt_
_lt_
_eq_
_add_
_sub_
_mul_

"""



class point:
    def _init_ (addr, x,y):
        addr.x = x
        addr.y = y
    def _add_(addr, other):
        return point(addr.x+other.x, addr.y+other.y)
    def _sub_(addr, other):
        return point(addr.x-other.x, addr.y-other.y)
    def _mul_(addr, other):
        return point(addr.x*other.x, addr.y*other.y)
    def _eq_(addr, other):
        if(addr.x == other.x and addr.y == other.y):
            print("equal")
        else:
            print("not qual")
            
p1 = point(4,9)
p2 = point(7,9)
p3 = p1+p2
p4 = p1-p2
p5 = p1*p2
print(f"{p1 == p2}")
print(f"{p3.x},{p3.y}")
print(f"{p4.x},{p4.y}")
print(f"{p5.x},{p5.y}")