#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#define L sizeof(struct adm)
#define E sizeof(struct student)
struct adm//����Ա�ṹ��
{
    char name[20];
    char pas[14];
    struct adm *next;
};
struct student//ѧ���ṹ��
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
/**************************Ư������************************************************************/

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
    printf("\t\t\t****          ��������             **********\n");
    printf("\t\t\t****          ѧ���ɼ�             **********\n");
    printf("\t\t\t*****         ����ϵͳ            ***********\n");
    printf("\t\t\t******         ��ȴ�            ************\n");
    printf("\t\t\t*******                         *************\n");
    printf("\t\t\t*********         ר������     **************\n");
    printf("\t\t\t***********          ��ѩͬѧ ***************\n");
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
    printf("\n");  //��ʼ����
    printf("\t\t   �بp�T�T���بp�T�T���بp�T�T���بp�T�T���بp�T�T��\n");
    printf("\t\t   ��                                               ��\n");
    printf("\t\t   ��                                               ��\n");
    printf("\t\t   ���X�m�T�T�[�X�T�T�T�T�[�X�T�T�T�T�[�X�T�T�T�T�[ ��\n");
    printf("\t\t   ���U��ӭ  �U�U   ʹ�� �U�U   ���� �U�U  ϵͳ  �U ��\n");
    printf("\t\t   ���^��T��a�^��T�T��a�^��T�T��a�^��T�T��a ��\n");
    printf("\t\t   ��                                               ��\n");
    printf("\t\t   ��                                               ��\n");
    printf("\t\t   ��\t       ѧ���ɼ�����ϵͳ                     ��\n");
    printf("\t\t   ��                                               ��\n");
    printf("\t\t   ��                                               ��\n");
    printf("\t\t   ��                                               ��\n");
    printf("\t\t   ��                                               ��\n");
    printf("\t\t   �بp�T�T���بp�T�T���بp�T�T���بp�T�T���بp�T�T��\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    system("pause");//����system���� ʵ���������ʼ
    system("cls");
}


