#!/usr/bin/env python
# coding: utf-8

# In[1]:


def recolectarDatos(lista, tam):
    for i in range(tam):
        aux = float(input("Elemento {}: ".format(i)))
        lista.append(aux)


# In[2]:


def promedio(lista):
    suma = 0
    float(suma)
    for i in lista:
        suma += i
    return suma/len(lista)


# In[ ]:


examenes = []
practicas = []
tareas = []
listas = [examenes,practicas,tareas]
elementos = ("Examenes", "Practicas", "Tareas")
print("Bienvenido")
for ciclo in range(3):
    cantidad = int(input("Introduzca la cantidad de {}: ".format(elementos[ciclo])))
    recolectarDatos(listas[ciclo], cantidad)
    
calificacion = float(promedio(examenes))*0.65 + float(promedio(practicas))*0.35
extra = promedio(tareas)
if(extra > 8.5):
    extra = 0.5
elif(extra <= 7):
    extra = -0.5
else:
    extra = 0
    
calificacion += extra
print("La calificación final es: {}".format(calificacion))
    