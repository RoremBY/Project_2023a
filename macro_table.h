typedef struct macro {
    char* name;
    char* content;
} macro;


macro create_macro(char* name, char* content);
int add_macro(macro* macro_array, macro m, int index, int current_size);
void copy_macro(macro source, macro *destination);
char* get_name(macro m);
char* get_content(macro m);
void set_name(macro m, char* name);
void set_content(macro m, char* content);