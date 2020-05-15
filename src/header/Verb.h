#ifndef VERB
#define VERB

#include <string>
#include <vector>

typedef struct {
    std::string infinitive;
    std::string simple;
    std::string participle;
    bool simple_flag;
    bool participle_flag;
} FormsOfVerb;

void read_from_file(
        const std::string& file_path, std::vector<FormsOfVerb>& array_of_verbs);
void rand_verbs(int* array, int size);
bool check_verbs(
        const std::string& reference_verb, const std::string& user_verb);
int result(int number_of_verbs, int right_value);
void message_right(const FormsOfVerb& verb);
void message_wrong(const FormsOfVerb& verb);
void print_form(int index);
void print_random_verb(const FormsOfVerb& verb);
#endif
