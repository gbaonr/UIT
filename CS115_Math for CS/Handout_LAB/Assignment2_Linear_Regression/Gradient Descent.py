import numpy as np
import matplotlib as plt
import math

def grad(x):
    return  2*x + 5*np.cos(x)

def cost(x):
    return x**2 + 5*np.sin(x)

def GD(eta, x0):
    x = [x0]
    for i in range(1000):
        x_new = x[-1] - eta*grad(x[-1])
        x.append(x_new)
        if abs(grad(x[-1])) < 1e-4:
            break
    return (x[-1], i)

(x, it) = GD(0.01, -5)
print("result = {} after {} iterations.".format(x, it))
print("cost = {}".format(grad(x)))