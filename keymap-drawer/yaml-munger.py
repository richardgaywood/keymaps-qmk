#!/usr/bin/env python3

import yaml, sys

color_group_munges = {
  'SYMBOLS' : {
      '\'': '1',
      '`': '1',
      '"': '1',

      '[': '2', ']': '2',
      '(': '2', ')': '2',
      '{': '2', '}': '2',

      '!': '3',
      '<': '3',
      '>': '3',
      '=': '3',
      '!': '3',

      '&': '4',
      '|': '4',
      '~': '4',

      '+': '5',
      '-': '5',
      '/': '5',
      '*': '5',

  }
}

def process_key(key, layer_name, row_idx, col_idx):
    # sys.stderr.write(f'KEY IS <<{key}>>\n')
    # sys.stderr.write(f'LAYER IS <<{layer}>>\n')
    if type(key) is str and layer_name in color_group_munges and key in color_group_munges[layer_name]:
        return {'t': key, 'type': 'colour-group-' + color_group_munges[layer_name][key]}
    return "";

data = yaml.safe_load(sys.stdin.read())

layer_name = 'SYMBOLS'
layer = data['layers'][layer_name];

for row_idx, row in enumerate(layer):
    for col_idx, key in enumerate(row):
        new_key = process_key(key, layer_name, row_idx, col_idx)

        if(new_key):
            # super lazy; print debugging info to stderr because script main output goes to stdout
            # sys.stderr.write(f'changing key on layer {layer_name}, row {row_idx}, col {col_idx}\n')
            # sys.stderr.write(f'Old: <<{key}>>\n')
            # sys.stderr.write(f'New: <<{new_key}>>\n')

            data['layers'][layer_name][row_idx][col_idx] = new_key

yaml.dump(data, sys.stdout, sort_keys=False)
