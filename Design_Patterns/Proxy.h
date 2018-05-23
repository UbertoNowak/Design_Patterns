/*
 * Proxy.h
 *
 *  Created on: 23 maj 2018
 *      Author: hubert
 */

#ifndef PROXY_H_
#define PROXY_H_

// 1. Abstract Interface
class Subject{
public:
	virtual ~Subject();
	virtual void draw() = 0;
};

// Data consume object
class Image : public Subject{
public:
	Image();
	~Image();
	void draw();

};

class Proxy : public Subject{

	Subject* real_Image;

public:
	Proxy();
	~Proxy();
	void draw();
};

void ProxyExample();

#endif /* PROXY_H_ */
