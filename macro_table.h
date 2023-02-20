
/*
 * macro_list, built of:
 * char* name - name of the macro
 * char* content - content of the macro
 * macro_list* next - the next macro on the list
 */
typedef struct macro_list{
    char* name;
    char* content;
    struct macro_list* next;
}macro_list;

/*
 * Function that create a macro_list with name and content and return it.
 * Parameters:
 * name - name of the macro
 * content - content of the macro
 * Returns:
 * The function returns a pointer to a macro_list object with the name and content given, and the next->NULL.
 */
macro_list* create_macro(char* name, char* content);

/*
 * Function that add a new macro_list object to the head.
 * Parameters:
 * head - the head of the macro_list
 * name - name of the new macro
 * content - content of the new macro
 * Returns:
 * The function returns a pointer to the head of the macro_list with the new macro_list at the end of the list.
 */
macro_list* add_macro(macro_list* head, char* name, char* content);

/*
 * Function that returns the name of a macro.
 * Parameters:
 * node - pointer to macro_list object.
 * Returns:
 * The function returns a pointer to the name of the macro.
 */
char* get_name(macro_list* node);

/*
 * Function that returns the content of a macro.
 * Parameters:
 * node - pointer to macro_list object.
 * Returns:
 * The function returns a pointer to the content of the macro.
 */
char* get_content(macro_list* node);