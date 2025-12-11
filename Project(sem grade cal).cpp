#include<iostream>
#include<iomanip>
#include<windows.h>
using namespace std;

class intro{
	
	public:
		
	intro()
	{
	system("color 7");
	cout<<"\n\n\n";
    cout<<"\t\t==============================================="<<endl;
    cout<<"\t\t|                                             |"<<endl;
    cout<<"\t\t|         Welcome to GPA/CGPA Calculator      |"<<endl;
    cout<<"\t\t|                                             |"<<endl;
    cout<<"\t\t===============================================\n"<<endl;
    Sleep(1000);
    } 
    
    void menu()
	{
	system("color 7");
	cout<<"\n\n\n\t\t\tLoading system.";
    for(int i=0;i<10;i++) {
    cout << ".";
    Sleep(300);
    }
    cout << "  Done!\n";
    system("cls");
    cout<<"\n\n";
    cout<<"\t\t***********************************************"<<endl;
    cout<<"\t\t*                  MAIN MENU                  *"<<endl;
    cout<<"\t\t***********************************************"<<endl;
    cout<<"\t\t*                                             *"<<endl;
    cout<<"\t\t*         1. Calculate GPA                    *"<<endl;
    cout<<"\t\t*         2. Calculate CGPA                   *"<<endl;
    cout<<"\t\t*         3. View Grading System              *"<<endl;
    cout<<"\t\t*         4. Exit                             *"<<endl;
    cout<<"\t\t*                                             *"<<endl;
    cout<<"\t\t***********************************************"<<endl;
    }

};

class gpa_cal{
	
	    	private:
			
			int subject;
			string subject_name[100];
			string grade[100];
			int credit_hour[100];
			double grade_point[100];
			double total_point=0;
			int total_credit=0;
			float gpa=0;
			
			public:
				
			gpa_cal (){
				cout<<"\n    --- Input ---"<<endl;
				cout<<"__________________________"<<endl;
				cout<<"\n\n Enter the number of subjects in your semester :\t";
		        cin>>subject;
		        cin.ignore();
		        system ("cls");
			}
			
			void subject_input(){	
			    cout<<"\n    --- Input ---"<<endl;
			    cout<<"__________________________"<<endl<<endl<<endl;
		    	for(int i=0;i<subject;i++){
				cout<<" Enter your "<<i+1<<" subject name :\t\t";
				getline(cin,subject_name[i]);
			}
		    	system ("cls");
	     	}
			
			void grade_input(){
				cout<<"\n    --- Input ---"<<endl;
				cout<<"__________________________"<<endl<<endl<<endl;
				for(int i=0;i<subject;i++){
				bool valid=false;	
				while(!valid){
				cout<<" Enter the Grade of "<<subject_name[i]<<" :\t\t";
				cin>>grade[i];
				if(grade[i]=="A+"||grade[i]=="A"||grade[i]=="B+"||grade[i]=="B"||grade[i]=="B-"||grade[i]=="C+"||grade[i]=="C"||grade[i]=="D"||grade[i]=="F"){
						valid=true;
			}
		    	else{
				cout<<"\n ERROR!! Enter a valid Grade (A+, A, B+, B, B-, C+, C, D, F)!"<<endl<<endl;}
	    	}
		}
		system ("cls");
	}
	
	        void credit_input(){
	        	cout<<"\n    --- Input ---"<<endl;
				cout<<"__________________________"<<endl<<endl<<endl;
	        	for(int i=0;i<subject;i++){
	            	do {
	        		cout<<" Enter Credit Hours of "<<subject_name[i]<<" :  ";
	        		cin>>credit_hour[i];
	        		if (credit_hour[i]<0) {
                       cout << "Invalid! Credit Hour must be positive.\n"<<endl;
                 }
                     } while(credit_hour[i]<0);
				}
		system ("cls");
	}
	        
	        void set_gradepoint(){
	        	for(int i=0;i<subject;i++){
	        		
	        		if (grade[i]=="A+"){
	        			grade_point[i]=4.00;
					}
					else if(grade[i]=="A"){
						 	grade_point[i]=3.70;
					}
						else if(grade[i]=="B+"){
						 	grade_point[i]=3.40;
					}
						else if(grade[i]=="B"){
						 	grade_point[i]=3.00;
					}
						else if(grade[i]=="B-"){
						 	grade_point[i]=2.50;
					}
						else if(grade[i]=="C+"){
						 	grade_point[i]=2.00;
					}
						else if(grade[i]=="C"){
						 	grade_point[i]=1.50;
					}
						else if(grade[i]=="D"){
							grade_point[i]=1.00;
					}
				    	else if(grade[i]=="F"){
							grade_point[i]=0.00;
					}
				}
			}
			
			void cal_gpa(){
				for (int i=0;i<subject;i++){
					total_point+=(grade_point[i]*credit_hour[i]);
				}
				for (int i=0;i<subject;i++){
					total_credit+=credit_hour[i];
				}
				gpa=total_point/total_credit;
				cout<<fixed<<setprecision(2);
			}
         	
