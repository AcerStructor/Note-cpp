CC = g++
PROGRAM_NAME = "Movie Collection.exe"
HEADER_FILES = Movies.hpp Movie.hpp
SRC_FILES = main.cpp Movies.cpp
OBJECT_FILES = main.o Movies.o

Build: Compile Link

Link: $(OBJECT_FILES)
	$(CC) -o $(PROGRAM_NAME) $(OBJECT_FILES)

Compile: $(SRC_FILES) $(HEADER_FILES)
	$(CC) -c  $(SRC_FILES)

.PHONY : clean
clean:
	del $(OBJECT_FILES) $(PROGRAM_NAME)