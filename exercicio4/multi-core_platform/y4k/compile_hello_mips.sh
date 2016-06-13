#!/bin/sh

export LD_LIBRARY_PATH=/home/staff/lucas/mc723/hw_tools/systemc-2.3.1/lib-linux64/:$LD_LIBRARY_PATH
export PATH=$PATH:/home/staff/lucas/mc723/hw_tools/ArchC-2.2.0/installed/bin:/home/staff/lucas/mc723/hw_tools/mips-newlib-elf/bin/

Y4KPATH="/home/ec2014/ra033324/y4k/classes/mc723a/git_2016s1.mc723a/exercicio4/multi-core_platform/y4k"

echo
echo "mips-newlib-elf-gcc -specs=archc ${Y4KPATH}/hello.c -o ${Y4KPATH}/hello.mips"
mips-newlib-elf-gcc -specs=archc ${Y4KPATH}/hello.c -o ${Y4KPATH}/hello.mips
