#include <pybind11/pybind11.h>

#include <perf_sleep/perf_sleep.h>

namespace py = pybind11;

PYBIND11_MODULE(pyperfsleep, m) {

    m.doc() = "Python binding for high-precision sleep";

    py::class_<PerfSleep>(m, "PerfSleep")
            .def(py::init())
            .def_static("thread_sleep", &PerfSleep::thread_sleep, "sleep with high precision using thread")
            .def("clock_sleep", &PerfSleep::clock_sleep, "sleep with high precision using clock_nanosleep");
            
}