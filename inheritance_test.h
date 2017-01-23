#pragma once

#include "allhead.h"

namespace inheritance_test {
	class Grandpa {
	public:
		Grandpa() {
			age = 99;
			who = "Grandpa";
		}
		virtual void Foo() {
			cout << who << " is " << age << " now" << endl;
		}
		// virtual 
		~Grandpa() {
			cout << who << " is " << age << " now" << endl;
			cout << "Grandpa is old" << endl;
		}
		int age;
		string who;
	};

	class Father : public Grandpa {
	public:
		Father() {
			age = 50;
			who = "Father";
		}
		virtual void Foo() {
			cout << who << " is " << age << " now" << endl;
		}
		//virtual 
		~Father() {
			Foo();
			cout << "Father is strong" << endl;
		}
	};

	class Son : public Father {
	public:
		Son() {
			age = 20;
			who = "Son";
		}
		virtual void Foo() {
			cout << who << " is " << age << " now" << endl;
		}
		//virtual 
		~Son() {
			cout << who << " is " << age << " now" << endl;
			cout << "Son is young" << endl;
		}

	};

	void test() {
		Grandpa* grandpa;
		grandpa = new Father();
		// grandpa->Foo();
		delete grandpa;
		grandpa = new Son();
		//grandpa->Foo();
		delete grandpa;
		
	}
}