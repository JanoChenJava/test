
#include<iostream>
#include<fstream>///����һ���ı��ļ���д����Ϣ
#include<string.h>

using namespace std;

struct student///�ṹ��
{
	char no[13];///ѧ��
	char name[20];///����
	char address[100];///��ַ
	char tel_no[12];///�绰����
	char post_code[7];///�ʱ�
	char e_mail[40];///�����ַ
};
class inter///��Ϣ��
{
private:
	student st[35];///�û���
public:
	void add(char no[13], char name[20], char address[100], char tel_no[12], char post_code[7], char e_mail[40]);///�����Ϣ
	void del(char name[20]);///ɾ��
	void find1(char no[13]);///����ѧ��
	void find2(char name[20]);///��������
	void list1();///��ѧ������
	void list2();///����������
	int correct(char name[20]);
	void read();///��ȡ�ļ�
	void write();///¼���ļ�
	void format();///��ʽ��
	int back()///���ؽ���
	{
		cout << "        ���ػ��ǻص����˵� ��TΪ�˳��� RΪ�ص����˵��� :   ";
		char back;
		cin >> back;
		if (back == 'R' || back == 'r')
			return 1;
		else
			return 0;
	}
	void print(int i)///����
	{
		cout << " ѧ��:" << st[i].no << endl;
		cout << " ����:" << st[i].name << endl;
		cout << " ��ַ:" << st[i].address << endl;
		cout << " �绰���� :" << st[i].tel_no << endl;
		cout << " �ʱ�:" << st[i].post_code << endl;
		cout << "E_MAIL:" << st[i].e_mail << endl;
	}
};
/// ������ ��ҳ
int main()
{
	inter a;///�������
	a.format();///��ʼ����Ϣ
	char select1;///����
	cout << endl;
top:
	cout << "\t\t                      ����ʦ��                     " << endl << "\t\t ��������������������������� " << endl << "\t\t �� ��" << endl << "\t\t �� ͨ Ѹ ¼ ��" << endl << "\t\t �� ��" << endl << "\t\t �� 1. ͨѶ¼�༭ .            4. ��������  .       ��" << endl << "\t\t �� ��" << endl << "\t\t �� 2. ��ѯ��ϵ�� .            5. ���ļ�������� .   ��" << endl << "\t\t �� ��" << endl << "\t\t �� 3. ������д���ļ� .        6. ��ʽ�������ã� .   ��" << endl << "\t\t �� ��" << endl << "\t\t ��������������������������� " << endl << "\t\t                                                    " << endl << endl << "\t\t\t ѡ�� :";
	cin >> select1;
	switch (select1)
	{
	case '1':
		cout << "        (1) ���:" << endl;
		cout << "        (2) ɾ��:" << endl;
		cout << "        (3) �޸�:" << endl;
		char select2;///����
		cout << "        ��ѡ�� :" << endl;
		cin >> select2;
		switch (select2)
		{
		case '1':
			cout << "        ������ӵ����� :" << endl;
			char no[13];
			char name[20];
			char address[100];
			char tel_no[12];
			char post_code[7];
			char e_mail[40];
			cout << "         ����ѧ�� :" << endl;
			cin >> no;
			cout << "         �������� :" << endl;
			cin >> name;
			cout << "         �����ַ :" << endl;
			cin >> address;
			cout << "         ����绰���� :" << endl;
			cin >> tel_no;
			cout << "         �����ʱ� :" << endl;
			cin >> post_code;
			cout << "         ���� E_mail:" << endl;
			cin >> e_mail;
			a.add(no, name, address, tel_no, post_code, e_mail);
			cout << "        ���ػ��ǻص����˵��� T Ϊ�˳��� RΪ�ص����˵������ƴ�Сд�� :";
			char back_add;
			cin >> back_add;
			if (back_add == 'R' || back_add == 'r')
				goto top;
			else
				goto bottom;
		break; case '2':
			cout << "        ����Ҫɾ���˵����� :" << endl;
			char name2[20];
			cin >> name2;
			a.del(name2);
			cout << "        ���ػ��ǻص����˵��� T Ϊ�˳��� RΪ�ص����˵������ƴ�Сд�� :";
			char back_del;
			cin >> back_del;
			if (back_del == 'R' || back_del == 'r')
				goto top;
			else
				goto bottom;
			break;
		case '3':
			cout << "        ������Ҫ�޸��˵����� :" << endl;
			char name3[20];
			cin >> name3;
			if (a.correct(name3))
				goto top;
			else goto bottom;
			break;
		}
		break;
	case '2':
		cout << "        (1) ������������ " << endl;
		cout << "        (2) ����ѧ�Ų��� " << endl;
		char select3;///����
		cout << "        ��ѡ�� :  ";
		cin >> select3;
		switch (select3)
		{
		case '1':
			char name4[20];
			cout << "         �������� :  ";
			cin >> name4;
			a.find2(name4);///����������
			cout << "        ���ػ��ǻص����˵��� T Ϊ�˳��� RΪ�ص����˵������ƴ�Сд�� :";
			char back_f1;
			cin >> back_f1;
			if (back_f1 == 'R' || back_f1 == 'r')
				goto top;
			else
				goto bottom;
			break;
		case '2':
			char no4[13];
			cout << "         ����ѧ�� :  ";
			cin >> no4;
			a.find1(no4);///��ѧ�Ų���
			cout << "        ���ػ��ǻص����˵��� T Ϊ�˳��� RΪ�ص����˵������ƴ�Сд�� :";
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
		a.write();///¼���ļ�
		cout << "        ���ػ��ǻص����˵� ��TΪ�˳��� RΪ�ص����˵��� ���ƴ�Сд�� :   ";
		char back_w;
		cin >> back_w;
		if (back_w == 'R' || back_w == 'r')
			goto top;
		else
			goto bottom;
		break;
	case '4':
		cout << "         (1) ��ѧ������ :" << endl;
		cout << "         (2) ���绰�������� :" << endl;
		cout << "          ��ѡ�� :";
		char select4;///����
		cin >> select4;
		switch (select4)
		{
		case '1':
			a.list1();
			cout << "        ���ػ��ǻص����˵��� T Ϊ�˳��� RΪ�ص����˵������ƴ�Сд�� :";
			char back;
			cin >> back;
			if (back == 'R' || back == 'r')
				goto top;
			else
				goto bottom;
			break;
		case '2':
			a.list2();
			cout << "        ���ػ��ǻص����˵��� T Ϊ�˳��� RΪ�ص����˵������ƴ�Сд�� :";
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
		a.read();///��ȡ�ļ�
		cout << "        ���ػ��ǻص����˵� ��TΪ�˳��� RΪ�ص����˵��� ���ƴ�Сд�� :   ";
		char back_r;
		cin >> back_r;
		if (back_r == 'R' || back_r == 'r')
			goto top;
		else
			goto bottom;
		break;
	case '6':
		cout << "         ��ȷ��ɾ���������� !(Y/N)   ";
		char select5;///����
		cin >> select5;
		if (select5 == 'Y' || select5 == 'y')
			a.format();///�������
		cout << "        ���ػ��ǻص����˵� ��TΪ�˳��� RΪ�ص����˵��� ���ƴ�Сд�� :   ";
		char back_f;
		cin >> back_f;
		if (back_f == 'R' || back_f == 'r')
			goto top;
		else
			goto bottom;
		break;
	}
bottom:
	cout << "           ������������������������  " << endl;
	return 0;
}
/// �����ϵ��
void inter::add(char no[13], char name[20], char address[100], char tel_no[12], char post_code[7], char e_mail[40])
{
	int x = 1;///��־λ
	for (int i = 0; i<35; i++)///ͨ��ѭ�������ÿ���û�����Ϣ
	{
		if (!strcmp(st[i].no, "0"))///�ж��Ƿ�
		{
			strcpy(st[i].address, address);///�ɵ�ַ��ӽ�ȥ
			strcpy(st[i].e_mail, e_mail);///��������ӽ�ȥ
			strcpy(st[i].name, name);///��������ӽ�ȥ
			strcpy(st[i].no, no);///��ѧ����ӽ�ȥ
			strcpy(st[i].post_code, post_code);///���ʱ���ӽ�ȥ
			strcpy(st[i].tel_no, tel_no);///�ɵ绰������ӽ�ȥ
			x = 0;
		}
		if (x == 0)
			break;
	}
}
/// ɾ����ϵ��
void inter::del(char name[20])
{
	int x = 1;///��־λ
	for (int i = 0; i<35; i++)
	{
		if (!strcmp(st[i].name, name))
		{
			strcpy(st[i].address, "0");///�ɵ�ַɾ��
			strcpy(st[i].e_mail, "0");///������ɾ��
			strcpy(st[i].name, "0");///������ɾ��
			strcpy(st[i].no, "0");///��ѧ��ɾ��
			strcpy(st[i].post_code, "0");///���ʱ�ɾ��
			strcpy(st[i].tel_no, "0");///�ɵ绰����ɾ��
			cout << "         ɾ���ɹ��� " << endl;
			break;
		}
		else
		{
			x = 0;
		}
	}
	if (x == 0)
		cout << "         ������������ " << endl;
}
/// �޸���ϵ��
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
		cout << "û�д���ϵ��!!\n";

	}
	else
	{
	char select; cout << "        (1) �޸����� :" << endl; cout << "        (2) �޸�ѧ�� :" << endl; cout << "        (3) �޸ĵ�ַ :" << endl;  cout << "        (4) �޸��ʱ� :" << endl;  cout << "        (5) �޸ĵ绰���� :" << endl;  cout << "        (6) �޸� E_MAIL:" << endl; cout << "         ��ѡ�� :"; cin >> select;
	switch (select)
	{
	case '1':cout << "         ����Ҫ�޸ĵ����� :";
		char name1[30];
		cin >> name1;
		strcpy(st[x].name, name1);
		cout << "        �޸ĳɹ��� " << endl;
		return
			back();
		break;
	case '2':
		cout << "         ����Ҫ�޸ĵ�ѧ�� :";
		char no1[13];
		cin >> no1;
		strcpy(st[x].no, no1);
		cout << "        �޸ĳɹ��� " << endl;
		return
			back();
		break;
	case '3':
		cout << "         ����Ҫ�޸ĵĵ�ַ :";
		char address1[100];
		cin >> address1;
		strcpy(st[x].address, address1);
		cout << "        �޸ĳɹ��� " << endl;
		return
			back();
		break;
	case '4':
		cout << "         ����Ҫ�޸ĵ��ʱ� :";
		char post_code1[7];
		cin >> post_code1;
		strcpy(st[x].post_code, post_code1);
		cout << "        �޸ĳɹ��� " << endl;
		return
			back();
		break;
	case '5':
		cout << "         ����Ҫ�޸ĵĵ绰���� :";
		char tel_no1[12];
		cin >> tel_no1;
		strcpy(st[x].tel_no, tel_no1);
		cout << "        �޸ĳɹ��� " << endl;
		return
			back();
		break;
	case '6':
		cout << "         ����Ҫ�޸ĵ� E_MAIL:";
		char e_mail1[40];
		cin >> e_mail1;
		strcpy(st[x].e_mail, e_mail1);
		cout << "        �޸ĳɹ��� " << endl;
		return
			back();
		break;

	}
	}
}
/// ��ѧ�Ų�ѯ��ϵ��
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
    cout << "        �����ѧ�Ų��Ҳ����� ����" << endl;
	main();
	}
}
///��������ѯ��ϵ��
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
	{cout << "        ������������Ҳ����� ����" << endl;
	main();
	}
}
/// ��ȡ�ļ�
void inter::read()
{
	char name1[20];
	cout << "        ������Ҫ������ļ��� :  ";
	cin >> name1;
	strcat(name1, ".txt");///�������ַ�����������
	ifstream  file(name1);///�����ļ�
	char line[120];
	char no[120];
	char name[120];
	char address[120];
	char post_code[120];
	char tel_no[120];
	char e_mail[120];
	int time = 0;///��־λ
	file.getline(line, 120);///���ļ���Ա����
	while (!file.eof())///ѭ�������ļ�
	{
		for (int k = 0; k<35; k++)///ѭ��ȫ���û�
		{
			if (time == 0)///ѧ��
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
			if (time == 1)///����
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
			if (time == 2)///��ַ
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
			if (time == 3)///�绰��
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
			if (time == 4)///�ʱ�
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
			if (time == 5)///�����ַ
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

	file.close();///�ر��ļ�
}
/// д���ļ�
void inter::write()
{
	char name[20];
	cout << "        ����Ҫ������ļ���  ";
	cin >> name;
	strcat(name, ".txt");
	ofstream  savefile(name);///����ļ�
	for (int i = 0; i<35; i++)
	{
		savefile << " ѧ��:" << st[i].no << endl;
		savefile << " ����:" << st[i].name << endl;
		savefile << " ��ַ:" << st[i].address << endl;
		savefile << " �绰���� :" << st[i].tel_no << endl;
		savefile << " �ʱ�:" << st[i].post_code << endl;
		savefile << "E_MAIL:" << st[i].e_mail << endl;
	}
	savefile.close();///�ر��ļ�
}
/// ��ѧ������
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
/// ���绰��������
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
/// ��ʽ��
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


