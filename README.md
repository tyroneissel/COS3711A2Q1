Question 1
Write a console application that can be run from the command line using the following forms:
count // run without any parameters
count file1.txt // pass one file name
count file1.txt fileTwo.txt // pass more than one file name
count –a –b file1.txt fileTwo.txt // pass flags to change
behaviour
count –ab –c file1.txt // pass flags in an alternative way

If no arguments are provided, then print a message describing what arguments should be
included.

The application should, using regular expressions, count the number of occurrences of each of
the following in the text files given. 

 If the –a flag is set, count the number of words longer than 4 characters that start with a capital
letter. There may be further capital letters in the word.
 If the –b flag is set, count the number of words that are hyphenated. This hyphen should not
be at the start or end of a word.

 If the –c flag is set, count the number of words that start and end on the same character.
 If the –d flag is set, count the number of words that do not start with a vowel. Note that these
words can start with any character, and do not just have to start with alphabetic characters.
If no flags are provided, it is assumed that all counts should be performed.

It is suggested that you remove all whitespace at the start and end of the document, as well are
removing all punctuation (.,?!:; and so on) – try doing this using a regular expression. Assume
that there is only 1 space between words.

Remember that to set command line arguments in Qt Creator, click on Projects in the left menu,
click on the Run menu and enter the arguments in the Command line arguments field. You can
also click the Run in terminal check box. 

