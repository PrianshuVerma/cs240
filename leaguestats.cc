#include <iostream>
#include <string>
#include <vector>


using namespace std;

class Team
{
    public:
    int wins;
    int losses;
    string name;

    Team(int w, int l, string n)
    {
        wins = w;
        losses = l;
        name = n;
    };
};

class MinHeap
{
public:
    // vector to store referances to teams
    vector<Team> heap;
    
    void delAllK(int k, int parent) {

        if (parent >= heap.size()) return;
        
        if (k == heap[parent].wins) {
            
            heap.erase(heap.begin() + parent);
            
            fixDown(parent);
            
            delAllK(k, parent);
            
        }
        
        else {
            
            delAllK(k, (2 * parent) + 1);
            delAllK(k, (2 * parent) + 2);
        }

    }
    
    // this deletes t object from MinHeap
    void del (Team t, int parent){
        
        if (parent >= heap.size()) {
    
        }
        
        else if (heap[parent].name == t.name){
            
            heap.erase(heap.begin() + parent);
            fixDown(parent);
        }
        
        else if (heap[parent].losses > t.losses) {
            // t doesnt exist in heap then
        }
        
        else {
            del(t, (2* parent) + 1);
            del(t, (2* parent) + 2);
        }
        
    }
    
    void fixDown (int p){
        
        int parent = p;
        int lchild = (2 * parent) + 1;
        int rchild = (2 * parent) + 2;

        while (lchild < heap.size() || rchild < heap.size()){

            // both children exist
            if (lchild < heap.size() && rchild < heap.size()) {
                
                // parent is greater then both children so we break
                if (heap[parent].losses < heap[lchild].losses && heap[parent].losses < heap[rchild].losses){
                    break;
                    }
                
                else if (heap[lchild].losses < heap[rchild].losses && heap[lchild].losses < heap[parent].losses) {
                    //swap parent with left child 
                    swap(heap[parent],heap[lchild]);
                    parent = lchild;
                    }
                
                else if (heap[rchild].losses < heap[lchild].losses && heap[rchild].losses < heap[parent].losses) {
                    //swap parent with right child
                    swap(heap[parent],heap[rchild]);
                    parent = rchild;
                    }
                }
                
            // then rchild doesnt exist so we'll look at lchild
            else if (rchild >= heap.size() && heap[lchild].losses < heap[parent].losses) {
                //swap parent with left child
                swap(heap[parent],heap[lchild]);
                parent = lchild;
                }   
            
            else if (rchild >= heap.size() && heap[lchild].losses > heap[parent].losses) {
                break;
                }
            
            lchild = (2 * parent) + 1;
            rchild = (2 * parent) + 2;
                
            }
    }
    
    void fixUp(){
        
        int child = heap.size() - 1;
        int parent = (child - 1) / 2;

        while ((child >= 1 && parent >= 0) && (heap[parent].losses > heap[child].losses)){

            swap(heap[parent], heap[child]);
            child = parent;
            parent = (child - 1) / 2;
        };
    }

    void insert(const Team &t){
        heap.push_back(t);
        fixUp();
    }
    
    Team delMin() {
        Team t = heap[0];
        heap.erase(heap.begin());
        fixDown(0);
        return t;
    }
    
    void removeAll(){
        heap.clear();
    }

    void print(){
        for (unsigned int i = 0; i < heap.size(); i++){
            cout << heap[i].name;
        }};
};

class MaxHeap{
    public:
    // vector to store referances to teams
    vector<Team> heap;
    
    void delAllK(int k, int parent) {

        // since this is a maxheap we can exit if K is greater
        if (parent >= heap.size() || k > heap[parent].wins) return;
        
        if (k == heap[parent].wins) {

            heap.erase(heap.begin() + parent);
            fixDown(parent);
            delAllK(k, parent);
        }
        
        else {
            delAllK(k, (2 * parent) + 1);
            delAllK(k, (2 * parent) + 2);
        }
    }
    
    // this deletes t object from MaxHeap
    void del (Team t, int parent){
        
        if (parent >= heap.size()) {
    
        }
        
        else if (heap[parent].name == t.name){
            
            heap.erase(heap.begin() + parent);
            fixDown(parent);
        }
        
        else if (heap[parent].wins < t.wins) {
            // t doesnt exist in heap then
        }
        
        else {
            del(t, (2* parent) + 1);
            del(t, (2* parent) + 2);
        }
        
    }
    
