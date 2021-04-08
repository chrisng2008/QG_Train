# -*- coding: utf-8 -*-

import numpy as np

# 一元线性回归模型
class SimpleLinearRegression():

    def __init__(self):
        self._a = None
        self._b = None

    def fit (self, x_train, y_train):
        assert x_train.ndim==1, "Sample Linear Regression only solve single feature training data set"
        assert len(x_train)==len(y_train),"the size of the x_train must be eaqul to the size of the y_train"

        y_train_mean=np.mean(y_train)
        x_train_mean=np.mean(x_train)
        # 最小二乘法
        num = 0.0
        d = 0.0
        for x,y in zip(x_train, y_train):
            num += x*y - x*y_train_mean
            d += x**2-x*x_train_mean
        self._a = num/d
        self._b = y_train_mean-self._a*x_train_mean
        return self

    # 对结果进行预测
    def predict(self, x_test):
        assert x_test.ndim == 1 , "Simple Linear Regression can only solve predict feature train training data set"
        assert  self._a is not None and self._b is not None,"must fit before predict"
        return np.array((self._a * x_test + self._b))

    def _predict(self, x_single):
        return self._a * x_single + self._b
        
# 预测多元线性回归模型
class MultipleLinearRegression():

    def __init__(self):
        self._intercept = None
        self._coef = None
        self._theta = None

    def fit_normal(self, X_train, y_train):
        # X_train = np.concatenate((np.ones(len(X_train)), X_train), axis=1)
        X_train = np.hstack([np.ones((len(X_train), 1)),X_train])
        self._theta = np.linalg.inv(X_train.T.dot(X_train)).dot(X_train.T.dot(y_train))
        self._intercept = self._theta[0]
        self._coef = self._theta[1:]

    def __repr__(self):
        return "MultipleLinearRegression()"

    def predict(self,x_test):
        assert self._coef is not None and self._intercept is not None,"must fit before predict"
        x_test = np.hstack([np.ones((len(x_test), 1)), x_test])
        return np.array(x_test.dot(self._theta))

        












