Steps to execute the code:
1.  Ensure you have a C++ compiler (e.g., g++) installed on your system.
2.  Clone the Repository:https://github.com/saumya1411/Compounded-word
3.  Compile the Code: https://github.com/saumya1411/Compounded-word/blob/main/CompoundWord/compoundWord.cpp
4.  Run the Program

Overview of program:

  The program starts by reading a list of words from the provided text file.

  Then it sorts the words in descending order of length, with longer words comes first in the list.

  To  check whether a word is a compound word, it creates a dictionary (unordered set) of known words from the list.

  It then iterates through the sorted words using a recursive approach. This will be done by breaking the word into prefix and suffix and checking if both parts are 
  valid words in the dictionary.

  If a valid compound word is found, it is checked to determine if it's longer than the current longest compound word. If it is, it becomes the new longest compound 
  word, and the previous longest compound word becomes the second longest.

  The program reports the longest and second longest compound words found, along with the time taken to process the input file.

  If no valid compound words are found in the input file, the program will report both the longest and second longest compound words as empty strings.
