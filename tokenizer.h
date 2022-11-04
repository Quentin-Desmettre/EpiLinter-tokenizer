#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <QString>

class Tokenizer
{
public:
    virtual void nimp() = 0;

    static QString getTokens(QString file_content);
};

#endif // TOKENIZER_H
