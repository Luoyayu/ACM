import numpy as np
a = [36, 53, 12, 55, 71, 34]
c = np.cumsum(sorted(a))
print(np.sum(c) - c[0] - len(a) + 1)
