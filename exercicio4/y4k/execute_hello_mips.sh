#!/bin/sh

export LD_LIBRARY_PATH=/home/staff/lucas/mc723/hw_tools/systemc-2.3.1/lib-linux64/:$LD_LIBRARY_PATH
export PATH=$PATH:/home/staff/lucas/mc723/hw_tools/ArchC-2.2.0/installed/bin:/home/staff/lucas/mc723/hw_tools/mips-newlib-elf/bin/

MIPSTLMPATH='/home/ec2014/ra033324/y4k/classes/mc723a/git_2016s1.mc723a/exercicio4/mips-tlm/'

${MIPSTLMPATH}/mips.x --load=${MIPSTLMPATH}/../y4k/hello.mips
