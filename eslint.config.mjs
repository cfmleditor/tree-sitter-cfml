import treesitter from 'eslint-config-treesitter';

export default [
  {
    ignores: [
      '**/node_modules/**',
      '**/build/**',
      '**/prebuilds/**',
      'docs/**',
      '.cursor/**',
      'examples/**',
    ],
  },
  ...treesitter,
];
