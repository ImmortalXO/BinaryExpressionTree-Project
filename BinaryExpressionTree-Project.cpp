#include <iostream>
#include <string>
#include <stack>
#include <cstring>
#include <fstream>

#include "binaryExpressionTree.h"

using namespace std;

int main() {
    ifstream inFile("RpnData.txt");
    ofstream outFile("RpnOutputData.txt");

    if (!inFile.is_open() || !outFile.is_open()) {
        cerr << "Error opening the input/output file. Try again.";
        return 1;
    }

    string postfix;
    while (getline(inFile, postfix)) {
        binaryExpressionTree<string> tree;
        tree.buildExpressionTree(postfix);
        double evalResult = tree.evaluateExpressionTree();
        outFile << postfix << " = " << evalResult << endl;
    }

    inFile.close();
    outFile.close();

    return 0;
};