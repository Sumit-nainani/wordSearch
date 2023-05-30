
#include<bits/stdc++.h>

/*Given a 2D board of letters and a word. Check if the word exists in the board. 
The word can be constructed from letters of adjacent cells only. ie - horizontal 
or vertical neighbors. The same letter cell can not be used more than once.*/

/*
Approach:
    doing dfs over matrix and find if current character of word is matched with current cell.
    if yes then do dfs for next cells 
*/
class solution{
public:

vector<pair<int,int>> v={
    {1,0},{0,1},{-1,0},{0,-1}
};

// validate function
bool vd(int i,int j,int n,int m){
    return i>=0 && j>=0 && i<n && j<m;
}
bool dfs(vector<vector<char>>& board, string word,int e,int l,int i,int j,int n,int m){
    if(e==l) return true;
    board[i][j]='.';  //for not visiting same cell agaain
    for(auto&it:v){
        int x=i+it.first;
        int y=j+it.second;
        if(!vd(x,y,n,m)) continue;   //outside the board
        if(board[x][y]=='.') continue;
        if(word[e]==board[x][y]) return dfs(board,word,e+1,l,x,y,n,m);
    }
    return false;
}
    bool isWordExist(vector<vector<char>>& board, string word) {
        // Code here
        int n=board.size();
        int m=board[0].size();
        int l=word.size();
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(board[i][j]==word[0])  // first word matching is important 
                    if(dfs(board,word,1,l,i,j,n,m)) 
                        return true;
               
        return false;
    }
};