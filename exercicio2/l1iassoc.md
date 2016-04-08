../../dinero4sbc/dineroIV -informat s -trname gcc_f2b -maxtrace 20 -l1-isize 128K -l1-ibsize 128 -l1-iassoc 1 -l1-irepl l -l1-ifetch a -l1-dsize 64K -l1-dbsize 64 -l1-dassoc 2 -l1-drepl l -l1-dfetch a -l2-usize 512K -l2-ubsize 64 -l2-uassoc 16 -l2-urepl l -l2-ufetch a

|trname|parameter|miss rate L1i|miss rate L1d|miss rate L2u|
|---|---|---|---|---|
|gcc_f2b|l1iassoc=1|0.0010|0.0024|0.0017|
|gcc_f2b|l1iassoc=2|0.0003|0.0009|0.0006|
|gcc_f2b|l1iassoc=4|0.0001|0.0004|0.0002|
|gcc_f2b|l1iassoc=8|0.0001|0.0002|0.0002|
|gcc_f2b|l1iassoc=16|0.0001|0.0002|0.0002|
|gcc_m2b|l1iassoc=1|0.0000|0.0001|0.0000|
|gcc_m2b|l1iassoc=2|0.0000|0.0000|0.0000|
|gcc_m2b|l1iassoc=4|0.0000|0.0000|0.0000|
|gcc_m2b|l1iassoc=8|0.0000|0.0000|0.0000|
|gcc_m2b|l1iassoc=16|0.0000|0.0000|0.0000|
