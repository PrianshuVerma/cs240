#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
//Class for teams

class Team {
	
	public:
        int wins;
        int losses;
        string name;

	Team(int w,int l,string n) {
		wins = w;
		losses = l;
		name = n;
	};
};

class MinHeap {
	public:

        // vector to store referances to teams
        vector <Team> heap;

        void insert(const Team &t ){
               heap.push_back(t);
        }
	
        void fixUp(int numOfTeams) {

                int child = numOfTeams - 1;
                int parent = (child - 1) / 2;

                while ( (child >= 0 && parent >= 0) && (heap[parent].losses >= heap[child].losses) ) {
			
			swap(heap[parent],heap[child]);
			child = parent;
			parent = ( child - 1 ) / 2;
		};
        }

	void print() {

		for(unsigned int i = 0; i < heap.size(); i++) {

                                std::cout << heap[i].name << ' ';

                        }
		std::cout << endl;
	};


};

class MaxHeap {

        //vector to store referances to teams
        vector <Team> heap;
};


class TeamPQ {

        // all private things
        private:

                MinHeap lossesMinHeap;
                MaxHeap winsMaxHeap;
                int numOfTeams;


        public:

		TeamPQ() {
			numOfTeams = 0;
		};


		 void insert(const Team &t){
		 	numOfTeams += 1;
			lossesMinHeap.insert(t);
			lossesMinHeap.fixUp(numOfTeams);
			
		 };

    		 const Team &findMaxWins() const;    // O(1) time
     		 const Team &findMinLosses() const;  // O(1) time


		void removeMaxWins();
		void removeMinLosses();
		void removeAllK(int k);


		void printMin(){

			 lossesMinHeap.print();
		};

};



int main() {

	Team a = Team(0,1, "fsdf");
	Team b = Team(0,2,"f");
	Team c = Team(0,3,"fsf");
	Team d = Team(0,4,"fd");

   
	TeamPQ o;

        o.insert(a);
	o.insert(b);
	o.insert(c);
	o.insert(d);

	o.printMin();
};
