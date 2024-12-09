SRC := src
OBJ := obj
DEPS := $($(SRC)/%.h)  # array_arith.h my_common.h sparce.h
CFLAG := -g -I$(SRC)

_OBJ1 := array_arith.o my_common.o array_test.o
OBJ1 = $(patsubst %, obj/%, $(_OBJ1)) # obj/array_arith.o

_OBJ2 := sparce.o sparce_test.o
OBJ2 = $(patsubst %, obj/%, $(_OBJ2))

_OBJ3 := array_arith.o my_common.o problem2.o
OBJ3 = $(patsubst %, obj/%, $(_OBJ3))

all: test test2 p2

test: $(OBJ1)
	gcc -o $@ $^

test2: $(OBJ2)
	gcc -o $@ $^

p2: $(OBJ3)
	gcc -o $@ $^

$(OBJ)/%.o: $(SRC)/%.c $(DEPS)
	gcc -c -o $@ $< $(CFLAG)

clean:
	del *.exe obj\*.o
