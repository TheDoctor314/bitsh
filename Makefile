SRC = bitsh.c linenoise.c util.c
EXEC = bitsh
C_FLAGS = -Wall -Werror -Wpedantic -g

all: $(EXEC)

$(EXEC): $(SRC)
	gcc $(C_FLAGS) -o $(EXEC) $(SRC)
