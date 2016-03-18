#!/usr/bin/python3

import sys, os.path as path
import numpy as np
import matplotlib as mpl
import matplotlib.pyplot as plt
import subprocess as sp
import time

def main():
    n_samples = int(sys.argv[1])
    args = sys.argv[2:]

    list_walltimes = []
    for i in range(n_samples):
        # time.sleep(.5)
        time_previous = time.time()
        proc = sp.Popen(args, stdout=sp.PIPE, stderr=sp.PIPE)
        out, err = proc.communicate()
        time_delta = time.time() - time_previous
        print('%2d' % i, time_delta)
        list_walltimes.append(time_delta)

    arr_walltimes = np.array(list_walltimes)
    print(list_walltimes)

    fig = plt.figure(facecolor='white')
    fig.suptitle('min_time: %.1fs, avg_time: %.1fs, std_time: %.2fs (%d samples)' % (arr_walltimes.min(), arr_walltimes.mean(), arr_walltimes.std(), n_samples))
    ax = fig.add_subplot(1, 1, 1)
    x_formatter = mpl.ticker.ScalarFormatter(useOffset=False)
    ax.xaxis.set_major_formatter(x_formatter)
    ax.set_xlabel('execution time (seconds)')
    ax.set_ylabel('count')
    ax.hist(list_walltimes)
    fig.savefig(path.join(path.dirname(sys.argv[2]), 'hist.png'))


if __name__ == '__main__':
    main()
