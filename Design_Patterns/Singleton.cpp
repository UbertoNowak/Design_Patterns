/*
 * Singleton.cpp
 *
 *  Created on: 22 maj 2018
 *      Author: Uberto Nowak
 *      Copyright (C) 2018
 */

#include <iostream>
#include "Singleton.h"

using namespace std;

President* President::static_instance = NULL;
string President::name = "George Washington";

President::President(){
	cout<< "Ctor" <<endl;
}

President::~President(){
	cout<< "Dctor" <<endl;
}

President* President::election() {
	if(!static_instance)
		static_instance = new President;

	return static_instance;
}

void President::SetNewPresident(string n) {
	name = n;
}

string President::WhoIsThePresident() {
	return name;
}

void SingletonExample() {
	// President newPresident; -> error: calling a protected constructor of class 'President'
	cout<< President::election()->WhoIsThePresident() <<endl;

	President::election()->SetNewPresident("Abraham Lincoln");
	cout<< President::election()->WhoIsThePresident() <<endl;

	President::election()->SetNewPresident("John F. Kennedy");
	cout<< President::election()->WhoIsThePresident() <<endl;
}

