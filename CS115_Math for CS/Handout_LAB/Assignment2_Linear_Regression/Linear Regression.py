from __future__ import print_function, unicode_literals, division
import numpy as np
import matplotlib.pyplot as plt

#height (cm)
X = np.array([[147, 150, 153, 158, 163, 165, 168, 170, 173, 175, 178, 180, 183]]).T
#weight (kg)
Y = np.array([[49, 50, 51,  54, 58, 59, 60, 62, 63, 64, 66, 67, 68]]).T


#building X bar
one = np.ones((X.shape[0], 1))
Xbar = np.concatenate((one, X), axis=1)

#Calculate the weights of fitting values
A = np.dot(Xbar.T, Xbar)
b = np.dot(Xbar.T, Y)
A = np.linalg.pinv(A)
w = np.dot(A, b)
print(w.shape)

#preparing the fitting line
w0 = w[0][0]
w1 = w[1][0]
x0 = np.linspace(145, 185, 2)
y0 = w0 + w1*x0
print("X0 = {} and Y0 = {}".format(x0, y0))

#Drawing the fitting line
#visualize
plt.plot(X.T, Y.T, 'ro')            #data
plt.plot(x0, y0, color='blue', linestyle='-' )                    #fitting line
plt.axis([140, 190, 45, 75])
plt.xlabel('Height (cm)')
plt.ylabel('Weight (kg)')
plt.show()

def predict(w, x):
    return w[1][0]*x + w[0][0]

y155 = predict(w, 155)
y160 = predict(w, 160)
print("Height = 155 --> Weight = {:.0f}".format(y155))
print("Height = 160 --> Weight = {:.0f}".format(y160))


# SUPER SHORT WAY USING sklearn lib
from sklearn import linear_model, datasets

    #fit the model with linear regression
regr = linear_model.LinearRegression(fit_intercept=False) #fit intercept = False to calculate the bias
regr.fit(Xbar, Y)
    #print result
print("Result by sklearn = ", regr.coef_)
print("my result = ", w.T)
