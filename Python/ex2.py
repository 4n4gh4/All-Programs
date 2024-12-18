class CR:
    def __init__(self,nr1=0,dr1=1,ni1=0,di1=1):
        self.nr=nr1
        self.dr=dr1
        self.ni=ni1
        self.di=di1

    def __add__(self,other):
        return CR(self.nr+other.nr,0,0,0)
    
    def __rshift__(self,other):
        print(f"{other.nr}")
    
a=CR(1,2,3,4)
b=CR(56,0,0,0)
c=a+b
c>>c
