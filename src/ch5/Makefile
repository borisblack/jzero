CC = cc -g

LIBS_HEADERS = ../util/*.h
HEADERS = ${LIBS_HEADERS}
LIBS_SRC = ../util/*.c
SRC = ${LIBS_SRC}
INCLUDE_PATHS = -I../util

j0: ${HEADERS} ${SRC} javalex.l j0gram.y tree.h j0.h tree.c j0.c
	bison --debug -d j0gram.y
	flex -ojavalex.lex.c javalex.l
	${CC} ${INCLUDE_PATHS} ${SRC} javalex.lex.c j0gram.tab.c tree.c j0.c -o $@
# 	./$@ hello.java
# 	dot -Tpng hello.java.dot >hello.png
