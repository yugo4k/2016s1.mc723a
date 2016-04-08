#!/usr/bin/python3

import os
import subprocess as sp

def main():
    traces = [('/home/staff/lucas/mc723/traces/176.gcc.f2b/', 'gcc_f2b'), ('/home/staff/lucas/mc723/traces/176.gcc.m2b', 'gcc_m2b')]
    for tracepath, trname in traces:
        os.chdir(tracepath)
        command  = '../../dinero4sbc/dineroIV'
        args = [command]
        args += ['-informat', 's']
        args += ['-trname', trname]
        args += ['-maxtrace', '20']

        repl = 'l'
        fetch = 'd'
        walloc = 'a'
        wback = 'a'

        l1isize = '64K'
        l1ibsize = '64'
        l1iassoc = '2'
        l1irepl = repl
        l1ifetch = fetch
        l1iwalloc = walloc
        l1iwback = wback

        l1dsize = '64K'
        l1dbsize = '64'
        l1dassoc = '2'
        l1drepl = repl
        l1dfetch = fetch
        l1dwalloc = walloc
        l1dwback = wback

        l2usize = '64K'
        l2ubsize = '64'
        l2uassoc = '16'
        l2urepl = repl
        l2ufetch = fetch
        l2uwalloc = walloc
        l2uwback = wback

        args += ['-l1-isize', l1isize]
        args += ['-l1-ibsize', l1ibsize]
        # args += ['-l1-iassoc', l1iassoc]
        # args += ['-l1-irepl', l1irepl]
        # args += ['-l1-ifetch', l1ifetch]
        # args += ['-l1-iwalloc', l1iwalloc]
        # args += ['-l1-iwback', l1iwback]

        args += ['-l1-dsize', l1dsize]
        args += ['-l1-dbsize', l1dbsize]
        # args += ['-l1-dassoc', l1dassoc]
        # args += ['-l1-drepl', l1drepl]
        # args += ['-l1-dfetch', l1dfetch]
        # args += ['-l1-dwalloc', l1dwalloc]
        # args += ['-l1-dwback', l1dwback]

        args += ['-l2-usize', l2usize]
        args += ['-l2-ubsize', l2ubsize]
        # args += ['-l2-uassoc', l2uassoc]
        # args += ['-l2-urepl', l2urepl]
        # args += ['-l2-ufetch', l2ufetch]
        # args += ['-l2-uwalloc', l2uwalloc]
        # args += ['-l2-uwback', l2uwback]

        print(' '.join(args))

        proc = sp.Popen(args, stdout=sp.PIPE, stderr=sp.PIPE)
        out, err = proc.communicate()
        print(out)
        print(err)

if __name__ == '__main__':
    main()
