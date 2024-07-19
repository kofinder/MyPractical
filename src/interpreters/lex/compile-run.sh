# clean
rm -rf lex.yy.c myscanner


#compile lex
lex lexer.l

#build program
cc myscanner.c lex.yy.c -ll -o myscanner

# Run the compiled program:
./myscanner <db_config.in


#Clean
rm -rf lex.yy.c myscanner
