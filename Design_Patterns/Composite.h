/*
 * Composite.h
 *
 *  Created on: 22 maj 2018
 *      Author: Uberto Nowak
 *      Copyright (C) 2018
 */

#ifndef COMPOSITE_H_
#define COMPOSITE_H_

#include <vector>

// Component
class Tree{
public:
	virtual void traverse() = 0;
	virtual ~Tree();
};

// Leaf
class Leaf : public Tree{
	int value;

public:
	Leaf(int val);
	~Leaf();
	void traverse();
};

// Composite
class Composite : public Tree{
	std::vector <Tree*> children;
	int value;

public:
	Composite(int val);
	~Composite();
	void traverse();
	void addChild(Tree* child);

};

void CompositeExample();

#endif /* COMPOSITE_H_ */
