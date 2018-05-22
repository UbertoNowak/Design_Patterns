/*
 * Singleton.h
 *
 *  Created on: 22 maj 2018
 *      Author: Uberto Nowak
 *      Copyright (C) 2018
 */

#ifndef SINGLETON_H_
#define SINGLETON_H_

// Singleton
class President {
public:
	// getInstance function
	static President* election();
	static void SetNewPresident(std::string name);
	static std::string WhoIsThePresident();

	~President();

protected:
	President();

private:
	static President* static_instance;
	static std::string name;
};

void SingletonExample();

#endif /* SINGLETON_H_ */
