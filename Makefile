.PHONY: all clean

CC=clang-9
CC_TRAVIS=clang-7

CFLAGS=-std=c11 -ggdb -masm=intel -Wformat -Wimplicit -Wall -Wextra -Wfloat-equal -Wshadow -Wpointer-arith -Werror -Winit-self -Wunreachable-code -O3 -fverbose-asm 
AFLAGS=--enable=all --language=c --std=c11 --inconclusive -f -v --suppress=missingIncludeSystem --platform=unix

SRC=main.c
EXEC=main

ADD := include/controller.c $(shell echo include/src/*.c)
DBG=gdb
ANLZ=cppcheck
MEMCHCK=valgrind --leak-check=full --show-leak-kinds=all --tool=memcheck

MOVE=mv *.s asm/

all: build assembly

build: $(SRC) $(INCLUDE)
	@echo Building $(SRC) with $(CC)
	@$(CC) -o $(EXEC) $(CFLAGS)$(MARCH) $(SRC) $(ADD) -Iinclude/
	@echo Building is Done "¯\_(ツ)_/¯"

assembly: $(SRC) $(INCLUDE)
	@echo Assembling $(SRC) with Intel Syntax and $(CC)
	@$(CC) $(CFLAGS)$(MARCH) -S $(SRC) $(ADD) -Iinclude
	@$(MOVE)
	@echo Assembling is Done "¯\_(ツ)_/¯"

analyze:
	$(ANLZ) $(AFLAGS) $(SRC) $(ADD) -Iinclude/ -Iinclude/src

debug: $(EXEC)
	$(DBG) $(EXEC)

mem: $(EXEC)
	$(MEMCHCK) ./$(EXEC)

travis: $(SRC)
	$(CC_TRAVIS) -o $(EXEC) $(CFLAGS)$(MARCH) $(SRC) $(ADD) -Iinclude/

run: $(EXEC)
	./$(EXEC)

clean:
	@echo Cleaning up...
	@rm $(EXEC)
	@rm asm/*.s
	@echo So fresh here "¯\_(ツ)_/¯"
