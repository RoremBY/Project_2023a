typedef struct macro_list{
    char* name;
    char* content;
    struct macro_list* next;
}macro_list;

macro_list* create_empty_macro();
macro_list* create_macro(char* name, char* content);
is_macro_empty(macro_list* node);
macro_list* add_macro(macro_list* head, char* name, char* content);
char* get_name(macro_list* node);
char* get_content(macro_list* node);