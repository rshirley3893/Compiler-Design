**EX:3 - Procedure**

cd /mnt/c/Users/Desktop

rm -f lex.yy.c y.tab.c y.tab.h art\_expr

flex art\_expr.l

bison -dy art\_expr.y

gcc lex.yy.c y.tab.c -o art\_expr -lfl

./art\_expr

