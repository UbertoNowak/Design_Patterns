/*
 * Adapter.h
 *
 *  Created on: 22 maj 2018
 *      Author: Uberto Nowak
 *      Copyright (C) 2018
 */

#ifndef ADAPTER_H_
#define ADAPTER_H_

typedef int Wire;

// Target interface
class EuropeanSocket{
public:
	virtual int voltage() = 0;
	virtual Wire L() = 0;
	virtual Wire N() = 0;
	virtual Wire PE() = 0;
	virtual ~EuropeanSocket();
};

// Adaptee interrace class
class BritishSocket{
public:
	virtual int voltage() = 0;
	virtual Wire L() = 0;
	virtual Wire N() = 0;
	virtual ~BritishSocket();
};

// Adaptee class
class Socket : public BritishSocket{
public:
	int voltage(); 	// 240
	Wire L();		//  1
	Wire N();		// -1
	Wire PE();		// 	0
};

// Adapter to target interface
class Adapter : public EuropeanSocket{

	BritishSocket* uk_socket;

public:
	void plugIn(BritishSocket* adaptee_class);
	int voltage();	// 230
	Wire L();		// UK->L
	Wire N();		// UK->N
	Wire PE();		// UK->N
};

// Client
class BatteryCharger{

	// Target interface
	EuropeanSocket* eu_socket;

public:
	void plugIn(EuropeanSocket* adapter);
	void charge();
};

void AdapterExample();

#endif /* ADAPTER_H_ */
