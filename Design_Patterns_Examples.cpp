//============================================================================
// Name        : Design_Patterns_Examples.cpp
// Author      : Uberto Nowak
// Version     :
// Copyright   : Copyright (C) 2018
// Description : Design Patterns Examples
//============================================================================

#include <iostream>

#include "Design_Patterns/AbstractFactory.h"
#include "Design_Patterns/FactoryMethod.h"
#include "Design_Patterns/Builder.h"
#include "Design_Patterns/Singleton.h"

#include "Design_Patterns/Adapter.h"
#include "Design_Patterns/Composite.h"

using namespace std;

int main() {

	// Creational Design Patterns
	//----------------------------
	//Abstract_Factory_Example();
	//FactoryMethodExample();
	//BuilderExample();
	//SingletonExample();

	// Structural Design Patterns
	//----------------------------
	//AdapterExample();
	CompositeExample();


	cout << "Done" << endl;
	return 0;
}
