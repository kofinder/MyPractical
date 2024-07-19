# clean
rm -rf lex.yy.c calc y.tab.c y.tab.h

#compile yacc
yacc -d parser.y

#compile lex
lex lexer.l

#build program
gcc lex.yy.c y.tab.c -o calc

# Run the compiled program:
./calc

# Print result:
echo $?

printf "\n"

#Clean
rm -rf lex.yy.c y.tab.c y.tab.h
