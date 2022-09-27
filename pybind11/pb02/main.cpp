#include"func1.h"
#include <pybind11/pybind11.h>

namespace py = pybind11;

/*面向对象*/


PYBIND11_MODULE(example, m) {

	py::class_<Pet>(m, "Pet", py::dynamic_attr())
		.def(py::init<const std::string &>())
		.def("setName", &Pet::setName)
		.def("getName", &Pet::getName)


		// lambda函数
		.def("__repr__",
			[](const Pet &a) {return "<example.Pet named '" + a.name + "'>"; })		// __repr__ 是python类的

		// 改变私有属性在python端可访问
		.def_readwrite("name", &Pet::name);

		// 动态属性 ->> 在定义时添加py::dynamic_attr()	python端定义完可直接访问


		

}
