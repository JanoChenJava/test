#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>


int mingyan();      ///用户名验证
int guayan(int);    ///挂失验证
int miyan(int);     ///密码函数
float T=0;          /// 定义全局变量T,记录用户一天取款数的总和
void QUKUAN();      ///取款函数
void CUNKUAN();     ///存款函数
void CHAXUN();      ///查询所有用户信息函数
void XIAOHU();      ///销户函数
void ZHUCE();       ///开户函数
void ZHUANZHANG();  ///转账函数
void lose();        ///挂失函数
void chaall();      ///查询所有用户信息

char YHM[100][30];   ///用户名
char MIMA[100][30];  ///密码
char Ggua[100][30];	 ///挂失用户名

float YuE[100];      ///存款余额
int UserShu=0;       ///用户数
int guashu=0;        ///挂失用户数

int main()///主页面
{

	int ML;///定义整形变量ML

	while(ML) ///进入while循环
	{
	    printf("\n\n\t欢迎使用ATM取款机\n"); ///\t代表tab，四个空格
		printf("\t\t1.开户\t\t  4.取款\n");  ///\t代表tab，四个空格
		printf("\t\t2.存款\t\t  5.销户\n");  ///\t代表tab，四个空格
		printf("\t\t3.查询\t\t  6.转账\n");  ///\t代表tab，四个空格
		printf("\t\t7.账户信息\t  8.挂失\n");///\t代表tab，四个空格
		printf("\t\t0.退出\n");
		scanf("%d",&ML);///输入一个数字，&是取地址符
		printf("\n");///输出\n，空一行
		switch(ML)///进行switch选择语句
		{
		case 1:ZHUCE();break;  ///当ML为1时,调用注册子函数
		case 2:CUNKUAN();break;///当ML为2时,调用注存款子函数
		case 3:CHAXUN();break; ///当ML为3时,调用查询子函数
		case 4:QUKUAN();break; ///当ML为4时,调用取款子函数
		case 5:XIAOHU();break; ///当ML为5时,调用销户子函数
		case 6:ZHUANZHANG();break;///当ML为6时,调用转账子函数
        case 7:chaall();break; ///当ML为7时,调用查询子函数
		case 8:lose();break;   ///当ML为8时,调用挂失子函数
        case 0:                ///当ML为0时，进行以下语句
			 printf("欢迎您再次使用！\n");
			 exit(0);///通常是用在子程序中用来终结程序，使用后程序自动结束，跳回操作系统
			 break;   ///跳出switch函数
		}
	}


}

void QUKUAN()///取款
{
	int i,m;      ///定义整形变量i,m
	float n;      ///定义浮点形变量n
	i=mingyan();  ///把mingyan()赋值给i
	m=guayan(i);  ///把guayan()赋值给m
	if(m==1)///如果m=1，进行以下语句
		m=miyan(i);///把mingyan()赋值给m
	while(m==1)
	{
		printf("请输入您的取款金额: ");
		scanf("%f",&n);///输入一个字符，&是取地址符
		if(n>2000)///如果n>2000时
		{
			printf("每笔取款不得超过2000\n");
			QUKUAN();///调用取款子函数
				break;///跳出while函数


		}
		T+=n;///相当于T=T+n
		if(T>50000)///当T大于50000时，进行以下语句
		{
			printf("每天取款总数不能超过50000，");
			break;///跳出while函数
		}
		if(n<=YuE[i])///当n小于等于余额时
		{
			printf("请取走您的钞票。\n");
			YuE[i]-=n;///相当于YuE[i]=YuE[i]-n
			break;///跳出while函数
		}
		else///当n大于余额时，进行以下语句
			printf("您的余额不足，请重新输入。\n");
	}
}

