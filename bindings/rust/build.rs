fn main() {
    let root_dir = std::path::Path::new(".");
    let cfml_dir = root_dir.join("cfml").join("src");
    let cfhtml_dir = root_dir.join("cfhtml").join("src");
    let cfscript_dir = root_dir.join("cfscript").join("src");
    let common_dir = root_dir.join("common");

    let mut config = cc::Build::new();
    config.include(&cfml_dir);
    config
        .flag_if_supported("-std=c11")
        .flag_if_supported("-Wno-unused-parameter")
        .flag_if_supported("-Wno-unused-value")
        .flag_if_supported("-Wno-implicit-fallthrough");

    let mut config = cc::Build::new();
    config.include(&cfml_dir);

    for path in &[
        cfml_dir.join("parser.c"),
        cfml_dir.join("scanner.c"),
        cfhtml_dir.join("parser.c"),
        cfhtml_dir.join("scanner.c"),
        cfscript_dir.join("parser.c"),
        cfscript_dir.join("scanner.c"),
    ] {
        config.file(path);
        println!("cargo:rerun-if-changed={}", path.to_str().unwrap());
    }

    println!(
        "cargo:rerun-if-changed={}",
        common_dir.join("scanner.h").to_str().unwrap()
    );

    config.compile("tree-sitter-cfml");
}