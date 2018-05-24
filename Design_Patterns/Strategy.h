/*
 * Strategy.h
 *
 *  Created on: 24 maj 2018
 *      Author: Uberto Nowak
 *      Copyright (C) 2018
 */

#ifndef STRATEGY_H_
#define STRATEGY_H_

// Abstract Interface
class Transport_Strategy {
public:
	virtual ~Transport_Strategy();
	virtual void transport() = 0;
};

// Different strategy of transport
class Taxi : public Transport_Strategy{
public:
	void transport();
};

class Bus : public Transport_Strategy{
public:
	void transport();
};

class Train : public Transport_Strategy{
public:
	void transport();
};

// Context
class Person{
	Transport_Strategy *strategy;
public:
	Person();
	~Person();

	enum TransportType{
		TAXI, BUS, TRAIN
	};

	void setStrategy(int type);
	void transport_to_airport();
};

void StrategyExample();

#endif /* STRATEGY_H_ */
