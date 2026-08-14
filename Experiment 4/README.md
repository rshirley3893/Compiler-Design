**EX:4 - Procedure**

cd /mnt/c/Users/R\\ Shirley/Desktop/CD\\ Ex

rm -f lex.yy.c y.tab.c y.tab.h valvar

flex valvar.l

bison -dy valvar.y

gcc lex.yy.c y.tab.c -o valvar -lfl

./valvar

