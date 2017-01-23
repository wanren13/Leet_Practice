#pragma once

#include "allhead.h"

namespace car_rental_design {
	class CAR;
	typedef shared_ptr<CAR> CARPtr;


	enum PACKAGE_TYPE {
		REGULAR,
		ADDTIONAL_ROW,
		SPORTS
	};

	class Package {
	public:
		virtual int getAddtionalSeat() { return 0; }
		virtual string getAdditionalPacakge () { return string(); }
	};

	class SUVThirdRowPackage : public Package {
	public:
		int getAddtionalSeat() {
			return 3;
		}
		string getAdditionalPacakge() {
			return string("Add Third Row");
		}
	};

	class SEDANSportsPackage : public Package {
	public:
		string getAdditionalPacakge() {
			return string("Sport");
		}
	};

	
	class CAR {
	public:
		CAR(){}
		CAR(string br, int s) : brand(br), seats(s) {}
		virtual void setLicense(string lp) { license_plate = lp; }
		virtual int numOfSeats() { return seats; }
		virtual string getPacakges() { return ""; }
		virtual void addPackage(shared_ptr<Package> p) { package = p; }
		virtual string getBrand() const { return brand; }
		virtual string getLicensePlate() const { return license_plate; }
		friend ostream& operator<<(ostream& os, CARPtr& obj);
	protected:
		string brand;
		string license_plate;
		shared_ptr<Package> package;
		int seats;
	};

	ostream& operator<<(ostream& os, CARPtr& car) {
		os << "Brand: " << car->getBrand() << endl;
		os << "License Plate: " << car->getLicensePlate() << endl;
		os << "Number of Seats: " << car->numOfSeats() << endl;
		os << "Package Installed: " << car->getPacakges() << endl;		
		return os;
	}


	class SUV :public CAR {
	public:
		SUV(string brand, int seats) :CAR(brand, seats) {}
	};

	class SEDAN :public CAR {
	public:
		SEDAN(string brand, int seats) :CAR(brand, seats) {}
	};

	class CARUPGRADE : public CAR {
	public:
		CARUPGRADE(CARPtr c) : car(c) {}
		void setLicense(string lp) { 
			car->setLicense(lp); 
		}
		string getBrand() const { 
			return car->getBrand();
		}
		string getLicensePlate() const { 
			return car->getLicensePlate(); 
		}
		int numOfSeats() {
			return car->numOfSeats() + package->getAddtionalSeat();
		}
		string getPacakges() {
			return car->getPacakges() + package->getAdditionalPacakge() + string(" ");
		}
	protected:
		CARPtr car;
	};
	

	class SUVThirdRowUpgrade : public CARUPGRADE {
	public:
		SUVThirdRowUpgrade(CARPtr c) : CARUPGRADE(c) {
			addPackage(shared_ptr<Package>(new SUVThirdRowPackage()));
		}
	};

	class SEDANSportsUpgrade : public CARUPGRADE {
	public:
		SEDANSportsUpgrade(CARPtr c) : CARUPGRADE(c) {
			addPackage(shared_ptr<Package>(new SEDANSportsPackage()));
		}
	};

	class CARFactory {
	public:
		virtual CARPtr orderNewCar(string brand, int seats, PACKAGE_TYPE type) = 0;
	};

	class SUVFactory :public CARFactory {
	public:
		CARPtr orderNewCar(string brand, int seats, PACKAGE_TYPE type) {
			CARPtr car = CARPtr(new SUV(brand, seats));
			if (type == ADDTIONAL_ROW)
				car = CARPtr(new SUVThirdRowUpgrade(car));

			return car;
		}
	};

	class SEDANFactory :public CARFactory {
	public:
		CARPtr orderNewCar(string brand, int seats, PACKAGE_TYPE type) {
			CARPtr car = CARPtr(new SEDAN(brand, seats));
			if (type == SPORTS)
				car = CARPtr(new SEDANSportsUpgrade(car));

			return car;
		}
	};

	class CarRental {
	public:
		void listAllCars() const {
			cout << "Car List:" << endl << endl;
			for (CARPtr c : cars) {
				cout << c << endl;
			}
		}

		const vector<CARPtr>& getAllCars() {
			return cars;
		}

		void addCars() {
			shared_ptr<CARFactory> SUVFact = shared_ptr<CARFactory>(new SUVFactory());
			shared_ptr<CARFactory> SEDANFact = shared_ptr<CARFactory>(new SEDANFactory());

			CARPtr car;
			int FIVE_SEATS = 5;
			car = SUVFact->orderNewCar("TOYOTA", FIVE_SEATS, REGULAR);
			car->setLicense("YHJ789");
			cars.push_back(car);

			car = SUVFact->orderNewCar("HONDA", FIVE_SEATS, ADDTIONAL_ROW);
			car->setLicense("JIOY76");
			cars.push_back(car);

			car = SEDANFact->orderNewCar("HYUNDAI", FIVE_SEATS, SPORTS);
			car->setLicense("DFVB52");
			cars.push_back(car);

			car = SEDANFact->orderNewCar("MERCEDES-BENZ", FIVE_SEATS, SPORTS);
			car->setLicense("ER456N");
			cars.push_back(car);

			car = SEDANFact->orderNewCar("BYD", FIVE_SEATS, REGULAR);
			car->setLicense("MLK23R");
			cars.push_back(car);
		}

	private:
		vector<CARPtr> cars;
	};
	

	void test() {
		CarRental store;
		store.addCars();
		//store.listAllCars();
		vector<CARPtr> cars = store.getAllCars();

		cout << "List All Cars with 5 seats:" << endl << endl;
		for (CARPtr car : cars) {
			if (car->numOfSeats() == 5) {
				cout << car << endl;
			}
		}

		cout << "List All Cars with 8 seats:" << endl << endl;
		for (CARPtr car : cars) {
			if (car->numOfSeats() == 8) {
				cout << car << endl;
			}
		}
	}
}