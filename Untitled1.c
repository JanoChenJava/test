
#include<iostream>
#include<fstream>///创建一个文本文件并写入信息
#include<string.h>

using namespace std;

struct student///结构体
{
	char no[13];///学号
	char name[20];///姓名
	char address[100];///地址
	char tel_no[12];///电话号码
	char post_code[7];///邮编
	char e_mail[40];///邮箱地址
};
class inter///信息类
{
private:
	student st[35];///用户数
public:
	void add(char no[13], char name[20], char address[100], char tel_no[12], char post_code[7], char e_mail[40]);///添加信息
	void del(char name[20]);///删除
	void find1(char no[13]);///查找学号
	void find2(char name[20]);///查找姓名
	void list1();///按学号排序
	void list2();///按姓名排序
	int correct(char name[20]);
	void read();///读取文件
	void write();///录入文件
	void format();///格式化
	int back()///返回界面
	{
		cout << "        返回还是回到主菜单 （T为退出， R为回到主菜单） :   ";
		char back;
		cin >> back;
		if (back == 'R' || back == 'r')
			return 1;
		else
			return 0;
	}
	void print(int i)///输入
	{
		cout << " 学号:" << st[i].no << endl;
		cout << " 姓名:" << st[i].name << endl;
		cout << " 地址:" << st[i].address << endl;
		cout << " 电话号码 :" << st[i].tel_no << endl;
		cout << " 邮编:" << st[i].post_code << endl;
		cout << "E_MAIL:" << st[i].e_mail << endl;
	}
};
/// 主函数 首页
int main()
{
	inter a;///定义对象
	a.format();///初始化信息
	char select1;///变量
	cout << endl;
top:
	cout << "\t\t                      集宁师范                     " << endl << "\t\t ★★★★★★★★★★★★★★★★★★★★★★★★★★ " << endl << "\t\t ※ ※" << endl << "\t\t ※ 通 迅 录 ※" << endl << "\t\t ※ ※" << endl << "\t\t ※ 1. 通讯录编辑 .            4. 按序排列  .       ※" << endl << "\t\t ※ ※" << endl << "\t\t ※ 2. 查询联系人 .            5. 将文件读入程序 .   ※" << endl << "\t\t ※ ※" << endl << "\t\t ※ 3. 将资料写入文件 .        6. 格式化（慎用） .   ※" << endl << "\t\t ※ ※" << endl << "\t\t ★★★★★★★★★★★★★★★★★★★★★★★★★★ " << endl << "\t\t                                                    " << endl << endl << "\t\t\t 选择 :";
	cin >> select1;
	switch (select1)
	{
	case '1':
		cout << "        (1) 添加:" << endl;
		cout << "        (2) 删除:" << endl;
		cout << "        (3) 修改:" << endl;
		char select2;///变量
		cout << "        请选择 :" << endl;
		cin >> select2;
		switch (select2)
		{
		case '1':
			cout << "        输入添加的资料 :" << endl;
			char no[13];
			char name[20];
			char address[100];
			char tel_no[12];
			char post_code[7];
			char e_mail[40];
			cout << "         输入学号 :" << endl;
			cin >> no;
			cout << "         输入姓名 :" << endl;
			cin >> name;
			cout << "         输入地址 :" << endl;
			cin >> address;
			cout << "         输入电话号码 :" << endl;
			cin >> tel_no;
			cout << "         输入邮编 :" << endl;
			cin >> post_code;
			cout << "         输入 E_mail:" << endl;
			cin >> e_mail;
			a.add(no, name, address, tel_no, post_code, e_mail);
			cout << "        返回还是回到主菜单（ T 为退出， R为回到主菜单，不计大小写） :";
			char back_add;
			cin >> back_add;
			if (back_add == 'R' || back_add == 'r')
				goto top;
			else
				goto bottom;
		break; case '2':
			cout << "        输入要删除人的姓名 :" << endl;
			char name2[20];
			cin >> name2;
			a.del(name2);
			cout << "        返回还是回到主菜单（ T 为退出， R为回到主菜单，不计大小写） :";
			char back_del;
			cin >> back_del;
			if (back_del == 'R' || back_del == 'r')
				goto top;
			else
				goto bottom;
			break;
		case '3':
			cout << "        输入需要修改人的姓名 :" << endl;
			char name3[20];
			cin >> name3;
			if (a.correct(name3))
				goto top;
			else goto bottom;
			break;
		}
		break;
	case '2':
		cout << "        (1) 根据姓名查找 " << endl;
		cout << "        (2) 根据学号查找 " << endl;
		char select3;///变量
		cout << "        请选择 :  ";
		cin >> select3;
		switch (select3)
		{
		case '1':
			char name4[20];
			cout << "         输入姓名 :  ";
			cin >> name4;
			a.find2(name4);///按姓名查找
			cout << "        返回还是回到主菜单（ T 为退出， R为回到主菜单，不计大小写） :";
			char back_f1;
			cin >> back_f1;
			if (back_f1 == 'R' || back_f1 == 'r')
				goto top;
			else
				goto bottom;
			break;
		case '2':
			char no4[13];
			cout << "         输入学号 :  ";
			cin >> no4;
			a.find1(no4);///按学号查找
			cout << "        返回还是回到主菜单（ T 为退出， R为回到主菜单，不计大小写） :";
			char back_f2;
			cin >> back_f2;
			if (back_f2 == 'R' || back_f2 == 'r')
				goto top;
			else
				goto bottom;
			break;
		}
		break;
	case '3':
		a.write();///录入文件
		cout << "        返回还是回到主菜单 （T为退出， R为回到主菜单， 不计大小写） :   ";
		char back_w;
		cin >> back_w;
		if (back_w == 'R' || back_w == 'r')
			goto top;
		else
			goto bottom;
		break;
	case '4':
		cout << "         (1) 按学号排序 :" << endl;
		cout << "         (2) 按电话号码排序 :" << endl;
		cout << "          请选择 :";
		char select4;///变量
		cin >> select4;
		switch (select4)
		{
		case '1':
			a.list1();
			cout << "        返回还是回到主菜单（ T 为退出， R为回到主菜单，不计大小写） :";
			char back;
			cin >> back;
			if (back == 'R' || back == 'r')
				goto top;
			else
				goto bottom;
			break;
		case '2':
			a.list2();
			cout << "        返回还是回到主菜单（ T 为退出， R为回到主菜单，不计大小写） :";
			char back1;
			cin >> back1;
			if (back1 == 'R' || back1 == 'r')
				goto top;
			else
				goto bottom;
			break;
		}
		break;
	case '5':
		a.read();///读取文件
		cout << "        返回还是回到主菜单 （T为退出， R为回到主菜单， 不计大小写） :   ";
		char back_r;
		cin >> back_r;
		if (back_r == 'R' || back_r == 'r')
			goto top;
		else
			goto bottom;
		break;
	case '6':
		cout << "         请确认删除所有资料 !(Y/N)   ";
		char select5;///变量
		cin >> select5;
		if (select5 == 'Y' || select5 == 'y')
			a.format();///清除资料
		cout << "        返回还是回到主菜单 （T为退出， R为回到主菜单， 不计大小写） :   ";
		char back_f;
		cin >> back_f;
		if (back_f == 'R' || back_f == 'r')
			goto top;
		else
			goto bottom;
		break;
	}
bottom:
	cout << "           ★★★★★★★★★★★★★★★★★★★★★★★  " << endl;
	return 0;
}
/// 添加联系人
void inter::add(char no[13], char name[20], char address[100], char tel_no[12], char post_code[7], char e_mail[40])
{
	int x = 1;///标志位
	for (int i = 0; i<35; i++)///通过循坏来添加每个用户的信息
	{
		if (!strcmp(st[i].no, "0"))///判断是否
		{
			strcpy(st[i].address, address);///吧地址添加进去
			strcpy(st[i].e_mail, e_mail);///吧邮箱添加进去
			strcpy(st[i].name, name);///吧姓名添加进去
			strcpy(st[i].no, no);///吧学号添加进去
			strcpy(st[i].post_code, post_code);///吧邮编添加进去
			strcpy(st[i].tel_no, tel_no);///吧电话号码添加进去
			x = 0;
		}
		if (x == 0)
			break;
	}
}
/// 删除联系人
void inter::del(char name[20])
{
	int x = 1;///标志位
	for (int i = 0; i<35; i++)
	{
		if (!strcmp(st[i].name, name))
		{
			strcpy(st[i].address, "0");///吧地址删除
			strcpy(st[i].e_mail, "0");///吧邮箱删除
			strcpy(st[i].name, "0");///吧姓名删除
			strcpy(st[i].no, "0");///吧学号删除
			strcpy(st[i].post_code, "0");///吧邮编删除
			strcpy(st[i].tel_no, "0");///吧电话号码删除
			cout << "         删除成功！ " << endl;
			break;
		}
		else
		{
			x = 0;
		}
	}
	if (x == 0)
		cout << "         输入姓名错误！ " << endl;
}
/// 修改联系人
int inter::correct(char name[30])
{
	int x=0;
	for (int i = 0; i<35; i++)
	{
		if (strcmp(st[i].name, name)==0)
			x = i;
	}
	if (x==0)
	{
		cout << "没有此联系人!!\n";

	}
	else
	{
	char select; cout << "        (1) 修改姓名 :" << endl; cout << "        (2) 修改学号 :" << endl; cout << "        (3) 修改地址 :" << endl;  cout << "        (4) 修改邮编 :" << endl;  cout << "        (5) 修改电话号码 :" << endl;  cout << "        (6) 修改 E_MAIL:" << endl; cout << "         请选择 :"; cin >> select;
	switch (select)
	{
	case '1':cout << "         输入要修改的姓名 :";
		char name1[30];
		cin >> name1;
		strcpy(st[x].name, name1);
		cout << "        修改成功！ " << endl;
		return
			back();
		break;
	case '2':
		cout << "         输入要修改的学号 :";
		char no1[13];
		cin >> no1;
		strcpy(st[x].no, no1);
		cout << "        修改成功！ " << endl;
		return
			back();
		break;
	case '3':
		cout << "         输入要修改的地址 :";
		char address1[100];
		cin >> address1;
		strcpy(st[x].address, address1);
		cout << "        修改成功！ " << endl;
		return
			back();
		break;
	case '4':
		cout << "         输入要修改的邮编 :";
		char post_code1[7];
		cin >> post_code1;
		strcpy(st[x].post_code, post_code1);
		cout << "        修改成功！ " << endl;
		return
			back();
		break;
	case '5':
		cout << "         输入要修改的电话号码 :";
		char tel_no1[12];
		cin >> tel_no1;
		strcpy(st[x].tel_no, tel_no1);
		cout << "        修改成功！ " << endl;
		return
			back();
		break;
	case '6':
		cout << "         输入要修改的 E_MAIL:";
		char e_mail1[40];
		cin >> e_mail1;
		strcpy(st[x].e_mail, e_mail1);
		cout << "        修改成功！ " << endl;
		return
			back();
		break;

	}
	}
}
/// 按学号查询联系人
void inter::find1(char no[13])
{
	int x, y = 1;
	for (int i = 0; i<35; i++)
	{
		if (strcmp(st[i].no, no)==0)
		{
			x = i;
			print(x);
		}
		else
        {
            y=0;
        }
	}
	if(y=0)
	{
    cout << "        输入的学号查找不到！ ！！" << endl;
	main();
	}
}
///按姓名查询联系人
void inter::find2(char name[20])
{
	int x,y=1;
	for (int i = 0; i<35; i++)
	{
		if (strcmp(st[i].name, name)==0)
		{
			x = i;
			print(x);
		}
		else
        {
            y=0;
        }
	}
	if(y=0)
	{cout << "        输入的姓名查找不到！ ！！" << endl;
	main();
	}
}
/// 读取文件
void inter::read()
{
	char name1[20];
	cout << "        输入你要导入的文件名 :  ";
	cin >> name1;
	strcat(name1, ".txt");///把俩个字符串链接起来
	ifstream  file(name1);///输入文件
	char line[120];
	char no[120];
	char name[120];
	char address[120];
	char post_code[120];
	char tel_no[120];
	char e_mail[120];
	int time = 0;///标志位
	file.getline(line, 120);///类文件成员函数
	while (!file.eof())///循坏整个文件
	{
		for (int k = 0; k<35; k++)///循坏全部用户
		{
			if (time == 0)///学号
			{
                strcpy(no, line);
				time = 1;
				for (int i = 0; i<120; i++)
				{
					if (no[i] == ':')
					{
						i++;
						for (int j = 0; j<13; j++)
						{
							st[k].no[j] = no[i];
							i++;
						}
					}
				}
				file.getline(line, 120, '\n');

			}
			if (time == 1)///姓名
			{
				strcpy(name, line);
				time = 2;
				for (int i = 0; i<120; i++)
				{
					if (name[i] == ':')
					{
						i++;
						for (int j = 0; j<20; j++)
						{
							st[k].name[j] = name[i];
							i++;
						}
					}
				}
				file.getline(line, 120, '\n');
			}
			if (time == 2)///地址
			{
				strcpy(address, line);
				time = 3;
				for (int i = 0; i<120; i++)
				{
					if (address[i] == ':')
					{
						i++;
						for (int j = 0; j<100; j++)
						{
							st[k].address[j] = address[i];
							i++;
						}
					}
				}
				file.getline(line, 120, '\n');
			}
			if (time == 3)///电话号
			{
				strcpy(tel_no, line);
				time = 4;
				for (int i = 0; i<120; i++)
				{
					if (tel_no[i] == ':')
					{
						i++;
						for (int j = 0; j<12; j++)
						{
							st[k].tel_no[j] = tel_no[i];
							i++;
						}
					}
				}
				file.getline(line, 120, '\n');
			}
			if (time == 4)///邮编
			{
				strcpy(post_code, line);
				time = 5;
				for (int i = 0; i<120; i++)
				{
					if (post_code[i] == ':')
					{
						i++;
						for (int j = 0; j<7; j++)
						{
							st[k].post_code[j] = post_code[i];
							i++;
						}
					}
				}
				file.getline(line, 120, '\n');
			}
			if (time == 5)///邮箱地址
			{
				strcpy(e_mail, line);
				time = 0;
				for (int i = 0; i<120; i++)
				{
					if (e_mail[i] == ':')
					{
						i++;
						for (int j = 0; j<40; j++)
						{
							st[k].e_mail[j] = e_mail[i];
							i++;
						}
					}
				}
				file.getline(line, 120, '\n');
			}
		}
	}

	file.close();///关闭文件
}
/// 写入文件
void inter::write()
{
	char name[20];
	cout << "        输入要保存的文件名  ";
	cin >> name;
	strcat(name, ".txt");
	ofstream  savefile(name);///输出文件
	for (int i = 0; i<35; i++)
	{
		savefile << " 学号:" << st[i].no << endl;
		savefile << " 姓名:" << st[i].name << endl;
		savefile << " 地址:" << st[i].address << endl;
		savefile << " 电话号码 :" << st[i].tel_no << endl;
		savefile << " 邮编:" << st[i].post_code << endl;
		savefile << "E_MAIL:" << st[i].e_mail << endl;
	}
	savefile.close();///关闭文件
}
/// 按学号排序
void inter::list1()
{
	for (int i = 0; i<34; i++)
	{
		for (int j = 0; j<35 - i; j++)
		{
			if (strcmp(st[j].no, st[j + 1].no)>0)
			{
				char no[13];
				char name[20];
				char address[100];
				char tel_no[12];
				char post_code[7];
				char e_mail[40];
				strcpy(no, st[j].no);
				strcpy(st[j].no, st[j + 1].no);
				strcpy(st[j + 1].no, no);
				strcpy(name, st[j].name);
				strcpy(st[j].name, st[j + 1].name);
				strcpy(st[j + 1].name, name);
				strcpy(address, st[j].address);
				strcpy(st[j].address, st[j + 1].address);
				strcpy(st[j + 1].address, address);
				strcpy(tel_no, st[j].tel_no);
				strcpy(st[j].tel_no, st[j + 1].tel_no);
				strcpy(st[j + 1].tel_no, tel_no);
				strcpy(post_code, st[j].post_code);
				strcpy(st[j].post_code, st[j + 1].post_code);
				strcpy(st[j + 1].post_code, post_code);
				strcpy(e_mail, st[j].e_mail);
				strcpy(st[j].e_mail, st[j + 1].e_mail);
				strcpy(st[j + 1].e_mail, e_mail);
			}
		}
	}
	for (int k = 0; k<35; k++)
	{
		int x = 0;
		if (strcmp(st[k].no, "0"))
		{
			print(k);
			x = 1;
		}
		if (x == 1)
		{
			cout << endl;
			cout << "----------------------------------------------------------------------------" << endl;

		}
	}
}
/// 按电话号码排序
void inter::list2()
{
	for (int i = 0; i<34; i++)
	{
		for (int j = 0; j<35 - i; j++)
		{
			if (strcmp(st[j].tel_no, st[j + 1].tel_no)>0)
			{
				char no[13];
				char name[20];
				char address[100];
				char tel_no[12];
				char post_code[7];
				char e_mail[40];
				strcpy(no, st[j].no);
				strcpy(st[j].no, st[j + 1].no);
				strcpy(st[j + 1].no, no);
				strcpy(name, st[j].name);
				strcpy(st[j].name, st[j + 1].name);
				strcpy(st[j + 1].name, name);
				strcpy(address, st[j].address);
				strcpy(st[j].address, st[j + 1].address);
				strcpy(st[j + 1].address, address);
				strcpy(tel_no, st[j].tel_no);
				strcpy(st[j].tel_no, st[j + 1].tel_no);
				strcpy(st[j + 1].tel_no, tel_no);
				strcpy(post_code, st[j].post_code);
				strcpy(st[j].post_code, st[j + 1].post_code);
				strcpy(st[j + 1].post_code, post_code);
				strcpy(e_mail, st[j].e_mail);
				strcpy(st[j].e_mail, st[j + 1].e_mail);
				strcpy(st[j + 1].e_mail, e_mail);
			}
		}
	}
	for (int k = 0; k<35; k++)
	{
		int x = 0;
		if (strcmp(st[k].no, "0"))
		{
			print(k);
			x = 1;
		}
		if (x == 1)
		{
			cout << endl;
			cout << "---------------------------------------------------------------------" << endl;

		}
	}
}
/// 格式化
void inter::format()
{
	for (int i = 0; i<35; i++)
	{
		strcpy(st[i].address, "0");
		strcpy(st[i].e_mail, "0");
		strcpy(st[i].name, "0");
		strcpy(st[i].no, "0");
		strcpy(st[i].post_code, "0");
		strcpy(st[i].tel_no, "0");
	}
}


