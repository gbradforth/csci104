CXX = g++
CXXFLAGS = -Wall -g
all: interpreter

OBJS = ProgramState.o Print.o Let.o Add.o Sub.o Return.o GoSub.o GoTo.o End.o PrintAll.o Mult.o Div.o If.o


interpreter: Interpreter.cpp $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

Print.o: PrintStatement.cpp
	$(CXX) -c PrintStatement.cpp -o Print.o

Let.o: LetStatement.cpp
	$(CXX) -c LetStatement.cpp -o Let.o

ProgramState.o: ProgramState.cpp
	$(CXX) -c ProgramState.cpp -o ProgramState.o
	
Add.o: AddStatement.cpp
	$(CXX) -c AddStatement.cpp -o Add.o

Sub.o: SubStatement.cpp
	$(CXX) -c SubStatement.cpp -o Sub.o

Return.o: ReturnStatement.cpp
	$(CXX) -c ReturnStatement.cpp -o Return.o

GoSub.o: GoSubStatement.cpp
	$(CXX) -c GoSubStatement.cpp -o GoSub.o

GoTo.o: GoToStatement.cpp
	$(CXX) -c GoToStatement.cpp -o GoTo.o

End.o: EndStatement.cpp
	$(CXX) -c EndStatement.cpp -o End.o

PrintAll.o: PrintAllStatement.cpp
	$(CXX) -c PrintAllStatement.cpp -o PrintAll.o

Mult.o: MultStatement.cpp
	$(CXX) -c MultStatement.cpp -o Mult.o

Div.o: DivStatement.cpp
	$(CXX) -c DivStatement.cpp -o Div.o

If.o: IfStatement.cpp
	$(CXX) -c IfStatement.cpp -o If.o

.PHONY: clean
clean:
	rm $(OBJS)