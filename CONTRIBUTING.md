# Contributing

1. Follow **[README — Development](README.md#development)** for supported Node versions, `npm install`, `npm test`, and `npm run lint`.

2. Keep **`npm test`** and **`npm run lint`** green; CI runs both.

3. After grammar or scanner changes, run **`npm run build`** and include updated files under each dialect’s `cf*/src/` when the change is finished.

For scope or design questions, open an issue when useful.

## Releasing to PyPI

The `Release` workflow (`.github/workflows/release.yml`) builds wheels with `cibuildwheel`
and an sdist with `build`, then publishes to PyPI using
[trusted publishing](https://docs.pypi.org/trusted-publishers/) (OIDC, no stored token).
Before the first release, a PyPI project owner must register a trusted publisher for
`tree-sitter-cfml` (new projects can do this via "pending publisher" before any upload
has happened):

- Publisher: GitHub Actions
- Repository: `cfmleditor/tree-sitter-cfml`
- Workflow: `release.yml`
- Environment: `pypi`

Also create a `pypi` [environment](https://docs.github.com/en/actions/deployment/targeting-different-environments/using-environments-for-deployment)
in the repo settings (optionally with required reviewers) so the `publish-pypi` job's
`environment: pypi` matches.
