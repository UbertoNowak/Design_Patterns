/*
 * FactoryMethod.h
 *
 *  Created on: 16 maj 2018
 *      Author: Uberto Nowak
 *      Copyright (C) 2018
 */

#ifndef FACTORYMETHOD_H_
#define FACTORYMETHOD_H_

class Fruit{
public:
	// Factory Method
	static Fruit* createFruit(int choise);

	virtual void printFruit() = 0;
	virtual ~Fruit();
};

class Apple : public Fruit{
public:
	void printFruit();
	~Apple();
};

class Orange : public Fruit{
public:
	void printFruit();
	~Orange();
};

class Lemon : public Fruit{
public:
	void printFruit();
	~Lemon();
};

void FactoryMethodExample();

#endif /* FACTORYMETHOD_H_ */
