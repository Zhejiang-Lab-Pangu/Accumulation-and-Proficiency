#include <pybind11/pybind11.h>
namespace py = pybind11;

#include "func0.h"


PYBIND11_MODULE(func0, m)
{
	m.def("add", &add, "A function that adds two numbers",
		py::arg("i") = 1, py::arg("j") = 3);

	m.attr("answer") = 44;

	py::object world = py::cast("world");
	m.attr("name") = world;

}