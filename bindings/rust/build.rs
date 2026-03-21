fn main() {
    let root_dir = std::path::Path::new(".");
    let common_dir = root_dir.join("common");

    let flags = [
        "-std=c11",
        "-Wno-unused-parameter",
        "-Wno-unused-value",
        "-Wno-implicit-fallthrough",
    ];

    for (name, dir_name) in &[
        ("tree-sitter-cfml", "cfml"),
        ("tree-sitter-cfhtml", "cfhtml"),
        ("tree-sitter-cfscript", "cfscript"),
        ("tree-sitter-cfquery", "cfquery"),
    ] {
        let src_dir = root_dir.join(dir_name).join("src");
        let mut config = cc::Build::new();
        config.include(&src_dir);
        for flag in &flags {
            config.flag_if_supported(flag);
        }
        for file in &["parser.c", "scanner.c"] {
            let path = src_dir.join(file);
            config.file(&path);
            println!("cargo:rerun-if-changed={}", path.to_str().unwrap());
        }
        config.compile(name);
    }

    println!(
        "cargo:rerun-if-changed={}",
        common_dir.join("scanner.h").to_str().unwrap()
    );
}
