import numpy as np
import matplotlib.pyplot as plt

eV = 1.60217662e-19
Bohr_radius = 5.29e-11
hbar = 1.054571817e-34
m_e = 9.1093837e-31
pi = 3.14159265359
nor = Bohr_radius / hbar * np.sqrt(m_e * eV)

V = -13.6 * eV / eV
a = 20 * Bohr_radius / Bohr_radius

def f_even(E):
    tmp1 = np.sqrt(-E);
    tmp2 = np.sqrt(E - V);
    tmp3 = a * np.sqrt(2 * (E - V));
    return tmp1 - tmp2 * np.tan(nor * tmp3);

def f_odd(E):
    tmp1 = np.sqrt(-E);
    tmp2 = np.sqrt(E - V);
    tmp3 = a * np.sqrt(2 * (E - V));
    return tmp1 + tmp2 / np.tan(nor * tmp3);

import matplotlib as mpl
def format(fig):
    mpl.rcParams['font.family'] = 'STIXGeneral'
    plt.rcParams['xtick.labelsize'] = 19
    plt.rcParams['ytick.labelsize'] = 19
    plt.rcParams['font.size'] = 19
    plt.rcParams['figure.figsize'] = [5.6*6, 4*3]
    plt.rcParams['axes.titlesize'] = 18
    plt.rcParams['axes.labelsize'] = 18
    plt.rcParams['lines.linewidth'] = 2
    plt.rcParams['lines.markersize'] = 6
    plt.rcParams['legend.fontsize'] = 15
    plt.rcParams['mathtext.fontset'] = 'stix'
    plt.rcParams['axes.linewidth'] = 1.5
    # plt.style.use('dark_background')


def ax_format(ax, xmaj, xmin, ymaj, ymin):
    ax.xaxis.set_tick_params(which='major', size=5, width=1,
                            direction='in', top='on')
    ax.xaxis.set_tick_params(which='minor', size=3, width=1,
                            direction='in', top='on')
    ax.yaxis.set_tick_params(which='major', size=5, width=1,
                            direction='in', right='on')
    ax.yaxis.set_tick_params(which='minor', size=3, width=1,
                            direction='in', right='on')
    ax.xaxis.set_major_locator(mpl.ticker.MultipleLocator(xmaj))
    ax.xaxis.set_minor_locator(mpl.ticker.MultipleLocator(xmin))
    ax.yaxis.set_major_locator(mpl.ticker.MultipleLocator(ymaj))
    ax.yaxis.set_minor_locator(mpl.ticker.MultipleLocator(ymin))


fig1 = plt.figure(figsize=(10,10))
format(fig1)

ax1 = fig1.add_subplot(1, 1, 1)
#ax_format(ax1, 2, 0.4, 2, 0.4)


E = np.linspace(-13.59, 0, 10000)
ax1.plot(E, f_even(E), '.', label='even state')
ax1.plot(E, f_odd(E), '.', label='odd state')
ax1.set_xlim(-13.6, 0)
ax1.set_ylim(-10, 10)
ax1.set_title('Finite square well of depth $V=-13.6 \ \mathrm{eV}$ and half-width $20a_B$')
ax1.grid()
ax1.legend()
plt.savefig('eigenenergy.png')

