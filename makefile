FLAGS += -Wall -Werror --std=c++17
USER_DIR_S = build/src
USER_DIR_T = build/test
EXECUTABLE = bin/program
TEST = bin/test

.PHONY: all clean start addDir

GTEST_DIR = thirdparty/googletest

GOOGLE_TEST_INCLUDE = thirdparty/googletest/include

GFLAGS += -isystem $(GTEST_DIR)/include

LDFLAGS += -Wall -Wextra -pthread --std=c++17

all: addDir $(EXECUTABLE) $(TEST)

$(EXECUTABLE): $(USER_DIR_S)/main.o $(USER_DIR_S)/Verb.o $(USER_DIR_S)/Menu.o
	g++ $(FLAGS) $^ -o $@

$(USER_DIR_S)/main.o: src/main.cpp
	g++ $(FLAGS) -c src/main.cpp -o $@

$(USER_DIR_S)/Verb.o: src/Verb.cpp
	g++ $(FLAGS) -c src/Verb.cpp -o $@

$(USER_DIR_S)/Menu.o: src/Menu.cpp
	g++ $(FLAGS) -c src/Menu.cpp -o $@

$(TEST): $(USER_DIR_S)/Verb.o $(USER_DIR_S)/Menu.o $(USER_DIR_T)/Verb_unittest.o $(USER_DIR_T)/Menu_unittest.o $(USER_DIR_T)/gtest_main.a
	g++ $(GFLAGS) $(LDFLAGS) -lpthread $^ -o $@

$(USER_DIR_T)/gtest_main.a: $(USER_DIR_T)/gtest-all.o $(USER_DIR_T)/gtest_main.o
	$(AR) $(ARFLAGS) $@ $^

$(USER_DIR_T)/gtest-all.o :
	g++ -O2 $(GFLAGS) -I$(GTEST_DIR) $(LDFLAGS) -c \
            $(GTEST_DIR)/src/gtest-all.cc -o $@

$(USER_DIR_T)/gtest_main.o :
	g++ -O2 $(GFLAGS) -I$(GTEST_DIR) $(LDFLAGS) -c \
            $(GTEST_DIR)/src/gtest_main.cc -o $@

$(USER_DIR_T)/Verb_unittest.o: test/Verb_unittest.cpp
	g++ $(FLAGS) -I $(GOOGLE_TEST_INCLUDE) -I src -c test/Verb_unittest.cpp -o $@

$(USER_DIR_T)/Menu_unittest.o: test/Menu_unittest.cpp
	g++ $(FLAGS) -I $(GOOGLE_TEST_INCLUDE) -I src -c test/Menu_unittest.cpp -o $@

addDir:
	mkdir -p bin/ build/src build/test/
	./buildgtest.sh

start:
	./bin/program

check:
	./bin/test

clean:
	rm -rf $(USER_DIR_S)/*.o
	rm -rf $(USER_DIR_T)/*.o
	rm -rf bin/*
	rm -rf thirdparty
