#!/usr/bin/env python
# coding: utf-8

# In[1]:


def funcion():
    lista=[5,6,7,8,9,10,11,12]
    valor1 = 0
    valor2 = 1
    for i in lista:
        valor1 += i
    for j in lista:
        valor2 *= j
    print(valor1)
    print(valor2)
funcion()

