#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>


int mingyan();      ///�û�����֤
int guayan(int);    ///��ʧ��֤
int miyan(int);     ///���뺯��
float T=0;          /// ����ȫ�ֱ���T,��¼�û�һ��ȡ�������ܺ�
void QUKUAN();      ///ȡ���
void CUNKUAN();     ///����
void CHAXUN();      ///��ѯ�����û���Ϣ����
void XIAOHU();      ///��������
void ZHUCE();       ///��������
void ZHUANZHANG();  ///ת�˺���
void lose();        ///��ʧ����
void chaall();      ///��ѯ�����û���Ϣ

char YHM[100][30];   ///�û���
char MIMA[100][30];  ///����
char Ggua[100][30];	 ///��ʧ�û���

float YuE[100];      ///������
int UserShu=0;       ///�û���
int guashu=0;        ///��ʧ�û���

int main()///��ҳ��
{

	int ML;///�������α���ML

	while(ML) ///����whileѭ��
	{
	    printf("\n\n\t��ӭʹ��ATMȡ���\n"); ///\t����tab���ĸ��ո�
		printf("\t\t1.����\t\t  4.ȡ��\n");  ///\t����tab���ĸ��ո�
		printf("\t\t2.���\t\t  5.����\n");  ///\t����tab���ĸ��ո�
		printf("\t\t3.��ѯ\t\t  6.ת��\n");  ///\t����tab���ĸ��ո�
		printf("\t\t7.�˻���Ϣ\t  8.��ʧ\n");///\t����tab���ĸ��ո�
		printf("\t\t0.�˳�\n");
		scanf("%d",&ML);///����һ�����֣�&��ȡ��ַ��
		printf("\n");///���\n����һ��
		switch(ML)///����switchѡ�����
		{
		case 1:ZHUCE();break;  ///��MLΪ1ʱ,����ע���Ӻ���
		case 2:CUNKUAN();break;///��MLΪ2ʱ,����ע����Ӻ���
		case 3:CHAXUN();break; ///��MLΪ3ʱ,���ò�ѯ�Ӻ���
		case 4:QUKUAN();break; ///��MLΪ4ʱ,����ȡ���Ӻ���
		case 5:XIAOHU();break; ///��MLΪ5ʱ,���������Ӻ���
		case 6:ZHUANZHANG();break;///��MLΪ6ʱ,����ת���Ӻ���
        case 7:chaall();break; ///��MLΪ7ʱ,���ò�ѯ�Ӻ���
		case 8:lose();break;   ///��MLΪ8ʱ,���ù�ʧ�Ӻ���
        case 0:                ///��MLΪ0ʱ�������������
			 printf("��ӭ���ٴ�ʹ�ã�\n");
			 exit(0);///ͨ���������ӳ����������ս����ʹ�ú�����Զ����������ز���ϵͳ
			 break;   ///����switch����
		}
	}


}

void QUKUAN()///ȡ��
{
	int i,m;      ///�������α���i,m
	float n;      ///���帡���α���n
	i=mingyan();  ///��mingyan()��ֵ��i
	m=guayan(i);  ///��guayan()��ֵ��m
	if(m==1)///���m=1�������������
		m=miyan(i);///��mingyan()��ֵ��m
	while(m==1)
	{
		printf("����������ȡ����: ");
		scanf("%f",&n);///����һ���ַ���&��ȡ��ַ��
		if(n>2000)///���n>2000ʱ
		{
			printf("ÿ��ȡ��ó���2000\n");
			QUKUAN();///����ȡ���Ӻ���
				break;///����while����


		}
		T+=n;///�൱��T=T+n
		if(T>50000)///��T����50000ʱ�������������
		{
			printf("ÿ��ȡ���������ܳ���50000��");
			break;///����while����
		}
		if(n<=YuE[i])///��nС�ڵ������ʱ
		{
			printf("��ȡ�����ĳ�Ʊ��\n");
			YuE[i]-=n;///�൱��YuE[i]=YuE[i]-n
			break;///����while����
		}
		else///��n�������ʱ�������������
			printf("�������㣬���������롣\n");
	}
}

