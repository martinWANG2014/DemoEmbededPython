#include <Python.h>
#include <iostream>
int main(int argc, char**argv) {
    Py_Initialize();
    PyRun_SimpleString("import sys");
    PyRun_SimpleString("sys.path.append(\"../../pyscript/\")");
    PyObject* pModule = PyImport_ImportModule("inverse_sigma");
    PyObject*pFunc, *pArgs, *pValue;
    if (pModule != NULL) {
        pFunc = PyObject_GetAttrString(pModule, "inverse_var_sigma_1");
    }
    if (pFunc && PyCallable_Check(pFunc)) {
        pArgs = PyTuple_New(3);
    }
    PyTuple_SetItem(pArgs, 0, PyInt_FromLong(15));
    PyTuple_SetItem(pArgs, 1, PyInt_FromLong(60));
    PyTuple_SetItem(pArgs, 2, PyFloat_FromDouble(0.95));
    pValue = PyObject_CallObject(pFunc, pArgs);
    std::cout << PyFloat_AsDouble(pValue) << std::endl;
    Py_Finalize();
}