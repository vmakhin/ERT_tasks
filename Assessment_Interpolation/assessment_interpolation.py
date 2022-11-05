import sys
from pykrige.ok import OrdinaryKriging
import numpy as np
import matplotlib.pyplot as plt
import matplotlib.animation as animation
from scipy.interpolate import griddata as gd
import pandas as pds
import pybrain3.datasets as pd
from pybrain3.tools.shortcuts import buildNetwork
from pybrain3.supervised.trainers import BackpropTrainer

top = np.array([[121.39 ,13.51 ,1.494], [126.19 ,12.02 ,1.934], [130.27 ,13.11 ,2.148],
                   [127.42 ,10.09 ,9.155], [126.14 ,15.33 ,2.221],
                   [125.96 ,14.00 ,8.100] ,[123.15 ,10.88 ,2.039] ,[130.50 ,11.18 ,1.916],
                   [129.08 ,15.78 ,3.729], [122.74 ,15.82 ,7.137]])
df=pds.read_csv('coords.csv',header=0)
interpolationmethod = 'cubic'
p = 2
extrapolation_interval_x = 10.0/70
extrapolation_interval_y = 6.0/50


def main():
    extrapolation_spots = get_plane(121.0, 131.0,extrapolation_interval_x, 10.0, 16.0, extrapolation_interval_y)
    fig = plt.figure(figsize=(9, 11))
    ax = fig.add_subplot()
    ax.scatter(extrapolation_spots[:,0],extrapolation_spots[:,1],marker='.', s=10,color='red')
    ax.scatter(df['lon'], df['lat'], marker='*', s=20,color='blue')
    for i, txt in enumerate(df['value']):
        ax.annotate(df['value'][i], (df['lon'][i], df['lat'][i]),color='blue')
    ax.set_xlabel('longitude')
    ax.set_ylabel('latitude')
    ax.set_title('Point Locations')
    title = 'Point Locations'
    plt.savefig('plot_locations.png'.format(title))
 #   plt.show()
    method = 'snaps'
    method = 'contour'
    nearest_analysis(extrapolation_spots,method)
 #   kriging_analysis(extrapolation_spots,method)
    #neural_analysis(extrapolation_spots,method)


# def neural_analysis(extrapolation_spots,method):
#      top_extra = neural_net(extrapolation_spots, top)
#      gridx_top, gridy_top, gridz_top = interpolation(top_extra)
#      plot(top, gridx_top, gridy_top, gridz_top, method=method,
#      title='_top_neural_net', both=True)


# def neural_net(extrapolation_spots, data):
#      net = buildNetwork(2, 10, 1)
#      ds = pd.SupervisedDataSet(2, 1)
#      for row in top:
#          ds.addSample((row[0], row[1]), (row[2],))
#      trainer = BackpropTrainer(net, ds)
#      trainer.trainUntilConvergence()
#
#      new_points = np.zeros((len(extrapolation_spots), 3))
#      new_points[:, 0] = extrapolation_spots[:, 0]
#      new_points[:, 1] = extrapolation_spots[:, 1]
#      for i in range(len(extrapolation_spots)):
#          new_points[i, 2] = net.activate(extrapolation_spots[i, :2])
#      combined = np.concatenate((data, new_points))
#      return combined


def nearest_analysis(extrapolation_spots,method):
    top_extra = extrapolation(top, extrapolation_spots, method='nearest')
    gridx_top, gridy_top, gridz_top = interpolation(top_extra)
    plot(top, gridx_top, gridy_top, gridz_top, method=method,
            title='_top_nearest', both=True)


def kriging_analysis(extrapolation_spots,method):
    top_extra = extrapolation(top, extrapolation_spots, method='kriging')
    gridx_top, gridy_top, gridz_top = interpolation(top_extra)
    plot(top, gridx_top, gridy_top, gridz_top, method=method,
            title='_top_kriging')


def nearest_neighbor_interpolation(data, x, y, p=0.5):
    """
    Nearest Neighbor Weighted Interpolation
    http://paulbourke.net/miscellaneous/interpolation/
    http://en.wikipedia.org/wiki/Inverse_distance_weighting

    :param data: numpy.ndarray
        [[float, float, float], ...]
    :param p: float=0.5
        importance of distant samples
    :return: interpolated data
    """
    n = len(data)
    vals = np.zeros((n, 2), dtype=np.float64)
    distance = lambda x1, x2, y1, y2: (x2 - x1)**2 + (y2 - y1)**2
    for i in range(n):
        vals[i, 0] = data[i, 2] / (distance(data[i, 0], x, data[i, 1], y))**p
        vals[i, 1] = 1          / (distance(data[i, 0], x, data[i, 1], y))**p
    z = np.sum(vals[:, 0]) / np.sum(vals[:, 1])
    return z


def get_plane(xl, xu,i, yl, yu, j):
    xx = np.arange(xl, xu, i)
    yy = np.arange(yl, yu, j)
    extrapolation_spots = np.zeros((len(xx) * len(yy), 2))
    count = 0
    for i in xx:
        for j in yy:
            extrapolation_spots[count, 0] = i
            extrapolation_spots[count, 1] = j
            count += 1
    return extrapolation_spots


