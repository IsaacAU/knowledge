#include<vector>
#include<iostream>

using namespace std;

class BIT{
public:
	BIT(const vector<int> &v);
	int getSum(int,int) const;
	int getElem(int) const;
	void update(int,int);
	int getSize() const;
	friend ostream& operator<<(ostream&,const BIT&);
private:
	BIT(const BIT&);              // avoid copy
	BIT& operator=(const BIT&);   // avoid assign
	void initBIT(const vector<int>&,int);
	int getSum(int) const;
	void updateTree(int,int);
	vector<int> tree;
};

