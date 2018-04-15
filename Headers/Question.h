
//
// Created by edson on 31/03/18.
//

#ifndef TRABALHO_ED2_QUESTION_H
#define TRABALHO_ED2_QUESTION_H

#include <iostream>

using namespace std;

class Question {
private:
    unsigned int questionId;
    unsigned int userId;
    int score;
    string date;
    string title;
public:
    Question(string* question);
    ~Question();
    void printComponents ();
    int getQuestionId() const;

    bool operator<(const Question &rhs) const;
    bool operator>(const Question &rhs) const;
    bool operator<=(const Question &rhs) const;
    bool operator>=(const Question &rhs) const;
    friend ostream& operator <<(ostream &o, const Question &q);

};


#endif //TRABALHO_ED2_QUESTION_H