def kriging(data, extrapolation_spots):
    """
    https://github.com/bsmurphy/PyKrige

    NOTE: THIS IS NOT MY CODE

    Implementing a kriging algorithm is out of the scope of this homework

    Using a library. See attached paper for kriging explanation.
    """
    # gridx = np.arange(0.0, 200, 10)
    # gridy = np.arange(0.0, 200, 10)
    gridx = extrapolation_spots[:, 0]
    gridy = extrapolation_spots[:, 1]
   # extrapolation_spots[count, 0]
    # Create the ordinary kriging object. Required inputs are the X-coordinates of
    # the data points, the Y-coordinates of the data points, and the Z-values of the
    # data points. If no variogram model is specified, defaults to a linear variogram
    # model. If no variogram model parameters are specified, then the code automatically
    # calculates the parameters by fitting the variogram model to the binned
    # experimental semivariogram. The verbose kwarg controls code talk-back, and
    # the enable_plotting kwarg controls the display of the semivariogram.
    OK = OrdinaryKriging(data[:, 0], data[:, 1], data[:, 2], variogram_model='spherical',
                                 verbose=False, nlags=100)

    # Creates the kriged grid and the variance grid. Allows for kriging on a rectangular
    # grid of points, on a masked rectangular grid of points, or with arbitrary points.
    # (See OrdinaryKriging.__doc__ for more information.)
    z, ss = OK.execute('grid', gridx, gridy)
    return gridx, gridy, z, ss


def extrapolation(data, extrapolation_spots, method='nearest'):
    if method == 'kriging':
        xx, yy, zz, ss = kriging(data, extrapolation_spots)

        new_points = np.zeros((len(yy) * len(zz), 3))
        count = 0
        for i in range(len(xx)):
            for j in range(len(yy)):
                new_points[count, 0] = xx[i]
                new_points[count, 1] = yy[j]
                new_points[count, 2] = zz[i, j]
                count += 1
        combined = np.concatenate((data, new_points))
        return combined

    if method == 'nearest':
        new_points = np.zeros((len(extrapolation_spots), 3))
        new_points[:, 0] = extrapolation_spots[:, 0]
        new_points[:, 1] = extrapolation_spots[:, 1]
        for i in range(len(extrapolation_spots)):
            new_points[i, 2] = nearest_neighbor_interpolation(data,
                                    extrapolation_spots[i, 0],
                                    extrapolation_spots[i, 1], p=p)
        combined = np.concatenate((data, new_points))
        return combined


def interpolation(data):
    extrapolation_interval_x = 10.0 / 70
    extrapolation_interval_y = 6.0 / 50
    gridx, gridy = np.mgrid[121.0:131.0:extrapolation_interval_x, 10.0: 16.0:extrapolation_interval_y]
    gridz = gd(data[:, :2],data[:, 2], (gridx, gridy),
                method=interpolationmethod)
    return gridx, gridy, gridz


def plot(data, gridx, gridy, gridz, method='rotate', title='nearest', both=False):
    def update(i):
        ax.view_init(azim=i)
        return ax,

    if method == 'rotate':
        fig = plt.figure()
        ax = fig.add_axes([0.1, 0.1, 0.8, 0.8], projection='3d')

        ax.plot_wireframe(gridx, gridy, gridz, alpha=0.5)
        ax.scatter(data[:, 0], data[:, 1], data[:, 2], c='red')

        animation.FuncAnimation(fig, update, np.arange(360 * 5), interval=1)
        plt.show()

    elif method== 'snaps':
        fig = plt.figure(figsize=(10, 10))
        angles = [45, 120, 220, 310]

        if both:
            for i in range(4):
                ax = fig.add_subplot(2, 2, i+1, projection='3d')
                ax.plot_wireframe(gridx[0], gridy[0], gridz[0], alpha=0.5)
                ax.plot_wireframe(gridx[1], gridy[1], gridz[1], alpha=0.5)
                ax.scatter(data[:, 0], data[:, 1], data[:, 2], c='red')
                ax.view_init(azim=angles[i])
        else:
            for i in range(4):
                ax = fig.add_subplot(2, 2, i+1, projection='3d')
                ax.plot_wireframe(gridx, gridy, gridz, alpha=0.5)
                ax.scatter(data[:, 0], data[:, 1], data[:, 2], c='red')
                ax.view_init(azim=angles[i])
        plt.savefig('snaps_{}.png'.format(title))

    elif method == 'contour':
        fig1, ax2 = plt.subplots(constrained_layout=True)
        origin = 'lower'
        CS = ax2.contour(gridx, gridy, gridz, 30, cmap=plt.cm.PRGn, origin=origin)
        ax2.clabel(CS, fmt='%2.1f', colors='k', fontsize=7)
        ax2.scatter(gridx, gridy, marker='.', s=10, color='red')
        ax2.scatter(df['lon'], df['lat'], marker='*', s=20, color='blue')
        for i, txt in enumerate(df['value']):
            ax2.annotate(df['value'][i], (df['lon'][i], df['lat'][i]), color='blue')
        ax2.set_xlabel('longitude')
        ax2.set_ylabel('latitude')
        ax2.set_title('Point Locations and Extrapolated Conturs')
        plt.savefig('assessment_interpolation.png'.format(title))
  #      plt.show()


if __name__ == '__main__':
    sys.exit(main())#
