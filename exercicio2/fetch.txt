../../dinero4sbc/dineroIV -informat s -trname gcc_f2b -maxtrace 20 -l1-isize 64K -l1-ibsize 64 -l1-iassoc 2 -l1-irepl l -l1-ifetch d -l1-dsize 64K -l1-dbsize 64 -l1-dassoc 2 -l1-drepl l -l1-dfetch d -l2-usize 512K -l2-ubsize 64 -l2-uassoc 16 -l2-urepl l -l2-ufetch d
|trname|parameter|miss rate l1i|miss rate l1d|miss rate l2u|
|---|---|---|---|---|
|gcc_f2b|fetch=d|0.0024|0.0078|0.0886|
|gcc_f2b|fetch=a|0.0011|0.0033|0.0022|
|gcc_f2b|fetch=m|0.0017|0.8246|0.0031|
|gcc_f2b|fetch=t|0.0013|0.7843|0.0036|
|gcc_f2b|fetch=l|0.0024|0.0000|0.0024|
|gcc_m2b|fetch=d|0.0001|0.0374|0.3361|
|gcc_m2b|fetch=a|0.0000|0.0001|0.0001|
|gcc_m2b|fetch=m|0.0001|0.7202|0.0001|
|gcc_m2b|fetch=t|0.0001|0.6658|0.0001|
|gcc_m2b|fetch=l|0.0001|0.0000|0.0001|
