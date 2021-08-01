//
//  main.cpp
//  LeetCodeTest
//
//  Created by ZhangChi on 2020/12/28.
//

#include <iostream>
#include<vector>
#include<stack>
#include<map>
#include <algorithm>
using namespace std;
class Solution {
public:
    bool findLetter(vector<vector<char> >&board, vector<vector<bool> >& used, string word, int LetterID, int currentRow, int currentCol)
    {
        bool ifFind = false;
        /*
        cout << ifFind << ": " << currentRow << " " << currentCol << " " << word[LetterID] <<endl;
        for(int i = 0; i < used.size(); ++i)
        {
            for (int j = 0; j < used[0].size(); ++j)
                cout << used[i][j] << " " ;
            cout << endl;
        }
        cout << "---------" << endl;
        */
                
        if(LetterID == word.size())
            return true;
        if(currentCol < board[0].size()-1 && !used[currentRow][currentCol+1] && board[currentRow][currentCol+1]==word[LetterID])
        {
            // 当前[currentRow][currentCol+1]可以找到相应字母，标记后递归[currentRow][currentCol+1]寻找其四周的字母
            used[currentRow][currentCol+1] = true;
            ifFind = findLetter(board, used, word, LetterID+1, currentRow, currentCol+1);
            // 若递归后发现无法找到，则该[currentRow][currentCol+1]处不行，还原标记
            if (!ifFind)
                used[currentRow][currentCol+1] = false;
            else 
                return true;
        }
        if(currentCol > 0 && !used[currentRow][currentCol-1] && board[currentRow][currentCol-1]==word[LetterID])
        {
            // 当前[currentRow][currentCol-1]可以找到相应字母，标记后递归[currentRow][currentCol-1]寻找其四周的字母
            used[currentRow][currentCol-1] = true;
            ifFind = findLetter(board, used, word, LetterID+1, currentRow, currentCol-1);
            // 若递归后发现无法找到，则该[currentRow][currentCol-1]处不行，还原标记
            if (!ifFind)
                used[currentRow][currentCol-1] = false;
            else 
                return true;
        }
        if(currentRow < board.size()-1 && !used[currentRow+1][currentCol] && board[currentRow+1][currentCol]==word[LetterID])
        {
            // 当前[currentRow+1][currentCol]可以找到相应字母，标记后递归[currentRow+1][currentCol]寻找其四周的字母
            used[currentRow+1][currentCol] = true;
            ifFind = findLetter(board, used, word, LetterID+1, currentRow+1, currentCol);
            // 若递归后发现无法找到，则该[currentRow+1][currentCol]处不行，还原标记
            if (!ifFind)
                used[currentRow+1][currentCol] = false;
            else 
                return true;
        }
        if(currentRow >0 && !used[currentRow-1][currentCol] && board[currentRow-1][currentCol]==word[LetterID])
        {
            // 当前[currentRow-1][currentCol]可以找到相应字母，标记后递归[currentRow-1][currentCol]寻找其四周的字母
            used[currentRow-1][currentCol] = true;
            ifFind = findLetter(board, used, word, LetterID+1, currentRow-1, currentCol);
            // 若递归后发现无法找到，则该[currentRow-1][currentCol]处不行，还原标记
            if (!ifFind)
                used[currentRow-1][currentCol] = false;
            else 
                return true;
        }
        
        return ifFind;
    }


    bool exist(vector<vector<char> >&board, string word)
    {
        vector<vector<bool> > used;
        vector<bool> tmp;
        for (int j = 0; j < board[0].size(); ++j)
            tmp.push_back(false);
        for(int i = 0; i < board.size(); ++i)
            used.push_back(tmp);


        bool result = false;
        
        for(int currentRow = 0; currentRow  < board.size(); ++currentRow)
        {
            for(int currentCol = 0; currentCol < board[0].size(); ++currentCol)
            {
                if(board[currentRow][currentCol] == word[0])
                {
                    used[currentRow][currentCol] = true;
                    result = findLetter(board,used,word,1,currentRow,currentCol);
                    if(result)
                        return true;
                    used[currentRow][currentCol] = false;
                }
                
            }
                
        }
        return result;
    }
};

int main() {
    // insert code here...
    
    return 0;
}
