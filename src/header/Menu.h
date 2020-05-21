#ifndef MENU
#define MENU

#define FILE_VERBS "res/verbs.txt"
#define FILE_ABOUT "res/about.txt"
#define FILE_RULES "res/rules.txt"

#include <string>

int join();
bool is_valid_choice(const std::string& choice);
void start();
bool is_valid_number(const std::string& number_of_verbs);
int string_to_number(const std::string& number_of_verbs);
bool check_file(const std::string& file);
void about(const std::string& file);

#endif
