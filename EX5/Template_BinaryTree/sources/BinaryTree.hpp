#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <queue>
#include <memory>
using namespace std;
const int COUNT = 10;

namespace ariel
{
    template <typename T>
    class BinaryTree
    {
        public:
            //each Node contains a generic type of data (T) , pointer to left child , pointer to right child  
            class Node 
            {
                public:
                    T data;
                    shared_ptr<Node> left;
                    shared_ptr<Node> right;
                    Node(const T& v): data(v), left(nullptr) , right(nullptr) {}
                    ~Node()
                    {
                        //delete left;
                        //delete right;
                    }
                    Node(const Node& other):left(nullptr),right(nullptr),data(other.data)
                    {
                        if (other.left != nullptr )
                        {
                            left = make_shared<Node>(*other.left);
                        }
                        if (other.right != nullptr)
                        {
                            right = make_shared<Node>(*other.right);
                        }
                    }
                    Node(Node&& other)noexcept:left(nullptr),right(nullptr),data(other.data)
                    {
                        if (other.left != nullptr )
                        {
                            left = make_shared<Node>(*other.left);
                        }
                        if (other.right != nullptr)
                        {
                            right = make_shared<Node>(*other.right);
                        }
                        other.left = nullptr;
                        other.right = nullptr;
                    }
                    Node& operator=(Node&& other)noexcept
                    {
                        if(left){delete left;}
                        if(right){delete right;}
                        data = other.data;
                        left = other.left;
                        right = other.right;
                        return *this;
                    }
                    Node& operator=(const Node& other)
                    {
                        if(*this == other){return *this;}
                        data = other.data;

                        shared_ptr<Node> left_orig = left;
                        left = make_shared<Node>(*other.left);
                        ////delete left_orig;

                        shared_ptr<Node> right_orig = right;
                        right = make_shared<Node>(*other.right);
                        ////delete right_orig;

                        return *this;
                    }
            };
            //pre-order iterator class , the iterator implements with pointer to current node ,
            //and queue of node pointers.
            class iterator
            {
                private:
                    shared_ptr<Node> current;
                    queue<shared_ptr<Node>> my_queue;

                    //recurcive init function , insert the nodes pointer to the queue
                    //according pre order principle
                    void init_pre_order(shared_ptr<Node> root)
                    {
                        if(root==nullptr){return;}
                        my_queue.push(root);
                        init_pre_order(root->left);
                        init_pre_order(root->right);
                    }

                    //recurcive init function , insert the nodes pointer to the queue
                    //according post order principle
                    void init_post_order(shared_ptr<Node> root)
                    {
                        if(root==nullptr){return;}
                        init_post_order(root->left);
                        init_post_order(root->right);
                        my_queue.push(root);
                    }

                    //recurcive init function , insert the nodes pointer to the queue
                    //according in order principle
                    void init_in_order(shared_ptr<Node> root)
                    {
                        if(root==nullptr){return;}
                        init_in_order(root->left);
                        my_queue.push(root);
                        init_in_order(root->right);
                    }
                public:
                    iterator(shared_ptr<Node> ptr , int type)
                    {
                        if(nullptr==ptr)
                        {
                            current = nullptr;
                            return;
                        }
                        if(type==1){init_pre_order(ptr);}
                        if(type==2){init_post_order(ptr);}
                        if(type==3){init_in_order(ptr);}
                        current = my_queue.front();
                        my_queue.pop();
                        if(nullptr==ptr){current = nullptr;}
                    }
                    //return copy of the iterator before increase the current pointer of the iterator
                    iterator operator++(int)
                    {
                        if(nullptr==current)
                        {
                            return *this;
                        }
                        iterator tmp = *this;
                        if(my_queue.empty())
                        {
                            current=nullptr;
                            return tmp;
                        }
                        current = my_queue.front();
                        my_queue.pop();
                        return tmp;
                    }
                    //return the iterator after increase the cuurent pointer of the iterator
                    iterator& operator++()
                    {
                        if(my_queue.empty())
                        {
                            current =  nullptr;
                            return *this;
                        }
                        current = my_queue.front();
                        my_queue.pop();
                        return *this;
                    }
                    bool operator==(const iterator& other)
                    {
                        return current == other.current;
                    }
                    //compare the current pointer of the two iterators.
                    bool operator!=(const iterator& other)
                    {
                        if(nullptr == current){return false;}
                        return current != other.current;   
                    }
                    T& operator*()
                    {
                        return current->data;
                    }
                    T* operator->()
                    {
                        return &(current->data);
                    }
                    
            };

