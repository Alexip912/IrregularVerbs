#ifndef VERB
#define VERB

#include <string>
#include <vector>

struct VerbForms {
    std::string infinitive;
    std::string simple;
    std::string participle;
};

std::vector<VerbForms> read_from_file(const std::string& file_path);
std::vector<int> rand_verbs(int size);
int check_verbs(
        const std::vector<std::string>& user_verbs, const VerbForms& reference);
int result(int number_of_verbs, int right_value);
void accrual_of_points(int temp, int& right_value);
void message_right(int result);
void message_wrong(const VerbForms& verb, int result);
void print_random_verb(const VerbForms& verb);
void message_mark(int percent);
#endif
