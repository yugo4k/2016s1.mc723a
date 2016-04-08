../../dinero4sbc/dineroIV -informat s -trname gcc_f2b -maxtrace 20 -l1-isize 128K -l1-ibsize 128 -l1-iassoc 8 -l1-irepl l -l1-ifetch a -l1-dsize 128K -l1-dbsize 128 -l1-dassoc 8 -l1-drepl l -l1-dfetch a -l2-usize 128K -l2-ubsize 64 -l2-uassoc 16 -l2-urepl l -l2-ufetch a

|trname|parameter|miss rate L1i|miss rate L1d|miss rate L2u|
|---|---|---|---|---|
|gcc_f2b|l2usize=128K|0.0001|0.0002|0.0002|
|gcc_f2b|l2usize=256K|0.0001|0.0002|0.0002|
|gcc_f2b|l2usize=512K|0.0001|0.0002|0.0002|
|gcc_f2b|l2usize=1M|0.0001|0.0002|0.0002|
|gcc_f2b|l2usize=2M|0.0001|0.0002|0.0002|
|gcc_m2b|l2usize=128K|0.0000|0.0000|0.0000|
|gcc_m2b|l2usize=256K|0.0000|0.0000|0.0000|
|gcc_m2b|l2usize=512K|0.0000|0.0000|0.0000|
|gcc_m2b|l2usize=1M|0.0000|0.0000|0.0000|
|gcc_m2b|l2usize=2M|0.0000|0.0000|0.0000|