         	void gpa_result(){
         		system("color 7");
         		cout<<"\n === Final Report ===\n"<<endl;
         		cout<<left<<setw(30)<<"Subject"<<setw(30)<<"Credit Hour"<<setw(30)<<"Grade"<<endl;
         		cout<<"---------------------------------------------------------------------"<<endl;
         		for (int i=0;i<subject;i++){
         		   cout<<left<<setw(30)<<subject_name[i]<<setw(30)<<credit_hour[i]<<setw(30)<<grade[i]<<endl;
				 }
				cout<<"---------------------------------------------------------------------\n"<<endl;
				 cout<<"Total Credit Hours : "<<total_credit<<endl;
				 cout<<"Semester GPA : "<<gpa<<endl<<endl;
				 system("pause");
				 system ("cls");
			 }
	
};

class cgpa_cal{
	
	private:
		int semester;
		double gpa[100];
		int credit_hour[100];
		double mul[100];
		double sum_of_gpa=0;
		int sum_of_credit=0;
		float cgpa=0;
		
	public:
		
		cgpa_cal(){
			cout<<"\n    --- Input ---"<<endl;
			cout<<"__________________________"<<endl<<endl<<endl;
			cout<<" How many semester's CGPA you want to calculate :\t\t";
			cin>>semester;
			system ("cls");
		}
		
		void input_gpa(){
			cout<<"\n    --- Input ---"<<endl;
			cout<<"__________________________"<<endl<<endl<<endl;
			for(int i=0;i<semester;i++){
				do{
				cout<<" Enter "<<i+1<<" semester GPA :\t\t";
				cin>>gpa[i];
				cout<<" Enter "<<i+1<<" semester Credit Hour :\t";
				cin>>credit_hour[i];
				cout<<endl;
				if(gpa[i]>4.00||gpa[i]<0.00){
					cout<<"\n Error!! Enter valid GPA!\n"<<endl;
				}
				if(credit_hour[i]<0){
					cout<<"\n Error!! Enter valid Credit Hours!\n"<<endl;
				}
			    }while (gpa[i]>4.00||gpa[i]<0.00||credit_hour[i]<0);
			}
			system ("cls");
		}
		
		void cal_cgpa(){
			for(int i=0;i<semester;i++){
				mul[i]=gpa[i]*credit_hour[i];
			}
			for(int i=0;i<semester;i++){
				sum_of_gpa+=mul[i];
			}
			for(int i=0;i<semester;i++){
				sum_of_credit+=credit_hour[i];
			}
			cgpa=sum_of_gpa/sum_of_credit;
			cout<<fixed<<setprecision(2);
		}
		
		void cgpa_result(){
			system("color 7");
			cout<<"\n === Final Report ===\n"<<endl;
			cout<<left<<setw(20)<<"Semester"<<setw(20)<<" GPA"<<setw(20)<<"Credit Hours"<<endl;
			cout<<"-----------------------------------------------------"<<endl;
			for(int i=0;i<semester;i++){
				cout<<i+1<<left<<setw(20)<<" Semester"<<setw(20)<<gpa[i]<<setw(20)<<credit_hour[i]<<endl;
			}
			cout<<"-----------------------------------------------------"<<endl;
			cout<<"Total Credit Hours : "<<sum_of_credit<<endl;
			cout<<"Total CGPA : "<<cgpa<<endl<<endl;
			system("pause");
			system ("cls");
		}
		
};

class grade_chart{
	
	public:
	string grade[9]={"A+","A","B+","B","B-","C+","C","D","F"};
	float grade_point[9]={4.00,3.70,3.40,3.00,2.50,2.00,1.50,1.00,0.00};
	string status[9]={"Exceptional","Outstanding","Excellent","Very_Good","Good","Average","Satisfactory","Pass","Fail"};
	
	 grade_chart(){
	system("color 7");
	cout<<" === Grading System === "<<endl;
    cout<<"----------------------------------------------------"<<endl;
    cout<<left<<setw(20)<<"Grade"<<setw(20)<<"Grade Point"<<setw(20)<<"Status"<<endl;
    cout<<"----------------------------------------------------"<<endl;
    for(int i=0;i<9;i++){
    cout<<left<<setw(20)<<grade[i]<<setw(20)<<grade_point[i]<<setw(20)<<status[i]<<endl;
    }
    cout<<"----------------------------------------------------"<<endl<<endl;
      system("pause");
      system("cls");
    }
                
};

int main(){

	int choice;
    intro welcome;

    do {
    	welcome.menu();
        cout<<"Enter your choice (1-4): ";
        cin>>choice;
        system("cls");

        switch(choice) {
            case 1: {
            	system ("color 2");
                gpa_cal gpaObj;
                gpaObj.subject_input();
                gpaObj.grade_input();
                gpaObj.credit_input();
                gpaObj.set_gradepoint();
                gpaObj.cal_gpa();
                gpaObj.gpa_result();
                break;
            }
            case 2: {
            	system ("color 2");
                cgpa_cal cgpaObj;
                cgpaObj.input_gpa();
                cgpaObj.cal_cgpa();
                cgpaObj.cgpa_result();
                break;
            }
            case 3: {
                grade_chart gradeObj;
                break;
            }
            case 4: {
                cout << "\n\n\n Thank you for using the program. Goodbye!\n";
                break;
            }
            default: {
                cout << "Invalid choice! Please enter 1-4.\n";
            }
        }
    } while (choice != 4);

    return 0;
}
