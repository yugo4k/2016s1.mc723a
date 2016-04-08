#!/usr/bin/python3

import sys
import numpy as np
import matplotlib.pyplot as plt

def main():
    filepath = sys.argv[1]
    lines = open(filepath).read().splitlines()[3:]

    f2bx = []
    f2bl1i = []
    f2bl1d = []
    f2bl2u = []

    m2bx = []
    m2bl1i = []
    m2bl1d = []
    m2bl2u = []

    for line in lines:
        words = line[1:-1].split('|')
        if 'f2b' in words[0]:
            f2bx.append(words[1].split('=')[1])
            f2bl1i.append(float(words[2]))
            f2bl1d.append(float(words[3]))
            f2bl2u.append(float(words[4]))
        else:
            m2bx.append(words[1].split('=')[1])
            m2bl1i.append(float(words[2]))
            m2bl1d.append(float(words[3]))
            m2bl2u.append(float(words[4]))

    xlabel = 'block size'

    fig = plt.figure(facecolor='white', figsize=(16, 4), dpi=80)
    fig.subplots_adjust(left=.07, right=.97, top=.9, bottom=.2)

    ax = fig.add_subplot(1, 2, 1)
    ax.grid()
    ax.set_title('f2b')
    ax.set_xlabel(xlabel)
    ax.set_ylabel('miss rate')
    ax.set_xticks(np.arange(len(f2bx)))
    ax.set_xticklabels(f2bx)
    ax.plot(np.arange(len(f2bx)), f2bl1i, 'o-', label='L1i')
    ax.plot(np.arange(len(f2bx)), f2bl1d, 'o-', label='L1d')
    ax.plot(np.arange(len(f2bx)), f2bl2u, 'o-', label='L2u')
    ax.set_ylim((0, 1.1 * ax.get_ylim()[1]))
    handles, labels = ax.get_legend_handles_labels()
    ax.legend(handles, labels)

    ax = fig.add_subplot(1, 2, 2)
    ax.grid()
    ax.set_title('m2b')
    ax.set_xlabel(xlabel)
    ax.set_ylabel('miss rate')
    ax.set_xticks(np.arange(len(m2bx)))
    ax.set_xticklabels(m2bx)
    ax.plot(np.arange(len(m2bx)), m2bl1i, '^-', label='L1i')
    ax.plot(np.arange(len(m2bx)), m2bl1d, 'v-', label='L1d')
    ax.plot(np.arange(len(m2bx)), m2bl2u, 'o-', label='L2u')
    ax.set_ylim((0, 1.1 * ax.get_ylim()[1]))
    handles, labels = ax.get_legend_handles_labels()
    ax.legend(handles, labels)

    fig.savefig('./' + xlabel.replace(' ', '_') + '.png')

    plt.show()

if __name__ == '__main__':
    main()
