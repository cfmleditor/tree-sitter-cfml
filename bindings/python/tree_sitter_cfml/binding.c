#include <Python.h>

typedef struct TSLanguage TSLanguage;

TSLanguage *tree_sitter_cfml(void);
TSLanguage *tree_sitter_cfhtml(void);

static PyObject* _binding_language_cfml(PyObject *self, PyObject *args) {
    return PyLong_FromVoidPtr(tree_sitter_cfml());
}

static PyObject* _binding_language_cfhtml(PyObject *self, PyObject *args) {
    return PyLong_FromVoidPtr(tree_sitter_cfhtml());
}


static PyMethodDef methods[] = {
    {"language_cfml", _binding_language_cfml, METH_NOARGS,
     "Get the tree-sitter language for Cfml."},
    {"language_cfhtml", _binding_language_cfhtml, METH_NOARGS,
     "Get the tree-sitter language for Cfhtml."},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef module = {
    .m_base = PyModuleDef_HEAD_INIT,
    .m_name = "_binding",
    .m_doc = NULL,
    .m_size = -1,
    .m_methods = methods
};

PyMODINIT_FUNC PyInit__binding(void) {
    return PyModule_Create(&module);
}
