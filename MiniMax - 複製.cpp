
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <stdlib.h>
#include <stdio.h>

using namespace std;
int Pow( int a, int b );
int limDepth;
int BranNum;
int *num;
int numIndex;

class node{
	public:
		int data;
		bool valid = false;

		node(){}
		/*~node(){
			cout << "³Q±þ¤F";
		}*/
		vector<node *> table;
};

node *create();

void Tree( node* root,int depth ){
	int index;
	node * temp;
	if( depth == limDepth ){
		root->data = num[numIndex];
		root->valid = true;
		numIndex++;
	}
	else{
		depth++;
		//root->table.resize(BranNum);
		for ( index=0;index<BranNum;index++ ){
			temp = create();
			root->table.push_back(temp);
			Tree( temp, depth);
		}
	}
}

node * create(){
	node * n = new node();
	return n;
}

void ReadData(){

	string str;
	string str1 = ",";
	ifstream input("´ú¸ÕÀÉ.txt");
	stringstream ss;
	string temp;
	int index = 0;
	int i;
	while ( input >> str ){
		if ( index == 0 ){
			BranNum = stoi( str );
			cout << BranNum << endl;
		}
		else if ( index == 1 ){
			limDepth = stoi( str );
			cout << limDepth << endl;
			num = new int[ Pow( BranNum, limDepth ) ];
		}
		//if ( str.find(",")!=string::npos ){
		else{
			cout << "hi";
			ss.clear();
			ss.str( str );
			for ( i=0;i<16;i++ ){
				getline( ss,temp,',' );
				num[i] = stoi( temp );
				cout << num[i] << " ";
			}
		}
		index++;
	}
	input.close();
}

int Pow( int a, int b ){
	return (int)pow( (double)a, (double)b );
}

int main()
{
	node * n = create();
	ReadData();

	Tree( n,0 );
    return 0;
}
