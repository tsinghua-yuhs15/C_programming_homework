//
//  interact.cpp
//  Human Resouce Management
//
//  Created by 于海粟 on 2017/4/24.
//  Copyright © 2017年 于海粟. All rights reserved.
//
#include <vector>
#include "interact.hpp"
using namespace std;

fstream f;
int fflag;
string filename;

void main_action(){
    fflag=0;
    filename="";
    auto _inst='0';
    while(1){
        cout<<((fflag==0)?"no file using":("using  "+filename))<<endl;
        cout<<"Please enter instructions:"<<endl;
        cin>>_inst;
        switch(_inst){
            case 'n'://new file
                if(new_file()){
                    cout<<"create file failed"<<endl;
                    fflag=0;
                }
                break;
            case 'l'://load file
                if(load_file()){
                    cout<<"load error"<<endl;
                }
                break;
            case 'e'://exit
                exit(0);
        }
    }
}

int new_file(){
    fflag=1;
    cout<<"Please enter the file name you want:"<<endl;
    cin>>filename;
    cout<<"using  "+filename<<endl;
    
    f.open(filename,ios::out);
    if(!f) return 1;
    vector<employee> vec;
    while(1){
        if(fflag==0) break;
        auto _inst='0';
        cout<<"Please enter instructions:"<<endl;
        cin>>_inst;
        switch(_inst){
            case 'i'://insert employee info
                if(insert_employee_info(vec)){
                    cout<<"insert error"<<endl;
                }
                break;
            case 'e'://exit new file creation
                save_confirm(vec);
                break;
        }
    }
    return 0;
}

int load_file(){
    fflag=1;
    cout<<"Please enter the filename you are about to open:"<<endl;
    cin>>filename;
    f.open(filename,ios::in|ios::out);
    if(!f) return 1;
    cout<<"using "+filename<<endl;
    string input;
    vector<employee> vec;
    char tp[MAX_SIZE];
    while(f.getline(tp, MAX_SIZE)){
        if(!f) cout<<"!!!"<<endl;
        int i=0,j=0,k=0;
        char info[4][MAX_SIZE],tmp;
        while((tmp=tp[i++])!=0){
            if(tmp=='*'){
                j++;
                k=0;
                continue;
            }
            info[j][k++]=tmp;
        }
        employee *e=new employee(info[1],info[2],atof(info[3]));
        vec.push_back(*e);
    }
    f.close();
    f.open(filename,ios::in|ios::out);
    if(!f) cout<<"!!!"<<endl;
    while(1){
        if(fflag==0) break;
        auto _inst='0';
        int number=0;
        cout<<"Please enter instruction:"<<endl;
        cin>>_inst;
        switch(_inst){
                case 'e':
                save_confirm(vec);
                return 0;
                case 'd':
                display(vec);
                break;
                case 'i':
                cout<<"please enter the info you want to insert:"<<endl;
                if(insert_employee_info(vec)){
                    cout<<"insert error"<<endl;
                }
                break;
                case 's':
                cout<<"please enter the searching content:"<<endl;
                cin>>input;
                const char *s=input.data();
                if(search_employee_info(vec,s,number)){
                    cout<<"search failure"<<endl;
                }
                vec[number].dis_employee_info();
                cout<<"any change?"<<endl;
                cin>>_inst;
                if(_inst=='y'){
                    modify(vec[number]);
                }
                break;
        }
    }
    return -1;
}

int insert_employee_info(vector<employee> &vec){
    if(!f){
        return 1;
    }
    string name,grade;
    double salary;
    cout<<"please enter new information"<<endl<<"name:";
    cin>>name;
    cout<<"grade:";
    cin>>grade;
    cout<<"salary:";
    cin>>salary;
    employee *e =new employee(name,grade,salary);
    vec.push_back(*e);
    return 0;
}

int search_employee_info(vector<employee> &vec,const char* input,int &number){
    number=-1;
    if(input[0]>='0'&&input[0]<='9'){
        //number input
        number=atoi(input)-1;
        if(number<0||number>=vec.size()) return 1;
        return 0;
    }
    for(int i=0;i<vec.size();i++){
        if(vec[i].get_name()==input){
            number=i;
            return 0;
        }
    }
    return 1;
}

int save_confirm(vector<employee> &vec){
    if(!f){
        return 1;
    }
    string write;
    auto _inst='0';
    cout<<"save confirm?"<<endl;
    cin>>_inst;
    switch (_inst) {
        case 'y':
            for(int i=0;i<vec.size();i++){
                write=to_string(vec[i].get_individualEmpNo())+"*"+vec[i].get_name()+"*"+vec[i].get_grade()+"*"+to_string(vec[i].get_accumPay());
                f<<write<<endl;
            }
            vec.clear();
            employee::reset();
            fflag=0;
            f.close();
            break;
    }
    return 0;
}
int display(vector<employee> &vec){
    for(int i=0;i<vec.size();i++){
        vec[i].dis_employee_info();
    }
    return 0;
}

int modify(employee &e){
    string name,grade;
    double salary;
    cout<<"please enter new information"<<endl<<"name:";
    cin>>name;
    cout<<"grade:";
    cin>>grade;
    cout<<"salary:";
    cin>>salary;
    e.set_employee_info(name, grade, salary);
    return 0;
}
