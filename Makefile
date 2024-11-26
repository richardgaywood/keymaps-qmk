sofle-rg:
	qmk compile -kb sofle -km rg -e CONVERT_TO=elite_pi
	keymapviz -t fancy keyboards/sofle/keymaps/rg/keymap.c -t fancy
	keymapviz -t json -o keyboards/sofle/keymaps/rg/latest-build.json keyboards/sofle/keymaps/rg/keymap.c	
	keymapviz -r keyboards/sofle/keymaps/rg/keymap.c > /dev/null
