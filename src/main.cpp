#include <iostream>
#include <bitset>
#include <stdbool.h>
#include <stdint.h>
#include "utils.h"

using namespace std;

int main(int argc, char *argv[])
{

    int output1 = 1234;
    int output2 = 5678;
    bitset<8> output3 = output1;

    cout << endl;
    cout << "Output 1: " << output1 << endl;
    cout << "Output 2: " << output2 << endl;
    cout << "Output 3: " << output3 << endl;
    cout << endl;

    return 0;
}