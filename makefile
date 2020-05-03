FLAGS = -Wall -Werror --std=c++17
USER_DIR_S = build/src
EXECUTABLE = bin/program

all: $(EXECUTABLE)

$(EXECUTABLE): $(USER_DIR_S)/main.o $(USER_DIR_S)/Verb.o $(USER_DIR_S)/Menu.o
	g++ $(FLAGS) $(USER_DIR_S)/main.o $(USER_DIR_S)/Verb.o $(USER_DIR_S)/Menu.o -o $(EXECUTABLE)

$(USER_DIR_S)/main.o: src/main.cpp
	g++ $(FLAGS) -c src/main.cpp -o $(USER_DIR_S)/main.o

$(USER_DIR_S)/Verb.o: src/Verb.cpp
	g++ $(FLAGS) -c src/Verb.cpp -o $(USER_DIR_S)/Verb.o

$(USER_DIR_S)/Menu.o: src/Menu.cpp
	g++ $(FLAGS) -c src/Menu.cpp -o $(USER_DIR_S)/Menu.o

clean:
	rm -rf $(USER_DIR_S)/*.o
	rm -rf bin/*