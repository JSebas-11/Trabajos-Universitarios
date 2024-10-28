#Formulas para practicar con variables definidas
from math import sqrt, modf

a: int = 3
b: int = 4
c: float = 1/3
d: float = 1/2
m: int = 6
n: float = 1/4

operaciones: dict ={'1' : a**2 - 2*a*b + b**2,
'2' : c**2 +2*c*d + d**2,
'3' : a/c + b/d,
'4' : c/d - m/n + 2,
'5' : a**2/3 - b**2/2 + m**2/6,
'6' : 3/5*c - 1/2*b + 2*d,
'7' : a*b/n + a*c/d - b*d/m,
'8' : sqrt(b) + sqrt(n) + sqrt(6*m),
'9' : c*sqrt(3*a) - d*sqrt(16*b**2) + n*sqrt(8*d),
'10' : m**a/d**b,
'11' : 3*c**2/4 + 4*n**2/m,
'12' : 4*d**2/2 + 16*n**2/2 - 1,
'13' : (a+b)/c - (b+m)/d,
'14' : (b-a)/n + ((m-b)/d) + 5*a,
'15' : (12*c-a)/(2*b) - (16*n-a)/m + 1/d,
'16' : sqrt(4*b) + sqrt(3*a)/3 - sqrt(6*m)/6,
'17' : (sqrt(b)+sqrt(2*d))/2 - (sqrt(3*c)+sqrt(8*d))/4, 
'18' : 2*sqrt(a**2*b**2)/3 + 3*sqrt(2+d**2)/4 - a*sqrt(n)}

print("Resultados: ")
for num, ope in operaciones.items():
    parte_decimal, parte_entera = modf(ope)
    if parte_decimal == 0:
        print(f"\tResultado {num}: {int(ope)}")
    else:
        print(f"\tResultado {num}: {ope}")