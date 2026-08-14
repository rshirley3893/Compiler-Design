import numpy as np
scores=np.array([78,85,92,67,88,95,73])
print(scores.sum())
print(scores.mean())
print(scores.min())
print(scores.max())
print(scores.std())
a=np.cumsum(scores)
print(a)
