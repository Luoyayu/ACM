import matplotlib.pyplot as plt

input_values = [1, 2, 3, 5, 6]

squares = [1, 4, 9, 25, 36]

plt.title('Square Numbers', fontsize=24)
plt.xlabel("value", fontsize=14)
plt.ylabel("square of Value", fontsize=14)

plt.tick_params(axis='both', which='majory', labelsize=14)

plt.scatter(2, 4, s=20)
plt.show()
