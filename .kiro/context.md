# tree-sitter-cfml Project Context

## Project Overview
CFML grammar for tree-sitter. This is a multi-grammar project with three parsers:
- `cfml/` - Main CFML grammar
- `cfhtml/` - CFHTML grammar
- `cfscript/` - CFScript grammar

## Build Commands

### Generate parsers
```bash
npm run build
# or
make generate
```

### Build for playground
```bash
npm run prestart
```

## Testing

### Run all tests
```bash
npm test
# or
make test
```

### Test Node.js bindings
```bash
npm run testbindings
```

### Parse examples
```bash
npm run parse
```

## Development

### Start playground
```bash
npm start
# or
npm run playground
```

### Generate documentation WASM
```bash
npm run docswasm
```

## Project Structure
- `cfml/`, `cfhtml/`, `cfscript/` - Individual grammar directories with grammar.js and src/
- `common/` - Shared code and HTML entities
- `scripts/` - Build and utility scripts
- `test/` - Test files
- `bindings/` - Language bindings (Node, Python, Rust, Go, Swift)
- `queries/` - Tree-sitter queries
