#include<iostream>
#include<string>
#include<fstream>
using namespace std;

class node{
	public:
		char data;
		node* next;
};
class stack{
	public:
		node *head, *tail;
	public:
		stack(){
			head = NULL;
			tail = NULL;
		}
		void push(char value){
			node *temp = new node;
			temp -> data = value;
			temp -> next = NULL;
			if(head == NULL){
				head = temp;
				tail = temp;
			}
			else{
				tail -> next = temp;
				tail = temp;
			}
			
		}
		char pop() {
			if(head == NULL){
				return -1;
			}
			node *current;
			current = head;
			
			node* previous;
			previous= head;
 
    		while(current->next != NULL) {
    			previous = current;
    			current = current->next;
			}
			char output = current -> data;
			previous->next = NULL;
			tail = previous;
			delete current;
			return output; 
		}
		char top() {
			if(head == NULL){
				return 'f';
			}
    		node *current;
			current = head;
			
			node* previous;
			previous= head;
 
    		while(current->next != NULL) {
    			previous = current;
    			current = current->next;
			}
			return current -> data;
		}
//		int empty() 
//		{ 
//    		return head == NULL; 
//		} 
};
bool AreParanthesesBalanced(string exp, int &bracket, int &bracketCounter, int &closeB){
	int openCount = 0;
	stack S;
	int openBrackets = 0;
	int closeBrackets = 0;
	bool flag = false;
	for(int i = 0; i < exp.length(); i++){
		if(exp[i] == '(' || exp[i] == '{' || exp[i] == '['){
			S.push(exp[i]);
			openCount++;
			openBrackets++;
		}
		else if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']'){
			closeBrackets++;
	//		char stat = S.top();
	//		if(stat == 'f'){
	//			return false;
	//			
	//		}
			if((S.top() == '(' && exp[i] == ')') || (S.top() == '{' && exp[i] == '}') || (S.top() == '[' && exp[i] == ']')){
				bracket++;
	//			cout << "matching" << endl;
				if(S.head != S.tail){
					openCount--;
					S.pop();
				}
			}
			else{
				bracketCounter = bracket * 2;
//				cout << endl << "opening bracket not found :" << bracketCounter << endl;
				return false;
				
				
			}
		}
	}
	if(S.head == S.tail && openBrackets == closeBrackets){
		return true;
	}
	else{
		closeB = (bracket) * 2;
//		bracketCounter = openCount;
//		cout << "closing bracket not found: " << bracket + 1 << endl;
		return false;
		
	}
}
int main()
{
	int lineFinder = 0;
	int closeB = 0;
	int bracketCounter = 0;
	int bracket = 0;
	string fileData;
	//reading file
	string line;
	ifstream mfile ("zahidFile.cpp");
	if (mfile.is_open())
	{
		while ( getline (mfile,line, '\0') )	
    	{
    	  fileData = line;
//    	  cout<<endl<<endl<<fileData<<endl<<endl<<endl;
    	}
		mfile.close();
	}
	else cout << "Unable to open file";
	if(AreParanthesesBalanced(fileData, bracket, bracketCounter, closeB))
		cout<< endl << endl << "Brackets are Balanced" << endl << endl;
	else{
		cout<< endl << endl << "Brackets are Not Balanced"<< endl << endl;
	}
//	cout << endl << "opening bracket not found :" << bracketCounter << endl;
//	cout << endl << "closing bracket not found: " << closeB << endl;
	int totalBrackets = bracketCounter + closeB - 1;
	cout<<endl<<endl<<endl;
	int brackline = 0;
	int paranthCounter = 0; 
	string lineCheck;
	ifstream m2file ("zahidFile.cpp");
	if (m2file.is_open())
	{
		
		while ( getline (m2file,lineCheck) )				//Getline (ifstreamVar, string, ',')
    	{
    	  
    	  for(int i = 0; i <= lineCheck.length(); i++){
    	  	
    	  	if(lineCheck[i] == '{' || lineCheck[i] == '[' || lineCheck[i] == '(' || lineCheck[i] == '}' || lineCheck[i] == ']' || lineCheck[i] == ')'){
    	  		 
				if(paranthCounter == totalBrackets){
    	  			cout << "error at line: " << lineFinder + 2 << endl<< endl;
    	  		}
    	  		
    	  		paranthCounter++;
    	  		
    	  	}
    	  	
    	  }
    	  lineFinder++;
    	  
    	}
    	
    	mfile.close();
	}

	else cout << "Unable to open file";

	
	
	
	return 0;
}
