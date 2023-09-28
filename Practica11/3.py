def multiplicar(a,b):
    if b == 0:
        return 0
    elif b > 0:
        return a + multiplicar(a,b-1)
    else: 
        return -multiplicar(a, -b)
    
a = int(input())
b = int(input())
print("Resultado =",multiplicar(a,b))