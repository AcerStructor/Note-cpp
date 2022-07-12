CC = g++
PROGRAM_NAME = "Raw Pointer Exercise.exe"
SRC_FILES = RawPointerExercise.cpp
OBJECT_FILES = RawPointerExercise.o

Build: Compile Link

Link: $(OBJECT_FILES)
	$(CC) -o $(PROGRAM_NAME) $(OBJECT_FILES)

Compile: $(SRC_FILES)
	$(CC) -c  $(SRC_FILES)

.PHONY : clean
clean:
	del $(OBJECT_FILES) $(PROGRAM_NAME)