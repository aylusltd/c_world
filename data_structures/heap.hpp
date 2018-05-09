#include <iostream>
#include <string>
const bool DEBUG_MODE=false;

// #define NULL nullptr
namespace heap{
    template <class T>
    class Heap{
    private:
        void logger(std::string args){
            if(DEBUG_MODE == true){
                std::cout<<args<<std::endl;    
            }
        }
        T l[4];
        T* list = l;
        int size=0;
        int capacity=4;

        int getLeftChildIndex(int position){return (2 * position + 1);}
        int getRightChildIndex(int position){return (2 * position + 2);}
        int getParentIndex(int position){return (position - 1)/2;}
        
        bool hasLeftChild(int position){return getLeftChildIndex(position)< size;}
        bool hasRightChild(int position){return getRightChildIndex(position)<size;}
        bool hasParent(int position){return position>0;}

        T leftChild(int position){return list[getLeftChildIndex(position)];}
        T rightChild(int position){return list[getRightChildIndex(position)];}
        T parent(int position){return list[getParentIndex(position)];}

        void swap(int a, int b){T t = list[a]; list[a]=list[b]; list[b]=t;}
        void ensureCapacity(){
            if(size == capacity){
                capacity *= 2;
                T * temp = new T [capacity];
                for(int i=0; i<size; i++){
                    temp[i]=list[i];
                }
                list=temp;
            }
        }
        void compact(){
            if( size<(capacity/2) && (capacity - size) > 10){
                capacity *= .75;
                T * temp = new T [capacity];
                for(int i=0; i<size; i++){
                    temp[i]=list[i];
                }
                list=temp;
            }
        }
        void heapifyDown(){
            T minChild;
            int i=0;
            while(hasLeftChild(i)){
                int minChildIndex = getLeftChildIndex(i);
                if(hasRightChild(i) && rightChild(i)<leftChild(i)){
                    minChildIndex = getRightChildIndex(i);
                }
                if(list[i] < list[minChildIndex]){
                    break;
                } else {
                    swap(i, minChildIndex);
                    i = minChildIndex;
                }
            }

        }
        void heapifyUp(){}

    public:
        Heap(T a){list[0]=a;}
        Heap(){}
        T peek(){return list[0];}
        T poll(){
            T retVal = list[0];
            if(size>0){
                // list[size] = NULL;
                size--;
                list[0]=list[size];
                heapifyDown();
                compact();    
            }
            
            return retVal;
        }
        void add(T newVal){
            logger("Adding");
            ensureCapacity();
            logger("Has Capacity");
            list[size]=newVal;
            logger("Value set");

            size++;
        }
        
    };
}