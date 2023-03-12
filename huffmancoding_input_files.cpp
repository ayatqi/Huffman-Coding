// *********************************************************
// Program: Group01_num04_huffmancoding_input_files.cpp
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
#include<iostream>
#include<string>
#include<random>
#include<fstream>
#include<set>

using namespace std;

int main() {
    // Create a string of possible characters
    string characters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    // words count
    int count[5] = {10,50,100,1000,10000};
    string fileIn[5]={"huffmancoding_00000010_input","huffmancoding_00000050_input","huffmancoding_00000100_input"
    , "huffmancoding_00001000_input","huffmancoding_00010000_input"};


    for(int x=0; x<5; x++){

        // Open a file for writing
        ofstream out_file(fileIn[x] + ".txt");

        // Create a random number generator
        random_device rd;
        mt19937 rng(rd());

        // Create a uniform distribution over the possible characters
        uniform_int_distribution<int> dist(0, characters.size() - 1);

        // Create a uniform distribution over the possible word lengths
        uniform_int_distribution<int> word_length_dist(4, 6);


            string allword[count[x]];

            // Generate 10 random words
            for (int i = 0; i <count[x]; i++) {
            // Generate a random word by selecting random characters from the string
            string word;

            int word_length = word_length_dist(rng);
            for (int j = 0; j < word_length; j++) {
            word += characters[dist(rng)];
            }

                allword[i] = word;
            }

            // Create a set to store the unique letters
            set<char> letters;

          // Iterate through the array of words
          for (const auto &word1 : allword) {
            // Iterate through the letters in each word
            for (const auto &c : word1) {
              // Insert the letter into the set
              letters.insert(c);
            }
          }

          int UniqueChar = 0;
          for (const auto &c : letters) {
            UniqueChar = UniqueChar+ 1;
          }

          out_file<< UniqueChar << ' '<<endl;
          //cout<<UniqueChar<<endl;

          for (const auto &c : letters) {
            out_file << c << ' '<<endl;
            //cout<<c<<endl;
          }



            for(int i=0; i<count[x];i++){
                // Write the word to the file
                out_file << allword[i]<<" ";
                //cout<<allword[i]<<" ";
            }

        // Displaying the output file in the screen
       ifstream in(fileIn[x] + ".txt");


        string out;
        while (getline(in, out))
            cout << out << endl;

        // Close the file
        out_file.close();
    }


    return 0;
}
