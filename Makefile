# self-note: make runs the first target by default

all: # 1st target
	g++ -Iinclude ./src/main.cpp ./src/Trie.cpp ./src/TrieNode.cpp -o ./build/autotrie
	./build/autotrie

clean: # 2nd target
	rm ./build/*

debug:
	g++ -Iinclude ./src/main.cpp ./src/Trie.cpp ./src/TrieNode.cpp -g -o ./build/autotrie_debug
	gdb ./build/autotrie_debug