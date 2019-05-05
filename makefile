kbc: kbc_dev_gui_functions.c\
 kbc_dev_core_functions.c\
 kbc_dev_main.c

	gcc kbc_dev_gui_functions.c kbc_dev_core_functions.c kbc_dev_main.c \
-o kbc \
`pkg-config --libs gtk+-3.0` `pkg-config --cflags gtk+-3.0` \
-rdynamic
	./kbc