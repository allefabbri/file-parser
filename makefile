PARSER_H   = file_parser.h
PARSER_CPP = file_parser.cpp
PARSER_OBJ = file_parser.o
EXAMPLE    = example.cpp
EXE        = example.exe
OPT        = -std=c++11

all: example
	./$(EXE)

example: $(PARSER_OBJ)
	g++ $(OPT) -o $(EXE) $(PARSER_OBJ) $(EXAMPLE)

$(PARSER_OBJ): $(PARSER_H) $(PARSER_CPP)
	g++ $(OPT) -c -o $(PARSER_OBJ) $(PARSER_CPP)
