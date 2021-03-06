#!/usr/bin/python3

import os
import subprocess as sp

def main():
    traces = [('/home/staff/lucas/mc723/traces/176.gcc.f2b/', 'gcc_f2b'), ('/home/staff/lucas/mc723/traces/176.gcc.m2b', 'gcc_m2b')]
    for i, (tracepath, trname) in enumerate(traces):
        # for j, repl in enumerate(['l', 'f', 'r']):
        #     varname = 'repl'
        #     var = 'repl=%s' % repl
        # for j, fetch in enumerate(['d', 'a', 'm', 't', 'l']):
        #     varname = 'fetch'
        #     var = 'fetch=%s' % fetch
        # for j, walloc in enumerate(['a', 'n', 'f']):
        #     varname = 'walloc'
        #     var = 'walloc=%s' % walloc
        # for j, wback in enumerate(['a', 'n', 'f']):
        #     varname = 'wback'
        # #     var = 'wback=%s' % wback
        # for j, l1isize in enumerate(['16K', '32K', '64K', '128K', '256K']):
        #     varname = 'l1isize'
        #     var = 'l1isize=%s' % l1isize
        # for j, l1ibsize in enumerate(['16', '32', '64', '128', '256']):
        #     varname = 'l1ibsize'
        #     var = 'l1ibsize=%s' % l1ibsize
        # for j, l1iassoc in enumerate(['1', '2', '4', '8', '16']):
        #     varname = 'l1iassoc'
        #     var = 'l1iassoc=%s' % l1iassoc
        # for j, l1dsize in enumerate(['16K', '32K', '64K', '128K', '256K']):
        #     varname = 'l1dsize'
        #     var = 'l1dsize=%s' % l1dsize
        # for j, l1dbsize in enumerate(['16', '32', '64', '128', '256']):
        #     varname = 'l1dbsize'
        #     var = 'l1dbsize=%s' % l1dbsize
        # for j, l1dassoc in enumerate(['1', '2', '4', '8', '16']):
        #     varname = 'l1dassoc'
        #     var = 'l1dassoc=%s' % l1dassoc
        # for j, l2usize in enumerate(['128K', '256K', '512K', '1M', '2M']):
        #     varname = 'l2usize'
        #     var = 'l2usize=%s' % l2usize
        # for j, l2ubsize in enumerate(['16', '32', '64', '128', '256']):
        #     varname = 'l2ubsize'
        #     var = 'l2ubsize=%s' % l2ubsize
        for j, l2uassoc in enumerate(['4', '8', '16', '32', '64']):
            varname = 'l2uassoc'
            var = 'l2uassoc=%s' % l2uassoc

            os.chdir(tracepath)
            command  = '../../dinero4sbc/dineroIV'
            args = [command]
            args += ['-informat', 's']
            args += ['-trname', trname]
            args += ['-maxtrace', '20']

            repl = 'l'
            # fetch = 'd'
            fetch = 'a'
            walloc = 'a'
            wback = 'a'

            # l1isize = '64K'
            l1isize = '128K'
            # l1ibsize = '64'
            l1ibsize = '128'
            # l1iassoc = '2'
            l1iassoc = '8'
            l1irepl = repl
            l1ifetch = fetch
            l1iwalloc = walloc
            l1iwback = wback

            # l1dsize = '64K'
            l1dsize = '128K'
            # l1dbsize = '64'
            l1dbsize = '128'
            # l1dassoc = '2'
            l1dassoc = '8'
            l1drepl = repl
            l1dfetch = fetch
            l1dwalloc = walloc
            l1dwback = wback

            l2usize = '512K'
            l2ubsize = '64'
            # l2uassoc = '16'
            l2urepl = repl
            l2ufetch = fetch
            l2uwalloc = walloc
            l2uwback = wback

            args += ['-l1-isize', l1isize]
            args += ['-l1-ibsize', l1ibsize]
            args += ['-l1-iassoc', l1iassoc]
            args += ['-l1-irepl', l1irepl]
            args += ['-l1-ifetch', l1ifetch]
            # args += ['-l1-iwalloc', l1iwalloc]
            # args += ['-l1-iwback', l1iwback]

            args += ['-l1-dsize', l1dsize]
            args += ['-l1-dbsize', l1dbsize]
            args += ['-l1-dassoc', l1dassoc]
            args += ['-l1-drepl', l1drepl]
            args += ['-l1-dfetch', l1dfetch]
            # args += ['-l1-dwalloc', l1dwalloc]
            # args += ['-l1-dwback', l1dwback]

            args += ['-l2-usize', l2usize]
            args += ['-l2-ubsize', l2ubsize]
            args += ['-l2-uassoc', l2uassoc]
            args += ['-l2-urepl', l2urepl]
            args += ['-l2-ufetch', l2ufetch]
            # args += ['-l2-uwalloc', l2uwalloc]
            # args += ['-l2-uwback', l2uwback]

            if i == 0 and j == 0:
                output_line = ' '.join(args)
                print(output_line)
                output_text = output_line + '\n\n'
                output_line = '|trname|parameter|miss rate L1i|miss rate L1d|miss rate L2u|'
                print(output_line)
                output_text += output_line + '\n'
                output_line = '|---|---|---|---|---|'
                print(output_line)
                output_text += output_line + '\n'

            proc = sp.Popen(args, stdout=sp.PIPE, stderr=sp.PIPE)
            out, err = proc.communicate()
            counter = 0
            for line in out.decode('utf-8').splitlines():
                if 'rate' in line:
                    if counter == 0:
                        rate_l1i = float(line.split()[3])
                    elif counter == 1:
                        rate_l1d = float(line.split()[3])
                    elif counter == 2:
                        rate_l2u = float(line.split()[3])
                    counter += 1
            output_line = ('|%s|%s|%.4f|%.4f|%.4f|' % (trname, var, rate_l1i, rate_l1d, rate_l2u))
            print(output_line)
            output_text += output_line + '\n'
            # print('err:', err.decode('utf-8'))
    print(output_text)
    fout = open('/home/ec2014/ra033324/Desktop/mc723a/git_2016s1.mc723a/exercicio2/' + varname + '.md', 'w')
    fout.write(output_text)
    fout.close()


if __name__ == '__main__':
    main()
