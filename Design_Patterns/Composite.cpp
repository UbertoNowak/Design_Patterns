/*
 * Composite.cpp
 *
 *  Created on: 22 maj 2018
 *      Author: Uberto Nowak
 *      Copyright (C) 2018
 */

#include <iostream>
#include "Composite.h"

using namespace std;

Tree::~Tree() {
	cout<< "Tree Dctor" <<endl;
}

Leaf::Leaf(int val) {
	value = val;
}

Leaf::~Leaf() {
	cout<< "Leaf Dctor" <<endl;
}

void Leaf::traverse() {
	cout<< value <<" ";
}

Composite::Composite(int val) {
	value = val;
}

void Composite::traverse() {
    cout << "Row" << value << ":  ";
    for (int i = 0; i < children.size(); i++)
      children[i]->traverse();
}

Composite::~Composite() {
	cout<< "Composite Dctor" <<endl;
}

void Composite::addChild(Tree* child) {
	children.push_back(child);
}

void CompositeExample() {

	Composite tree[3] = { 1, 2, 3};

	tree[0].addChild( new Leaf(10) );
	tree[1].addChild( new Leaf(20) );
	tree[2].addChild( new Leaf(30) );

	tree[0].addChild( new Leaf(11) );

	tree[1].addChild( new Leaf(21) );
	tree[1].addChild( new Leaf(22) );

	for(int i=0; i<3; ++i){
		tree[i].traverse();
		cout<<endl;
	}
}


