#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#define L sizeof(struct adm)
#define E sizeof(struct student)
struct adm//管理员结构体
{
    char name[20];
    char pas[14];
    struct adm *next;
};
struct student//学生结构体
{
    char ID[20];
    char name[25];
    char sex[5];
    float english;
    float computer;
    float average;
    float sum;
    struct student *next;
};
/**************************漂亮界面************************************************************/

void face6()
{
    int i,l;
    system("cls");
    system("color 9");
    printf("\t\t\t*********************************************\n");
    printf("\t\t\t*********************************************\n");
    printf("\t\t\t*******       ********        ***************\n");
    printf("\t\t\t*****          *****            *************\n");
    printf("\t\t\t****            ***               ***********\n");
    printf("\t\t\t****             *                 **********\n");
    printf("\t\t\t****          正在启动             **********\n");
    printf("\t\t\t****          学生成绩             **********\n");
    printf("\t\t\t*****         管理系统            ***********\n");
    printf("\t\t\t******         请等待            ************\n");
    printf("\t\t\t*******                         *************\n");
    printf("\t\t\t*********         专属制作     **************\n");
    printf("\t\t\t***********          王雪同学 ***************\n");
    printf("\t\t\t*************               *****************\n");
    printf("\t\t\t***************           *******************\n");
    printf("\t\t\t*****************       *********************\n");
    printf("\t\t\t******************    ***********************\n");
    printf("\t\t\t******************* *************************\n");
    printf("\t\t\t");
    for(i=0; i<45; i++)
    {
        for(l=0; l<30000000; l++);
        printf(">");
    }
    printf("\n");
    printf("\n");
    system("cls");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");  //开始界面
    printf("\t\t   ∝╬══→∝╬══→∝╬══→∝╬══→∝╬══→\n");
    printf("\t\t   ◆                                               ◆\n");
    printf("\t\t   ◆                                               ◆\n");
    printf("\t\t   ◆╔╩══╗╔════╗╔════╗╔════╗ ◆\n");
    printf("\t\t   ◆║欢迎  ║║   使用 ║║   管理 ║║  系统  ║ ◆\n");
    printf("\t\t   ◆╚◎═◎╝╚◎══◎╝╚◎══◎╝╚◎══◎╝ ◆\n");
    printf("\t\t   ◆                                               ◆\n");
    printf("\t\t   ◆                                               ◆\n");
    printf("\t\t   ◆\t       学生成绩管理系统                     ◆\n");
    printf("\t\t   ◆                                               ◆\n");
    printf("\t\t   ◆                                               ◆\n");
    printf("\t\t   ◆                                               ◆\n");
    printf("\t\t   ◆                                               ◆\n");
    printf("\t\t   ∝╬══→∝╬══→∝╬══→∝╬══→∝╬══→\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    system("pause");//利用system函数 实现任意键开始
    system("cls");
}


/************************登陆界面**********************************************************/
int face1()//返回用户的选择
{
    int t;
    printf("\n\n\n\n\t\t\t1------------用户登录\n");
    printf("\t\t\t2------------用户注册\n");
    printf("\t\t\t0------------退出系统\n");
    printf("\t\t\t");
    scanf("%d",&t);
    system("cls");
    return t;
}
void login()//注册并写入文件
{
    struct adm a;
    int i;
    char c;
    FILE *fp;
    system("cls");
    printf("\n\n\n\t\t\t请输入用户名：");
    scanf("%s",a.name);
    getchar();
    printf("\n\n\n\t\t\t请输入密码：");
    for(i=0; i<13; i++)
    {
        c=getch();
        if(c==13)
            break;
        else if(c==8)
        {
            printf("\b \b");
        }
        else
        {
            printf("*");
            a.pas[i]=c;
        }

    }
    a.pas[i]='\0';
    if((fp=fopen("adm.txt","ab+"))==NULL)
    {
        fp=fopen("adm.txt","wb+");
    }
    fseek(fp,0L,2);
    fwrite(&a,L,1,fp);
    fclose(fp);

}
long f_len()//计算文件长度
{
    long len,n,i;
    FILE *fp;
    if((fp=fopen("adm.txt","rb+"))==NULL)
    {
        printf("\n\n\n\t\t\t文件无法打开！请先注册！\n");
        fp=fopen("adm.txt","w+");
        fclose(fp);
        return 0;
    }
    fseek(fp,0L,2);
    len=ftell(fp);
    n=len/L;
    return n;
}
struct adm *adm_read()
{
    FILE *fp;
    struct adm *p;
    long n,i;
    if((fp=fopen("adm.txt","rb+"))==NULL)
    {
        printf("\n\n\n\t\t\t文件无法打开！请先注册！\n");
        fp=fopen("adm.txt","w+");
        fclose(fp);
        return 0;
    }
    n=f_len();
    p=(struct adm*)malloc(L*n);
    for(i=0; i<n; i++)
    {
        fread(p+i,L,1,fp);
    }
    fclose(fp);
    return p;
}
void adm_release(struct adm*p)//释放管理员空间
{
    struct adm*q;
    long n,i;
    n=f_len();
    for(i=0; i<n; i++)
        free(p+i);
}
int load()//登陆界面，登陆成功返回1
{
    int t,j;
    long i,n;
    char name[20],pas[20],c;
    FILE *fp;
    struct adm *p;
    n=f_len();
    printf("\n\n\n\t\t\t请输入用户名：");
    scanf("%s",name);
    getchar();
    printf("\n\n\n\t\t\t请输入密码：");
    for(j=0; j<13; j++)
    {
        c=getch();
        if(c==13)
            break;
        else if(c==8)
        {
            printf("\b \b");
        }
        else
        {
            printf("*");
            pas[j]=c;
        }

    }
    pas[j]='\0';
    p=adm_read();
    if(n==0)
    {
        printf("\n\n\n\t\t\t请先注册！\n");
        return 0;
    }
    for(i=0; i<n; i++)
    {
        if(strcmp(name,(p+i)->name)==0&&strcmp(pas,(p+i)->pas)==0)
        {
            adm_release(p);
            return 1;
        }
    }
    if(i==n)
    {
        printf("\n\n\n\t\t\t输入错误！\n");
        adm_release(p);
        return 0;
    }
}
int loading()//进入主菜单
{
    int t,k;
    t=face1();
    if(t==2)
    {
        login();
        return 1;
    }
    if(t==1)
    {
        k=load();
        if(k==0)
        {
            return 0;
        }
        else
        {
            face6();
            return 1;
        }

    }
    if(t==0)
        exit(0);
}
/********************大界面********************************************************/
int face2()//显示大界面
{
    int t;
    system("cls");
    printf("\n\n\n\t\t\t1-------------学生录入\n");
    printf("\t\t\t2-------------学生浏览\n");
    printf("\t\t\t3-------------学生查询\n");
    printf("\t\t\t4-------------学生删除\n");
    printf("\t\t\t5-------------学生统计\n");
    printf("\t\t\t0-------------退出系统\n");
    printf("\t\t\t请输入您的选择：");
    scanf("%d",&t);
    system("cls");
    return t;
}
/************************大程序*************************************************************/
void input()
{
    struct student a;
    FILE *fp;
    char c;
    if((fp=fopen("student.txt","ab+"))==NULL)
    {
        fp=fopen("student.txt","wb+");
    }
    while(1)
    {
        printf("\t\t\t请输入学生姓名：");
        scanf("%s",a.name);
        printf("\t\t\t请输入学生学号：");
        scanf("%s",a.ID);
        printf("\t\t\t请输入学生性别：");
        scanf("%s",a.sex);
        printf("\t\t\t请输入学生英语成绩：");
        scanf("%f",&a.english);
        printf("\t\t\t请输入学生C语成绩：");
        scanf("%f",&a.computer);
        a.sum=a.english+a.computer;
        a.average=a.sum/2.0;
        fseek(fp,0L,2);
        fwrite(&a,E,1,fp);
        system("cls");
        printf("\n\n\n\t\t\t信息已保存！\n");
        getchar();
        printf("\n\n\n\t\t\t是否继续输入\n\n\n\t\t\t(继续输入请按任意键，不在输入请按N/n)\n");
        scanf("%c",&c);
        system("cls");
        if(c=='N'||c=='n')
            break;
    }
    fclose(fp);
}
long student_len()//学生个数
{
    long n,i,len;
    FILE *fp;
    if((fp=fopen("student.txt","rb+"))==NULL)
    {
        fp=fopen("student.txt","wb+");
        fclose(fp);
        return 0;
    }
    fseek(fp,0L,2);
    len=ftell(fp);
    n=len/E;
    return n;
}
struct student *student_read()//从文件读取学生信息
{
    struct student *p;
    FILE *fp;
    long n,i;
    if((fp=fopen("student.txt","rb+"))==NULL)
    {
        fp=fopen("student.txt","wb+");
        fclose(fp);
        return NULL;
    }
    n=student_len();
    p=(struct student *)malloc(E*n);
    fread(p,E,n,fp);
    return p;

}
void student_release(struct student*p)//释放学生结构体
{
    long n,i;
    n=student_len();
    for(i=0; i<n; i++)
        free(p+i);
}
void output()//学生信息浏览
{
    struct student *p;
    long n,i;
    p=student_read();
    n=student_len();
    if(n)
        printf("姓名      学号      性别      英语      C语      平均分     总分\n");
    else
        printf("\t\t\t此时没有学生信息！\n");
    for(i=0; i<n; i++)
    {
        printf("%-10s%-10s%-5s     %-5.1f     %-5.1f     %-5.1f      %-5.1f\n",(p+i)->name,(p+i)->ID,(p+i)->sex,(p+i)->english,(p+i)->computer,(p+i)->average,(p+i)->sum);
    }
    system("pause");
    if(n)
        student_release(p);
}
int face3()//按姓名学号
{
    int t;
    printf("\n\n\n\t\t\t1---------按姓名查找\n");
    printf("\t\t\t2---------按学号查找\n");
    printf("\t\t\t请输入您的选择\n");
    scanf("%d",&t);
    system("pause");
    return t;
}
void search()//按照学号或姓名查找
{
    int t=face3();
    struct student *p;
    char a[20];
    long n,i;
    system("cls");
    if(t==1)
    {
        printf("\t\t\t输入查询学生的姓名：");
        scanf("%s",a);
    }
    else if(t==2)
    {
        printf("\t\t\t输入查询学生的学号：");
        scanf("%s",a);
    }
    else
    {
        printf("\t\t\t输入错误！\n");
        return;
    }
    p=student_read();
    n=student_len();
    if(n==0)
    {
        printf("此时没有学生信息！\n");
        system("pause");
        return;
    }
    for(i=0; i<n; i++)
    {
        if(strcmp((p+i)->name,a)==0)
        {
            printf("姓名      学号      性别      英语      C语      平均分     总分\n");
            printf("%-10s%-10s%-5s     %-5.1f     %-5.1f     %-5.1f      %-5.1f\n",(p+i)->name,(p+i)->ID,(p+i)->sex,(p+i)->english,(p+i)->computer,(p+i)->average,(p+i)->sum);
            system("pause");
            break;
        }
        if(t==2&&strcmp((p+i)->ID,a)==0)
        {
            printf("姓名      学号      性别      英语      C语      平均分     总分\n");
            printf("%-10s%-10s%-5s     %-5.1f     %-5.1f     %-5.1f      %-5.1f\n",(p+i)->name,(p+i)->ID,(p+i)->sex,(p+i)->english,(p+i)->computer,(p+i)->average,(p+i)->sum);
            system("pause");
            break;
        }
    }
    if(i==n)
    {
        printf("\n\n\n\t\t\t没有此学生的信息！\n");
        system("pause");
    }
}
int face4()//按学号姓名删除
{
    int t;
    printf("\t\t\t1----------按姓名删除\n");
    printf("\t\t\t2----------按学号删除\n");
    printf("\t\t\t请输入您的选择\n");
    scanf("%d",&t);
    system("cls");
    return t;
}
struct student *read_lianbiao()//读取学生信息放在链表,返回头指针
{
    FILE *fp;
    struct student *p,*q,*head;
    long n,i;
    n=student_len();
    if(n==0)
        return NULL;
    else
    {
        fp=fopen("student.txt","rb+");
        for(i=0; i<n; i++)
        {
            p=(struct student*)malloc(E);
            fread(p,E,1,fp);
            if(i==0)
            {
                head=p;
                q=p;
            }
            else
            {
                q->next=p;
                q=p;
            }
        }
        q->next=NULL;
        return head;
    }
}
void student_release1(struct student*p)//释放学生结构体
{
    long n,i;
    n=student_len();
    for(i=0; i<n; i++)
    {
        free(p);
        p=p->next;
    }

}
void delete1()//删除学生信息
{
    struct student *p,*head,*q;
    int t=face4();
    long n=student_len(),i;
    char a[20],c;
    FILE *fp;
    if(n==0)
    {
        printf("\t\t\t此时没有学生信息！\n");
        system("pause");
        return;
    }
    else if(t==1)
    {
        printf("\t\t\t请输入所删除学生的姓名\n");
        scanf("%s",a);
    }
    else if(t==2)
    {
        printf("\t\t\t请输入所删除学生的学号\n");
        scanf("%s",a);
    }
    else
    {
        printf("\t\t\t输入错误！\n");
        return;
    }
    head=p=q=read_lianbiao();
    for(i=0; i<n; i++)
    {
        if(t==1&&strcmp(p->name,a)==0)
        {
            printf("姓名      学号      性别      英语      C语      平均分     总分\n");
            printf("%-10s%-10s%-5s     %-5.1f     %-5.1f     %-5.1f      %-5.1f\n",p->name,p->ID,p->sex,p->english,p->computer,p->average,p->sum);
            getchar();
            printf("\t\t\t确定删除此学生的信息吗\n\n\n\t\t\t(删除请按任意键，不删除请按N/n)\n");
            scanf("%c",&c);
            if(c!='N'&&c!='n')
            {
                if(i==0)
                    head=p->next;
                else
                    q->next=p->next;
                if((fp=fopen("student.txt","w+"))==NULL)
                {
                    printf("文件打开错误！\n");
                    exit(0);
                }
                for(p=head;p;p=p->next)
                {
                    fwrite(p,E,1,fp);
                }
                //fwrite(p,E,n-1,fp);
                fclose(fp);
                printf("\n\n\n\t\t\t文件成功删除并保存！\n");
                system("pause");
                student_release1(head);
                return ;
            }
            else
                break;
        }
        if(t==2&&strcmp(p->ID,a)==0)
        {
            printf("姓名      学号      性别      英语      C语      平均分     总分\n");
            printf("%-10s%-10s%-5s     %-5.1f     %-5.1f     %-5.1f      %-5.1f\n",p->name,p->ID,p->sex,p->english,p->computer,p->average,p->sum);
            getchar();
            printf("\t\t\t确定删除此学生的信息吗\n\n\n\t\t\t\t(删除请按任意键，不删除请按N/n)\n");
            scanf("%c",&c);
            if(c!='N'&&c!='n')
            {
                if(i==0)
                {
                    head=p->next;
                }
                else
                    q->next=p->next;
                //p=head;
                if((fp=fopen("student.txt","wb+"))==NULL)
                {
                    printf("文件打开错误！\n");
                    exit(0);
                }
                for(p=head;p;p=p->next)
                {
                    fwrite(p,E,1,fp);
                }
                //fwrite(p,E,n-1,fp);
                fclose(fp);
                printf("\n\n\n\t\t\t文件成功删除并保存！\n");
                system("pause");
                student_release1(head);
                return ;
            }
            else
                break;
        }
        q=p;
        p=p->next;
        if(i==n-1)
        {
            printf("\t\t\t输入信息有误！\n");
            system("pause");
            return ;
        }
    }

}
int face5()
{
    int t;
    printf("\t\t\t1------------浏览英语成绩\n");
    printf("\t\t\t2------------浏览C语成绩\n");
    printf("\t\t\t3------------按总分排序\n");
    printf("\t\t\t4------------按平均分排序\n");
    printf("\t\t\t请输入您的选择\n");
    scanf("%d",&t);
    return t;
}
int sort(float x,float y)
{
    if(x<y)
        return 1;
    else
        return 0;
}
void scan_english(struct student *head,long n)
{
    struct student *p,m;
    p=head;
    long i,k,j;
    for(i=0;i<n-1;i++)
    {
        k=i;
        for(j=i+1;j<n;j++)
        {
            if(sort((p+k)->english,(p+j)->english))
            {
                m=*(p+k);
                *(p+k)=*(p+j);
                *(p+j)=m;
            }
        }
    }
}
void scan_computer(struct student *head,long n)
{
    struct student *p,m;
    p=head;
    long i,k,j;
    for(i=0;i<n-1;i++)
    {
        k=i;
        for(j=i+1;j<n;j++)
        {
            if(sort((p+k)->computer,(p+j)->computer))
            {
                m=*(p+k);
                *(p+k)=*(p+j);
                *(p+j)=m;
            }
        }
    }
}
void scan_sum(struct student *head,long n)
{
    struct student *p,m;
    p=head;
    long i,k,j;
    for(i=0;i<n-1;i++)
    {
        k=i;
        for(j=i+1;j<n;j++)
        {
            if(sort((p+k)->sum,(p+j)->sum))
            {
                m=*(p+k);
                *(p+k)=*(p+j);
                *(p+j)=m;
            }
        }
    }
}
void scan_average(struct student *head,long n)
{
    struct student *p,m;
    p=head;
    long i,k,j;
    for(i=0;i<n-1;i++)
    {
        k=i;
        for(j=i+1;j<n;j++)
        {
            if(sort((p+k)->average,(p+j)->average))
            {
                m=*(p+k);
                *(p+k)=*(p+j);
                *(p+j)=m;
            }
        }
    }
}
void calculate()
{
    int t;
    long i,n=student_len();
    struct student *head,*p;
    t=face5();
    head=student_read();
    if(t==1)
        scan_english(head,n);
    if(t==2)
        scan_computer(head,n);
    if(t==3)
        scan_sum(head,n);
    if(t==4)
        scan_average(head,n);
    if(t==1||t==2||t==3||t==4)
    {
        p=head;
        for(i=0; i<n; i++)
            printf("%-10s%-10s%-5s     %-5.1f     %-5.1f     %-5.1f      %-5.1f\n",(p+i)->name,(p+i)->ID,(p+i)->sex,(p+i)->english,(p+i)->computer,(p+i)->average,(p+i)->sum);
        system("pause");
    }

}
main()
{
    int t,k;
    while(1)
    {
        t=loading();
        while(t==1)
        {
            //face6();
            k=face2();
            if(k==0)
                exit(0);
            else if(k==1)
                input();
            else if(k==2)
                output();
            else if(k==3)
                search();
            else if(k==4)
                delete1();
            else  if(k==5)
                calculate();
            else
                printf("\n\n\n\t\t\t输入错误！\n");
        }
        system("pause");
        system("cls");
    }
    return 0;
}
