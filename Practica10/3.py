def MinMax(L):
    if len(L) == 1:
        return (L[0], L[0])
    elif len(L) == 2:
        if L[0] <= L[1]:
            return (L[0], L[1])
        else:
            return (L[1], L[0])
    else:
        mid = len(L)/2
        (minL,maxL) = MinMax(L[:int(mid)])
        (minR,maxR) = MinMax(L[int(mid):])
        if minL <= minR:
            min = minL
        else:
            min = minR
        if maxL >= maxR:
            max = maxL
        else:
            max = maxR
        return (min,max)

def principal():
    lista = [3, 10, 32, 100, 4, 76, 45, 32, 17, 12, 1]
    print("Los valores son: ", MinMax(lista))

principal()