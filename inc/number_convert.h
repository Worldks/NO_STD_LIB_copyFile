#ifndef NUMBER_CONVERTION_SENTRY
#define NUMBER_CONVERTION_SENTRY

enum { max_number_length = 12 };
/* Maybe should add this modul to string_operations.c (cause this module too litle)? */
int str_to_number(const char *str);
void number_to_str(int number, char *str);

#endif
