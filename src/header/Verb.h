#ifndef VERB
#define VERB

#include <string>

typedef struct {
    std::string word;
    std::string form;
} DataOfCurrentVerb;

extern bool simple, participle;
extern std::string array_of_verbs[121][3];

bool read_from_file(const std::string& filePath);
void rand_verbs(int* array, const int& size);
int check_verbs(const int* array, const int& size, DataOfCurrentVerb& object);
int result(const int& number_of_verbs, const int& right_value);
void message_right();
void message_wrong(const int& index, const DataOfCurrentVerb& object);
void print_form(const int& index);
void print_random_verb(const int& index);

#endif
