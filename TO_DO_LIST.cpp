#include<iostream>
#include<vector>
#include<string>
using namespace std;

struct Task{
	string description;
	bool completed;
};

vector<Task> tasks;

void addTask(){
	string description;
	cout<<"enter task description";
	cin.ignore();
	getline(cin, description);
	Task newTask={description,false};
	tasks.push_back(newTask);
	
	cout<<"Task added successfully";
}
	void viewTasks(){
		
		if(tasks.empty()){
			cout<<"No tasks in the list.\n";
		}
		else{
			for(size_t i=0; i<tasks.size();++i){
				cout<<i+1<<" . "<<(tasks[i].completed ? "completed" : "pending")<<endl;
			}
		}
	}

void markTaskcompleted(){
	viewTasks();
	int index;
	cout<<"enter task number to mark as completed: ";
	cin>>index;
	cin.ignore();
	
	if(index>0 && index <= tasks.size()){
		tasks[index-1].completed=true;
		cout<<"task marked as completed.\n";
		
	}
	else{
		cout<<"invlaid task number.\n";
	}
}



void removeTask(){
	viewTasks();
	int index;
	cout<<"enter task number to remove:";
	cin>>index;
	cin.ignore();
	if(index>0 && index<=tasks.size()){
		cout<<"Task \""<<tasks[index-1].description<<"\" removed.\n";
		tasks.erase(tasks.begin()+index-1);
		
	}
	else{
		cout<<"invalid task number\n";
	}
}

void mainmenu(){
	while(true){
		cout<<"\nto-do-list manager\n'";
		cout<<"1.add Tasks\n";
		cout<<"2.view Tasks\n";
		cout<<"3.mark Task as completed\n";
		cout<<"4.remove Tasks\n";
		cout<<"5.exit\n";
		cout<<"choose an option(1-5)";
	
		
		int choice;
		cin>>choice;
		cin.ignore();
		switch(choice){
			case 1:
				addTask();
				break;
			case 2:
				viewTasks();
				break;
			case 3:
				markTaskcompleted();
				break;
			case 4:
				removeTask();
				break;
			case 5:
				cout<<"exciting to-do list manager.goodbye!\n";
				return;
			default:
				cout<<"invalid option . please try again \n";
		}
	}
}
	int main()
	{
		mainmenu();
		return 0;
	}


