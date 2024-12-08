#!/usr/bin/env python3

import yaml, sys, re

color_group_munges = {
  'SYMBOLS' : {
    #   'color-group-1': '`"\'',
      'color-group-2': '[](){}',
      'color-group-3': '!<>=!',
      'color-group-4': '&|~',
      'color-group-5': '-+/*',
  }
}

nums = re.compile(r'^\d$')
alphas = re.compile(r'^[a-zA-Z]$')
punct = re.compile(r'^([\[\]!"#$%&\'\(\)*+,./:;<=>?@\\^_\-`{|}~])|(NUBS)|(NUHS)$')

def process_key(key, layer_name, row_idx, col_idx):
    # sys.stderr.write(f'KEY IS <<{key}>>\n')
    # sys.stderr.write(f'LAYER IS <<{layer_name}>>\n')
    if type(key) is not str or key == '':
        # not yet supported
        return ""

    if layer_name in color_group_munges:
        for color_group in color_group_munges[layer_name]:
            if key in color_group_munges[layer_name][color_group]:
                return {'t': key, 'type': color_group}
    # default color for all other punctuaton on the symbol layer
    if layer_name == 'SYMBOLS' and punct.match(key):
        return {'t': key, 'type': 'color-group-1'}

    if layer_name == 'QWERTY':
        if nums.match(key): return {'t': key, 'type': 'color-group-1'}
        elif alphas.match(key): return {'t': key, 'type': 'color-group-2'}
        elif punct.match(key): return {'t': key, 'type': 'color-group-1'}
        else: return {'t': key, 'type': 'color-group-3'}

    if layer_name == 'NUMPAD':
        if nums.match(key): return {'t': key, 'type': 'color-group-1'}
        elif alphas.match(key): return {'t': key, 'type': 'color-group-2'}
        elif punct.match(key): return {'t': key, 'type': 'color-group-3'}
        else: return {'t': key, 'type': 'color-group-4'}    
    return "";

data = yaml.safe_load(sys.stdin.read())

for layer_name in data['layers']:
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
