#include <Python.h>

typedef struct TSLanguage TSLanguage;

TSLanguage *tree_sitter_cfml(void);
TSLanguage *tree_sitter_cfhtml(void);
TSLanguage *tree_sitter_cfscript(void);

static PyObject* _binding_language_cfml(PyObject *Py_UNUSED(self), PyObject *Py_UNUSED(args)) {
    return PyCapsule_New(tree_sitter_cfml(), "tree_sitter.Language", NULL);
}

static PyObject* _binding_language_cfhtml(PyObject *Py_UNUSED(self), PyObject *Py_UNUSED(args)) {
    return PyCapsule_New(tree_sitter_cfhtml(), "tree_sitter.Language", NULL);
}

static PyObject* _binding_language_cfscript(PyObject *Py_UNUSED(self), PyObject *Py_UNUSED(args)) {
    return PyCapsule_New(tree_sitter_cfscript(), "tree_sitter.Language", NULL);
}

static PyMethodDef methods[] = {
    {"language_cfml", _binding_language_cfml, METH_NOARGS,
     "Get the tree-sitter language for CFML."},
    {"language_cfhtml", _binding_language_cfhtml, METH_NOARGS,
     "Get the tree-sitter language for CFHTML."},
    {"language_cfscript", _binding_language_cfscript, METH_NOARGS,
     "Get the tree-sitter language for CFSCRIPT."},
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
