// *********************************************************
// Program: Group01_num02_huffmancoding_00000003_output.cpp
// Course: TCP2101 ALGORITHM DESIGN & ANALYSIS
// Class: TC1V
// Trimester: 2110
// Member_1: 1181302169ID | Ahmed, Ahmed Riyadh Mohammed    | 1181302169@student.mmu.edu.my  | +967 733 273 422
// Member_2: 1191202335   | Ayat Abdulaziz Gaber Al-Khulaqi | 1191202335@student.mmu.edu.my  | +60 18-293 6294
// Member_3: 1191102484   | Roha Ali                        | 1191102484@student.mmu.edu.my  | +60 11-2615 5759
// Member_4: 1201303439   | Shawn Slyvester A L Damotharam  | 1201303439@student.mmu.edu.my  | +60 16-582 1302
// *********************************************************
// Task Distribution
// Member_1:
// Member_2:
// Member_3:
// Member_4:
// *********************************************************
// C++(STL) program for Huffman Coding with STL
#include <bits/stdc++.h>
#include <algorithm>
#include <chrono>
using namespace std;
using namespace std::chrono;

// A Huffman tree node
struct MinHeapNode {

	// One of the input characters
	char data;

	// Frequency of the character
	unsigned freq;

	// Left and right child
	MinHeapNode *left, *right;

	MinHeapNode(char data, unsigned freq)

	{

		left = right = NULL;
		this->data = data;
		this->freq = freq;
	}
};


// For comparison of
// two heap nodes (needed in min heap)
struct compare {

	bool operator()(MinHeapNode* l, MinHeapNode* r)

	{
		return ((l->freq != r->freq) ? l->freq > r->freq : l->data < r->data);
	}
};

// Prints huffman codes from
// the root of Huffman Tree.
void printCodes(struct MinHeapNode* root, string str, string symbols_str, string codes[])
{

	if (!root)
		return;

	if (root->data != '$') {
//		cout << root->data << " " << str << "\n";
		codes[symbols_str.find(root->data)]	= str;
	}

	printCodes(root->left, str + "1", symbols_str, codes);
	printCodes(root->right, str + "0", symbols_str, codes);
}

// The main function that builds a Huffman Tree and
// print codes by traversing the built Huffman Tree
void HuffmanCodes(char data[], int freq[], int size, string symbols_str, string codes[])
{
	struct MinHeapNode *left, *right, *top;

	// Create a min heap & inserts all characters of data[]
	priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> minHeap;

	for (int i = 0; i < size; ++i)
		minHeap.push(new MinHeapNode(data[i], freq[i]));

	// Iterate while size of heap doesn't become 1
	while (minHeap.size() != 1) {

		// Extract the two minimum
		// freq items from min heap
		left = minHeap.top();
		minHeap.pop();

		right = minHeap.top();
		minHeap.pop();

		// Create a new internal node with
		// frequency equal to the sum of the
		// two nodes frequencies. Make the
		// two extracted node as left and right children
		// of this new node. Add this node
		// to the min heap '$' is a special value
		// for internal nodes, not used
		top = new MinHeapNode('$', left->freq + right->freq);

		top->left = left;
		top->right = right;

		minHeap.push(top);
	}

	// Print Huffman codes using
	// the Huffman tree built above
	printCodes(minHeap.top(), "", symbols_str, codes);
}

int main() {

	string data, words;
	int size= 0;

	// start measuring execution time
	steady_clock::time_point start = steady_clock::now();

    // Read from the text file
    ifstream MyReadFile("huffmancoding_00000003_input.txt");

    // get the number of characters
    MyReadFile >> size;

    // declare arrays for the characters, their frequencies and their codes
    char symbols[size] = {};
    int freq[size] = {0};
    string codes[size] = {""};

    // loop size times to read the individual characters
    for (int i = 0; i < size; i++) {
    	MyReadFile >> symbols[i];
	}

	// read the last line which is the list of words
    while(getline (MyReadFile, data)) words = data;

    // Close the file
    MyReadFile.close();


	// calcualte the frequencies of character into freq array
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < words.size(); j++) {
			if (symbols[i] == words[j]) freq[i]++;
		}

	}


	// Huffman Code
	string symbols_str = symbols;
	//cout << symbols;
	HuffmanCodes(symbols, freq, size, symbols_str, codes);


	// output... save to file output.txt
	ofstream outputFile("huffmancoding_00000003_output.txt");



	int total = 0;
	// saving the number of unique character in the output file
	outputFile << size << endl;

	// saving the letters with their freq, code and total character bit in the output file
	for (int i = 0; i < size; i++) {
		int len = freq[i] * codes[i].size();
    	outputFile << symbols[i] << " " << freq[i] << " " << codes[i] << " " << len << endl;
    	total += len;
	}

	outputFile << endl;
	words.erase(std::remove_if(words.begin(), words.end(), ::isspace), words.end());
	outputFile << total << "-bit out of " << words.size() * 7 << "-bit" << endl;
	outputFile << "total space " << round(float(total) / float(words.size() * 7) * 100)  << "%" << endl;

	// stop measuring execution time
    steady_clock::time_point end = steady_clock::now();
    microseconds elapsed_time_micros = duration_cast<microseconds>(end - start);
    double elapsed_time_secs = elapsed_time_micros.count() / 1000000.0;

	// saving the total time taken in the output file
	outputFile << elapsed_time_secs << "microseconds" << endl;

	outputFile.close();

	// Displaying the output file in the screen
	ifstream in("huffmancoding_00000003_output.txt");


	string out;
	while (getline(in, out))
        cout << out << endl;

    return 0;
}
