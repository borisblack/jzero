CC = cc -g

LIBS_HEADERS = ../util/*.h ../struct/*.h
HEADERS = ${LIBS_HEADERS} serial.h tac.h typeinfo.h tree.h symtab.h j0.h
LIBS_SRC = ../util/*.c ../struct/*.c
SRC = ${LIBS_SRC} serial.c tac.c typeinfo.c tree.c symtab.c j0.c
INCLUDE_PATHS = -I../util -I../struct

j0: ${HEADERS} ${SRC} javalex.l j0gram.y
	bison --debug -d j0gram.y
	flex -ojavalex.lex.c javalex.l
	${CC} ${INCLUDE_PATHS} ${SRC} javalex.lex.c j0gram.tab.c -o $@
# 	./$@ hello.java
# 	dot -Tpng hello.java.dot >hello.png
