#ifndef MENU
#define MENU

#include <string>

int Join();
bool is_valid_choice(const std::string& choice);
void Start(std::string& choice);
int is_valid_number(const std::string& number_of_verbs);
bool check_file(const std::string& file_about);
void About(const std::string& file_about);

#endif