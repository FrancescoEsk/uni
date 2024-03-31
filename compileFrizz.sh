# programma shelll per compilare automaticamente (Frizz)
gcc -o $2 c/$1;
mv $2 bin/;
cd bin/;
./$2;