../../dinero4sbc/dineroIV -informat s -trname gcc_f2b -maxtrace 20 -l1-isize 64K -l1-ibsize 64 -l1-iassoc 2 -l1-irepl l -l1-ifetch d -l1-dsize 64K -l1-dbsize 64 -l1-dassoc 2 -l1-drepl l -l1-dfetch d -l2-usize 512K -l2-ubsize 64 -l2-uassoc 16 -l2-urepl l -l2-ufetch d
|trname|parameter|miss rate L1i|miss rate L1d|miss rate L2u|
|---|---|---|---|---|
|gcc_f2b|repl=l|0.0024|0.0078|0.0886|
|gcc_f2b|repl=f|0.0026|0.0084|0.0969|
|gcc_f2b|repl=r|0.0025|0.0086|0.1076|
|gcc_m2b|repl=l|0.0001|0.0374|0.3361|
|gcc_m2b|repl=f|0.0001|0.0374|0.3437|
|gcc_m2b|repl=r|0.0001|0.0376|0.0995|
