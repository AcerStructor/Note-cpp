CC = g++
PROGRAM_NAME = "Add Number Lines.exe"
SRC_FILES = AddNumberLines.cpp
OBJECT_FILES = AddNumberLines.o

Build: Compile Link

Link: $(OBJECT_FILES)
	$(CC) -o $(PROGRAM_NAME) $(OBJECT_FILES)

Compile: $(SRC_FILES) $(HEADER_FILES)
	$(CC) -c $(SRC_FILES)

.PHONY : clean
clean:
	del $(OBJECT_FILES) $(PROGRAM_NAME)