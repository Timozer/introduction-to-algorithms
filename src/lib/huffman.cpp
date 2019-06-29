
#include "huffman.h"

#include <algorithm>
#include <map>
#include <iostream>

Huffman::Huffman()
{
}
Huffman::~Huffman()
{

}

void Huffman::Encode(std::string const &_doc)
{
    _Statistics(_doc);
    _BuildHuffmanTree();
    // _ShowTree();
    _GenCodes(mpTreeRoot, "");
    for(auto&& item : mCodes)
    {
        std::cout << item.first << " : " << item.second << std::endl;
    }

}

void Huffman::_GenCodes(NODE *_pNode, std::string &&_code)
{
    if (_pNode == nullptr) {
        return;
    }
    
    if (_pNode->pLeft != nullptr) {
        _GenCodes(_pNode->pLeft, _code + "0");
    }

    if (_pNode->pRight != nullptr) {
        _GenCodes(_pNode->pRight, _code + "1");
    }
    
    if (_pNode->pLeft == nullptr && _pNode->pRight == nullptr) {
        mCodes[_pNode->elem.first] = _code;
    }
}
void Huffman::Decode()
{

}
// void Huffman::_ShowTree()
// {
//     _ShowTree(mpTreeRoot, 0);
//     for(int i = 0; i < stree.size(); ++i)
//     {
//         for(int j = 0; j < i; ++j)
//         {
//             std::cout << "\t";
//         }

//         for(int j = 0; j < stree[i].size(); ++j)
//         {
//             std::cout << stree[i][j]->elem.first << " : " << stree[i][j]->elem.second << "\t";
//         }
//         std::cout << std::endl;
//     }
// }
// void Huffman::_ShowTree(NODE *_pNode, int level)
// {
//     if (_pNode == nullptr) {
//         return;
//     }
    
//     stree[level].push_back(_pNode);

//     _ShowTree(_pNode->pLeft, level + 1);
//     _ShowTree(_pNode->pRight, level + 1);
// }
void Huffman::_BuildHuffmanTree()
{
    
    if (mNodes.size() == 1) {
        mpTreeRoot = *mNodes.begin();
        mNodes.pop_front();
        return;
    }
    
    if (mNodes.size() > 2) {
        std::sort(mNodes.begin(), mNodes.end(),
                  [](NODE const *_lh, NODE const *_rh) {
                      return _lh->elem.second < _rh->elem.second;
                  });
    }

    NODE *tmpLeft = mNodes[0];
    NODE *tmpRight = mNodes[1];
    NODE *tmpCur = new NODE;

    mNodes.pop_front();
    mNodes.pop_front();

    tmpCur->elem.first = 0;
    tmpCur->elem.second = tmpLeft->elem.second + tmpRight->elem.second;

    tmpCur->pLeft = tmpLeft;
    tmpCur->pRight = tmpRight;
    tmpLeft->pParent = tmpCur;
    tmpRight->pParent = tmpCur;
    mNodes.push_front(tmpCur);

    _BuildHuffmanTree();
}
void Huffman::_Statistics(std::string const &_doc)
{
    for (auto &&item : _doc)
    {
        mChars[item]++;
    }

    for (auto &&item : mChars)
    {
        NODE *tmp = new NODE;
        tmp->elem = item;
        mNodes.push_back(tmp);
    }

    // for (auto &&item : mChars)
    // {
    //     switch (item.first)
    //     {
    //     case '\n': /* code */
    //         std::cout << "\\n"
    //                   << " " << item.second << std::endl;
    //         break;
    //     case '\t': /* code */
    //         std::cout << "\\t"
    //                   << " " << item.second << std::endl;
    //         break;
    //     case ' ': /* code */
    //         std::cout << "space"
    //                   << " " << item.second << std::endl;
    //         break;
    //     default:
    //         std::cout << item.first << " " << item.second << std::endl;
    //         break;
    //     }
    // }
}