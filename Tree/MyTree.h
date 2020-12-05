#pragma once
#include "TreeAbstract.h"
#include <vector>

class Tree: public AbstractTree
{
protected:
    struct Node
    {
        Node* parent;
        vector <Node*> child;
        void* data;
        size_t dataSize;
    };

    Node* root;
    int treeSize;//количество вершин
    size_t usedSpace;
    size_t freeSpace;
    MemoryManager* memory;

public:
    Tree (MemoryManager &mem): AbstractTree(mem)
    {
        root = NULL;
        usedSpace = 0;
        freeSpace = mem.size();
        memory = &mem;
        treeSize = 0;
    }
	~Tree()
    {
        clear();
        root = NULL;
        memory = NULL;
    }

    class TreeIterator: public AbstractTree::Iterator
    {
    public:
        Node* curNode;
        Tree* tree;
        TreeIterator(Tree* tree, Node* root): tree(tree), curNode(root){}
        ~TreeIterator();

        void* getElement(size_t &size);
        bool hasNext();
        void goToNext();
        bool equals(Container::Iterator* right);
		bool equalsNull();

        bool goToParent();
        bool goToChild(int child_index);
    };
    
    void deleteNodeRecursive(Node* node);
    Node* findNodeRecursive(Node* node, void* elem, size_t size);

    int size();
    size_t max_bytes();
    Iterator* find(void *elem, size_t size);
    Iterator* newIterator();
    Iterator* begin();
    Iterator* end();
    void remove(Container::Iterator *iter);
    void clear();
    bool empty();

    int insert(Iterator *iter, int child_index, void *elem, size_t size);
    bool remove(Iterator *iter, int leaf_only);
};