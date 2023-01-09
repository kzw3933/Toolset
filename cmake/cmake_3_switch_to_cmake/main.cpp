#include <iostream>

#include "answer.hpp"

int main(int argc, char *argv[]) {

    int expected_answer = answer::find_the_ultimate_answer();

    for(;;) {
        std::cout << "What's the ultimate answer?" << std::endl;
        int answer;
        std::cin >> answer;
        if (answer == expected_answer) {
            std::cout << "Correct!" << std::endl;
            break;
        }
    }

    return 0;
}