    void fixDown (int p){
        
        int parent = p;
        int lchild = (2 * parent) + 1;
        int rchild = (2 * parent) + 2;
        
        while (lchild < heap.size() || rchild < heap.size()){
            
            // both children exist
            if (lchild < heap.size() && rchild < heap.size()) {
                
                // parent is greater then both children so we break
                if (heap[parent].wins > heap[lchild].wins && heap[parent].wins > heap[rchild].wins){
                    break;
                    }
                
                else if (heap[lchild].wins > heap[rchild].wins && heap[lchild].wins > heap[parent].wins) {
                    //swap parent with left child 
                    swap(heap[parent],heap[lchild]);
                    parent = lchild;
                    }
                
                else if (heap[rchild].wins > heap[lchild].wins && heap[rchild].wins > heap[parent].wins) {
                    //swap parent with right child
                    swap(heap[parent],heap[rchild]);
                    parent = rchild;
                    }
                }
            
            // then rchild doesnt exist so we'll look at lchild
            else if (rchild >= heap.size() && heap[lchild].wins > heap[parent].wins) {
                //swap parent with left child
                swap(heap[parent],heap[lchild]);
                parent = lchild;
                }   
            
            else if (rchild >= heap.size() && heap[lchild].wins < heap[parent].wins) {
                break;
                }
            
            lchild = (2 * parent) + 1;
            rchild = (2 * parent) + 2;
                
            }}
        
    
    void fixUp(){
        
        int child = heap.size() - 1;
        int parent = (child - 1) / 2;

        while ((child >= 1 && parent >= 0) && (heap[parent].wins < heap[child].wins)){

            swap(heap[parent], heap[child]);
            child = parent;
            parent = (child - 1) / 2;
        };
    }

    void insert(const Team &t){
        heap.push_back(t);
        fixUp();
    }
    
    Team delMax() {
        Team t = heap[0];
        heap.erase(heap.begin());
        fixDown(0);
        return t;
    }

    void print(){
        for (unsigned int i = 0; i < heap.size(); i++){
            cout << heap[i].name;
        }};
    
    void removeAll(){
        heap.clear();
    }
    
    int num() {
        return heap.size();
    }
};

class TeamPQ {
    
private:
    MinHeap lossesMinHeap;
    MaxHeap winsMaxHeap;

public:

    void insert(const Team &t) {
        lossesMinHeap.insert(t);
        winsMaxHeap.insert(t);
    };
    
    const Team &findMaxWins() const {
        return winsMaxHeap.heap[0];
    }; 
    
    const Team &findMinLosses() const {
        return lossesMinHeap.heap[0];
    };
    
    void removeMaxWins(){
        Team t = winsMaxHeap.delMax();
        lossesMinHeap.del(t, 0);
    };
    
    void removeMinLosses(){
        Team t = lossesMinHeap.delMin();
        winsMaxHeap.del(t, 0);
    };
    
    void removeAllK(int k){
        winsMaxHeap.delAllK(k, 0);
        lossesMinHeap.delAllK(k, 0);
    };

    void printMin() { lossesMinHeap.print(); };
    
    void printMax() { winsMaxHeap.print(); };
    
    void reset(){
      winsMaxHeap.removeAll();
      lossesMinHeap.removeAll();
    };
    
    int numOfTeams (){
      return winsMaxHeap.num();  
    };
};

int main()
{
    int wins;
    int losses;
    int k;
    string name;
    string input;
    
    TeamPQ tms;
    
    cin >> input;

    while (input != "x") {
        
        if (input == "r"){
            tms.reset();
        }
        
        else if (input == "i"){
            cin >> wins;
            cin >> losses; 
            cin >> name;
            tms.insert(Team(wins,losses,name));
        }
        
        else if (input == "pw"){
            if ( tms.numOfTeams() > 0) {
                cout << tms.findMaxWins().name << endl;
            }}
        
        else if (input == "pl"){
            if ( tms.numOfTeams() > 0) {
                cout << tms.findMinLosses().name << endl;
            }}
        
        else if (input == "rw") {
            if ( tms.numOfTeams() > 0) {
                tms.removeMaxWins();
            }}
        
        else if (input == "rl") {
            if ( tms.numOfTeams() > 0) {
                tms.removeMaxWins();
            }}
        
        else if (input == "ra"){
          if ( tms.numOfTeams() > 0) {
                cin >> k;
                tms.removeAllK(k);
            }}
        
        cin >> input ;
    }
};



