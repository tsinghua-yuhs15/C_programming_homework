//
//  interact.hpp
//  Human Resouce Management
//
//  Created by 于海粟 on 2017/4/24.
//  Copyright © 2017年 于海粟. All rights reserved.
//

#ifndef interact_hpp
#define interact_hpp

#define  MAX_SIZE 100

#include "welcome_logo.hpp"
#include <fstream>
#include <map>
#include <sstream>


//文件格式：编号*姓名*职位*工资

void main_action();
int new_file();
int load_file();
int insert_employee_info(vector<employee> &vec);
int search_employee_info(vector<employee> &vec,const char* input,int &number);
int save_confirm(vector<employee> &vec);
int modify(employee &e);
int display(vector<employee> &vec);

#endif /* interact_hpp */
