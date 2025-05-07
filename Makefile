sofle-rg:
	qmk compile -kb sofle -km rg -e CONVERT_TO=elite_pi

	@keymapviz -t fancy keyboards/sofle/keymaps/rg/keymap.c
	@keymapviz -r keyboards/sofle/keymaps/rg/keymap.c > /dev/null

	@qmk c2json -kb sofle -km rg -o keymap-drawer/$@.qmk.json --no-cpp

    # this could all be one single piped operation but I like to \
	  keep the YAML and JSON files around for convenience \
	  NB: can use this to get layer names automatically: \
	   https://github.com/jbarr21/keymap-display/blob/main/scripts/json2yaml
	@keymap -c keymap-drawer/keymap-drawer.conf parse \
		-c 12 \
		--layer-names QWERTY COMMANDS SYMBOLS ADJUST NUMPAD \
		-q keymap-drawer/$@.qmk.json \
		-o keymap-drawer/$@.k-d.yaml
	@./keymap-drawer/yaml-munger.py \
	     < keymap-drawer/$@.k-d.yaml \
		 > keymap-drawer/$@.k-d_munged.yaml
	@keymap -c keymap-drawer/keymap-drawer.conf \
	    draw keymap-drawer/$@.k-d_munged.yaml \
		-o $@.svg


bad-wings-rg1:
	qmk compile -kb hazel/bad_wings_v2 -km rg1

	qmk c2json -kb hazel/bad_wings_v2 -km rg1 -o keymap-drawer/$@.qmk.json --no-cpp

	keymap -c keymap-drawer/keymap-drawer.conf parse \
		-c 12 \
		--layer-names QWERTY COMMANDS SYMBOLS ADJUST NUMPAD MOUSE \
		-q keymap-drawer/$@.qmk.json \
		-o keymap-drawer/$@.k-d.yaml
	./keymap-drawer/yaml-munger.py \
	     < keymap-drawer/$@.k-d.yaml \
		 > keymap-drawer/$@.k-d_munged.yaml
	keymap -c keymap-drawer/keymap-drawer.conf \
	    draw keymap-drawer/$@.k-d_munged.yaml \
		--qmk-info-json qmk_firmware/keyboards/hazel/bad_wings_v2/info.json \
		-o $@.svg
