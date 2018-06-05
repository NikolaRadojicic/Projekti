#include "syntree.hpp"
#include<map>
#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>
#include<cmath>
#include<cstdio>
using namespace std;

extern FILE* f;	
extern map<string,string> tableType;
extern map<string,int> tableInt;
extern map<string,string> tableId;

extern map<string,pair<string,string> > instPrint;


extern vector<Instruction*> vInst;
extern vector<string> operandsNameTable;
extern string IdOfLastInstruction;
extern bool changed;

extern map<string,int> instructionNumberTable;
extern int instructionNumber;


SynTree :: ~SynTree(){}


Instruction :: Instruction(string id , string o ,SynTree* l , SynTree* r){
	dead = false;
	id_name = id;
	op = o;
	if(o != ""){
		operands.resize(0);
		operands.push_back(l);
		operands.push_back(r);
		}
	else{
		operands.resize(0);
		operands.push_back(l);
	}

}


void Instruction :: setDead(){
	dead = true;
}


string Instruction :: getIdName(){
	return id_name;
}


string Instruction :: print(bool out) const{	/*funkcija vraca ispis izraza sa desne strane u obliku : operand operacija operand*/

	if(!dead){
		string s;
		s = s + id_name + "=";
		for(unsigned i = 0 ; i < operands.size() ; i++){
			if(operands[i]->className() == "Const")
				s = s + to_string(operands[i]->getVal()); 
			else
				s = s + operands[i]->Name();
			
			if(i+2 == operands.size() )
				s = s + op ; 
			}
	
			s = s + ";";
			if(out){
				const char* output = s.c_str();
				fprintf(f , "%s\n", output);
		
			}
			return s.substr(2,s.length()-2);
	}

	return "";
}


string Instruction :: printInverse(bool out) const{	/*vraca se kroz funkciju obrnut ispis izraza sa desne strane*/
																										/*ako je bilo a + b , stampa se b + a */
	if(!dead){
		string s;
		s = s + id_name + "=";
		unsigned size = operands.size();
		for(unsigned i = 0 ; i < size; i++){
			if(operands[size-1-i]->className() == "Const")
				s = s + to_string(operands[size-1-i]->getVal()); 
			else
				s = s + operands[size-1-i]->Name();
			
			if(i+2 == operands.size() )
				s = s + op ; 
			}
	
			s = s + ";";
			if(out){
				const char* output = s.c_str();
				fprintf(f , "%s\n", output);
			}
		return s.substr(2,s.length()-2);
	}

	return "";
}


string Const :: className() const{
	return "Const";
}


string Const ::  Name() const{
	return "";
}


int Const :: getVal() const{
	return value;
}

string Variable :: className() const{
	return "Variable";
}


string Variable ::  Name() const{
	return name;
}


int Variable :: getVal() const{
	return 0;
}



void Instruction :: run_optimize(int optimization_num){

	switch(optimization_num){		/*U zavisnosti od prosledjenog broja se poziva odgovarajuca optimizacija nad instrukcijom*/

		case 0 : alg_transf_optimize();break;
		case 1 : const_fold_optimize();break;
		case 2 : propag_copy_optimize();break;
		case 3 : elim_sub_optimize();break;
		case 4 : elim_dead_optimize();break;
		default: {}
	}


}



int exp2(int n){	/*funkcija koja ispituje da li je broj mozda stepen 2*/
	int i	= 1;
	while(i <= 10){
		if(pow(2,i) == n)
			return i;
		i++;
	}
	return -1;
}



