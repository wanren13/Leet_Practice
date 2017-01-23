#pragma once

#include "allhead.h"

namespace singleton_namespace {
	class singleton {
	public :
		static singleton* getInstance() {
			if (!instance) {
				instance = new singleton;
			}
			return instance;
		}
	private:
		static singleton* instance;
		singleton () {}
	};

	singleton* singleton::instance = NULL;

	void test () {
		singleton* instance = singleton::getInstance();
		cout << instance << endl;
		instance = singleton::getInstance();
		cout << instance << endl;
	}
}
 