CC = g++
PROGRAM_NAME = "Smart Pointer Exercise.exe"
HEADER_FILES = Test.hpp
SRC_FILES = SmartPointerExercise.cpp
OBJECT_FILES = SmartPointerExercise.o

Build: Compile Link

Link: $(OBJECT_FILES)
	$(CC) -o $(PROGRAM_NAME) $(OBJECT_FILES)

Compile: $(SRC_FILES) $(HEADER_FILES)
	$(CC) -c  $(SRC_FILES)

.PHONY : clean
clean:
	del $(OBJECT_FILES) $(PROGRAM_NAME)