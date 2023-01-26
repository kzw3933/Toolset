#include <iostream>

#include <answer/answer.hpp>

int main(int argc, char *argv[]) {

    for(;;) {
        std::cout << "What's the ultimate answer?" << std::endl;
        std::string answer;
        std::cin >> answer;
        auto expected_answer = answer::find_the_ultimate_answer();
        if (answer == expected_answer) {
            std::cout << "Correct!" << std::endl;
            break;
        }
    }

    return 0;
}
