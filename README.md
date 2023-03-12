# Huffman-Coding-C++

## There are three different coding files :

### huffmancoding_00000003_output.cpp
##### struct MinHeapNode: 
A node that stores a character, its frequency, and pointers to its left and right children in a Huffman tree.
##### struct compare: 
A comparator that compares two MinHeapNode objects based on their frequency and character value.
##### void printCodes: 
A function that generates and stores the Huffman codes for each character in a given set of frequencies.
##### void printCodes:
A function that recursively traverses the Huffman tree and appends 0 or 1 to the code string depending on whether it goes left or right. It also stores the code in the codes array according to the symbols_str string.
##### void HuffmanCodes: 
A function that builds a Huffman tree from the data and freq arrays using a min heap. It then calls printCodes to generate and store the codes for each character.
##### int main: 
The main function that reads the input file and extracts the number of unique characters, their frequencies, and the text. It then calls HuffmanCodes to encode the text using Huffman coding. It also writes some statistics to an output file and displays them on the screen.

### huffmancoding_input_files.cpp
##### int main: 
A function that creates five files with different numbers of random words composed of uppercase letters. It also writes the number and list of unique letters in each file. It uses random number generators and distributions to create the words and a set to store the unique letters.

### huffmancoding_outputs.cpp
##### struct MinHeapNode:
A structure that stores a character, its frequency, and pointers to its left and right children in a Huffman tree.
##### struct compare:
A structure that defines a comparison function for two MinHeapNode objects based on their frequency and character value.
##### void printCodes:
A function that recursively traverses the Huffman tree and appends 0 or 1 to the code string depending on whether it goes left or right. It also stores the code in the codes array according to the symbols_str string.
##### void printCodes: 
A function that generates and stores the Huffman codes for each character by traversing the Huffman tree from the root node and passing a string, a symbols string, and a codes array as parameters.
##### void HuffmanCodes:
A function that builds a Huffman tree from an array of characters and their frequencies using a priority queue of MinHeapNode objects. It then calls printCodes to generate and store the codes in an array of strings.
##### int main: 
A function that reads an input file with unique characters and their frequencies, calls HuffmanCodes to generate the codes, writes them to an output file along with other information such as total bits and space percentage, measures the execution time, and displays the output file on the screen.
