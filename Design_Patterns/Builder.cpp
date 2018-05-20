/*
 * Builder.cpp
 *
 *  Created on: 18 maj 2018
 *      Author: Uberto Nowak
 *      Copyright (C) 2018
 */

#include <iostream>
#include "Builder.h"

using namespace std;

Burger::Burger(string name) : name(name){
}

Drink::Drink(string name) : name(name) {
}

Accessories::Accessories(string name) : name("Toy"){
	Accessories::name = name;
}

void McDonaldsMeal::order() {
	cout<< "Burger: " << burger->name <<endl;
	cout<< "Drink: " << drink->name <<endl;
	cout<< "Addition: " << addition->name <<endl;
}

Builder::~Builder() {
}

Burger* HappyMeal::createBurger() {
	return new Burger("Hamburger");
}

Drink* HappyMeal::createDrink() {
	return new Drink("Juice");
}

Accessories* HappyMeal::createAccessories() {
	return new Accessories("Awesome Toy");
}

Burger* McWrap::createBurger() {
	return new Burger("Wrap");
}

Drink* McWrap::createDrink() {
	return new Drink("Coke");
}

Accessories* McWrap::createAccessories() {
	return new Accessories("Chips");
}

void Director::chooseBuilder(Builder* b) {
	builder = b;
}

McDonaldsMeal* Director::getMeal() {

	McDonaldsMeal* meal = new McDonaldsMeal;

	meal->burger = builder->createBurger();
	meal->drink = builder->createDrink();
	meal->addition = builder->createAccessories();

	return meal;
}

void BuilderExample(){
	// Final product
	McDonaldsMeal* Meal;

	// Director
	Director Cashier;

	// Different products
	HappyMeal happyMeal;
	McWrap mcWrap;

	cout<< "1 Client" <<endl;
	Cashier.chooseBuilder(&happyMeal);
	Meal = Cashier.getMeal();
	Meal->order();

	cout<< "2 Client" <<endl;
	Cashier.chooseBuilder(&mcWrap);
	Meal = Cashier.getMeal();
	Meal->order();

}