void Instruction :: alg_transf_optimize(){
	
	if(!dead){

				
					if(operands.size() == 2){

							if(operands[0]->className() == "Const" && operands[1]->className() == "Const"){
										
										int val1 = operands[0]->getVal();
										int val2 = operands[1]->getVal();

										if(op == "*" || op == "/"){
										
												int v = exp2(val1);
												int v1 = exp2(val2);
												if(v != -1 && op != "/"){
														if(op == "*")
																op = "<<";		/* mnozenje i deljenje se zamenjuju sa siftovanjem */
														else
															op = ">>";

															operands.clear();
															operands.push_back(new Const(val2));
															operands.push_back(new Const(v));
															changed = true;
																}
												else if(v1 != -1){

															if(op == "*")
																op = "<<";
															else
																op = ">>";
															
															operands.clear();
															operands.push_back(new Const(val1));
															operands.push_back(new Const(v1));
															changed = true;
																}
												else if(val1 == 1 && op != "/"){
															op = "";
															operands.clear();
															operands.push_back(new Const(val2));
													}
												else if(val2 == 1){
															op = "";
															operands.clear();
															operands.push_back(new Const(val1));
													}
												
													
										}

										if(op == "-" || op == "+"){

												if(val1 == 0){
															op = "";
															operands.clear();
															operands.push_back(new Const(val2));
													}
												else if(val2 == 0){
															op = "";
															operands.clear();
															operands.push_back(new Const(val1));
													}
										}
	
							}

							else if(operands[0]->className() == "Variable" && operands[1]->className() == "Const"){
										
									if(op == "+" || op == "-"){

										if(operands[1]->getVal() == 0){
											string name = operands[0]->Name();
											operands.resize(0);
											operands.push_back(new Variable(name));
											changed = true;

																}

														}

										else if(op == "*" || op == "/"){

										if(operands[1]->getVal() == 1){
											string name = operands[0]->Name();
											operands.clear();
											operands.push_back(new Variable(name));
											changed = true;

																}

										else{
											int v = exp2(operands[1]->getVal());
											if(v != -1){
															if(op == "*")
																op = "<<";	// ukoliko je konstanta stepen 2 , onda se vrsi siftovanje umesto mnozenja
															else 
																op = ">>";
															operands.clear();
															operands.push_back(new Variable(operands[0]->Name()));
															operands.push_back(new Const(v));
															
															changed = true;
																}
												
													}

												
											
									}
							}
							else if(operands[0]->className() == "Const" && operands[1]->className() == "Variable"){
										
										if(op == "+" || op == "-"){

										if(operands[0]->getVal() == 0){
											string name = operands[1]->Name();
											operands.clear();
											operands.push_back(new Variable(name));
											changed = true;

																}

														}

										else if(op == "*" ){

										if(operands[0]->getVal() == 1){
											string name = operands[1]->Name();
											operands.clear();
											operands.push_back(new Variable(name));
											changed = true;

																}

										else{
											int v = exp2(operands[0]->getVal());
											if(v != -1){
															
															op = "<<";
															operands.clear();
															operands.push_back(new Variable(operands[1]->Name()));
															operands.push_back(new Const(v));
															
															changed = true;
																}
												
													}

												
											
									}


									}

									else if(operands[0]->className() == "Variable" && operands[1]->className() == "Variable"){
										
										if(op == "+" ){
					
												if(operands[0]->Name() == operands[1]->Name()){	// ukoliko je npr izraz a + a , zamenjuje se sa 2 * a
														string name = operands[1]->Name();
														op = "*";
														operands.clear();
														operands.push_back(new Const(2));
														operands.push_back(new Variable(name));
														changed = true;

																				

																		}

															}

									}
						


					}

				}

}



void Instruction :: PropagFillTable(){	/*stavljamo u tablicu koja promenljiva cuva konstantu a koja identifikator*/
																				/* i u tablici cuvamo vrednosti u promenljivama sa leve strane*/
	if(operands.size() == 1){
		if(operands[0]->className() == "Const"){
				tableType[id_name] = "int";
				tableInt[id_name] = operands[0]->getVal();
			}
		else{
					tableType[id_name] = "id";
					tableId[id_name] = operands[0]->Name();
					
			}
		
	}
}



