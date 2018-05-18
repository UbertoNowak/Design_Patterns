/*
 * FactoryMethod.cpp
 *
 *  Created on: 16 maj 2018
 *      Author: Uberto Nowak
 *      Copyright (C) 2018
 */

#include <iostream>
#include <vector>
#include "FactoryMethod.h"

using namespace std;

// Client class
void FactoryMethodExample(){

	vector<Fruit*> shop;

	for(int i=0; i<4; ++i){
		shop.push_back( Fruit::createFruit(i) );
	}

	for(int i=0; i<4; ++i){
		if(shop[i] != NULL){
			shop[i]->printFruit();
		}
	}
}

// factory method creates different objects of class Fruit
Fruit* Fruit::createFruit(int choise){
	switch(choise){
		case 0:
			return new Apple;
		case 1:
			return new Orange;
		case 2:
			return new Lemon;
		default:
			cout<<"Wrong choise"<<endl;
			return NULL;
	}
}

Fruit::~Fruit(){
	cout<<"Dctor Fruit"<<endl;
}

void Apple::printFruit(){
	cout<<"Apple"<<endl;
}

Apple::~Apple(){
	cout<<"Dctor Apple"<<endl;
}

void Orange::printFruit(){
	cout<<"Orange"<<endl;
}

Orange::~Orange(){
	cout<<"Dctor Orange"<<endl;
}

void Lemon::printFruit(){
	cout<<"Lemon"<<endl;
}

Lemon::~Lemon(){
	cout<<"Dctor Lemon"<<endl;
}
