# self-notes: 
# -> make runs the first target by default
# -> header files not in the same directory as src, so we have to specify their location with -I(directory)

all: # 1st target
	g++ -Iinclude ./src/main.cpp ./src/Trie.cpp ./src/TrieNode.cpp -o ./build/autotrie
	./build/autotrie

clean: # 2nd target
	rm ./build/*

debug:
	g++ -Iinclude ./src/main.cpp ./src/Trie.cpp ./src/TrieNode.cpp -g -o ./build/autotrie_debug
	gdb ./build/autotrie_debug