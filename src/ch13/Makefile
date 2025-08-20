# CC = cc -g
# CC = g++ -ggdb -DDEBUG -O0 -Wall
CC = cl /Zi /EHsc /DYY_NO_UNISTD_H

LIBS_HEADERS = ../util/*.h
LIBS_SRC = ../util/*.c
# INCLUDE_PATHS = -I../util
INCLUDE_PATHS = /I ../util

J0_HEADERS = $(LIBS_HEADERS) x64.h byc.h serial.h tac.h typeinfo.h tree.h symtab.h j0.h
J0_SRC = $(LIBS_SRC) x64.cc byc.cc serial.cc tac.cc typeinfo.cc tree.cc symtab.cc j0.cc

J0X_HEADERS = $(LIBS_HEADERS) byc.h j0machine.h
J0X_SRC = $(LIBS_SRC) j0machine.cc j0x.cc

j0: $(J0_HEADERS) $(J0_SRC) javalex.l j0gram.y
	bison --debug -d j0gram.y
	flex -ojavalex.lex.cc javalex.l
	$(CC) $(INCLUDE_PATHS) $(J0_SRC) javalex.lex.c j0gram.tab.c -o $@
# 	dot -Tpng hello.java.dot >hello.png

j0.exe: $(J0_HEADERS) $(J0_SRC) javalex.l j0gram.y
	win_bison --debug -d j0gram.y --header=j0gram.tab.h -o j0gram.tab.cc
	win_flex -ojavalex.lex.cc javalex.l
	$(CC) $(INCLUDE_PATHS) /Fe:$@ $(J0_SRC) javalex.lex.cc j0gram.tab.cc
# 	dot -Tpng hello.java.dot >hello.png

j0x: $(J0X_HEADERS) $(J0X_SRC)
	$(CC) $(INCLUDE_PATHS) $(J0X_SRC) -o $@

j0x.exe: $(J0X_HEADERS) $(J0X_SRC)
	$(CC) $(INCLUDE_PATHS) /Fe:$@ $(J0X_SRC)

bc: j0.exe
	./j0 hello.java
	./j0x hello.j0

x64: j0.exe
	./j0 -x64 hello.java
	as -o hello.o hello.s
	gcc -o hello.exe hello.o
	./hello

hi.exe: hi.h hi.cc
	$(CC) /Fe:$@ ../util/*.c hi.cc
