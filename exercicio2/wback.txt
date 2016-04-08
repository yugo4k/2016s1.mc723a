../../dinero4sbc/dineroIV -informat s -trname gcc_f2b -maxtrace 20 -l1-isize 64K -l1-ibsize 64 -l1-iassoc 2 -l1-irepl l -l1-ifetch a -l1-dsize 64K -l1-dbsize 64 -l1-dassoc 2 -l1-drepl l -l1-dfetch a -l2-usize 512K -l2-ubsize 64 -l2-uassoc 16 -l2-urepl l -l2-ufetch a
|trname|parameter|miss rate L1i|miss rate L1d|miss rate L2u|
|---|---|---|---|---|
|gcc_f2b|wback=a|0.0011|0.0033|0.0022|
|gcc_f2b|wback=n|0.0011|0.0033|0.0022|
|gcc_f2b|wback=f|0.0011|0.0033|0.0022|
|gcc_m2b|wback=a|0.0000|0.0001|0.0001|
|gcc_m2b|wback=n|0.0000|0.0001|0.0001|
|gcc_m2b|wback=f|0.0000|0.0001|0.0001|
