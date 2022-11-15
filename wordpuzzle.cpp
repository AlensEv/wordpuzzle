
//  main.cpp
//  project 1
// Alens Evra
//  Created by Al E on 9/13/22.
// This is a  word puzzle word searching game that uses functions and 1d array to print print out a 2d array grid / to run this program I used terminal
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int nrows;
int ncols;
char* input;
char* output;

// reads and minipulates the word chars coming form printGrid
bool isWordAtInput(string word, int r, int c, int rincr, int cincr){
    for (int i =0; i<word.length(); i++) {
        if((c<0 || c>= ncols )|| (r<0 || r >= nrows ) || word[i] != input [r*ncols+c]){
            return false;
        }
        r += rincr;
        c += cincr;
    }
    return true; // return true when errors werent found with the isWordAtinput chars
}
//
void setWordAtOutput(string word, int r, int c, int rincr, int cincr)
{
    for(int i=0; i < word.length(); i++)
    {
        char j = word.at(i);
        output[r*ncols+c]= j;
        c += cincr;
        r = r + rincr;
       
    }
}


bool initGame(string filename) {
    ifstream file (filename);
    /// checks for file
    if (!file.is_open()) {
        cout << filename << "I couldnt locate this file "<< endl;
      return false;
    }
    // reading rows and cols values
    file >> nrows;
    file >> ncols;
    output = new char[nrows* ncols];
    input = new char [nrows* ncols];
   

    for (int i=0; i < nrows*ncols; i++){
        file >> input[i];
        output[i]='-'; // output grid layout with dash later to be replaced with each word character
    }
    return true;
}
void printGrid(char grid[]) {
    for (int r=0; r < nrows; r++){
        for(int c =0; c<ncols; c++){
            int i= r*ncols+c;
            cout << grid[i] <<" " ;
        }
        cout << endl;
        
        }
    }

// find word fucntion is used to find if chars are all in the organization of the word. It checks in all directions to complete this operation
void findWord(string word){
    for (int c=0; c<ncols; ++c) for (int r=0; r< nrows; ++r){
        {
            
            // each of these signify which direction the the grid will print either vertical diagnal horizontal
            // /1 & 0 control the direction of the matrix
            // There are a total of 9 nine direction in which this the word can read
            if (isWordAtInput(word, r, c, 0, -1))
            {setWordAtOutput(word, r,c,0,-1);}
            if (isWordAtInput(word, r, c, 1, 0))
            {setWordAtOutput(word,r,c,1, 0);} //  down
            if (isWordAtInput(word, r, c, 0, -1))
            {setWordAtOutput(word,r,c,0,-1);}
            if (isWordAtInput(word, r, c, 0, -1))
            {setWordAtOutput(word,r,c,0,-1);}
            if (isWordAtInput(word, r, c, 0, -1))
            {setWordAtOutput(word,r,c,0,-1);}
            if (isWordAtInput(word, r, c, 1, 1))
            {setWordAtOutput(word,r,c,1,1);}
            if (isWordAtInput(word, r, c, 0, -1))
            {setWordAtOutput(word,r,c,0,-1);}
            if (isWordAtInput(word, r, c, 0, 1))
            {setWordAtOutput(word,r,c,0,1);}
            if (isWordAtInput(word, r, c, 1, -1))
            {setWordAtOutput(word,r,c,1,-1);}
        }}
}


// main
int main(int argc, char* argv[]) {
    string filename(argv[1]);
 
    if (!initGame(filename)) { return -1; }
    printGrid(input);
 
    for (int i=2; i<argc; ++i) {
        string word(argv[i]);
        cout << "Searching for " << word << endl;
        findWord(word);
    }
 
    printGrid(output);
    delete input;
    delete output;
}
