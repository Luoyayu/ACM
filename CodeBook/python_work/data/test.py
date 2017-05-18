import matplotlib.pyplot as plt

# 
# squares = [1, 4, 9, 16, 25]
# inputs = [1, 2, 3, 4, 5]
# plt.plot(inputs, squares, linewidth=5)
# plt.xlabel("value", fontsize=14)
# plt.ylabel("square of value", fontsize=14)
# plt.title("the square of value", fontsize=24)
# plt.tick_params(axis='both', labelsize=14)

# 
dot_x = [value for value in range(0, 1001)]
dot_y = [value ** 2 for value in dot_x]

# set range for x,y [x_min, x_max, y_min, y_max]
plt.axis([1, 1000, 1, 555555])

# edgecolors 删除点的轮廓 cmap 颜色映射
plt.scatter(dot_x, dot_y, c=dot_x, edgecolors='none', s=5, cmap=plt.cm.Blues)

# save picture to .png
plt.savefig('square_plot.png', bbox_include='tight')

plt.show()
