/*
 * Decorator.h
 *
 *  Created on: 23 maj 2018
 *      Author: Uberto Nowak
 *      Copyright (C) 2018
 */

#ifndef DECORATOR_H_
#define DECORATOR_H_

// 1. Abstract Interface
class Abstract_LOTR{
public:
	virtual void display() = 0;
	virtual ~Abstract_LOTR();
};

// 2. Core Functionality
class LOTR_Character : public Abstract_LOTR{
	std::string name;
public:
	LOTR_Character(std::string n);
	~LOTR_Character();
	void display();

};

// 3. Second level base class
class Decorator : public Abstract_LOTR {
	// 4. Create instance of Abstract Interface
	Abstract_LOTR* Charakter;

public:
	Decorator(Abstract_LOTR* name);
	void display();
};

// 5. Create optional class
class elf : public Decorator{
public:
	elf(Abstract_LOTR* name);
	void display();
};

class dwarf : public Decorator{
public:
	dwarf(Abstract_LOTR* name);
	void display();
};

class archer : public Decorator{
public:
	archer(Abstract_LOTR* name);
	void display();
};

class axeman : public Decorator{
public:
	axeman(Abstract_LOTR* name);
	void display();
};

void DecoratorExample();

#endif /* DECORATOR_H_ */
