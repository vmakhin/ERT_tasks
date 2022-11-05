from scipy.spatial import Delaunay
import numpy as np
import matplotlib.pyplot as plt

points = np.array([[121.39 ,13.51], [126.19 ,12.02 ], [130.27 ,13.11 ],
                   [127.42 ,10.09 ], [126.14 ,15.33 ],
                   [125.96 ,14.00 ] ,[123.15 ,10.88 ] ,[130.50 ,11.18 ],
                   [129.08 ,15.78 ], [122.74 ,15.82 ]])
z = np.array([1.494, 1.934, 2.148,
                   9.155, 2.221,
                   8.100,2.039,1.916,
                   3.729,7.137])
tri = Delaunay(points)

plt.triplot(points[:,0], points[:,1], tri.simplices)
plt.plot(points[:,0], points[:,1], 'o')
plt.savefig('Delaunay_Triangulation.png'.format('Delaunay Triangulation'))
#plt.show()

# Graphical options for tricontouring
levels = np.arange(z.min(), z.max(), 0.5)
plt.tricontour(points[:,0], points[:,1], z[:], levels=levels)
plt.savefig('Delaunay_Linear_Interpolation.png'.format('Delaunay Linear Interpolation'))
#plt.show()
