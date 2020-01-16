.PHONY: all clean

CC=clang-8
MARCH=bdver1
CFLAGS=-std=c11 -ggdb -masm=intel -Wformat -Wimplicit -Wall -Wextra -Wfloat-equal -Wshadow -Wpointer-arith -Werror -Winit-self -Wunreachable-code -O3 -march=$(MARCH) -fverbose-asm
AFLAGS=--enable=all --language=c --platform=unix64 --std=c11 --inconclusive -f -v --suppress=missingIncludeSystem
SRC=main.c
EXEC=main
ADD := $(shell echo include/src/*.c)
DBG=gdb
ANLZ=cppcheck
DIR=/home/sada/source/HomeWork
MEMCHCK=valgrind --leak-check=full --show-leak-kinds=all --tool=memcheck
MOVE=mv *.s asm/

all: build assembly

build: $(SRC) $(INCLUDE)
	@echo Building $(SRC) with $(CC)
	@$(CC) -o $(EXEC) $(CFLAGS) $(SRC) $(ADD)  -Iinclude/
	@echo Building is Done "¯\_(ツ)_/¯"

assembly: $(SRC) $(INCLUDE)
	@echo Assembling $(SRC) with Intel Syntax and $(CC)
	@$(CC) -S $(CFLAGS) $(SRC) $(ADD) -Iinclude
	@$(MOVE)
	@echo Assembling is Done "¯\_(ツ)_/¯"

debug: build $(EXEC)
	$(DBG) $(EXEC)

mem: build $(EXEC)
	$(MEMCHCK) ./$(EXEC)

analyze:
	$(ANLZ) $(AFLAGS) $(SRC) $(CTRL) $(ADD) -Iinclude/ -Iinclude/src

run: build $(EXEC)
	./$(EXEC)

clean:
	@echo Cleaning up...
	@rm $(EXEC)
	@rm asm/*.s
	@echo So fresh here "¯\_(ツ)_/¯"
