from sklearn import datasets
import numpy as np

#载入数据
from sklearn.datasets import load_boston
boston = datasets.load_boston()
x = boston.data
y = boston.target

#数据分割
from sklearn.model_selection import train_test_split
X_train,X_text,y_train ,y_text = train_test_split(x , y , random_state= 42)

#归一化处理
from sklearn.preprocessing import StandardScaler
standardScaler = StandardScaler()
standardScaler.fit(X_train)
X_train_standard = standardScaler.transform(X_train)
X_text = standardScaler.transform(X_text)

X_standard = standardScaler.transform(x)


def J(theta,x,y):
    try:
        return np.sum((y - x.dot(theta))**2)/len(x)
    except:
        return float('inf')

def dJ(theta , x, y):
    res = np.empty(len(theta))
    res[0] = np.sum(x.dot(theta) - y)
    for i in range(1,len(theta)):
        res[i] = (x.dot(theta) - y).dot(x[:,i])
    return  res * 2 / len(x)

def gradient_descent(x , y , init_theta , eta , iters = 1e4 , epsilon = 1e-4):
    theta = init_theta
    i_iters = 0
    while i_iters < iters:
        gradient = dJ(theta, x, y)
        last_theta = theta
        theta = theta - eta * gradient
        if(abs(J(theta , x , y) - J(last_theta , x , y)) < epsilon):
            break
        i_iters += 1
    return theta

eta = 0.01
X_train_new = np.hstack([np.ones((len(X_train_standard), 1)), X_train_standard])
inti_theta = np.zeros(X_train_new.shape[1])

# 模型训练
theta = gradient_descent(X_train_new, y_train,inti_theta ,eta)

intercept = theta[0]
coef = theta[1:]


def score_(X, y, intercept, coef):
    y_ture = y
    y_predict = X.dot(coef) + intercept
    u = np.sum((y_ture - y_predict) ** 2)
    v = np.sum((y_ture - y_ture.mean()) ** 2)
    R2 = (1 - u / v)
    return R2
Rr = score_(X_text,y_text,intercept,coef)

print("R方为",Rr)