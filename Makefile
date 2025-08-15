# self-note: make runs the first target by default

all: # 1st target
	g++ -o ./build/autotrie ./src/main.cpp ./src/trie.cpp ./src/trienode.cpp
	./build/autotrie

clean: # 2nd target
	rm ./build/*