void CUNKUAN()///存款
{
	int i,m;///定义整形变量
	float n;///定义整形变量
	i=mingyan();///把mingyan()赋值给i
	m=guayan(i);///把guayan()赋值给m
		m=miyan(i);///把///把guayan()赋值给m赋值给m
	while(m==1)///当m=时1
	{
		printf("请输入您的存款金额: ");///输出 请输入你的存款金额
		scanf("%f",&n);///输入一个数字，&是取地址符
		YuE[i]=YuE[i]+n;///将余额与存款金额之和赋予给余额
		printf("存款成功！");///输出 存款成功
		printf("您的当前余额为: %.2f\n",YuE[i]);///输出 您的当前余额
		m=0;///将0赋值给m
	}
}
void CHAXUN()///查询
{
	int i,m;///定义整形变量
	i=mingyan();///
	m=guayan(i);///
	if(m==1)///
		m=miyan(i);///
}



void ZHUCE()   ///开户
{
	int i,n=UserShu,j=0;
	float m;///定义整形变量
	char User[32],mima1[32],mima2[32];///定义整形变量
	printf("请输入您的用户名: ");///输出 请输入您的用户名
	getchar();
	scanf("%s",User);///输入用户名
	for(i=0;i<n+1;i++)///当i=0，i小于n+1，i自增
	{
		if(strcmp(User,YHM[i])==0)///确定用户名是否存在
		{
			printf("该用户名已存在\n");///输出该用户已存在
			break;///结束循环
		}
		else///否则用户名不存在
		{
			strcpy(YHM[UserShu],User);///将用户名存入
			while(j!=1)///while循环
			{
				printf("请输入您的密码: ");///输出 请输入您的密码
				scanf("%s",mima1);///输入密码
				printf("请再次输入您的密码: ");///输出 请再次输入密码
				scanf("%s",mima2);///再次输入密码
				if(strcmp(mima1,mima2)==0)/// 比较两次输入的密码
				{
					printf("密码设置成功\n"); ///输出 密码设置成功
					printf("请输入您的存款金额： ");///输出 请输入您的存款余额
					scanf("%f",&m);///输入存款金额
					printf("恭喜您，开户成功\n");///输出 开户成功
					strcpy(MIMA[UserShu],mima1);///将密码放入密码库
					YuE[UserShu]=m;///将余额存入
					j=1;///将1赋予j
				}
				else///否则  密码不同
					printf("两次输入不相同,请重新输入。\n ");///输出 两次输入不相同，请重新输入。
			}
			UserShu++;///使用者数自增
			break;///结束循环
		}
	}
}


void XIAOHU()///销户
{
	int i,n,m;///定义整形变量
	i=mingyan();///将mingyan赋予给i
	m=guayan(i);///把guayan()赋值给m
	if(m==1)///当m等于1时
		m=miyan(i);///把miyan(i)赋值给m
	while(m==1)///m从1开始循环
	{
		printf("您确定要注销您的账户？\n   <1>确认    <2>取消   \n");///输出 您确定要注销您的账户？换行输出 <1>确认    <2>取消
		scanf("%d",&n);///输入数字
		if(n==1)///当n等于1时
		{
			for(;i<UserShu;i++)///循环次数小于用户者数
			{
				strcpy(YHM[i],YHM[i+1]);///将后一位用户名赋予给本用户名
				strcpy(MIMA[i],MIMA[i+1]);///将后一位密码赋予给本密码
				YuE[i]=YuE[i+1];///将后一位存款余额赋予给本存款余额
			}
		}
	UserShu--;///使用者数自减
	printf("销户成功！\n");///输出 销户成功
	m=0;///将0赋予给m
	}
}

