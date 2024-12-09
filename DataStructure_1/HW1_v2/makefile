SRC := src
OBJ := obj
DEPS := $($(SRC)/%.h)  # array_arith.h my_common.h sparce.h
CFLAG := -g -I$(SRC)

_OBJ1 := array_arith.o my_common.o array_test.o
OBJ1 = $(patsubst %, obj/%, $(_OBJ1)) # obj/array_arith.o

_OBJ2 := array_arith.o my_common.o problem2.o
OBJ2 = $(patsubst %, obj/%, $(_OBJ2))

_OBJ3 := sparce.o my_common.o transpose_test.o
OBJ3 = $(patsubst %, obj/%, $(_OBJ3))

_OBJ4 := sparce.o my_common.o problem4.o
OBJ4 = $(patsubst %, obj/%, $(_OBJ4))

all: test1 problem2 test2 problem4

test1: $(OBJ1)
	gcc -o $@ $^

problem2: $(OBJ2)
	gcc -o $@ $^

test2: $(OBJ3)
	gcc -o $@ $^

problem4: $(OBJ4)
	gcc -o $@ $^

$(OBJ)/%.o: $(SRC)/%.c $(DEPS)
	gcc -c -o $@ $< $(CFLAG)

clean:
	del *.exe obj\*.o
