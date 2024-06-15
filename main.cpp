#include <QCoreApplication>
#include <QRegularExpression>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QIODevice>

//Remove punctuation
QString removePunctuation(const QString& input)
{
    QRegularExpression punctRegex("[\\p{P}\\p{S}]+");
    QString text = input;
    text.remove(punctRegex);
    return text;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //Assign rules for regular expression names
    bool countAll = (argc == 1);
    bool longWords = countAll;
    bool hyphenatedWords = countAll;
    bool startEndSameLetter = countAll;
    bool notStartVowel = countAll;

    for (int i = 1; i < argc; ++i) {
        QString arg(argv[i]);
        if (arg == "-a")
            longWords = true;
        else if (arg == "-b")
            hyphenatedWords = true;
        else if (arg == "-c")
            startEndSameLetter = true;
        else if (arg == "-d")
            notStartVowel = true;
    }

    // Read the files
    QFile myFile("C:/Qt/A2/Q1/Count/fileOne.txt");
    if  (!myFile.open(QIODevice::ReadOnly)) {
        qDebug() << "Cannot open fileOne for reading";
        return 1;
    }

    QFile myFileTwo("C:/Qt/A2/Q1/Count/fileTwo.txt");
    myFileTwo.open(QIODevice::ReadOnly);

    //Read entire files as strings
    QTextStream streamFile(&myFile);
    QString myText = streamFile.readAll();

    QTextStream streamFileTwo(&myFileTwo);
    QString myTextTwo = streamFileTwo.readAll();

    //Remove whitespace and remove punctuation
    QRegularExpression trimRegex("^\\s+|\\s+$");
    QString trimmed = myText.trimmed();
    QString trimmedTwo = myTextTwo.trimmed();
    QString clean = removePunctuation(trimmed);
    QString cleanTwo = removePunctuation(trimmedTwo);

    //Start regular expressions
    QString heading = "Number of Words Longer Than 4 Letters That Start with a Capital: ";
    QRegularExpression longerThanFour("\\b[A-Z][A-Za-z]{4,}\\b");
    int count = 0;
    auto words_begin = longerThanFour.globalMatch(clean);
    while (words_begin.hasNext()) {
        words_begin.next();
        ++count;
    }
    qDebug() << heading << count; //Print output

    QString heading2 = "Number of Hyphenated Words: ";
    QRegularExpression hyphenated("\\b[A-Za-z]+-[A-Za-z]+\\b");
    int count2 = 0;
    auto words_begin2 = hyphenated.globalMatch(cleanTwo);
    while (words_begin2.hasNext()) {
        words_begin2.next();
        ++count2;
    }
    qDebug() << heading2 << count2;

    QString heading3 = "Number of Words That Start and End on the Same Letter: ";
    QRegularExpression sameLetters("\\b([A-Za-z])\\w*\\1\\b");
    int count3 = 0;
    auto words_begin3 = sameLetters.globalMatch(cleanTwo);
    while (words_begin3.hasNext()) {
        words_begin3.next();
        ++count3;
    }
    qDebug() << heading3 << count3;

    QString heading4 = "Number of Words That Doesn't Start with a Vowel: ";
    QRegularExpression numVowels("\\b[^AEIOUaeiou\\W]\\w*\\b");
    int count4 = 0;
    auto words_begin4 = numVowels.globalMatch(cleanTwo);
    while (words_begin4.hasNext()) {
        words_begin4.next();
        ++count4;
    }
    qDebug() << heading4 << count4;

    //Close both files
    myFile.close();
    myFileTwo.close();

    return 0;
}
