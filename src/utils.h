#include <iostream>
#include <fstream>
#include <random>

using namespace std;

string getLastLineOfFile(ifstream *fs);
int getRandomNumInRange(int range_from, int range_to);
void error(const char *err);