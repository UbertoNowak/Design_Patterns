/*
 * Observer.h
 *
 *  Created on: 23 maj 2018
 *      Author: Uberto Nowak
 *      Copyright (C) 2018
 */

#ifndef OBSERVER_H_
#define OBSERVER_H_

class Observer;

// 1. Subject
class SecuritySystem{
	int state;
	// 1.1 Create views of Observers
	std::vector <Observer*> views;
public:
	// 1.2 Create attach of Observers
	void attach(Observer *o);
	// 1.3 Create notify function
	void notify();

	int getState();
	void setState(int value);

};

// 2. Observer interface
class Observer{
	// 2.1 Create Subject Model
	SecuritySystem *system;
	int value;

public:
	// 2.2 Observers register themselves with the Subject
	Observer(SecuritySystem *s, int val);
	virtual ~Observer(){};
    virtual void update() = 0;
    SecuritySystem* getSystem();
    int getValue();
    void setValue(int val);

};

// 3. Create many other Observers
class AlarmNode : public Observer{
public:
	AlarmNode(SecuritySystem *s, int val) : Observer(s, val){};
	void update();
};

class Door : public Observer{
public:
	Door(SecuritySystem *s, int val) : Observer(s, val){};
	void update();
};

class Phone : public Observer{
public:
	Phone(SecuritySystem *s, int val) : Observer(s, val){};
	void update();
};

void ObserverExample();

#endif /* OBSERVER_H_ */
