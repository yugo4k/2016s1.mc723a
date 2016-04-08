../../dinero4sbc/dineroIV -informat s -trname gcc_f2b -maxtrace 20 -l1-isize 64K -l1-ibsize 16 -l1-iassoc 2 -l1-irepl l -l1-ifetch a -l1-dsize 64K -l1-dbsize 64 -l1-dassoc 2 -l1-drepl l -l1-dfetch a -l2-usize 512K -l2-ubsize 64 -l2-uassoc 16 -l2-urepl l -l2-ufetch a

|trname|parameter|miss rate L1i|miss rate L1d|miss rate L2u|
|---|---|---|---|---|
|gcc_f2b|l1ibsize=16|0.0011|0.0049|0.0030|
|gcc_f2b|l1ibsize=32|0.0010|0.0038|0.0024|
|gcc_f2b|l1ibsize=64|0.0011|0.0033|0.0022|
|gcc_f2b|l1ibsize=128|0.0011|0.0028|0.0020|
|gcc_f2b|l1ibsize=256|0.0014|0.0029|0.0021|
|gcc_m2b|l1ibsize=16|0.0000|0.0001|0.0001|
|gcc_m2b|l1ibsize=32|0.0000|0.0001|0.0001|
|gcc_m2b|l1ibsize=64|0.0000|0.0001|0.0001|
|gcc_m2b|l1ibsize=128|0.0001|0.0001|0.0001|
|gcc_m2b|l1ibsize=256|0.0001|0.0001|0.0001|
