#ifndef RED_BLACK_TREE_H
#define RED_BLACK_TREE_H

#include <string>

using namespace std;
struct RBTNode {
	int data;
    unsigned short int color;
    RBTNode *left = nullptr;
    RBTNode *right = nullptr; 
    RBTNode *parent = nullptr;
};

class RedBlackTree{
	
	public:
	
		RedBlackTree();
        ~RedBlackTree();

        void Insert(int x); 
        bool Contains(int target);
        
        
        int GetMin();
        int GetMax();
        int Size();
        
        
        std::string ToInfixString() const {return InfixString(root);};
        std::string ToPrefixString() const {return PrefixString(root);};
        std::string ToPostfixString() const {return PostfixString(root);};

		void rlRotate(RBTNode* currNode); 
		void lrRotate(RBTNode* currNode); 
		void llRotate(RBTNode* currNode); 
		void rrRotate(RBTNode* currNode); 
       
        //void LeftRotation(RBTNode* rbn);
        //void RightRotation(RBTNode* rbn);
        void FlipColor(RBTNode* rbn); // may need more coloring methods
        RBTNode* GetUncle(RBTNode* rbn);
        RBTNode* GetNode(int x); 

//	private:
        RBTNode *root = nullptr;
        unsigned long long int numItems = 0;

        static std::string InfixString(RBTNode* currNode);
        static std::string PrefixString(RBTNode* currNode); 
        static std::string PostfixString(RBTNode* currNode); 

};

#endif
