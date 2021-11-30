#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <set>
#include "utils.h"

using namespace std;

int main(int argc, char *argv[])
{

    ifstream file;            // input file
    vector<string> colors;    // array to hold bulb colors
    vector<int> quantities;   // array to hold bulb quantities
    set<int> pickedBulbs;     // represented as an index

    // 
    if (argc == 1) {
        error("File does not exist. Please specify a valid path to file as a command line argument");
        return 0;
    };

    file.open(argv[1]);

    if (!file.good()) {
        error("File does not exist. Please specify a valid path to file as a command line argument");
        return 0;
    }

    /**
     * @brief Pull out the last line of the file and convert it to an integer
    */
    stringstream lastLineOfFile(getLastLineOfFile(&file));
    int numBulbsToPick = 0;
    lastLineOfFile >> numBulbsToPick;
    file.close(); // reset file


    /**
     * @brief Parse the input file by seperating strings and numbers and inserting these as values into two seperate vector arrays
    */
    file.open(argv[1]);

    char currChar;
    char prevChar;
    string str;
    while (file.get(currChar))
    {
        if (isspace(currChar)) {

            if (isdigit(prevChar)) {
                // convert str to int
                stringstream nums(str);
                int quant = 0;
                nums >> quant;
                quantities.push_back(quant);       // add int to array of quantities
            } else {
                colors.push_back(str.c_str());     // add color to array of color strings
            }
            str.clear();

        } else {
            str.push_back(currChar);
        }

        prevChar = currChar; // we use the currChar for detecting spaces and new lines and the prevChar for differentiating strings from integers
    }
    

    /**
     * @brief "Pick" the Bulbs
    */     
    for (int i = 0; i < numBulbsToPick; i++)
    {
        // get a random number between 0 and colors.size();
        int randomIndex = getRandomNumInRange(0, colors.size());
        bool bulbPicked = false;
        
        // use this number as an index and "pick" a lightbulb
        while (!bulbPicked)
        {    
            if (quantities[randomIndex] != 0) {        // if there are any bulbs left of this color, pick it
                pickedBulbs.insert(randomIndex);
                quantities[randomIndex] -= 1;
                bulbPicked = true;
            } else {                                   // otherwise, pick again
                randomIndex = getRandomNumInRange(0, colors.size());
            }
        }
    }

    // Print results to console
    cout << endl;
    cout << numBulbsToPick << " total bulbs picked." << endl;
    cout << pickedBulbs.size() << " unique colors." << endl;
    cout << endl;

    file.close();
    return 0;
}