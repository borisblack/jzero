CC = cc -g

LIBS_HEADERS = ../util/*.h
HEADERS = ${LIBS_HEADERS}
LIBS_SRC = ../util/*.c
SRC = ${LIBS_SRC}
INCLUDE_PATHS = -I../util

simple: nnws.l simple.h simple.c
	flex -onnws.lex.c nnws.l
	${CC} nnws.lex.c simple.c -o $@

simple2: nnws-tok.l simple2.h simple2.c
	flex -onnws-tok.lex.c nnws-tok.l
	${CC} nnws-tok.lex.c simple2.c -o $@

j0: ${HEADERS} ${SRC} javalex.l j0.h j0.c
	flex -ojavalex.lex.c javalex.l
	${CC} ${INCLUDE_PATHS} ${SRC} javalex.lex.c j0.c -o $@
