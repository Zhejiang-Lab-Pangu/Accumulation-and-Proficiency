#pragma once
#include<string>


struct Pet {
	Pet(const std::string &name, int age=23) : name(name), age(age) {}
	
	void set(int);
	void set(const std::string &);
	int set(int, int) const;
	
	std::string name;
	int age;

	virtual ~Pet() = default;
	
};

struct Dog : Pet {
	Dog(const std::string &name) : Pet(name) { }
	std::string bark() const { return "woof!"; }
};



struct PPet {
	enum Kind {
		Dog = 0,
		Cat
	};

	struct Attributes {
		float age = 0;
	};

	PPet(const std::string &name, Kind type) : name(name), type(type) { }

	std::string name;
	Kind type;
	Attributes attr;
};