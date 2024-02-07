#include <iostream>

int main()
{
    std::string question[] = {"1.What year was C++ created?",
                              "2. Who invented C++?",
                              "3. What is the predecessor of C++?"};

    std::string options[][4] = {{"A. 1969", "B. 1975", "C. 1985", "D. 1989"},
                                {"A. Guido Van Rossum", "B. Bjarne Stroustrup", "C. John Carmack", "D. Mark Zuckerburg"},
                                {"A. C", "B. C+", "C. C--", "B++"}};

    char answerKey[] = {'C', 'B', 'A', 'B'};

    int size = sizeof(question) / sizeof(question[0]);
    char guess;
    int score;

    for (int i = 0; i < size; i++)
    {
        std::cout << "**************************************\n";
        std::cout << question[i] << '\n';
        std::cout << "**************************************\n";

        for (int j = 0; j < (sizeof(options[i]) / sizeof(options[i][0])); j++)
        {
            std::cout << options[i][j] << '\n';
        }

        std::cin >> guess;
        guess = toupper(guess);

        if (guess == answerKey[i])
        {
            std::cout << "CORRECT\n";
            score++;
        }
        else
        {
            std::cout << "WRONG!\n";
            std::cout << "Answer: " << answerKey[i] << '\n';
        }
    }

    std::cout << "**************************************\n";
    std::cout << "RESULTS: " << score << " or " << (size / (double)size) * 100 << "%\n";
    std::cout << "**************************************\n";

    return 0;
}