void CUNKUAN()///���
{
	int i,m;///�������α���
	float n;///�������α���
	i=mingyan();///��mingyan()��ֵ��i
	m=guayan(i);///��guayan()��ֵ��m
		m=miyan(i);///��///��guayan()��ֵ��m��ֵ��m
	while(m==1)///��m=ʱ1
	{
		printf("���������Ĵ����: ");///��� ��������Ĵ����
		scanf("%f",&n);///����һ�����֣�&��ȡ��ַ��
		YuE[i]=YuE[i]+n;///�����������֮�͸�������
		printf("���ɹ���");///��� ���ɹ�
		printf("���ĵ�ǰ���Ϊ: %.2f\n",YuE[i]);///��� ���ĵ�ǰ���
		m=0;///��0��ֵ��m
	}
}
void CHAXUN()///��ѯ
{
	int i,m;///�������α���
	i=mingyan();///
	m=guayan(i);///
	if(m==1)///
		m=miyan(i);///
}



void ZHUCE()   ///����
{
	int i,n=UserShu,j=0;
	float m;///�������α���
	char User[32],mima1[32],mima2[32];///�������α���
	printf("�����������û���: ");///��� �����������û���
	getchar();
	scanf("%s",User);///�����û���
	for(i=0;i<n+1;i++)///��i=0��iС��n+1��i����
	{
		if(strcmp(User,YHM[i])==0)///ȷ���û����Ƿ����
		{
			printf("���û����Ѵ���\n");///������û��Ѵ���
			break;///����ѭ��
		}
		else///�����û���������
		{
			strcpy(YHM[UserShu],User);///���û�������
			while(j!=1)///whileѭ��
			{
				printf("��������������: ");///��� ��������������
				scanf("%s",mima1);///��������
				printf("���ٴ�������������: ");///��� ���ٴ���������
				scanf("%s",mima2);///�ٴ���������
				if(strcmp(mima1,mima2)==0)/// �Ƚ��������������
				{
					printf("�������óɹ�\n"); ///��� �������óɹ�
					printf("���������Ĵ��� ");///��� ���������Ĵ�����
					scanf("%f",&m);///��������
					printf("��ϲ���������ɹ�\n");///��� �����ɹ�
					strcpy(MIMA[UserShu],mima1);///��������������
					YuE[UserShu]=m;///��������
					j=1;///��1����j
				}
				else///����  ���벻ͬ
					printf("�������벻��ͬ,���������롣\n ");///��� �������벻��ͬ�����������롣
			}
			UserShu++;///ʹ����������
			break;///����ѭ��
		}
	}
}


void XIAOHU()///����
{
	int i,n,m;///�������α���
	i=mingyan();///��mingyan�����i
	m=guayan(i);///��guayan()��ֵ��m
	if(m==1)///��m����1ʱ
		m=miyan(i);///��miyan(i)��ֵ��m
	while(m==1)///m��1��ʼѭ��
	{
		printf("��ȷ��Ҫע�������˻���\n   <1>ȷ��    <2>ȡ��   \n");///��� ��ȷ��Ҫע�������˻���������� <1>ȷ��    <2>ȡ��
		scanf("%d",&n);///��������
		if(n==1)///��n����1ʱ
		{
			for(;i<UserShu;i++)///ѭ������С���û�����
			{
				strcpy(YHM[i],YHM[i+1]);///����һλ�û�����������û���
				strcpy(MIMA[i],MIMA[i+1]);///����һλ���븳���������
				YuE[i]=YuE[i+1];///����һλ����������������
			}
		}
	UserShu--;///ʹ�������Լ�
	printf("�����ɹ���\n");///��� �����ɹ�
	m=0;///��0�����m
	}
}

