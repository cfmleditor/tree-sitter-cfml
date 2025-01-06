#include <napi.h>

typedef struct TSLanguage TSLanguage;

extern "C" TSLanguage *tree_sitter_cfml();
extern "C" TSLanguage *tree_sitter_cfhtml();
extern "C" TSLanguage *tree_sitter_cfscript();

// "tree-sitter", "language" hashed with BLAKE2
const napi_type_tag LANGUAGE_TYPE_TAG = {
  0x8AF2E5212AD58ABF, 0xD5006CAD83ABBA16
};

Napi::Object Init(Napi::Env env, Napi::Object exports) {
    auto cfml = Napi::Object::New(env);
    cfml["name"] = Napi::String::New(env, "cfml");
    auto cfml_language = Napi::External<TSLanguage>::New(env, tree_sitter_cfml());
    cfml_language.TypeTag(&LANGUAGE_TYPE_TAG);
    cfml["language"] = cfml_language;

    auto cfhtml = Napi::Object::New(env);
    cfhtml["name"] = Napi::String::New(env, "cfhtml");
    auto cfhtml_language = Napi::External<TSLanguage>::New(env, tree_sitter_cfhtml());
    cfhtml_language.TypeTag(&LANGUAGE_TYPE_TAG);
    cfhtml["language"] = cfhtml_language;

    auto cfscript = Napi::Object::New(env);
    cfscript["name"] = Napi::String::New(env, "cfscript");
    auto cfscript_language = Napi::External<TSLanguage>::New(env, tree_sitter_cfscript());
    cfscript_language.TypeTag(&LANGUAGE_TYPE_TAG);
    cfscript["language"] = cfscript_language;

    exports["cfml"] = cfml;
    exports["cfhtml"] = cfhtml;
    exports["cfscript"] = cfscript;

    return exports;
}

NODE_API_MODULE(tree_sitter_cfml_binding, Init)
