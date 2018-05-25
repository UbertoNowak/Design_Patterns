/*
 * Visitor.cpp
 *
 *  Created on: 24 maj 2018
 *      Author: Uberto Nowak
 *      Copyright (C) 2018
 */

#include <iostream>
#include "Visitor.h"

using namespace std;

Element::~Element() {
	cout<< "Element Dtor" <<endl;
}

void TaxiCompany_A::accept(Visitor& visitor) {
	visitor.visit_A(this);
}

void TaxiCompany_B::accept(Visitor& visitor) {
	visitor.visit_B(this);
}

Visitor::~Visitor() {
	cout<< "Visitor Dctor" <<endl;
}

void Customer_A::visit_A(TaxiCompany_A* taxi) {
	cout<< "Client A visit in Taxi A" <<endl;
}

void Customer_A::visit_B(TaxiCompany_B* taxi) {
	cout<< "Client A visit in Taxi B" <<endl;
}

void Customer_B::visit_A(TaxiCompany_A* taxi) {
	cout<< "Client B visit in Taxi A" <<endl;
}

void Customer_B::visit_B(TaxiCompany_B* taxi) {
	cout<< "Client B visit in Taxi B" <<endl;
}

void VisitorExample() {

	Customer_A Client_A;
	Customer_B Client_B;
	TaxiCompany_A Taxi_A;
	TaxiCompany_B Taxi_B;

	Taxi_A.accept(Client_A);
	Taxi_A.accept(Client_B);

	Taxi_B.accept(Client_A);
	Taxi_B.accept(Client_B);
}
