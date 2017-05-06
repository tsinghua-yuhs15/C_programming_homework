//
//  interact.cpp
//  Human Resouce Management
//
//  Created by 于海粟 on 2017/4/24.
//  Copyright © 2017年 于海粟. All rights reserved.
//

#include "interact.hpp"

employee* e;
string file,context;
ifstream infile;
ofstream outfile;

map<int,string> save_;

void main_action(){
    char s;
    map<int,string>::iterator it;
    file="";
    int pgm_flag=0;
    while(1){
        if(file==""){
            cout<<"当前未使用任何文件"<<endl;
        }
        else{
            cout<<"正在使用文件："+file<<endl;
        }
        instructions_print();
        cin>>s;
        string save;
        switch(s){
            case 'l':
                //读取文件
                pgm_flag=1;
                load_file();
                break;
            case 's':
                //储存文件
                pgm_flag=2;
                save_file();
                break;
            case 'i':
                //插入信息
                pgm_flag=3;
                save=insert_employee();
                save_.insert(map<int,string>::value_type(e->get_individualEmpNo(),save));
                break;
            case 'c':
                //修改信息
                pgm_flag=4;
                it=search_employee();
                if(it!=save_.end()){
                    //found
                    save=correct_employee();
                    it->second=save;
                }
                break;
            case 'e':
                //退出程序
                pgm_flag=-1;
                
                
                break;
        }
        if(pgm_flag==-1){
            break;
        }
        else{
            continue;
        }
    }
    cout<<"byebye"<<endl;
}


void load_file(){
    char temp;
    cout<<"请输入要读取的文件名称："<<endl;
    cin>>file;
    infile.open(file+".txt",ios::in);
    if(!infile){
        cerr<<"Open File Error"<<endl;
        exit(1);
    }
    while(infile.get(temp)){
        cout<<temp;
    }
    string s;
    cout<<endl;
}

void save_file(){
    cin>>file;
    outfile.open(file+".txt",ios::out);
    if(!outfile){
        cerr<<"Open File Error"<<endl;
        exit(1);
    }
    for(map<int,string>::iterator it=save_.begin();it!=save_.end();it++){
        outfile<<it->first<<"&"<<it->second;
    }
}

string insert_employee(){
    stringstream tp;
    cout<<"请输入您要插入的员工类型"<<endl;
    string type,save,name;
    cin>>type;
    if(type=="employee"){
        string gr;
        double ap;
        cout<<"请输入姓名"<<endl;
        cin>>name;
        cout<<"请输入员工等级"<<endl;
        cin>>gr;
        cout<<"请输入员工薪资"<<endl;
        cin>>ap;
        e=new employee(name,gr,ap);
        tp<<ap;
        save = "employee&name:"+name+"&grade:"+gr+"&salary:"+tp.str();
    }
    else if(type=="Manager"){
        string l,d,name;
        cout<<"请输入姓名"<<endl;
        cin>>name;
        cout<<"请输入经理等级"<<endl;
        cin>>l;
        cout<<"请输入经理部门"<<endl;
        cin>>d;
        e=new Manager(name,l,d);
        save = "Manager&name:"+name+"&level:"+l+"&department:"+d;
    }
    else if(type=="Salesman"){
        double sales,ap;
        string p,name;
        cout<<"请输入姓名"<<endl;
        cin>>name;
        cout<<"请输入销售额"<<endl;
        cin>>sales;
        cout<<"请输入负责产品"<<endl;
        cin>>p;
        cout<<"请输入月薪"<<endl;
        cin>>ap;
        e=new Salesman(name,ap,p,sales);
        tp<<ap;
        save = "Salesman&name:"+name+"&salary:"+tp.str()+"&product:"+p+"&sales:";
        tp.clear();
        tp<<sales;
        save += tp.str();
    }
    else if(type=="Technician"){
        int wh;
        string f,l,name;
        cout<<"请输入姓名"<<endl;
        cin>>name;
        cout<<"请输入工作时间"<<endl;
        cin>>wh;
        cout<<"请输入研究领域"<<endl;
        cin>>f;
        cout<<"请输入技术等级"<<endl;
        cin>>l;
        e=new Technician(name,wh,f,l);
        tp<<wh;
        save = "Technician&name:"+name+"&work hours:"+tp.str()+"&field:"+f+"&level:"+l;
    }
    else if(type=="Salesmanager"){
        string l,p,name;
        double f;
        cout<<"请输入姓名"<<endl;
        cin>>name;
        cout<<"请输入销售经理等级"<<endl;
        cin>>l;
        cout<<"请输入负责产品"<<endl;
        cin>>p;
        cout<<"请输入下属总收入"<<endl;
        cin>>f;
        e=new Salesmanager(name,l,p,f);
        tp<<f;
        save = "Salesmanager&name:"+name+"&salary:"+tp.str()+"&level:"+l+"&product:"+p;
    }
    return save;
}

