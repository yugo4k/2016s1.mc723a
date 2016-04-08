../../dinero4sbc/dineroIV -informat s -trname gcc_f2b -maxtrace 20 -l1-isize 16K -l1-ibsize 128 -l1-iassoc 2 -l1-irepl l -l1-ifetch a -l1-dsize 64K -l1-dbsize 64 -l1-dassoc 2 -l1-drepl l -l1-dfetch a -l2-usize 512K -l2-ubsize 64 -l2-uassoc 16 -l2-urepl l -l2-ufetch a
|trname|parameter|miss rate L1i|miss rate L1d|miss rate L2u|
|---|---|---|---|---|
|gcc_f2b|l1isize=16K|0.0087|0.0194|0.0140|
|gcc_f2b|l1isize=32K|0.0041|0.0093|0.0067|
|gcc_f2b|l1isize=64K|0.0011|0.0028|0.0020|
|gcc_f2b|l1isize=128K|0.0003|0.0009|0.0006|
|gcc_f2b|l1isize=256K|0.0001|0.0002|0.0001|
|gcc_m2b|l1isize=16K|0.0005|0.0010|0.0008|
|gcc_m2b|l1isize=32K|0.0002|0.0004|0.0003|
|gcc_m2b|l1isize=64K|0.0001|0.0001|0.0001|
|gcc_m2b|l1isize=128K|0.0000|0.0000|0.0000|
|gcc_m2b|l1isize=256K|0.0000|0.0000|0.0000|
