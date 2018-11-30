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

map<string, char > al;


string decode(string s){
	string r="",ans="";
	FI(s.size()){
		r+=s[i];
		if(al.find(r)!=al.end()){
			ans+=al[r];
			//cout<<r<<endl;
			r="";
		}
	}
	return ans;	
}

int main(){
    int b,c,n;
    int a;
    string cod;

    fstream fin,cdin,fout;
    fin.open("table.txt",ios::in);
    cdin.open("h_file.txt",ios::in);
    fout.open("output.txt",ios::out);
    
	string s,text="",ot;
	
	while(!fin.eof()){
		fin>>a;		
		fin>>cod;
		cout<<a<<'-'<<cod<<endl;
		al[cod]=a;
	}
	while(getline(cdin, s)){
		text+=s;
	}

	while(text[0]=='0'){
		text.erase(0, 1);		
	}
	text.erase(0, 1);

	
	cout<<"Short size: "<<text.size()<<'\n';
	ot=decode(text);
	cout<<"Original size: "<<(ot.size())*8<<'\n';
	fout<<ot;
    


}
