#include "utils.h"

using namespace std;

/**
 * @brief return the last line of the file
 * @param fs pointer to an already 'opened' ifstream
 * @note Taken from https://stackoverflow.com/a/37522062/4244964
*/
string getLastLineOfFile(ifstream *fs)
{
    //Go to the last character before EOF
    fs->seekg(-1, ios_base::end);
    bool keepLooping = true;
    while (keepLooping)
    {
        char ch;
        fs->get(ch); // Get current byte's data

        if ((int)fs->tellg() <= 1)
        {                        // If the data was at or before the 0th byte
            fs->seekg(0);        // The first line is the last line
            keepLooping = false; // So stop there
        }
        else if (ch == '\n')
        {                        // If the data was a newline
            keepLooping = false; // Stop at the current position.
        }
        else
        {                                 // If the data was neither a newline nor at the 0 byte
            fs->seekg(-2, ios_base::cur); // Move to the front of that data, then to the front of the data before it
        }
    }

    string lastLine;
    getline(*fs, lastLine); // Read the current line
    return lastLine;
}

/**
 * @brief Get a random number within a range
 * @note taken from https://stackoverflow.com/a/7560564/4244964
*/
int getRandomNumInRange(int range_from, int range_to)
{
    std::random_device rand_dev;
    std::mt19937 generator(rand_dev());
    std::uniform_int_distribution<int> distr(range_from, range_to);
    return distr(generator);
}

void error(const char *err)
{
    std::cout << err << "\n";
    return;
}