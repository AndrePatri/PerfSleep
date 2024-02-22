// Copyright (C) 2023  Andrea Patrizi (AndrePatri, andreapatrizi1b6e6@gmail.com)
// 
// This file is part of PerfSleep and distributed under the General Public License version 2 license.
// 
// PerfSleep is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 2 of the License, or
// (at your option) any later version.
// 
// PerfSleep is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with PerfSleep.  If not, see <http://www.gnu.org/licenses/>.
// 
#include <pybind11/pybind11.h>

#include <perf_sleep/perf_sleep.h>

namespace py = pybind11;

PYBIND11_MODULE(pyperfsleep, m) {

    m.doc() = "Python binding for high-precision sleep";

    py::class_<PerfSleep>(m, "PerfSleep")
            .def(py::init())
            .def_static("thread_sleep", &PerfSleep::thread_sleep, "sleep with high precision using thread");
            // .def("clock_sleep", &PerfSleep::clock_sleep, "sleep with high precision using clock_nanosleep");
            
}