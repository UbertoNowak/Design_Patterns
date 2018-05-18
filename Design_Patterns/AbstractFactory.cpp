/*
 * AbstractFactory.cpp
 *
 *  Created on: 16 maj 2018
 *      Author: Uberto Nowak
 *      Copyright (C) 2018
 */

#include <iostream>
#include <vector>
#include "AbstractFactory.h"

//#define KOREA

using namespace std;

void Kia_Ceed::create(){
	cout<<"Kia Ceed"<<endl;
}

void Kia_Sportage::create(){
	cout<<"Kia Sportage"<<endl;
}

void Mercedes_B_Class::create(){
	cout<<"Mercedes B Class"<<endl;
}

void Mercedes_GLS::create(){
	cout<<"Mercedes GLS"<<endl;
}

AbstractFactory::~AbstractFactory(){
	cout<<"Dctor AbstractFactory"<<endl;
}

Car* Korean_Factory::createPersonalCityCar(){
	return new Kia_Ceed;
}

Car* Korean_Factory::createSUV(){
	return new Kia_Sportage;
}

Korean_Factory::~Korean_Factory(){
	cout<<"Dctor Korean Factory"<<endl;
}

Car* German_Factory::createPersonalCityCar(){
	return new Mercedes_B_Class;
}

Car* German_Factory::createSUV(){
	return new Mercedes_GLS;
}

German_Factory::~German_Factory(){
	cout<<"Dctor German Factory"<<endl;
}

void Abstract_Factory_Example(){

	AbstractFactory* Factory;

	#ifdef KOREA
	  Factory = new Korean_Factory;
	#else // GERMAN
	  Factory = new German_Factory;
	#endif

	vector<Car*> carArray;

	carArray.push_back( Factory->createPersonalCityCar() );
	carArray.push_back( Factory->createSUV() );

	carArray[0]->create();
	carArray[1]->create();

	delete Factory;
}

