CC = cc -g

LIBS_HEADERS = ../util/*.h ../struct/*.h
HEADERS = ${LIBS_HEADERS} j0machine.h
LIBS_SRC = ../util/*.c ../struct/*.c
SRC = ${LIBS_SRC} j0machine.c j0x.c
INCLUDE_PATHS = -I../util -I../struct

j0x: ${HEADERS} ${SRC}
	${CC} ${INCLUDE_PATHS} ${SRC} -o $@
# 	./$@ hello.j0
