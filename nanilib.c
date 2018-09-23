#include "nanilib.h"
#include <unistd.h>
#include <stdio.h>
#include <sys/ioctl.h>
#include <stdlib.h>

struct padding {
    int left_padding;
    int top_padding;
    int bottom_padding;
};

int get_expansion_of_text(int window_columns){
    return window_columns/40;
}

struct padding get_padding(int expansion, int window_columns){
    int extra_spaces = window_columns% 40;
    struct padding pad = {
        extra_spaces/2,
        expansion,
        2*expansion
    };
    return pad;
}



void print_Lines(char *array_of_lines){
    for(int i = 0; i < sizeof(&array_of_lines) / sizeof(&array_of_lines[0]); i++){
        puts(&array_of_lines[i]);
    }
}

void generate_ascii_art(int window_rows, int window_columns){
    int expansion = get_expansion_of_text(window_columns);
    struct padding pad = get_padding(expansion,window_columns);
    int string_length = pad.left_padding + (40 * expansion) + 1;
    int number_of_lines_for_text = 5 * expansion;
    int number_of_rows = pad.top_padding + number_of_lines_for_text + pad.bottom_padding;
    char lines_of_text[number_of_rows][number_of_lines_for_text];


}

void nani(char message[]) {
    struct winsize window;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &window);
    generate_ascii_art(window.ws_row, window.ws_col);
    printf("lines %d\n", window.ws_row);
    printf("columns %d\n", window.ws_col);
    printf("Hello, World!\n");
}