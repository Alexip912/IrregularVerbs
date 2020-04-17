#include <ctime>
#include <cstdlib>

void randVerbs(int *array, int size) {
    srand(time(nullptr));
    bool there;
    int element;
    for (int i = 0; i < size;) {
        there = false;
        element = rand() % 121;
        for (int j = 0; j < i; ++j) {
            if (array[j] == element) {
                there = true;
                break;
            }
        }
        if (!there) {
            array[i] = element;
            ++i;
        }
    }
}