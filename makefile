FLAGS += -Wall -Werror --std=c++17
USER_DIR_S = build/src
USER_DIR_T = build/test
EXECUTABLE = bin/program
TEST = bin/test
GOOGLE_TEST_DIR = thirdparty/googletest
GOOGLE_TEST_INCLUDE = thirdparty/googletest/include
LD_FLAGS += -L $(GOOGLE_TEST_DIR)/lib -l gtest_main -l pthread

.PHONY: all clean start

all: $(EXECUTABLE) $(TEST)

$(EXECUTABLE): $(USER_DIR_S)/main.o $(USER_DIR_S)/Verb.o $(USER_DIR_S)/Menu.o
	g++ $(FLAGS) $(USER_DIR_S)/main.o $(USER_DIR_S)/Verb.o $(USER_DIR_S)/Menu.o -o $(EXECUTABLE)

$(USER_DIR_S)/main.o: src/main.cpp
	g++ $(FLAGS) -c src/main.cpp -o $(USER_DIR_S)/main.o

$(USER_DIR_S)/Verb.o: src/Verb.cpp
	g++ $(FLAGS) -c src/Verb.cpp -o $(USER_DIR_S)/Verb.o

$(USER_DIR_S)/Menu.o: src/Menu.cpp
	g++ $(FLAGS) -c src/Menu.cpp -o $(USER_DIR_S)/Menu.o


$(TEST): $(USER_DIR_S)/Verb.o $(USER_DIR_S)/Menu.o $(USER_DIR_T)/Verb_unittest.o $(USER_DIR_T)/Menu_unittest.o
	g++ $(FLAGS) $(LD_FLAGS) $(USER_DIR_S)/Verb.o $(USER_DIR_S)/Menu.o $(USER_DIR_T)/Verb_unittest.o $(USER_DIR_T)/Menu_unittest.o -o $(TEST)

$(USER_DIR_T)/Verb_unittest.o: test/Verb_unittest.cpp
	g++ $(FLAGS) -I $(GOOGLE_TEST_INCLUDE) -I src -c test/Verb_unittest.cpp -o $(USER_DIR_T)/Verb_unittest.o

$(USER_DIR_T)/Menu_unittest.o: test/Menu_unittest.cpp
	g++ $(FLAGS) -I $(GOOGLE_TEST_INCLUDE) -I src -c test/Menu_unittest.cpp -o $(USER_DIR_T)/Menu_unittest.o

start:
	./bin/program

check:
	./bin/test

clean:
	rm -rf $(USER_DIR_S)/*.o
	rm -rf $(USER_DIR_T)/*.o
	rm -rf bin/*
