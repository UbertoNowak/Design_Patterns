/*
 * Adapter.cpp
 *
 *  Created on: 22 maj 2018
 *      Author: Uberto Nowak
 *      Copyright (C) 2018
 */

#include <iostream>
#include "Adapter.h"

using namespace std;

EuropeanSocket::~EuropeanSocket() {
	cout<< "EU Dctor" <<endl;
}

BritishSocket::~BritishSocket() {
	cout<< "UK Dctor" <<endl;
}

int Socket::voltage() {
	return 240;
}

Wire Socket::L() {
	return 1;
}

Wire Socket::N() {
	return -1;
}

Wire Socket::PE() {
	return 0;
}

void Adapter::plugIn(BritishSocket* socket) {
	uk_socket = socket;
}

int Adapter::voltage() {
	return 230;
}

Wire Adapter::L() {
	return uk_socket->L();
}

Wire Adapter::N() {
	return uk_socket->N();
}

Wire Adapter::PE() {
	return uk_socket->N();
}

void BatteryCharger::plugIn(EuropeanSocket* socket) {
	eu_socket = socket;
}

void BatteryCharger::charge() {
	cout<< "Power supply: " << eu_socket->voltage() <<endl;
	cout<< "L:" << eu_socket->L() <<", N:"<< eu_socket->N() <<", PE:"<< eu_socket->PE() <<endl;
}

void AdapterExample() {
	Socket* socket = new Socket;
	Adapter* adapter = new Adapter;
	BatteryCharger* charger = new BatteryCharger;

	adapter->plugIn(socket);
	charger->plugIn(adapter);

	charger->charge();

	delete socket;
	delete adapter;
	delete charger;
}


