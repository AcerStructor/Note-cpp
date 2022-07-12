CC = g++
PROGRAM_NAME = "Money Values.exe"
SRC_FILES = MoneyValues.cpp
OBJECT_FILES = MoneyValues.o

Build: Compile Link

Link: $(OBJECT_FILES)
	$(CC) -o $(PROGRAM_NAME) $(OBJECT_FILES)

Compile: $(SRC_FILES)
	$(CC) -c $(SRC_FILES)

.PHONY : clean
clean:
	del $(PROGRAM_NAME) $(OBJECT_FILES)