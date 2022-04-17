#include <iostream>
#include <fstream>
#include <vector>
#include "inc/bmp.h"
int main() {
    std::ifstream in("../word.txt");
    std::string tmp;
    std::vector<std::vector<char>> word;
    std::vector<char> v;
    in>>tmp;
    for(char & i : tmp)
    {
        v.push_back(i);
        word.push_back(v);
        v.clear();
    }
    while(!in.eof())
    {
        in>>tmp;
        for(int i=0;i<tmp.size();i++)
            word[i].push_back(tmp[i]);
    }
    bmp image("../examples/example1.bmp");
    image.shorthand(50,1000,word);
    image.write("../output.bmp");
    return 0;
}
