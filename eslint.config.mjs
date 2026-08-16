import treesitter from 'eslint-config-treesitter';

export default [
  {
    ignores: [
      '**/node_modules/**',
      '**/build/**',
      '**/prebuilds/**',
      'docs/**',
      // Third-party code fetched by `npm run corpus:fetch`. Gitignored, but not
      // otherwise hidden from ESLint, and an interrupted fetch leaves whatever
      // the clone contained under `corpus/.work/`.
      'corpus/**',
      '.cursor/**',
      'examples/**',
      'target/**',
    ],
  },
  ...treesitter,
];
