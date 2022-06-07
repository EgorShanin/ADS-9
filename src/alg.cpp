// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
      BST<std::string> bst;
      std::ifstream file(filename);
      if (!file) {
            std::cout << "File error!" << std::endl;
            return 0;
      }
      char letter = file.get();
      std::string word = "";
      while (!file.eof()) {
            if (('z' >= letter) && ('a' <= letter)) {
                word += letter;
            } else if (('Z' >= letter) && ('A' <= letter)) {
                word += tolower(letter);
            } else {
                bst.add(word);
                word = "";
            }
      }
      file.close();
      return bst;
}
