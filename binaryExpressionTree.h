#pragma once
#include <iostream>
#include <string>
#include <stack>
#include <cstring>
#include <sstream>

#include "binaryTree.h"

using namespace std;

class binaryExpressionTree : public binaryTreeType<string> {
private:
	double evaluateExpressionTree(nodeType<string>* p) {

	};
public:
	void buildExpressionTree(string& postfix) {
		stack<nodeType<string>*> stck;
		char* expression = new char[postfix.length() + 1];
		strcpy(expression, postfix.c_str());
		char* token = strtok(expression, " ");
		while (token != nullptr) {
			if (isdigit(token[0])) {
				nodeType<string>* newNode = new nodeType<string>;
				newNode->info = token;
				newNode->lLink = nullptr;
				newNode->rLink = nullptr;
				stck.push(newNode);
			}
			else if (token == "+" || token == "-" || token == "*" || token == "/") {
				nodeType<string>* newNode = new nodeType<string>;
				newNode->info = token;
				newNode->rLink = stck.top();
				stck.pop();
				newNode->lLink = stck.top();
				stck.pop();
				stck.push(newNode);
			}
			else {
				cerr << "Unsupported token";
				return;
			}
		}
		if (stck.size() != 1) {
			std::cerr << "Error: Malformed expression" << std::endl;
			return;
		}

		root = stck.top();
		//istringstream iss(postfix);
		//string token;
	}
};