string correct_employee(){
    stringstream tp;
    cout<<"请输入您要修改的员工类型"<<endl;
    string type,save,name;
    cin>>type;
    if(type=="employee"){
        string gr;
        double ap;
        cout<<"请输入姓名"<<endl;
        cin>>name;
        cout<<"请输入员工等级"<<endl;
        cin>>gr;
        cout<<"请输入员工薪资"<<endl;
        cin>>ap;
        tp<<ap;
        save = "employee&name:"+name+"&grade:"+gr+"&salary:"+tp.str();
    }
    else if(type=="Manager"){
        string l,d,name;
        cout<<"请输入姓名"<<endl;
        cin>>name;
        cout<<"请输入经理等级"<<endl;
        cin>>l;
        cout<<"请输入经理部门"<<endl;
        cin>>d;
        save = "Manager&name:"+name+"&level:"+l+"&department:"+d;
    }
    else if(type=="Salesman"){
        double sales,ap;
        string p,name;
        cout<<"请输入姓名"<<endl;
        cin>>name;
        cout<<"请输入销售额"<<endl;
        cin>>sales;
        cout<<"请输入负责产品"<<endl;
        cin>>p;
        cout<<"请输入月薪"<<endl;
        cin>>ap;
        tp<<ap;
        save = "Salesman&name:"+name+"&salary:"+tp.str()+"&product:"+p+"&sales:";
        tp.clear();
        tp<<sales;
        save += tp.str();
    }
    else if(type=="Technician"){
        int wh;
        string f,l,name;
        cout<<"请输入姓名"<<endl;
        cin>>name;
        cout<<"请输入工作时间"<<endl;
        cin>>wh;
        cout<<"请输入研究领域"<<endl;
        cin>>f;
        cout<<"请输入技术等级"<<endl;
        cin>>l;
        tp<<wh;
        save = "Technician&name:"+name+"&work hours:"+tp.str()+"&field:"+f+"&level:"+l;
    }
    else if(type=="Salesmanager"){
        string l,p,name;
        double f;
        cout<<"请输入姓名"<<endl;
        cin>>name;
        cout<<"请输入销售经理等级"<<endl;
        cin>>l;
        cout<<"请输入负责产品"<<endl;
        cin>>p;
        cout<<"请输入下属总收入"<<endl;
        cin>>f;
        tp<<f;
        save = "Salesmanager&name:"+name+"&salary:"+tp.str()+"&level:"+l+"&product:"+p;
    }
    return save;
}

map<int,string>::iterator search_employee(){
    map<int,string>::iterator it;
    cout<<"请输入要搜索的员工编号或姓名"<<endl;
    string input;
    cin>>input;
    const char* s=input.data();
    if(input[0]>='0'&&input[0]<=9){
        //num
        it=save_.find(atoi(s));
        cout<<"no:"<<it->first<<"  "<<it->second;
    }
    else{
        for(it=save_.begin();it!=save_.end();it++){
            auto s = it->second.find(input);
            if(s>0&&s<it->second.length()){
                break;
            }
        }
        cout<<"no:"<<it->first<<"  "<<it->second;
    }
    return it;
}
