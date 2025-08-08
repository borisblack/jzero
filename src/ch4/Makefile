CC = cc -g

LIBS_HEADERS = ../util/*.h
HEADERS = ${LIBS_HEADERS}
LIBS_SRC = ../util/*.c
SRC = ${LIBS_SRC}
INCLUDE_PATHS = -I../util

trivial: ${HEADERS} ${SRC} nnws.l ns.y trivial.h trivial.c
	bison -d ns.y
	flex -onnws.lex.c nnws.l
	${CC} ${INCLUDE_PATHS} ${SRC} nnws.lex.c ns.tab.c trivial.c -o $@

j0: ${HEADERS} ${SRC} javalex.l j0gram.y j0.h j0.c
	bison -d j0gram.y
	flex -ojavalex.lex.c javalex.l
	${CC} ${INCLUDE_PATHS} ${SRC} javalex.lex.c j0gram.tab.c j0.c -o $@
