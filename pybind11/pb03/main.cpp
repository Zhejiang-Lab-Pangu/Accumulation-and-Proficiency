#include"object.h"
#include <pybind11/pybind11.h>

namespace py = pybind11;



/*面向对象 -- 继承和自动推导*/


PYBIND11_MODULE(example1, m)
{
	py::class_<Pet>(m, "Pet")
		.def(py::init<const std::string &, int>())
		.def_readwrite("name", &Pet::name)
		.def_readwrite("age", &Pet::age)
		// overloaded method
		.def("set", py::overload_cast<int>(&Pet::set), "Set the pet's age")
		.def("set", py::overload_cast<const std::string &>(&Pet::set), "Set the pet's name")
		.def("set", py::overload_cast<int, int>(&Pet::set, py::const_), "Set the pet's name")
		;

	// Method 1: template parameter:
	py::class_<Dog, Pet >(m, "Dog")
		.def(py::init<const std::string &>())
		.def("bark", &Dog::bark); 
	


	/*方法2：先实例化再继承*/
	/*
	 py::class_<Pet> pet(m, "Pet");
	 pet.def(py::init<const std::string &>())
	    .def_readwrite("name", &Pet::name);
	 
	 py::class_<Dog>(m, "Dog", pet)
	 .def(py::init<const std::string &>())
	 .def("bark", &Dog::bark);
	 */


	// 多态
	m.def("pet_store", []() { return std::unique_ptr<Pet>(new Dog("Molly")); });	// 父类指针指向子类对象，如果没有虚函数，则不能实现多态； 那么python端访问不到子类成员函数

	
	// 枚举类型
	py::class_<PPet> ppet(m, "PPet");
	ppet.def(py::init<const std::string &, PPet::Kind>())
		.def_readwrite("name", &PPet::name)
		.def_readwrite("type", &PPet::type)
		.def_readwrite("attr", &PPet::attr);

	py::enum_<PPet::Kind>(ppet, "Kind")
		.value("Dog", PPet::Kind::Dog)
		.value("Cat", PPet::Kind::Cat)
		.export_values();

	py::class_<PPet::Attributes>(ppet, "Attributes")
		.def(py::init<>())
		.def_readwrite("age", &PPet::Attributes::age);



}