            //this recurcive method search Node in the tree by given T value 
            shared_ptr<Node> search(shared_ptr<Node> root , const T& value)
            {
                if(root->data == value){return root;}
                //search in left subTree
                if(root->left != nullptr) 
                {
                    shared_ptr<Node> res_left =  search(root->left , value);
                    if(res_left != nullptr){return res_left;}
                }
                //search in right subTree
                if(root->right != nullptr) 
                {
                    shared_ptr<Node> res_right = search(root->right , value);
                    if(res_right != nullptr){return res_right;}
                }
                return nullptr;
            }
            
            //members of the tree
            shared_ptr<Node> root;
        //public:
        
        
            BinaryTree():root(nullptr){}
            BinaryTree(const BinaryTree& other)
            {
                root = make_shared<Node>(*other.root);
            }
            BinaryTree(BinaryTree&& other)noexcept
            {
                //if(root){delete root;}
                root = other.root;
                other.root = nullptr;
            }
            BinaryTree& operator=(BinaryTree&& other)noexcept
            {
                if(root){delete root;}
                root = other.root;
                other.root = nullptr;
                return *this;
            }
            BinaryTree& operator=(BinaryTree other)
            {
                if(root == other.root){return *this;}
                shared_ptr<Node> tmp = root;
                root = make_shared<Node>(*other.root);
                //delete tmp;
                return *this;
            }
            ~BinaryTree()
            {
                //delete root call to Node destructor , that for each Node - delete his two childs , and so on..
                //delete root;
            }
            BinaryTree& add_root(const T& item)
            {
                //if there is already root - change his value
                if(nullptr != root)
                {
                    root->data = item;
                    return *this;
                }
                //if there is no root - create new one
                root = make_shared<Node>(item);
                
                return *this;
            }
            BinaryTree& add_left(const T& exist , const T& data)
            {
                //if the tree is empty - throw exception
                if(!root){throw std::invalid_argument("argument dosent exist!");}

                //call to search method to find the Node
                shared_ptr<Node> tmp = search(root , exist);

                //if there is no such exist Node - throw exception
                if(tmp == nullptr){throw std::invalid_argument("argument dosent exist!");}

                //if there is no left child - create new one
                if(tmp->left == nullptr)
                {
                    tmp->left = make_shared<Node>(data);
                    
                    return *this;
                }
                // change the left child data
                
                    tmp->left->data = data;
                    
                    return *this;
                
            }
            BinaryTree& add_right(const T& exist , const T& data)
            {
                //if the tree is empty - throw exception
                if(!root){throw std::invalid_argument("argument dosent exist!");}

                //call to search method to find the Node
                shared_ptr<Node> tmp = search(root , exist);

                //if there is no such exist Node - throw exception
                if(tmp == nullptr){throw std::invalid_argument("argument dosent exist!");}


                //if there is no right child - create new one
                if(tmp->right == nullptr)
                {
                    tmp->right = make_shared<Node>(data);
                    
                    return *this;
                }

                // change the right child data
                
                
                    tmp->right->data = data;
                    
                    return *this;
                
            }

            //help function for operator <<
            friend void print_tree(Node* root , int space , ostream& os)
            {
                // Base case 
                if (root == NULL) 
                    {return;} 
            
                // Increase distance between levels 
                space += COUNT; 
            
                // Process right child first 
                print_tree(root->right, space , os); 
            
                // Print current node after space 
                // count 
                os<<endl; 
                for (int i = COUNT; i < space; i++) 
                {    os<<" "; 
                os<<root->data<<"\n"; }
            
                // Process left child 
                print_tree(root->left, space , os); 
            }
            friend ostream& operator<<(ostream &os , BinaryTree& tree)
            {
                print_tree(tree.root , 0 , os);
                return os;
            }

            //the numbers represents the type of the desire iterator : 1.pre-order , 2.post-order , 3.in-order
            iterator begin_preorder()
            {
                return iterator(root , 1);
            }
            iterator end_preorder()
            {
                return iterator(nullptr , 1);
            }

            iterator begin_postorder()
            {
                return iterator(root , 2);
            }
            iterator end_postorder()
            {
                return iterator(nullptr , 2);
            }

            iterator begin_inorder()
            {
                return iterator(root , 3);
            }
            iterator end_inorder()
            {
                return iterator(nullptr , 3);
            }
            iterator begin()
            {
                return iterator(root , 3);
            }
            iterator end()
            {
                return iterator(nullptr , 3);
            }
    };
}
