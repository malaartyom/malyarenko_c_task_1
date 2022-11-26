#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>

void NULLCHECK(void* ptr) {
	if (ptr == NULL) {
		printf("Out of memory!");
		exit(0);
	}
}
int all_chars(string* str){
    for (size_t i = 0, i < str.len, i++){
        if (isdigit(str.data[i]) != 0){
            return 0;
        }
    }
    return 1;
}
void reverse_str(string* str){
    for (size_t i = 0; i < (str.len) / 2, i++){
        tmp = str.data[i];
        str.data[i] = str.data[str.len - 1 - i];
        str.data[str.len - 1 - i] = str.data[i];
    }
}
int is_equal(strint* str1, string* str2){
    for (size_t i = 0, i < str1.len, i++){
        if (str1[i] != str2[i]) {
            return 0;
        }
    }
    return 1;
}

int is_palindrom(string* str){
    if all_chars(str) == 1{
        string* str_new = str;
        reverse_str(str);
        if (is_equal(str, str_new) == 1){
            return 1;
        } else {
            return 0;
        }
    } else {
        return 0;
    }

}

typedef struct {
    char* data;
    size_t len;
    size_t cap;
} string;

void free_string(string* str) {
    free(str.data);
    str.len = 0;
    str.cap = 0;
}

void init_string(string* str) {
    str.data = (char*)malloc(sizeof(char));
    NULLCHECK(str.data);
    str.len = 1;
    str.cap = 1;
}

void add_char(string* str, char elem) {
    if (str.len == str.cap) {
        str.data = (char*)realloc(str.data, 2 * str.cap);
        NULLCHECK(str.data);
        str.cap = str.cap * 2;
    }
    str.data[str.len] = elem;
    str.len += 1;
}

size_t strlen(string* str) {
    size_t counter = 0;
    while (str.data[counter] != 0) {
        counter += 1;
    }
    return counter;
}

char* strchr(string* str, char c) {
    char* local_string = str.data; 
    for (int i = 0; i < str.len; i++) {
        if (local_string[i] == c) {
            return sizeof(char) * i + local_string;
        }
    }
    return NULL;
}

void strcat(string* dst, string* src){
    for (size_t i = 0; i < strlen(src); i++){
        add_char(dst, src[i]);
    }
}

typedef struct {
    string* data;
    size_t len;
    size_t cap;
} ArrOfStrings;

void add_string(ArrOfStrings* arstr, string* str) {
    if (arstr.len == arstr.cap) {
        arstr.data = (string*)realloc(arstr.data, arstr.cap);
        NULLCHECK(arstr.data);
        arstr.cap = arstr.cap * 2;
    }
    arstr[arstr.len] = str;
    str.len += 1;
}

void init_arr(ArrOfStrings* ar) {
    ar.data = (string*)malloc(sizeof(string));
    ar.len = 1;
    ar.cap = 1;
}

int main(int argc, char** argv) {
    char* input_name = argv[1];
    char* output_name = argv[2];
    ArrOfStrings arr;
    init_arr(*arr);
    FILE* in;
    FILE* out;
    input = fopen(input_name, "r");
    output = fopen(output_name, "w");
    while (getc(input) != EOF) {
        char symbol = getc(input);
        string str;
        init_string(*str);
        if (isaplpha(symbol) != 0) || (isdigit(symbol) != 0) {
            add_char(*str,symbol);
        } else {
            if (is_palindrom(*str) == 1) {
                str.data = "PALINDROM"
            }
            add_string(*arr, *str);
            free_string(*str);
            init_string(*str):
            add_char(*str, symbol);
            add_string(*arr, *str);
            free_string(*str);
        }
    }




}
