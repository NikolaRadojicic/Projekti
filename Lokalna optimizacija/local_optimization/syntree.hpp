#ifndef __SYNTREE_HPP__
#define __SYNTREE_HPP__ 1

#include<string>
#include<vector>
using namespace std;

class SynTree{
public:
	virtual string className() const = 0;;
	virtual string Name() const = 0;
	virtual int getVal() const = 0;
	virtual ~SynTree();
}; 

class Instruction{
public:
	Instruction(string id ,string o ,SynTree* l , SynTree* r);
	void alg_transf_optimize();
	void propag_copy_optimize();
	void const_fold_optimize();
	void elim_sub_optimize();	
	void elim_dead_optimize();	
	void run_optimize(int optimization_num);
	string print(bool out) const;
	string printInverse(bool out) const;
	void PropagFillTable();
	void ElimSubFillTable();
	void ElimDeadFillTable();
	void setDead();
	string getIdName();
private:
	bool dead;
	string id_name;
	string op;
	vector<SynTree*> operands;
};

class Const : public SynTree{
public:
	Const(int c):value(c){}
	string className() const;
	string Name() const;
	int getVal() const;
private:
	int value;
};

class Variable : public SynTree{
public:
	Variable(string n):name(n){}
	string className() const;
	string Name() const;
  int getVal() const;
private:
	string name;
};



#endif