void ZHUANZHANG()///转账
{
	int i,n,j,s=1;///定义整形变量
	float k;///定义整形变量
	char User[32];///定义整形变量
	i=mingyan();///把mingyan()赋值给i
	n=guayan(i);///把mingyan()赋值给i
	if(n==1)///当n等于一时
		n=miyan(i);///把mingyan()赋值给m
	while(n==1)///n等于1时循环
	{
		printf("请输入目标账户：");///输出 请输入目标账户
		scanf("%s",User);///输入 使用者账号
		for(j=0;j<UserShu;j++)///当j小于使用者数时，循环
		{
			if(strcmp(YHM[j],User)==0)///当使用者名和用户名相同时
			{
				n=2;///将2赋值给n
				break;///结束循环
			}
		}
		if(j==UserShu)///当j等于使用者数时
			printf("目标账户不存在，请重新输入。\n");///输出 目标账户不存在，请重新输入。
        while(n==2)///当n=2循环
        {
            printf("请输入转账金额：");///输出 请输入转账金额
            scanf("%f",&k);///输入 转账金额
            if(k<=YuE[i])///当转账金额小于等于存款余额时
            {
                YuE[i]=YuE[i]-k;///将本用户存款余额和本用户转账金额之差赋予给本用户存款余额
                YuE[j]=YuE[j]+k;///将转账用户存款余额和转账用户转账金额之和赋予给转账用户存款余额
                printf("转账成功！\n您的当前余额为： %.2f\n",YuE[i]);///输出转账成功！换行输出您的当前余额为
                break;///结束循环
            }
            else///否则当转账金额大于等于存款余额
                printf("余额不足，请重新输入。\n");///输出 余额不足，请重新输入。
        }
    }
}

void lose()///挂失
{
	int n,i,m;///定义整形变量n,i,m
	i=mingyan();///把mingyan()赋值给i
	m=guayan(i);///把guayan(i)赋值给m
	if(m==1)///当m等于1时
		m=miyan(i);///把mingyan()赋值给m
	if(m==1)///当m等于1时
	{
		printf("您确定要挂失您的账户？\n   <1>确认    <2>取消   \n");///输出 您确定要挂失您的账户？ 换行输出<1>确认    <2>取消
		scanf("%d",&n);///输入 数字
		if(n==1)///当n等于1时
		{
			strcpy(Ggua[guashu],YHM[i]);///将本账户复制到挂失库
			guashu++;///挂失数自增
			printf("%s 账户挂失成功！\n",YHM[i]);///输出 账户挂失成功！
		}
	}
}

void chaall()///查询所有用户信息
{
	int i;///定义整形变量
	for(i=0;i<UserShu;i++)
		printf("用户名:%15s     余额：%.2f\n",YHM[i],YuE[i]);
}

int mingyan()///用户名验证
{
	int m=1,i;///定义整形变量
	char User[32];///定义整形变量
	while(m==1)///当m等于1时循环
	{
		printf("请输入您的用户名: ");///输出 请输入您的用户名
		scanf("%s",User);/// 输入 使用者名
		for(i=0;i<UserShu;i++)///当i小于使用者数时  i自增
			if(strcmp(YHM[i],User)==0)///如果使用者和该账户相同
			{
				m=0;///将0赋值给m
				break;///结束循环
			}
		if(i==UserShu)///当i等于使用者数时

			printf("该用户不存在，请确认后再输入。 \n");///输出 该用户不存在，请确认后再输入。
	}
	return i;///返回值 i
}

int guayan(int i)///挂失验证
{
	int j,n;///定义整形变量
	for(j=0;j<guashu;j++)///
	{
		if(strcmp(YHM[i],Ggua[j])==0)///strcmp比较两个字符串是否相等
		{
			printf("此用户已经挂失，请解挂后再进行操作！\n");///
			n=0;///将0赋值于n
			break;///结束循环
		}
	}
	if(j==guashu)///如果j等于挂失用户数
		n=1;///将1赋值于n
	return n;///返回值为n
}

int miyan(int i)///密码验证
{
	char mima[32];///定义字符型变量mima\

	while(1)///
	{
		printf("请输入您的密码: ");///输出 请输入您的密码:
		scanf("%s",mima);///输入密码
		if(strcmp(MIMA[i],mima)==0)///strcmp比较两个字符串是否相等
        {
			printf("登陆成功！\n");
			printf("用户名：%s          余额： %.2f \n",YHM[i],YuE[i]);///输出用户名和余额
			break;///结束循环
		}
		else///strcmp比较两个字符串是否相等
			printf("您输入的密码不正确，请重新输入。\n");///输出您输入的密码不正确，请重新输入。
	}
	return 1;///返回值为1
}
