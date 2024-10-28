import sympy as sp 

#Ejemplo: 
#   La expresion debe ser ingresada de esta manera: 16*x**2 - 24*x*y + 9*y**2

while True:
    expre = input("0 para salir del programa\nExpresion=> ")
    
    if expre == "0":
        break
    
    symbols = []
    #Bucle para detectar las variables y almacenarlas en lista (symbols)
    for char in expre:    
        #if char in ("a-z"):
        if char.isalpha():
            symbols.append(char)
            
    #Redifinimos symbols y lo convertimos a set para eliminar duplicados
    symbols = set(symbols)
    
    #Concatenamos cada variable con un espacio en blanco y almacenamos en nueva lista
    symbols2 = []
    for symbol in symbols:
        symbols2.append(f"{symbol} ")
        
    #Utilizamos el metodo .join para convertir cada elemento de la lista a string y pasarlo al metodo .symbols
    #Cada symbol se almacenara en 'final_symbol' para asi poder pasar la expresion correctamente al metodo .factor  
    final_symbol = sp.symbols("".join(symbols2))

    result = sp.factor(expre)
    print(f"{result = }\n{"-":-<19}")