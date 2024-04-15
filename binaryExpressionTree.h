#pragma once
#include <iostream>
#include <string>
using namespace std;

template <typename Type>
class binaryTreeType;

template <typename Type>
struct nodeType {
	Type info;
	nodeType<Type>* lLink;
	nodeType<Type>* rLink;
};

class binaryExpressionTree: public binaryExpressionTree
{
protected:
public:
};

