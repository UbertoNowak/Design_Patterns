/*
 * AbstractFactory.h
 *
 *  Created on: 16 maj 2018
 *      Author: Uberto Nowak
 *      Copyright (C) 2018
 */

#ifndef ABSTRACTFACTORY_H_
#define ABSTRACTFACTORY_H_

class Car{
public:
	virtual void create() = 0;
	virtual ~Car(){};
};

// Kia family
class Kia_Ceed : public Car{
public:
	void create();
};

class Kia_Sportage : public Car{
public:
	void create();
};

// Mercedes Family
class Mercedes_B_Class : public Car{
public:
	void create();
};

class Mercedes_GLS : public Car{
public:
	void create();
};

// Abstract Factory
class AbstractFactory{
public:
	virtual Car* createPersonalCityCar() = 0;
	virtual Car* createSUV() = 0;
	virtual ~AbstractFactory();
};

class Korean_Factory : public AbstractFactory{
public:
	Car* createPersonalCityCar();
	Car* createSUV();
	~Korean_Factory();
};

class German_Factory : public AbstractFactory{
public:
	Car* createPersonalCityCar();
	Car* createSUV();
	~German_Factory();
};

void Abstract_Factory_Example();

#endif /* ABSTRACTFACTORY_H_ */
