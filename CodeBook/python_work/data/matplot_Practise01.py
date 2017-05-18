import matplotlib.pyplot as plt

import numpy as np

x = np.linspace(0, 4 * np.pi, 100)

plt.subplot(2, 2, 1)
plt.plot(x, np.sin(x), 'r-.')

plt.subplot(2, 2, 2)
plt.plot(x, np.sin(2 * x), 'g-.')

y = np.sin(x)
plt.subplot(2, 2, 3)
plt.scatter(x, y,c='b', s=5,edgecolor='none')

plt.show()


