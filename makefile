CFLAGS = g++ -Wall -Werror
USER_DIR_S = build/src
EXECUTABLE = bin/programm

all: $(EXECUTABLE)

$(EXECUTABLE): $(USER_DIR_S)/main.o $(USER_DIR_S)/readFile.o $(USER_DIR_S)/randVerb.o $(USER_DIR_S)/equality.o $(USER_DIR_S)/printForm.o $(USER_DIR_S)/message.o $(USER_DIR_S)/checkVerb.o 
	$(CFLAGS) $(USER_DIR_S)/main.o $(USER_DIR_S)/readFile.o $(USER_DIR_S)/randVerb.o $(USER_DIR_S)/equality.o $(USER_DIR_S)/printForm.o $(USER_DIR_S)/message.o $(USER_DIR_S)/checkVerb.o -o $(EXECUTABLE)

$(USER_DIR_S)/main.o: src/main.cpp
	$(CFLAGS) -c src/main.cpp -o $(USER_DIR_S)/main.o

$(USER_DIR_S)/readFile.o: src/readFile.cpp
	$(CFLAGS) -c src/readFile.cpp -o $(USER_DIR_S)/readFile.o

$(USER_DIR_S)/randVerb.o: src/randVerb.cpp
	$(CFLAGS) -c src/randVerb.cpp -o $(USER_DIR_S)/randVerb.o

$(USER_DIR_S)/equality.o: src/equality.cpp
	$(CFLAGS) -c src/equality.cpp -o $(USER_DIR_S)/equality.o

$(USER_DIR_S)/printForm.o: src/printForm.cpp
	$(CFLAGS) -c src/printForm.cpp -o $(USER_DIR_S)/printForm.o

$(USER_DIR_S)/message.o: src/message.cpp
	$(CFLAGS) -c src/message.cpp -o $(USER_DIR_S)/message.o

$(USER_DIR_S)/checkVerb.o: src/checkVerb.cpp
	$(CFLAGS) -c src/checkVerb.cpp -o $(USER_DIR_S)/checkVerb.o

clean:
	rm -rf $(USER_DIR_S)/*.o
	rm -rf bin/*