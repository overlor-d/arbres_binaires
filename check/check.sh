echo "Partie 1 : bst basics"
echo "============================"
gcc -o test test_get_key_bt_p.c -L. -lmybintree -I. && ./test
gcc -o test test_get_elt_size_bt_p.c -L. -lmybintree -I. && ./test
gcc -o test test_get_elt_bt_p.c -L. -lmybintree -I. && ./test
gcc -o test test_deepness_node_bt_p.c -L. -lmybintree -I. && ./test
gcc -o test test_height_bt_p.c -L. -lmybintree -I. && ./test
gcc -o test test_print_mode.c -L. -lmybintree -I. && ./test

gcc -o test test_search_bst.c -L. -lmybintree -I. && ./test
gcc -o test test_insertion_remove_bst.c -L. -lmybintree -I. && ./test
gcc -o test test_convert_print.c -L. -lmybintree -I. && ./test
gcc -o test test_insert_root.c -L. -lmybintree -I. && ./test

