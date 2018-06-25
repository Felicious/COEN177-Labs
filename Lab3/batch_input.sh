#/bin/bash
#This is a batch input for running the 18 ( -1 because i ran that one separately
#Sequential 1G
echo seq.o 1G.bin 
/bin/time -f %E ./seq.o /local/weka/1G.bin
/bin/time -f %E ./seq.o /local/weka/1G.bin
/bin/time -f %E ./seq.o /local/weka/1G.bin

echo seq.o 2.5G.bin
#Seq 2.5G
/bin/time -f %E ./seq.o /local/weka/2500M.bin
/bin/time -f %E ./seq.o /local/weka/2500M.bin
/bin/time -f %E ./seq.o /local/weka/2500M.bin

echo seq.o 5G.bin
#Seq 5G
/bin/time -f %E ./seq.o /local/weka/5G.bin
/bin/time -f %E ./seq.o /local/weka/5G.bin
/bin/time -f %E ./seq.o /local/weka/5G.bin

echo rand.o 1G.bin
#Rand 1G : only has 2 because i ran it once already
/bin/time -f %E ./rand.o /local/weka/1G.bin
/bin/time -f %E ./rand.o /local/weka/1G.bin

echo rand.o 2.5G bin
#Rand 2.5G
/bin/time -f %E ./rand.o /local/weka/2500M.bin
/bin/time -f %E ./rand.o /local/weka/2500M.bin
/bin/time -f %E ./rand.o /local/weka/2500M.bin

echo rand.o 5G.bin
#Rand 5G
/bin/time -f %E ./rand.o /local/weka/5G.bin
/bin/time -f %E ./rand.o /local/weka/5G.bin
/bin/time -f %E ./rand.o /local/weka/5G.bin

