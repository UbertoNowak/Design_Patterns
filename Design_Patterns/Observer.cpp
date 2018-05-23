/*
 * Observer.cpp
 *
 *  Created on: 23 maj 2018
 *      Author: Uberto Nowak
 *      Copyright (C) 2018
 */

#include <vector>
#include <iostream>
#include "Observer.h"

using namespace std;

void SecuritySystem::attach(Observer* o) {
	views.push_back(o);
}

void SecuritySystem::notify() {
	for (int i = 0; i < views.size(); i++){
		views[i]->update();
	}
}

int SecuritySystem::getState() {
	return state;
}

void SecuritySystem::setState(int value) {
	state = value;
	notify();
}

Observer::Observer(SecuritySystem* s, int val) {
	value = val;
	system = s;
	// Observers register themselves with the Subject
	system->attach(this);
}

SecuritySystem* Observer::getSystem() {
	return system;
}

int Observer::getValue() {
	return value;
}

void Observer::setValue(int val) {
	value = val;
}

void AlarmNode::update() {

	setValue( getSystem()->getState() );

	if( getValue() ){
		cout<< "AlarmNode OK, state: " << getValue() <<endl;
	}
	else{
		cout<< "Alarm! AlarmNode state: " << getValue() <<endl;
	}
}

void Door::update() {

	setValue( getSystem()->getState() );

	if( getValue() ){
		cout<< "Door OK, state: " << getValue() <<endl;
	}
	else{
		cout<< "Door open! state: " << getValue() <<endl;
	}
}

void Phone::update() {

	setValue( getSystem()->getState() );

	if( getValue() ){
		cout<< "Phone OK, state: " << getValue() <<endl;
	}
	else{
		cout<< "Call to Police! Phone state: " << getValue() <<endl;
	}
}

void ObserverExample(){

	SecuritySystem subject;
	AlarmNode Node(&subject, 1);
	Door MainDoor(&subject, 2);
	Phone SmartPhone(&subject, 3);

	subject.setState(1);
	subject.setState(0);

}


