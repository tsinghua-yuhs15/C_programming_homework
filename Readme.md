##C++作业报告——文件操作

<br>

***本次作业在OSX系统上进行测试，如果需要在windows上进行检查则需要复制源代码重新编译***

<br>
1.代码见src文件

2.简要原理分析

主要采用控制台交互的方法，通过用户输入指令，程序读取指令并进行相关操作。

3.运行结果：（结果较长无法截图，复制了控制台log信息）

                                        
                                        
	                                        
	         ***                 ***        
	      *********           *********     
	     ************       ************    
	     *************     *************    
	     **************   **************    
	     *************** ***************    
	      *******    *** ***    *******     
	       ******     *****     ******      
	        ******     ***     ******       
	          ******    *    ******         
	             ****** * ******            
	               ***********              
	                *********               
	                 *******                
	                  *****                 
	                    *                   
	                                        
	Welcome to the Human Resource Management Project Beta!
	no file using
	Please enter instructions:
	l
	Please enter the filename you are about to open:
	test
	load error
	no file using
	Please enter instructions:
	n
	Please enter the file name you want:
	test
	using  test
	Please enter instructions:
	i
	please enter new information
	name:ZhangSan
	grade:Manager
	salary:34579
	Please enter instructions:
	i
	please enter new information
	name:LiSi
	grade:Technician
	salary:23456
	Please enter instructions:
	i
	please enter new information
	name:WangWu
	grade:Salesman
	salary:12390
	Please enter instructions:
	e
	save confirm?
	y
	no file using
	Please enter instructions:
	l
	Please enter the filename you are about to open:
	test
	using test
	Please enter instruction:
	d
	1 ZhangSan Manager 34579
	2 LiSi Technician 23456
	3 WangWu Salesman 12390
	Please enter instruction:
	s
	please enter the searching content:
	3
	3 WangWu Salesman 12390
	any change?
	n
	Please enter instruction:
	s
	please enter the searching content:
	WangWu
	3 WangWu Salesman 12390
	any change?
	y
	please enter new information
	name:WangLiu
	grade:Salesmanager
	salary:22390
	Please enter instruction:
	d
	1 ZhangSan Manager 34579
	2 LiSi Technician 23456
	3 WangLiu Salesmanager 22390
	Please enter instruction:
	e
	save confirm?
	y
	no file using
	Please enter instructions:
	e
	byebye
	Program ended with exit code: 0
	
	
最终文件如图：
![](/Users/yhs/Desktop/text.png)