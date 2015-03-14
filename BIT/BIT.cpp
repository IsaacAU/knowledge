/*
 * BIT.cpp
 *
 *  Created on: Mar 14, 2015
 *      Author: Isaac
 */
#include "BIT.h"

BIT::BIT(const vector<int> &v):tree(vector<int>(v.size()+1,0)){
	for(int i=1; i<=v.size(); ++i)
		initBIT(v, i);
}

void BIT::initBIT(const vector<int> &v, int idx){
	int s=idx-(idx&-idx), e=idx;
	for(int i=s; i<e; ++i)
		tree[idx]+=v[i];
}

int BIT::getSum(int idx) const{
	int res=0;
	while(idx){
		res+=tree[idx];
		idx-=idx&-idx;
	}
	return res;
}

int BIT::getSum(int s, int e) const{
	return getSum(e+1)-getSum(s);
}

int BIT::getElem(int i) const{
	return getSum(i+1)-getSum(i);
}

int BIT::getSize() const{
	return tree.size()-1;
}

void BIT::updateTree(int idx, int dif){
	while(idx<tree.size()){
		tree[idx]+=dif;
		idx+=idx&-idx;
	}
}

void BIT::update(int i, int val){
	int idx=i+1, dif=val-getElem(i);
	updateTree(idx, dif);
}

ostream& operator<<(ostream& os, const BIT &bit){
	for(int i=0; i<bit.getSize(); ++i)
		os<<bit.getElem(i)<<'\t';
	return os;
}




