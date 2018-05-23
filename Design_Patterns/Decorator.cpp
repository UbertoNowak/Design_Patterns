/*
 * Decorator.cpp
 *
 *  Created on: 23 maj 2018
 *      Author: Uberto Nowak
 *      Copyright (C) 2018
 */

#include <iostream>
#include "Decorator.h"

using namespace std;

Abstract_LOTR::~Abstract_LOTR() {
	cout<< "Abstract Dctor" <<endl;
}

LOTR_Character::LOTR_Character(string n) {
	name = n;
}

LOTR_Character::~LOTR_Character() {
	cout<< "Character Dctor" <<endl;
}

void LOTR_Character::display() {
	cout<< name;
}

Decorator::Decorator(Abstract_LOTR* name){
	Charakter = name;
}

void Decorator::display() {
	Charakter->display();
}

elf::elf(Abstract_LOTR* name) : Decorator(name) {
}

void elf::display() {
	cout<< "Elf ";
	Decorator::display();
}

dwarf::dwarf(Abstract_LOTR* name) : Decorator(name){
}

void dwarf::display() {
	cout<< "Dwarf ";
	Decorator::display();
}

archer::archer(Abstract_LOTR* name) : Decorator(name) {
}

void archer::display() {
	cout<< "Archer ";
	Decorator::display();
}

axeman::axeman(Abstract_LOTR* name) : Decorator(name){
}

void axeman::display() {
	cout<< "Axeman ";
	Decorator::display();
}

void DecoratorExample() {

	Abstract_LOTR *Legolas = new archer( new elf( new LOTR_Character("Legolas") ) );
	Abstract_LOTR *Gimli = new axeman( new dwarf( new LOTR_Character("Gimli") ) );

	Legolas->display();
	cout<<endl;
	Gimli->display();
	cout<<endl;

	delete Legolas;
	delete Gimli;

}
