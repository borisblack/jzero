# CC = cc -g
CC = g++ -ggdb -DDEBUG -O0 -Wall

LIBS_HEADERS = ../util/*.h
LIBS_SRC = ../util/*.c
INCLUDE_PATHS = -I../util

J0_HEADERS = $(LIBS_HEADERS) byc.h serial.h tac.h typeinfo.h tree.h symtab.h j0.h
J0_SRC = $(LIBS_SRC) byc.cc serial.c tac.cc typeinfo.cc tree.cc symtab.cc j0.cc

J0X_HEADERS = $(LIBS_HEADERS) byc.h j0machine.h
J0X_SRC = $(LIBS_SRC) j0machine.cc j0x.cc

j0: $(J0_HEADERS) $(J0_SRC) javalex.l j0gram.y
	bison --debug -d j0gram.y
	flex -ojavalex.lex.c javalex.l
	$(CC) $(INCLUDE_PATHS) $(J0_SRC) javalex.lex.c j0gram.tab.c -o $@
# 	./$@ hello.java
# 	dot -Tpng hello.java.dot >hello.png

j0x: $(J0X_HEADERS) $(J0X_SRC)
	$(CC) $(INCLUDE_PATHS) $(J0X_SRC) -o $@
