#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Question {
public:
    string title;
    int correctIndex;
    vector<string> options;

    Question(string title, int correctAnswer, vector<string> options) {
        this->title = title;
        this->correctIndex = correctAnswer;
        this->options = options;
    }

    void print() {
        cout << this->title << "\n";
        for (string v : options) {
            cout << v << " ";
        }
        cout << "\n";
    }

    bool isCorrect(int choise) {
        return correctIndex == choise;
    }
};

class Quiz {
private:
    int length;
    vector<Question> questions;

public:
    Quiz(int length, vector<Question> questions) {
        this->length = length;
        this->questions = questions;
    }

    void startQuiz() {
        int correctAnswer = 0;

        for (int i = 0; i < length; i++) {
            cout << i + 1 << ": " << questions[i].title << "\n";

            int optionsize = questions[i].options.size();
            for (int j = 0; j < optionsize; j++) {
                cout << j + 1 << ". " << questions[i].options[j] << "\n";
            }

            cout << "Enter your Answer : ";
            int userchoise;
            cin >> userchoise;

            if (questions[i].isCorrect(userchoise)) {
                correctAnswer++;
            }
        }

        cout << "Your Score is : " << correctAnswer << "/" << length << "\n";
    }
};

int main() {
    vector<string> answers = {"4 Byte", "8 Byte", "16 Byte"};
    Question q("Int size", 1, answers);

    vector<Question> questions = {q};
    Quiz quiz(1, questions);

    quiz.startQuiz();

    return 0;
}