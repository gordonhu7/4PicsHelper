
#ifndef DICTIONARY_TRIE_H
#define DICTIONARY_TRIE_H

#include <vector>
#include <string>


class DictionaryTrie
{
public:

  //inner class node
  class Node{
  public:

     //frequency of word
     unsigned int freq;

     //if it is the end of a search
     bool end  = false;

     //char array
     Node* children[27] = {};

     //final word
     std::string word;

     //constructor
     Node(){}     

     //destructor
     //~Node();
  
  };

  /* Create a new Dictionary that uses a Trie back end */
  DictionaryTrie();

  /* Insert a word with its frequency into the dictionary.
   * Return true if the word was inserted, and false if it
   * was not (i.e. it was already in the dictionary or it was
   * invalid (empty string) */
  bool insert(std::string word, unsigned int freq);

  /* Return true if word is in the dictionary, and false otherwise */
  bool find(std::string word) ;

  /*finds index of the word and the eventual ascii character*/
  int index(char a)const;

  //traversing to the next node
  Node* traverse(Node* n,char c);

  unsigned int FIND(std::string word);

  /* Return up to num_completions of the most frequent completions
   * of the prefix, such that the completions are words in the dictionary.
   * These completions should be listed from most frequent to least.
   * If there are fewer than num_completions legal completions, this
   * function returns a vector with as many completions as possible.
   * If no completions exist, then the function returns a vector of size 0.
   * The prefix itself might be included in the returned words if the prefix
   * is a word (and is among the num_completions most frequent completions
   * of the prefix)
   */
  std::vector<std::string>
  predictCompletions(std::string prefix, unsigned int num_completions);

  //root of the tree
  Node* root;

  /* helper method to help delete all the nodes in the trie tree
   * for the destructor
   */
  void deleteAll(Node* n);

  /* Destructor */
  ~DictionaryTrie();

private:
  //no private variables needed
};

#endif // DICTIONARY_TRIE_H
