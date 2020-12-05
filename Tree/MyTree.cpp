#pragma once
#include "MyTree.h"

void* Tree::TreeIterator::getElement(size_t &size)
{
	if (curNode != NULL)
	{
		size = curNode->dataSize;
		return curNode->data;
	}
	else
	{
		size = NULL;
		return NULL;
	}
}

bool Tree::TreeIterator::hasNext()
{
    if(curNode->child.size() != 0)//есть ребенок
        return true;
    else
    {
        Node* temp = curNode;
        while(temp->parent != NULL)
        {
            for(int i = 0; i < temp->parent->child.size(); i++)
                if(temp->parent->child[i] == curNode && i != temp->parent->child.size() - 1)//есть брат/сестра
                    return true;
            temp = temp->parent;//идем выше по дереву
        }
        return false;
    }
}

void Tree::TreeIterator::goToNext()
{
    if(curNode->child.size() != 0)//есть ребенок
        curNode = curNode->child[0];
    else
    {
        Node* temp = curNode;
        while(temp->parent != NULL)
        {
            for(int i = 0; i < temp->parent->child.size(); i++)
				if (temp->parent->child[i] == curNode && i != temp->parent->child.size() - 1)//есть брат/сестра
				{
					curNode = temp->parent->child[i+1];
					return;
				}
            temp = temp->parent;//идем выше по дереву
        }
    }
}

bool Tree::TreeIterator::equals(Container::Iterator* right)
{
    return curNode == ((TreeIterator*)right)->curNode;
}

bool Tree::TreeIterator::equalsNull()
{
	return curNode == NULL;
}


bool Tree::TreeIterator::goToParent()
{
    if(curNode->parent != NULL)
    {
        curNode = curNode->parent;
        return true;
    }
    return false;
}

bool Tree::TreeIterator::goToChild(int child_index)
{
    if(curNode->child.size() >= child_index)
    {
        curNode = curNode->child[child_index - 1];
        return true;
    }
    return false;
}


void Tree::deleteNodeRecursive(Node* node)
{
    for(int i = 0; i < node->child.size(); i++)
        deleteNodeRecursive(node->child[i]);

    node->child.clear();
    usedSpace -= node->dataSize;
    treeSize--;
    //delete node->data;
    delete node;
	node = NULL;
}

Tree::Node* Tree::findNodeRecursive(Node* node, void* elem, size_t size)
{
    Node* temp = NULL;
    for(int i = 0; i < node->child.size(); i++)
    {
       if(memcmp(node->child[i]->data, elem, size) == 0)
           return node->child[i];
       temp = findNodeRecursive(node->child[i], elem, size);
    }
    return NULL;
}


int Tree::size()
{
    return treeSize;
}

size_t Tree::max_bytes()
{
    return _memory.size();
}

AbstractTree::Iterator* Tree::find(void *elem, size_t size)
{
    if(this->empty())    
		return new TreeIterator(this, NULL);

    if(memcmp(root->data, elem, size) == 0)//если ищут корень
        return begin();

    Node* temp = findNodeRecursive(root, elem, size);//попробуем найти вершину
    if(temp == NULL)//не нашли
        return new TreeIterator(this, NULL);

    TreeIterator* it = (TreeIterator*)newIterator();
    it->curNode = temp;
    return it;
}

AbstractTree::Iterator* Tree::newIterator()
{
    return new TreeIterator(this, root);
}

AbstractTree::Iterator* Tree::begin()
{
    return newIterator();
}

AbstractTree::Iterator* Tree::end()
{
    if(!empty())
    {
        TreeIterator* it = (TreeIterator*)newIterator();
        while(it->hasNext())
            it->goToNext();
        return it;
    }
    TreeIterator* it = (TreeIterator*)newIterator();
    return it;
}

void Tree::remove(Container::Iterator *iter)
{
    TreeIterator* it = (TreeIterator*)(iter);
    remove(it, 0);
}

void Tree::clear()
{
    if(empty()) return;//дерево пустое
    deleteNodeRecursive(root);
    usedSpace = 0;
    freeSpace = 0;
    treeSize = 0;
}

bool Tree::empty()
{
    return treeSize == 0;
}


int Tree::insert(Iterator *iter, int child_index, void *elem, size_t size)
{
    TreeIterator* it = (TreeIterator*) iter;
    if(freeSpace - usedSpace >= size && iter != NULL && it->curNode != NULL)
    {
        Node* newNode = new Node;
        newNode->parent = it->curNode;
        newNode->data = elem;
        newNode->dataSize = size;
        it->curNode->child.push_back(newNode);//возможно нужен insert
        usedSpace += newNode->dataSize;
        freeSpace -= newNode->dataSize;
        treeSize++;
        return 0;
    }
    if(freeSpace - usedSpace >= size && it->curNode == NULL)
    {
        Node* newNode = new Node;
        newNode->parent = NULL;
        newNode->data = elem;
        newNode->dataSize = size;
        root = newNode;
        it->curNode = root;
        usedSpace += newNode->dataSize;
        freeSpace -= newNode->dataSize;
        treeSize++;
        return 0;
    }
    return 1;
}

bool Tree::remove(Iterator *iter, int leaf_only)
{
    TreeIterator* it = (TreeIterator*) iter;
    if(it->curNode->child.size() != 0 && leaf_only == 1)
        return false;
    if(iter == NULL || it->curNode == NULL)
        return false;
    if(it->curNode->parent == NULL)
    {
        clear();
        return true;
    }
    else
    {
        int i = 0;
        while(it->curNode->parent->child[i]->data != it->curNode->data)//находим удаляемую вершину в векторе детей ее родителя
            i++;
        vector <Node*>::iterator it2 = it->curNode->parent->child.begin();
        for(int j = 0; j < i; j++)
            it2++;
        it->curNode->parent->child.erase(it2);//затираем ее там
		TreeIterator* it3 = (TreeIterator*)newIterator();
		it3->curNode = it->curNode;
		it->goToParent();
		deleteNodeRecursive(it3->curNode);
        return true;
    }
}