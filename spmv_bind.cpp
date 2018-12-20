// DO NOT EDIT: this file is generated

#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>
#include <pybind11/complex.h>

#include "spmv.cpp"

namespace py = pybind11;

void _spmv(
              const int n,
    py::array_t<int> & Ap,
    py::array_t<int> & Aj,
 py::array_t<double> & Ax,
 py::array_t<double> & Xx,
 py::array_t<double> & Yx
           )
{
    auto py_Ap = Ap.unchecked();
    auto py_Aj = Aj.unchecked();
    auto py_Ax = Ax.unchecked();
    auto py_Xx = Xx.unchecked();
    auto py_Yx = Yx.mutable_unchecked();
    const int *_Ap = py_Ap.data();
    const int *_Aj = py_Aj.data();
    const double *_Ax = py_Ax.data();
    const double *_Xx = py_Xx.data();
    double *_Yx = py_Yx.mutable_data();

    return spmv(
                        n,
                      _Ap, Ap.shape(0),
                      _Aj, Aj.shape(0),
                      _Ax, Ax.shape(0),
                      _Xx, Xx.shape(0),
                      _Yx, Yx.shape(0)
                );
}

PYBIND11_MODULE(spmv, m) {
    m.doc() = R"pbdoc(
    Pybind11 bindings for spmv.cpp

    Methods
    -------
    spmv
    )pbdoc";

    py::options options;
    options.disable_function_signatures();

    m.def("spmv", &_spmv,
        py::arg("n"), py::arg("Ap").noconvert(), py::arg("Aj").noconvert(), py::arg("Ax").noconvert(), py::arg("Xx").noconvert(), py::arg("Yx").noconvert(),
R"pbdoc(
)pbdoc");

}

