FLAGS	=	-std=c17 -Wall -g -fpermissive

INCLUDE	=	include
SRC		=	src
BIN		=	bin

LIBS	=
EXE		=	main

DEPS	=	$(wildcard $(SRC)/*.c)
OBJ		=	$(patsubst $(SRC)/%.c, $(BIN)/%.o, $(DEPS))

$(BIN)/%.o: $(SRC)/%.c
	mkdir -p $(BIN)
	$(CXX) -c -o $@ $< $(FLAGS) -I$(INCLUDE)

$(BIN)/$(EXE): $(OBJ)
	$(CXX) $(FLAGS) -I$(INCLUDE) -o $@ $^ $(LIBS)

clean:
	rm -rf $(BIN)/*