/************************��½����**********************************************************/
int face1()//�����û���ѡ��
{
    int t;
    printf("\n\n\n\n\t\t\t1------------�û���¼\n");
    printf("\t\t\t2------------�û�ע��\n");
    printf("\t\t\t0------------�˳�ϵͳ\n");
    printf("\t\t\t");
    scanf("%d",&t);
    system("cls");
    return t;
}
void login()//ע�Ტд���ļ�
{
    struct adm a;
    int i;
    char c;
    FILE *fp;
    system("cls");
    printf("\n\n\n\t\t\t�������û�����");
    scanf("%s",a.name);
    getchar();
    printf("\n\n\n\t\t\t���������룺");
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
long f_len()//�����ļ�����
{
    long len,n,i;
    FILE *fp;
    if((fp=fopen("adm.txt","rb+"))==NULL)
    {
        printf("\n\n\n\t\t\t�ļ��޷��򿪣�����ע�ᣡ\n");
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
        printf("\n\n\n\t\t\t�ļ��޷��򿪣�����ע�ᣡ\n");
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
void adm_release(struct adm*p)//�ͷŹ���Ա�ռ�
{
    struct adm*q;
    long n,i;
    n=f_len();
    for(i=0; i<n; i++)
        free(p+i);
}
int load()//��½���棬��½�ɹ�����1
{
    int t,j;
    long i,n;
    char name[20],pas[20],c;
    FILE *fp;
    struct adm *p;
    n=f_len();
    printf("\n\n\n\t\t\t�������û�����");
    scanf("%s",name);
    getchar();
    printf("\n\n\n\t\t\t���������룺");
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
        printf("\n\n\n\t\t\t����ע�ᣡ\n");
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
        printf("\n\n\n\t\t\t�������\n");
        adm_release(p);
        return 0;
    }
}
int loading()//�������˵�
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
/********************�����********************************************************/
int face2()//��ʾ�����
{
    int t;
    system("cls");
    printf("\n\n\n\t\t\t1-------------ѧ��¼��\n");
    printf("\t\t\t2-------------ѧ�����\n");
    printf("\t\t\t3-------------ѧ����ѯ\n");
    printf("\t\t\t4-------------ѧ��ɾ��\n");
    printf("\t\t\t5-------------ѧ��ͳ��\n");
    printf("\t\t\t0-------------�˳�ϵͳ\n");
    printf("\t\t\t����������ѡ��");
    scanf("%d",&t);
    system("cls");
    return t;
}
/************************�����*************************************************************/
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
        printf("\t\t\t������ѧ��������");
        scanf("%s",a.name);
        printf("\t\t\t������ѧ��ѧ�ţ�");
        scanf("%s",a.ID);
        printf("\t\t\t������ѧ���Ա�");
        scanf("%s",a.sex);
        printf("\t\t\t������ѧ��Ӣ��ɼ���");
        scanf("%f",&a.english);
        printf("\t\t\t������ѧ��C��ɼ���");
        scanf("%f",&a.computer);
        a.sum=a.english+a.computer;
        a.average=a.sum/2.0;
        fseek(fp,0L,2);
        fwrite(&a,E,1,fp);
        system("cls");
        printf("\n\n\n\t\t\t��Ϣ�ѱ��棡\n");
        getchar();
        printf("\n\n\n\t\t\t�Ƿ��������\n\n\n\t\t\t(���������밴����������������밴N/n)\n");
        scanf("%c",&c);
        system("cls");
        if(c=='N'||c=='n')
            break;
    }
    fclose(fp);
}
long student_len()//ѧ������
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
struct student *student_read()//���ļ���ȡѧ����Ϣ
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
void student_release(struct student*p)//�ͷ�ѧ���ṹ��
{
    long n,i;
    n=student_len();
    for(i=0; i<n; i++)
        free(p+i);
}
void output()//ѧ����Ϣ���
{
    struct student *p;
    long n,i;
    p=student_read();
    n=student_len();
    if(n)
        printf("����      ѧ��      �Ա�      Ӣ��      C��      ƽ����     �ܷ�\n");
    else
        printf("\t\t\t��ʱû��ѧ����Ϣ��\n");
    for(i=0; i<n; i++)
    {
        printf("%-10s%-10s%-5s     %-5.1f     %-5.1f     %-5.1f      %-5.1f\n",(p+i)->name,(p+i)->ID,(p+i)->sex,(p+i)->english,(p+i)->computer,(p+i)->average,(p+i)->sum);
    }
    system("pause");
    if(n)
        student_release(p);
}
int face3()//������ѧ��
{
    int t;
    printf("\n\n\n\t\t\t1---------����������\n");
    printf("\t\t\t2---------��ѧ�Ų���\n");
    printf("\t\t\t����������ѡ��\n");
    scanf("%d",&t);
    system("pause");
    return t;
}
void search()//����ѧ�Ż���������
{
    int t=face3();
    struct student *p;
    char a[20];
    long n,i;
    system("cls");
    if(t==1)
    {
        printf("\t\t\t�����ѯѧ����������");
        scanf("%s",a);
    }
    else if(t==2)
    {
        printf("\t\t\t�����ѯѧ����ѧ�ţ�");
        scanf("%s",a);
    }
    else
    {
        printf("\t\t\t�������\n");
        return;
    }
    p=student_read();
    n=student_len();
    if(n==0)
    {
        printf("��ʱû��ѧ����Ϣ��\n");
        system("pause");
        return;
    }
    for(i=0; i<n; i++)
    {
        if(strcmp((p+i)->name,a)==0)
        {
            printf("����      ѧ��      �Ա�      Ӣ��      C��      ƽ����     �ܷ�\n");
            printf("%-10s%-10s%-5s     %-5.1f     %-5.1f     %-5.1f      %-5.1f\n",(p+i)->name,(p+i)->ID,(p+i)->sex,(p+i)->english,(p+i)->computer,(p+i)->average,(p+i)->sum);
            system("pause");
            break;
        }
        if(t==2&&strcmp((p+i)->ID,a)==0)
        {
            printf("����      ѧ��      �Ա�      Ӣ��      C��      ƽ����     �ܷ�\n");
            printf("%-10s%-10s%-5s     %-5.1f     %-5.1f     %-5.1f      %-5.1f\n",(p+i)->name,(p+i)->ID,(p+i)->sex,(p+i)->english,(p+i)->computer,(p+i)->average,(p+i)->sum);
            system("pause");
            break;
        }
    }
    if(i==n)
    {
        printf("\n\n\n\t\t\tû�д�ѧ������Ϣ��\n");
        system("pause");
    }
}
int face4()//��ѧ������ɾ��
{
    int t;
    printf("\t\t\t1----------������ɾ��\n");
    printf("\t\t\t2----------��ѧ��ɾ��\n");
    printf("\t\t\t����������ѡ��\n");
    scanf("%d",&t);
    system("cls");
    return t;
}
struct student *read_lianbiao()//��ȡѧ����Ϣ��������,����ͷָ��
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
void student_release1(struct student*p)//�ͷ�ѧ���ṹ��
{
    long n,i;
    n=student_len();
    for(i=0; i<n; i++)
    {
        free(p);
        p=p->next;
    }

}
void delete1()//ɾ��ѧ����Ϣ
{
    struct student *p,*head,*q;
    int t=face4();
    long n=student_len(),i;
    char a[20],c;
    FILE *fp;
    if(n==0)
    {
        printf("\t\t\t��ʱû��ѧ����Ϣ��\n");
        system("pause");
        return;
    }
    else if(t==1)
    {
        printf("\t\t\t��������ɾ��ѧ��������\n");
        scanf("%s",a);
    }
    else if(t==2)
    {
        printf("\t\t\t��������ɾ��ѧ����ѧ��\n");
        scanf("%s",a);
    }
    else
    {
        printf("\t\t\t�������\n");
        return;
    }
    head=p=q=read_lianbiao();
    for(i=0; i<n; i++)
    {
        if(t==1&&strcmp(p->name,a)==0)
        {
            printf("����      ѧ��      �Ա�      Ӣ��      C��      ƽ����     �ܷ�\n");
            printf("%-10s%-10s%-5s     %-5.1f     %-5.1f     %-5.1f      %-5.1f\n",p->name,p->ID,p->sex,p->english,p->computer,p->average,p->sum);
            getchar();
            printf("\t\t\tȷ��ɾ����ѧ������Ϣ��\n\n\n\t\t\t(ɾ���밴���������ɾ���밴N/n)\n");
            scanf("%c",&c);
            if(c!='N'&&c!='n')
            {
                if(i==0)
                    head=p->next;
                else
                    q->next=p->next;
                if((fp=fopen("student.txt","w+"))==NULL)
                {
                    printf("�ļ��򿪴���\n");
                    exit(0);
                }
                for(p=head;p;p=p->next)
                {
                    fwrite(p,E,1,fp);
                }
                //fwrite(p,E,n-1,fp);
                fclose(fp);
                printf("\n\n\n\t\t\t�ļ��ɹ�ɾ�������棡\n");
                system("pause");
                student_release1(head);
                return ;
            }
            else
                break;
        }
        if(t==2&&strcmp(p->ID,a)==0)
        {
            printf("����      ѧ��      �Ա�      Ӣ��      C��      ƽ����     �ܷ�\n");
            printf("%-10s%-10s%-5s     %-5.1f     %-5.1f     %-5.1f      %-5.1f\n",p->name,p->ID,p->sex,p->english,p->computer,p->average,p->sum);
            getchar();
            printf("\t\t\tȷ��ɾ����ѧ������Ϣ��\n\n\n\t\t\t\t(ɾ���밴���������ɾ���밴N/n)\n");
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
                    printf("�ļ��򿪴���\n");
                    exit(0);
                }
                for(p=head;p;p=p->next)
                {
                    fwrite(p,E,1,fp);
                }
                //fwrite(p,E,n-1,fp);
                fclose(fp);
                printf("\n\n\n\t\t\t�ļ��ɹ�ɾ�������棡\n");
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
            printf("\t\t\t������Ϣ����\n");
            system("pause");
            return ;
        }
    }

}
int face5()
{
    int t;
    printf("\t\t\t1------------���Ӣ��ɼ�\n");
    printf("\t\t\t2------------���C��ɼ�\n");
    printf("\t\t\t3------------���ܷ�����\n");
    printf("\t\t\t4------------��ƽ��������\n");
    printf("\t\t\t����������ѡ��\n");
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
                printf("\n\n\n\t\t\t�������\n");
        }
        system("pause");
        system("cls");
    }
    return 0;
}
