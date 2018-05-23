/*
 * Proxy.cpp
 *
 *  Created on: 23 maj 2018
 *      Author: hubert
 */

#include <iostream>
#include <vector>
#include "Proxy.h"

using namespace std;

Subject::~Subject() {
	cout<< "Subject Dctor" <<endl;
}

Image::Image() {
	cout<< "Image Ctor" <<endl;
}

Image::~Image() {
	cout<< "Image Dctor" <<endl;
}

void Image::draw() {
	cout<< "Draw Iamge " <<endl;
}

Proxy::Proxy() {
	real_Image = new Image();
}

Proxy::~Proxy() {
	cout<< "Proxy Dctor" <<endl;
	delete real_Image;
}

void Proxy::draw() {
	real_Image->draw();
}

void ProxyExample() {

	Proxy* p = new Proxy();
	p->draw();

	delete p;

}
