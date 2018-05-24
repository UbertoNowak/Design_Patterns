/*
 * Strategy.cpp
 *
 *  Created on: 24 maj 2018
 *      Author: Uberto Nowak
 *      Copyright (C) 2018
 */

#include <iostream>
#include "Strategy.h"

using namespace std;

Transport_Strategy::~Transport_Strategy() {
	cout<< "Transport Strategy Dctor" <<endl;
}

void Taxi::transport() {
	cout<< "by Taxi" <<endl;
}

void Bus::transport() {
	cout<< "by Bus" <<endl;
}

void Train::transport() {
	cout<< "by Train" <<endl;
}

Person::Person() {
	strategy = NULL;
	cout<< "Person Ctor" <<endl;
}

Person::~Person() {
	cout<< "Person Dtor" <<endl;
	delete strategy;
}

void Person::setStrategy(int type) {

	delete strategy;

	switch(type){
		case TAXI:
			strategy = new Taxi;
			break;
		case BUS:
			strategy = new Bus;
			break;
		case TRAIN:
			strategy = new Train;
			break;
		default:
			cout<< "Strategy error" <<endl;
			break;
	}
}

void Person::transport_to_airport() {
	cout<< "Person transport to airport ";
	strategy->transport();
}

void StrategyExample() {

	Person Client;

	Client.setStrategy(Person::TAXI);
	Client.transport_to_airport();

	Client.setStrategy(Person::BUS);
	Client.transport_to_airport();

	Client.setStrategy(Person::TRAIN);
	Client.transport_to_airport();
}
