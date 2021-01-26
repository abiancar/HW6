#include <iostream>
#include <string>
#include "RedBlackTree.h"
#include <assert.h>

using namespace std; 

// constructor 
RedBlackTree::RedBlackTree()
{   
	// no action needed 
}
RedBlackTree::~RedBlackTree()
{}

/*
1) if tree is empty, insert the newNode as Root node with color black and exit from operation
2) If tree is not empty, insert the newNode as leaf node with color red
3) If the parent of newNode is black then exit from the operation
4) If the parent of newNode is Red then check the color of parent's sibling
5) If uncle is colored black or null then make suitable rotation and recolor it
6) If uncle is colorded red then perform recolor. Repeat the same until tree becomes proper red black tree 
*/

void RedBlackTree::Insert(int x)
{
	//FIX ME:
    // we should catch an error the user tries to insert an item that already exists!
    //if this->Contains(x) -> throw error or exit program
    
    /*
    try
    {
		if (this->Contains(x))
		{
			throw exception(); 
		}
	}
	catch (exception())
	{
		cout << "The item you are trying to insert already exists in the tree." << endl; 
	}*/
    
    // if the size of the tree is 0
	if (numItems == 0) // create a node, make the node the root node 
	{
		RBTNode* newNode = new RBTNode(); 
		newNode->color = 0; // set to black
        newNode->data = x; 
		this->root = newNode; 
		numItems += 1; 
	}
	
    else{ // tree is not empty, insert newNode as leaf node with color red
		
	    //2) If tree is not empty, insert the newNode as leaf node with color red
    	//3) If the parent of newNode is black then exit from the operation
	    //4) If the parent of newNode is Red then check the color of parent's sibling
	
        RBTNode* newNode = new RBTNode();
        newNode->data = x;
        newNode->color = 1; //set color as red
        
        //RBTNode* parent =  this->root;
        RBTNode* parent = this->root;
        RBTNode* child;

		if(x < parent->data){
            child = parent->left;
        }
        else{
            child = parent->right;
        }
        // we know that the child is not in a while loop

        if(child != nullptr){
            while(child != nullptr){
                if(x < child->data){
                    parent = child;
                    child = parent->left;                    
                }
                else{
                    parent = child;
                    child = parent->right;
                }

            }
        }

        child = newNode;
        child->parent = parent;



        cout << "CURRENT NODE DATA: " << child->data << endl;
        cout << "CURRENT NODE's PARENT DATA" << child->parent->data << endl;

        cout << "ROOT'S LEFT CHILD: " << this->root->left->data << endl;

        // child-> parent = parent; // parent is still being stored at this point so we can do this*/
        this->numItems++;
        cout << "HERE I AM" << endl;
        /*
        if(currNode->color != 0){ // if the new node's parent is red
            //check uncle color
		}*/
    }
	
}

bool RedBlackTree::Contains(int target) // FIXME: Prolly doesn't work yet
{
    // start at the root node, set it to currNode
    // if currNOde = target ... true
    // else: if the target is smaller than currNode, set currNode to left child
    //       if target is larger than currNode set currNode to right child
    // if the current node has no children, return false
    RBTNode* currNode = this->root;
    
    if(currNode == nullptr){return false;};
    if(currNode->data == target){return true;};
    
    while(currNode != nullptr){
        if(currNode->data == target){
            return true;
        }
        else if(target < currNode->data){
            currNode = currNode->left;
        }
        else{
            currNode = currNode->right;
        }
    }
    return false;


}


int RedBlackTree::GetMin()
{
    RBTNode* currNode = this->root;
    while(currNode-> left != nullptr){
        currNode = currNode->left;
    }
    return currNode->data;
}

int RedBlackTree::GetMax()
{
    RBTNode* currNode = this->root;
    while(currNode-> right != nullptr){
        currNode = currNode->right;
    }
    return currNode->data;
}

int RedBlackTree::Size()
{
	return numItems; 
}


string RedBlackTree::InfixString(RBTNode* currNode)
{
    // take a node
    // print the node
    // if the left node is not null, print the left
    // if the right node is not null, print the right
    
    // emptry RBT scenario
    cout << "A" << endl;

    if(currNode == nullptr){
       return "";
    }
    cout << "B" << endl;

    string colorString;
    string infixStr;
    int color = currNode->color;
    cout << "C" << endl;
    if(color == 0){
        colorString = "B";
    }
    else{
		cout << currNode->left->data << endl; 
        colorString = "R";
    }

    infixStr = infixStr + InfixString(currNode->left) + colorString + to_string(currNode->data) + InfixString(currNode->right);

    
	return infixStr; 
}

/*
string RedBlackTree::PrefixString(RBTNode* a)
{
	string s = "";
	return s; 
}

string RedBlackTree::PostfixString(RBTNode* a)
{
	string s = "";
	return s; 
}

RBTNode* RedBlackTree::GetUncle(RBTNode* rbn){ //requires testing but should work
    RBTNode* father = rbn->parent;
    RBTNode* grandFather = father->parent;

    if(grandFather->left == father){
        return grandFather->right;
    }
    else{return grandFather->left;};
}

void RedBlackTree::LeftRotation(RBTNode* currNode){ // may be bugs, simply changed left to right from sister method
    //the curr node's parent is going to change their son to the currNode's left child
    RBTNode* father = currNode->parent;
    RBTNode* rightChild = currNode->right;
    RBTNode* adoptedChild = rightChild->left;

    //handle the father interaction
    if(father->right == currNode){
        father->right = rightChild;
    }
    else{
        father->left = rightChild;
    }
    rightChild->parent = father;

    // have the left child become the currNode's father
    rightChild->right = currNode;
    currNode->parent = rightChild;

    // have the adopted child become the CurrNode's son
    adoptedChild->parent = currNode;
    currNode->right = adoptedChild;
}

void RedBlackTree::RightRotation(RBTNode* currNode){ // requires testing
    //the curr node's parent is going to change their son to the currNode's left child
    RBTNode* father = currNode->parent;
    RBTNode* leftChild = currNode->left;
    RBTNode* adoptedChild = leftChild->right;

    //handle the father interaction
    if(father->left == currNode){
        father->left = leftChild;
    }
    else{
        father->right = leftChild;
    }
    leftChild->parent = father;

    // have the left child become the currNode's father
    leftChild->right = currNode;
    currNode->parent =leftChild;

    // have the adopted child become the CurrNode's son
    adoptedChild->parent = currNode;
    currNode->left = adoptedChild;
}

void RedBlackTree::FLipColor(RBTNode* rbn){ //requires testing
    if(rbn->color == 0){
        rbn->color =1;
    }else{
        rbn->color =0;
    }

}*/
