/*
 * Visitor.h
 *
 *  Created on: 24 maj 2018
 *      Author: Uberto Nowak
 *      Copyright (C) 2018
 */

#ifndef VISITOR_H_
#define VISITOR_H_

class Visitor;

// 1. Add an accept(Visitor) method to the Element hierarchy
class Element{
public:
	virtual void accept(Visitor &visitor) = 0;
	virtual ~Element();
};

// 2. Create concrete elements
class TaxiCompany_A : public Element{
public:
	void accept(Visitor &visitor);
};

class TaxiCompany_B : public Element{
public:
	void accept(Visitor &visitor);
};

// 3. Create a Visitor witch visit() method for every element type
class Visitor{
public:
	virtual void visit_A(TaxiCompany_A *taxi) = 0;
	virtual void visit_B(TaxiCompany_B *taxi) = 0;
	virtual ~Visitor();
};

// 4. Create a  concrete visitors
class Customer_A : public Visitor{
public:
	void visit_A(TaxiCompany_A *taxi);
	void visit_B(TaxiCompany_B *taxi);
};

class Customer_B : public Visitor{
public:
	void visit_A(TaxiCompany_A *taxi);
	void visit_B(TaxiCompany_B *taxi);
};

void VisitorExample();

#endif /* VISITOR_H_ */
