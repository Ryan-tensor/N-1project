import tensorflow as tf
import numpy as np
xy = np.loadtxt("D:\\traintext\\yeongtong.txt", unpack=True  , dtype='float32')
x_data = xy[0]
y_data = xy[1]

W = tf.Variable(tf.random_uniform([1], -10.0, 10.0))
b = tf.Variable(tf.random_uniform([1], -10.0, 10.0))

X = tf.placeholder(tf.float32)
Y = tf.placeholder(tf.float32)

#가설설정
hypothesis = X * W + b

#costfunction
cost = tf.reduce_mean(tf.square(hypothesis - Y))
#경사하강 알고리즘
descent = W - tf.multiply(0.0001 , tf.reduce_mean(tf.multiply((tf.multiply(W, X) - Y), X)))
#경사하강 알고리즘 업데이트
update = W.assign(descent)

init = tf.initialize_all_variables()

sess = tf.Session()
sess.run(init)

for step in range(200):
    sess.run(update, feed_dict = {X:x_data, Y:y_data})
    print (step, sess.run(cost, feed_dict = {X:x_data, Y:y_data}), sess.run(W),sess.run(b))