void ZHUANZHANG()///ת��
{
	int i,n,j,s=1;///�������α���
	float k;///�������α���
	char User[32];///�������α���
	i=mingyan();///��mingyan()��ֵ��i
	n=guayan(i);///��mingyan()��ֵ��i
	if(n==1)///��n����һʱ
		n=miyan(i);///��mingyan()��ֵ��m
	while(n==1)///n����1ʱѭ��
	{
		printf("������Ŀ���˻���");///��� ������Ŀ���˻�
		scanf("%s",User);///���� ʹ�����˺�
		for(j=0;j<UserShu;j++)///��jС��ʹ������ʱ��ѭ��
		{
			if(strcmp(YHM[j],User)==0)///��ʹ���������û�����ͬʱ
			{
				n=2;///��2��ֵ��n
				break;///����ѭ��
			}
		}
		if(j==UserShu)///��j����ʹ������ʱ
			printf("Ŀ���˻������ڣ����������롣\n");///��� Ŀ���˻������ڣ����������롣
        while(n==2)///��n=2ѭ��
        {
            printf("������ת�˽�");///��� ������ת�˽��
            scanf("%f",&k);///���� ת�˽��
            if(k<=YuE[i])///��ת�˽��С�ڵ��ڴ�����ʱ
            {
                YuE[i]=YuE[i]-k;///�����û�������ͱ��û�ת�˽��֮�������û�������
                YuE[j]=YuE[j]+k;///��ת���û��������ת���û�ת�˽��֮�͸����ת���û�������
                printf("ת�˳ɹ���\n���ĵ�ǰ���Ϊ�� %.2f\n",YuE[i]);///���ת�˳ɹ�������������ĵ�ǰ���Ϊ
                break;///����ѭ��
            }
            else///����ת�˽����ڵ��ڴ�����
                printf("���㣬���������롣\n");///��� ���㣬���������롣
        }
    }
}

void lose()///��ʧ
{
	int n,i,m;///�������α���n,i,m
	i=mingyan();///��mingyan()��ֵ��i
	m=guayan(i);///��guayan(i)��ֵ��m
	if(m==1)///��m����1ʱ
		m=miyan(i);///��mingyan()��ֵ��m
	if(m==1)///��m����1ʱ
	{
		printf("��ȷ��Ҫ��ʧ�����˻���\n   <1>ȷ��    <2>ȡ��   \n");///��� ��ȷ��Ҫ��ʧ�����˻��� �������<1>ȷ��    <2>ȡ��
		scanf("%d",&n);///���� ����
		if(n==1)///��n����1ʱ
		{
			strcpy(Ggua[guashu],YHM[i]);///�����˻����Ƶ���ʧ��
			guashu++;///��ʧ������
			printf("%s �˻���ʧ�ɹ���\n",YHM[i]);///��� �˻���ʧ�ɹ���
		}
	}
}

void chaall()///��ѯ�����û���Ϣ
{
	int i;///�������α���
	for(i=0;i<UserShu;i++)
		printf("�û���:%15s     ��%.2f\n",YHM[i],YuE[i]);
}

int mingyan()///�û�����֤
{
	int m=1,i;///�������α���
	char User[32];///�������α���
	while(m==1)///��m����1ʱѭ��
	{
		printf("�����������û���: ");///��� �����������û���
		scanf("%s",User);/// ���� ʹ������
		for(i=0;i<UserShu;i++)///��iС��ʹ������ʱ  i����
			if(strcmp(YHM[i],User)==0)///���ʹ���ߺ͸��˻���ͬ
			{
				m=0;///��0��ֵ��m
				break;///����ѭ��
			}
		if(i==UserShu)///��i����ʹ������ʱ

			printf("���û������ڣ���ȷ�Ϻ������롣 \n");///��� ���û������ڣ���ȷ�Ϻ������롣
	}
	return i;///����ֵ i
}

int guayan(int i)///��ʧ��֤
{
	int j,n;///�������α���
	for(j=0;j<guashu;j++)///
	{
		if(strcmp(YHM[i],Ggua[j])==0)///strcmp�Ƚ������ַ����Ƿ����
		{
			printf("���û��Ѿ���ʧ�����Һ��ٽ��в�����\n");///
			n=0;///��0��ֵ��n
			break;///����ѭ��
		}
	}
	if(j==guashu)///���j���ڹ�ʧ�û���
		n=1;///��1��ֵ��n
	return n;///����ֵΪn
}

int miyan(int i)///������֤
{
	char mima[32];///�����ַ��ͱ���mima\

	while(1)///
	{
		printf("��������������: ");///��� ��������������:
		scanf("%s",mima);///��������
		if(strcmp(MIMA[i],mima)==0)///strcmp�Ƚ������ַ����Ƿ����
        {
			printf("��½�ɹ���\n");
			printf("�û�����%s          �� %.2f \n",YHM[i],YuE[i]);///����û��������
			break;///����ѭ��
		}
		else///strcmp�Ƚ������ַ����Ƿ����
			printf("����������벻��ȷ�����������롣\n");///�������������벻��ȷ�����������롣
	}
	return 1;///����ֵΪ1
}
