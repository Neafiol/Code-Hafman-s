#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <math.h>
#include <map>

#define FI(x) for(int i=0;i<(x);i++)
#define DB(x) cout<<#x<<": "<<(x)<<'\n';




using namespace std;

map<char, vector<bool> > al;

struct node{
    int p=0;
    char c =0;
    bool type=0;
    node* left=0;
    node* right=0;
};
fstream cdout;

void vout( vector<node*> v){
    FI(v.size()){
        cout<<v[i]->p<<' ';
    }
    cout<<'\n';
}
void codout( vector<bool> v){
    for(int i=1;i<v.size();i++){
        cdout<<v[i];
    }
    cdout<<'\n';
}
string strcod( vector<bool> v){
	string r="";
    for(int i=1;i<v.size();i++){
        r+=v[i]+'0';
    }
    return r;
}


bool comp (node* a, node* a1){
    return a->p > a1->p;
}
void codes(node* n,vector<bool> cod){
	cod.push_back(n->type);
	
	if(!n->left&&!n->right){
		cdout<<int(n->c)<<' ';
		codout(cod);
		al[n->c]=cod;
	}
	if(n->left){
		codes(n->left,cod);
	}
	if(n->right){
		codes(n->right,cod);
	}
	
}

string encodes(string s){
	string r="";
	FI(s.size()){
		r+=strcod(al[s[i]]);
	}
	return r;
	
}

void step(vector<node*> &v){

    node* n = new node();
    n->p+=v.back()->p;
    n->right=v.back();

    v.pop_back();
    n->p+=v.back()->p;
    n->left=v.back();
    v.back()->type = 1;
    v.pop_back();
    v.push_back(n);

}


int main(){
    int b,c;
    char a;
    vector<node*> alf;
    FI(255){
    	node* n =new node;
    	n->c=i;
    	alf.push_back(n);
	}

    fstream fin,tout;
    fin.open("input.txt",ios::in);
    cdout.open("table.txt",ios::out);
    tout.open("h_file.txt",ios::out);
    
	string s,text,et;
	
	while(getline(fin, s)){
		s+='\n';
		text+=s;
		for(int i=0;i<s.size();i++){
			a=s[i];
			alf[a]->p++;
		}
	}


    sort(alf.begin(),alf.end(),comp);
    while(alf.back()->p==0){
    	alf.pop_back();
	}
	
	while(alf.size()>1){
		step(alf);
		sort(alf.begin(),alf.end(),comp);
	}
	vout(alf);
	
	vector<bool>cd;
	codes(alf[0],cd);
		
	et=encodes(text);
	
	int buf =7-et.size()%8;
	et="1"+et;

	FI(buf) {
		et="0"+et;
	}
	
		
	tout<<et<<"\n";
	cout<<"Original size: "<<(text.size())*8<<'\n';
	cout<<"Short size: "<<et.size()<<'\n';


}
