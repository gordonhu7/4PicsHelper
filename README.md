# 4PicsHelper

Hey

Thanks for checking this out

This program helps you solve that dreaded 4Pics level. Simply run "./a.out shuffled_unique_freq.dict.txt" on terminal.

It might take a while since the runtime is n^12 since n is number of slots for the 12 words to be in. Could optimize because if
you feed the program the string "abcdefghijkl", it will generate "aaaaaaaaaaaa" as one of the combinations which is obviously
not a possible play in the game. 

It uses a trie tree to store the dictionary since the shuffled_unique_freq.dict.txt file has over 200,000 words and each with a 
unique frequency (how often they are used). Then it creates combinations of the string it was fed and checks if it is in the 
dictionary. If it is an actual word, it stores it into a set and the set automatically orders the words from most frequently
used to least frequently used. Iterator is used to traverse set. 

I am the master of 4Pics 1 Word.
