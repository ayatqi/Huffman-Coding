#include <bits/stdc++.h>
#include <algorithm>
#include <chrono>
using namespace std;
using namespace std::chrono;


struct MinHeapNode {


	char data;


	unsigned freq;


	MinHeapNode *left, *right;

	MinHeapNode(char data, unsigned freq)

	{

		left = right = NULL;
		this->data = data;
		this->freq = freq;
	}
};


struct compare {

	bool operator()(MinHeapNode* l, MinHeapNode* r)

	{
		return ((l->freq != r->freq) ? l->freq > r->freq : l->data < r->data);
	}
};


void printCodes(struct MinHeapNode* root, string str, string symbols_str, string codes[])
{

	if (!root)
		return;

	if (root->data != '$') {
		codes[symbols_str.find(root->data)]	= str;
	}

	printCodes(root->left, str + "1", symbols_str, codes);
	printCodes(root->right, str + "0", symbols_str, codes);
}


void HuffmanCodes(char data[], int freq[], int size, string symbols_str, string codes[])
{
	struct MinHeapNode *left, *right, *top;
	priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> minHeap;

	for (int i = 0; i < size; ++i)
		minHeap.push(new MinHeapNode(data[i], freq[i]));

	while (minHeap.size() != 1) {

		left = minHeap.top();
		minHeap.pop();

		right = minHeap.top();
		minHeap.pop();


		top = new MinHeapNode('$', left->freq + right->freq);

		top->left = left;
		top->right = right;

		minHeap.push(top);
	}


	printCodes(minHeap.top(), "", symbols_str, codes);
}

int main() {

	string data, words;
	int size= 0;
    string fileIn[5]={"huffmancoding_00000010_input","huffmancoding_00000050_input","huffmancoding_00000100_input"
    , "huffmancoding_00001000_input","huffmancoding_00010000_input"};

    string fileOut[5]={"huffmancoding_00000010_output","huffmancoding_00000050_output","huffmancoding_00000100_output"
    , "huffmancoding_00001000_output","huffmancoding_00010000_output"};

    for(int i=0; i<5; i++){
        steady_clock::time_point start = steady_clock::now();
        ifstream MyReadFile(fileIn[i] + ".txt");


        MyReadFile >> size;

        char symbols[size] = {};
        int freq[size] = {0};
        string codes[size] = {""};


        for (int i = 0; i < size; i++) {
            MyReadFile >> symbols[i];
        }

        while(getline (MyReadFile, data)) words = data;


        MyReadFile.close();

        for (int i = 0; i < size; i++) {
            for (int j = 0; j < words.size(); j++) {
                if (symbols[i] == words[j]) freq[i]++;
            }

        }



        string symbols_str = symbols;

        HuffmanCodes(symbols, freq, size, symbols_str, codes);


        ofstream outputFile(fileOut[i] + ".txt");


        int total = 0;

        outputFile << size << endl;


        for (int i = 0; i < size; i++) {
            int len = freq[i] * codes[i].size();
            outputFile << symbols[i] << " " << freq[i] << " " << codes[i] << " " << len << endl;
            total += len;
        }

        outputFile << endl;
        words.erase(std::remove_if(words.begin(), words.end(), ::isspace), words.end());
        outputFile << total << "-bit out of " << words.size() * 7 << "-bit" << endl;
        outputFile << "total space " << round(float(total) / float(words.size() * 7) * 100)  << "%" << endl;


        steady_clock::time_point end = steady_clock::now();
        microseconds elapsed_time_micros = duration_cast<microseconds>(end - start);
        double elapsed_time_secs = elapsed_time_micros.count() / 1000000.0;


        outputFile << elapsed_time_secs << "microseconds" << endl;

        outputFile.close();

       ifstream in(fileOut[i] + ".txt");


        string out;
        while (getline(in, out))
            cout << out << endl;
    }

    return 0;
}
