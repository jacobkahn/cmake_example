#include <pybind11/functional.h>
#include <pybind11/pybind11.h>
#include <functional>
#include <iostream>

namespace py = pybind11;

void myFunc1(int i) {
  std::cout << i << std::endl; // do anything really
}

int myFunc2(int i) {
  return i + 1;
}

PYBIND11_MODULE(cmake_example, m) {
  m.def("myFunc1", myFunc1);
  m.def("myFunc2", myFunc2);
  m.def(
      "some_func_operation",
      [](const std::function<void(int)>& func, int i) -> void {
        std::cout << "void return overload" << std::endl;
        func(i);
      });
  m.def(
      "some_func_operation",
      [](const std::function<int(int)>& func, int i) -> int {
        std::cout << "int return overload" << std::endl;
        return func(i);
      });

#ifdef VERSION_INFO
  m.attr("__version__") = VERSION_INFO;
#else
  m.attr("__version__") = "dev";
#endif
}
