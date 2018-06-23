CXXFLAGS=-std=c++11 -Wpedantic -Wall -Wextra -Werror -Weffc++ -Wzero-as-null-pointer-constant
CFLAGS=-std=c99 -pedantic -Wall -Wextra -Werror -ansi -Wwrite-strings

Test: testTree.cpp BinarySearchTree.h
	echo ---------compiling testTree.cpp to create executable program testTree-------------
	g++ -ggdb -std=c++11 testTree.cpp -o testTree

clean:
	echo --------removing executable program testTree----------------
	/bin/rm testTree
