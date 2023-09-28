def activites(s,f,n):
    print("Selected Activities are:")
    i = 0
    print("A{} ".format(i+1))
    for j in range(n):
        if s[j] >= f[i]:
            print("A{} ".format(j+1))
            i = j

s = (1, 2, 3, 2, 4, 5, 6, 8, 7)
f = (4, 5, 6, 8, 6, 7, 7, 12, 9)
n = len(s)
activites(s,f,n)
input()