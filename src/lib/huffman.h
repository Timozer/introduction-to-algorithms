
#ifndef HUFFMAN_H_
#define HUFFMAN_H_

#include <utility>
#include <string>
#include <deque>
#include <map>
#include <vector>

class Huffman
{
public:
    Huffman(/* args */);
    ~Huffman();

    void Encode(std::string const &_doc);
    void Decode();
    
private:
    /* data */
    
    struct NODE
    {
        NODE() : pParent(nullptr), pLeft(nullptr), pRight(nullptr) {}
        std::pair<char, int> elem;
        NODE *pParent;
        NODE *pLeft;
        NODE *pRight;
    };

    std::deque<NODE *> mNodes;
    std::map<char, int> mChars;
    std::map<char, std::string> mCodes;
    NODE *mpTreeRoot;

    // std::vector<std::vector<NODE *>> stree;
    /* functions */
    void _Statistics(std::string const &_doc);
    void _BuildHuffmanTree();
    void _GenCodes(NODE *_pNode, std::string &&_code);
    // void _ShowTree();
    // void _ShowTree(NODE *_pNode, int level);
};

#endif /* HUFFMAN_H_ */