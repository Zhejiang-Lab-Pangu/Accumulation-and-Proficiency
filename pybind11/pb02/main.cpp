#include"func1.h"
#include <pybind11/pybind11.h>

namespace py = pybind11;

/*�������*/


PYBIND11_MODULE(example, m) {

	py::class_<Pet>(m, "Pet", py::dynamic_attr())
		.def(py::init<const std::string &>())
		.def("setName", &Pet::setName)
		.def("getName", &Pet::getName)


		// lambda����
		.def("__repr__",
			[](const Pet &a) {return "<example.Pet named '" + a.name + "'>"; })		// __repr__ ��python���

		// �ı�˽��������python�˿ɷ���
		.def_readwrite("name", &Pet::name);

		// ��̬���� ->> �ڶ���ʱ���py::dynamic_attr()	python�˶������ֱ�ӷ���


		

}
