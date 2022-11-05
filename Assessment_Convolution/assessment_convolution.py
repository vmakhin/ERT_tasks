from scipy import signal
import numpy as np
import matplotlib.pyplot as plt
import pandas as pd

sig0=pd.read_table('convolve_raw_0.dat',header=None)
sig0.rename(columns = {0:'x',1:'y',2:'z',}, inplace = True)
sig1=pd.read_table('convolve_raw_1.dat',header=None)
sig1.rename(columns = {0:'x',1:'y',2:'z',}, inplace = True)
sig2 = signal.convolve2d(sig0, sig1, boundary='symm', mode='same')

fig, (ax_sig0, ax_sig1, ax_sig2) = plt.subplots(3, 1, figsize=(6, 15))
ax_sig0.scatter(sig0['x'],sig0['y'],np.log10(sig0['z']))
ax_sig0.set_title('Signal0')
ax_sig1.scatter(sig1['x'],sig1['y'],np.log10(sig1['z']))
ax_sig1.set_title('Signal1')

ax_sig2.scatter(np.log10(sig2[:,0]),np.log10(sig2[:,1]),np.log10(sig2[:,2]))
ax_sig2.set_title('Signal1 x Signal2 convolution')
plt.savefig('assessment_convolution.png'.format('Signal1 x Signal2 convolution'))
#plt.show()
