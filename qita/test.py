import matplotlib.pyplot as plt
import numpy as np
from sklearn.cluster import DBSCAN
from sklearn.datasets import make_moons

X, y = make_moons(n_samples=1000, noise=0.05, random_state=42)
print(X[:10], X.shape)
print(y[:10], y.shape)
plt.Figure(figsize=(10, 15))
plt.plot(X[:, 0], X[:, 1], 'r.')
plt.show()

dbscan = DBSCAN(eps=0.02, min_samples=5)
dbscan.fit(X)
print(dbscan.labels_[:10])
print(dbscan.core_sample_indices_[:10])


def plot_dbscan(dbscan, X, size, show_core_samples=True):
    core_mask = np.zeros_like(dbscan.labels_, dtype=bool)
    core_mask[dbscan.core_sample_indices_] = True
    anomalies_mask = dbscan.labels_ == -1
    non_core_mask = ~(core_mask | anomalies_mask)

    cores = dbscan.components_
    anomalies = X[anomalies_mask]
    non_cores = X[non_core_mask]

    plt.scatter(cores[:, 0], cores[:, 1], c=dbscan.labels_[core_mask], s=size, marker="o", cmap="Paired")
    plt.scatter(cores[:, 0], cores[:, 1], s=20, marker="*", c=dbscan.labels_[core_mask])
    plt.scatter(anomalies[:, 0], anomalies[:, 1], c="r", s=100, marker="x")
    plt.scatter(non_cores[:, 0], non_cores[:, 1], c=dbscan.labels_[non_core_mask], marker=".")
    plt.show()


plot_dbscan(dbscan, X, size=100)
