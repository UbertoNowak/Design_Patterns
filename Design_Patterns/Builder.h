/*
 * Builder.h
 *
 *  Created on: 18 maj 2018
 *  	Author: Uberto Nowak
 *      Copyright (C) 2018
 */

#ifndef BUILDER_H_
#define BUILDER_H_

// McDonald's products
class Burger{
public:
	std::string name;

	Burger(std::string name);
};

class Drink{
public:
	std::string name;

	Drink(std::string name);
};

class Accessories{
public:
	std::string name;

	Accessories(std::string name);
};

// Final product
class McDonaldsMeal{
public:
	Burger* burger;
	Drink* drink;
	Accessories* addition;

	void order();
};

// Builder is response for creating all parts
class Builder{
public:
	virtual Burger* createBurger() = 0;
	virtual Drink* createDrink() = 0;
	virtual Accessories* createAccessories() = 0;
	virtual ~Builder();

};

// Builder of HappyMeal
class HappyMeal : public Builder{
public:
	 Burger* createBurger();
	 Drink* createDrink();
	 Accessories* createAccessories();

};

// Builder of McWrap
class McWrap : public Builder{
public:
	 Burger* createBurger();
	 Drink* createDrink();
	 Accessories* createAccessories();

};

// Director is response for whole process
class Director{

	Builder* builder;

public:
	void chooseBuilder(Builder* b);
	McDonaldsMeal* getMeal();
};

void BuilderExample();

#endif /* BUILDER_H_ */