void Instruction :: propag_copy_optimize(){		
	
	if(!dead){

		if(operands.size() == 1){
			if(operands[0]->className() == "Variable"){		/*gledamo ako sa desne strane ima neka promenljiva da li ona postoji u tablici*/
					string name = operands[0]->Name();				
					map<string,string>::iterator tmp = tableType.find(name);
					if(tmp != tableType.end()){				/*ako postoji u tablici , menjamo tu vrednost sa desne strane sa vrednoscu iz tablice*/
							string type = tmp->second;
					
							if(type == "id")
								operands[0] = new Variable(tableId[name]);
							else
								operands[0] = new Const(tableInt[name]);

							changed = true;
						}
				}

		}
		else{			/*za instrukcije sa dva operanda*/
					if(operands[0]->className() == "Variable"){
						string name = operands[0]->Name();
						map<string,string>::iterator tmp = tableType.find(name);
						if(tmp != tableType.end()){
								string type = tmp->second;
							
								if(type == "id")
									operands[0] = new Variable(tableId[name]);
								else
									operands[0] = new Const(tableInt[name]);

								changed = true;
							}
			
			}


					if(operands[1]->className() == "Variable"){
							string name = operands[1]->Name();
							map<string,string>::iterator tmp = tableType.find(name);
							if(tmp != tableType.end()){
									string type = tmp->second;
									if(type == "id")
										operands[1] = new Variable(tableId[name]);
									else
										operands[1] = new Const(tableInt[name]);

									changed = true;
								}
			
				}

		}

	}
	
}
	


void Instruction :: const_fold_optimize(){	/*Ako su obe konstante samo se izvrsi operacija*/

	if(operands.size() == 2){

	if(operands[0]->className() == "Const" && operands[1]->className() == "Const"){
		int l = operands[0]->getVal();
		int r = operands[1]->getVal();
		operands.clear();
		if(op == "+")
			operands.push_back(new Const(l+r));
		else if(op == "-")
			operands.push_back(new Const(l-r));
		else if(op == "/")
			operands.push_back(new Const(l/r));
		else if(op == "*")
			operands.push_back(new Const(l*r));
		else if(op == "<<")
			operands.push_back(new Const(l << r));
		else if(op == ">>")
			operands.push_back(new Const(l >> r));	


		changed = true;
				
			}

	}


}



void Instruction ::  ElimSubFillTable(){	/*pamti se u tablici za svaku promenljivu sa leve strane njen potpis sa desne strane*/
																					/* npr za instrukciju a = 2 * b , cuvace se potpis 2 * b */
	instPrint[id_name].first = print(false);
	if(op == "+" || op == "*"){
		instPrint[id_name].second = printInverse(false);
				}
	else{
		instPrint[id_name].second = "";
		}

	instructionNumberTable[id_name] = instructionNumber;
	instructionNumber++;
}



void Instruction :: elim_sub_optimize(){	
 
	if(!dead){

		string printOfInstr = print(false);
		map<string,pair<string,string> >::iterator tmp;
		for(tmp = instPrint.begin() ; tmp != instPrint.end() ; tmp++){
			if(tmp->first != id_name){

					if(instructionNumberTable[id_name] > instructionNumberTable[tmp->first]){

						if((tmp->second).first == printOfInstr){	/*Porede se svi potpisi sa desne strane sa potpisom trenutne instrukcije*/
																									
											operands.clear();	
											operands.push_back(new Variable(tmp->first));		/* Ukoliko su isti potpisi sa desne strane se samo stavi ime */
											changed = true;																	/* promenljive koja u tablici ima isti potpis sa desne strane */
						
						}
						else if(op == "+" || op == "*"){		/*U ovom slucaju vazi komutativnost pa se pogleda obrnut potpis */
							if((tmp->second).second == printOfInstr){
											operands.clear();	
											operands.push_back(new Variable(tmp->first));
											changed = true;
								}
						}
					
				}

			}


		}

	}

}



void Instruction ::  ElimDeadFillTable(){		/*stavljamo u tablicu sve promenljive koje se javljaju sa desne strane*/
	if(!dead){

		if(operands.size() == 1){

			if(operands[0]->className() == "Variable")
				operandsNameTable.push_back(operands[0]->Name());

		}
		else {

			if(operands[0]->className() == "Variable")
				operandsNameTable.push_back(operands[0]->Name());

			if(operands[1]->className() == "Variable")
				operandsNameTable.push_back(operands[1]->Name());
		}

	}

}



void Instruction :: elim_dead_optimize(){		/*ako se ime promenljive sa leve strane instrukcije 
																							ne pojavljuje nigde sa desne strane izraza onda je mrtva*/
	if(id_name == IdOfLastInstruction)
		return;
	bool found = false;
	for(unsigned i = 0 ; i < operandsNameTable.size() ; i++)
			if(operandsNameTable[i] == id_name)
				found = true;


	if(!found && !dead){
		setDead();
		changed = true;
		}
}




