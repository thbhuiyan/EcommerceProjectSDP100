#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
#include<stdio.h>
//FILES for BABY category///
#define BBCLfile  "myDfile.bin"   //for baby clothing
#define BBFDfile "BFDfile.bin"//for baby food
#define BBTSfile "myBTSfile.bin"//for baby toys

//FILES for Men category///
#define MCLfile "MCLfile.bin"   //for men clothing
#define MFDfile "MFDfile.bin"//for men food
#define MEQfile "MEQfile.bin"//for men equipments

//FILES for tech category///
#define TMBfile  "TMBile.bin"   //for mobile
#define TACfile "TACfile.bin"//for accessories
#define TCMPfile "TCMPfile.bin"//for computer

//FILES for USER and ADMIN login
#define ULfile  "myULfile.bin"
#define ALfile  "myALfile.bin"

int choice,count;
struct user
{
    char username[40];
    char name[40];
    char contact[20];
    char mail[40];
    char password[20];
} userInfo;

struct admin
{
    char username[40];
    char name[40];
    char contact[20];
    char mail[40];
    char password[20];
}  adminInfo;

struct BabyProducts
{
    int bprice;
    int bserial;
    char bname[40];
} BBCL,BBTS,BBFD;

struct MenProducts
{
    int mprice;
    int mserial;
    char mname[40];
} MCL,MFD,MEQP;
struct TechProducts
{
    int tprice;
    int tserial;
    char tname[40];
} TMBL,TACS,TPC;

//void welcome();
int LoginSystem();
int USER();
int userLogin();
int userReg();
int userForgot();

int ADMIN();
int adminLogin();
int adminReg();
int adminForgot();

void KidsnMom();
void Bclothing();
void Btoys();
void ABtoys();
void Bfood();

void add_baby_clothing();
void add_baby_food();
void add_baby_toys();

void delete_baby_clothing();
void delete_baby_food();
void delete_baby_toys();

void SeeProducts();

void Mens();
void Mclothing();
void Mequipments();
void Mfood();

void Tech();
void TechAccessories ();
void TechComputers();

void Cart();

void KidsnMom()
{
    int n;
    printf("\t\t\t1. Baby clothing\n");
    printf("\t\t\t2. Babies toys/learning materials\n");
    printf("\t\t\t3. Baby food.\n");
    printf("\t\t\t4. Want to go back to previous panel!!!\n");
    printf("\n\t\t\tEnter your choice \n\t\t\t=>");
    scanf("%d",&n);
    switch(n)
    {
    case 1:
        Bclothing();
        break;
    case 2:
        Btoys();
        break;
    case 3:
        Bfood();
        break;
    case 4:
        KidsnMom();
        break;
    default:
        printf("\t\tWrong option selected. Try again !!!");
        KidsnMom();
        break;
    }
    Cart();
}
void Bclothing()
{
    FILE *fptr;
    system("cls");
    fptr=fopen(BBCLfile,"rb+");
    if(fptr==NULL)
    {
        printf("\t\tFile not created!!!\n");
    }
    else
    {
        printf("\t\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\n");
        printf("\t\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1 BABY CLOTHING \xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\n ");
        printf("\t\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\n");
        while(fread(&BBCL,sizeof(BBCL),1,fptr))
        {
            getchar();
            printf("\n\t\t Reading from baby clothing !!! \n");
            printf("\n\t\t\t product serial no. : %d",BBCL.bserial);
            printf("\n\t\t\t product name       : %s",BBCL.bname);
            printf("\n\t\t\t product price      : %d",BBCL.bprice);
        }
    }
    fclose(fptr);
    printf("\n\t\t\tEnter what kids product you want to purchase: \n");
    Cart();
    getchar();
    getchar();
}
void Btoys()
{
    FILE *fptr;
    system("cls");
    fptr=fopen(BBTSfile,"rb+");
    if(fptr==NULL)
    {
        printf("\t\tFile not created!!!\n");
    }
    else
    {
        printf("\t\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\n");
        printf("\t\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1 BABY TOYS \xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\n ");
        printf("\t\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\n");
        while(fread(&BBTS,sizeof(BBTS),1,fptr))
        {
            getchar();
            printf("\n\t\t Reading from baby toys !!! \n");
            printf("\n\t\t\t product serial no. : %d",BBTS.bserial);
            printf("\n\t\t\t product name       : %s",BBTS.bname);
            printf("\n\t\t\t product price      : %d",BBTS.bprice);
        }
    }
    fclose(fptr);
    printf("\n\t\t\tEnter what kids product you want to purchase: \n");
    Cart();
    getchar();
    getchar();
}
void Bfood()
{
    FILE *fptr;
    system("cls");
    fptr=fopen(BBFDfile,"rb+");
    if(fptr==NULL)
    {
        printf("\t\tFile not created!!!\n");
    }
    else
    {
        printf("\t\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\n");
        printf("\t\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1 BABY FOOD \xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\n ");
        printf("\t\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\n");
        while(fread(&BBFD,sizeof(BBFD),1,fptr))
        {
            getchar();
            printf("\n\t\t Reading from baby toys !!! \n");
            printf("\n\t\t\t product serial no. : %d",BBFD.bserial);
            printf("\n\t\t\t product name       : %s",BBFD.bname);
            printf("\n\t\t\t product price      : %d",BBFD.bprice);
        }
    }
    fclose(fptr);
    printf("\n\t\t\tEnter what kids product you want to purchase: \n");
    Cart();
    getchar();
    getchar();
}

void Cart()
{
    FILE *fptr,*tempFptr;
    char tempCart[50];
    scanf("%s",&tempCart);
    fptr=fopen(BBCLfile,"rb+");
    tempFptr=fopen("Cart.bin","wb+");
    if(tempFptr==NULL)
    {
        printf("\t\tFile is not created\n\n");
    }
    while(fread(&BBCL,sizeof(BBCL),1,fptr))
    {
        if(strcmp(BBCL.bname,tempCart)==0)
        {
            fwrite(&BBCL,sizeof(BBCL),1,tempFptr);
        }
    }
    fclose(fptr);
    fclose(tempFptr);
    fptr=fopen("Cart.bin","rb+");
    while(fread(&BBCL,sizeof(BBCL),1,fptr))
    {
        printf("\n\t\t\tProducts you have added in your cart!!!!\n\n");
        printf("\t\t\tSerial Number : %d\n",BBCL.bserial);
        printf("\t\t\tProduct Name  : %s\n",BBCL.bname);
        printf("\t\t\tProduct Price : %d\n",BBCL.bprice);
        getchar();
        printf("\t\tWant to buy more products !! \n\t\tEnter 1 :\n\t\tElse enter any key to go back to kidsnmom page\nEnter 'P' to go to payment system \n\n");
        char n;
        scanf("%d",&n);
        if(n==1)
        {
            Bclothing();
        }
        else if(n==2)
        {
            printf("\n\t\tWhat payment system are you going to use ?\n\t\tEnter 1 for Mobile Banking payment system\n\t\tEnter 2 for VISA/MASTER Card payment system\n\t\tEnter 3 for CASH ON DELIVERY payment\n\n\t\t=>");
            //payment();
        }
        else KidsnMom();
    }
    fclose(fptr);
}
void Mclothing()
{
    FILE *fptr;
    system("cls");
    fptr=fopen(BBCLfile,"rb+");
    if(fptr==NULL)
    {
        printf("\t\tFile not created!!!\n");
    }
    else
    {
        while(fread(&MCL,sizeof(MCL),1,fptr))
        {
            getchar();
            printf("\n\t\t Reading from Mens Category !!! \n\n");
            printf("\n\t\t Enter product serial no. : %d",MCL.mserial);
            printf("\n\t\t Enter product name       : %s",MCL.mname);
            printf("\n\t\t Enter product price      : %d\n",MCL.mprice);
        }
    }
    fclose(fptr);
    Cart();
    getchar();
    getchar();
}
void Mequipments()
{
}
void Mfood()
{
}
void TechAccessories ()
{
}
void TechComputers()
{

}
void Products_Category()
{
    int n;
    printf("\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1 Products Category Page \xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\n");
    printf("\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\n\n");
    printf("\n\t\t\tEnter what type of product you want to purchase: \n");
    printf("\t\t\t1. Kids and Moms \n");
    printf("\t\t\t2. Mens \n");
    printf("\t\t\t3. Tech and accessories\n");
    printf("\t\t\t4. Want to go back to User Login panel!!!\n");
    printf("\n\t\t\tEnter your choice \n\t\t\t=>");
    scanf("%d",&n);
    switch(n)
    {
    case 1:
        KidsnMom();
        break;
    case 2:
        Mens();
        break;
    case 3:
        Tech();
        break;
    case 4:
        USER();
        break;
    default:
        printf("\t\tWrong option selected. Try again !!!");
        KidsnMom();
        break;
    }
}
int main()
{
    system("cls");
    LoginSystem();
    //Products_Category();
}

void ABclothing()
{
    printf("\t\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\n");
    printf("\t\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1 WELCOME ADMIN TO MODIFY KIDS AND MOM CATEGORY PRODUCTS \xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\n ");
    printf("\t\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\n");

    printf("\t\t1. ADD PRODUCTS\n");
    printf("\t\t2. DELETE PRODUCTS \n");
    printf("\t\t3. SEE PRODUCTS\n");
    printf("\t\t4. Want to go back to previous page!!!\n");
    printf("\n\t\tEnter your choice \n\t\t=>");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        printf("\n\tIf Baby clothing (Enter 1)\t|||\tBaby food (Enter 2)\t|||\tBaby Toys (Enter 3) \n\t=>");        scanf("%d",&choice);
        if(choice==1)add_baby_clothing();
        else if(choice == 2)add_baby_food();
        else if(choice == 3) add_baby_toys();
        break;
    case 2:
        printf("\n\tIf Baby clothing (Enter 1)\t|||\tBaby food (Enter 2)\t|||\tBaby Toys (Enter 3) \n\t=>");
        scanf("%d",&choice);
        if(choice==1)delete_baby_clothing();
        else if(choice == 2)delete_baby_food();
        else if(choice == 3) delete_baby_toys();
        break;
    case 3:
        SeeProducts();
        break;
    case 4:
        KidsnMom();
        break;
    default:
        break;
        Cart();
        getchar();
    }
}
void ABtoys()
{
    FILE *fptr;
    system("cls");
    fptr=fopen(BBTSfile,"rb+");
    if(fptr==NULL)
    {
        printf("\t\tFile not created!!!\n");
    }
    else
    {
        while(fread(&BBCL,sizeof(BBCL),1,fptr))
        {
            getchar();
            printf("\n\t\t\t Reading from baby toys !!! \n\n");
            printf("\n\t\t\t Enter product serial no. : %d",BBCL.bserial);
            printf("\n\t\t\t Enter product name       : %s",BBCL.bname);
            printf("\n\t\t\t Enter product price      : %d\n",BBCL.bprice);
        }
    }
    fclose(fptr);
    Cart();
    getchar();
    getchar();
    delete_baby_toys();
}
void add_baby_clothing()
{
    FILE *fptr;
    system("cls");
    fptr=fopen(BBCLfile,"ab+");
    if(fptr==NULL)
    {
        printf("\t\tFile not created!!!\n");
    }
    else
    {
        printf("\t\tTo add baby clothing any key to continue...\n");
        printf("\t\tEnter product serial no. : \t");
        scanf("%d",&BBCL.bserial);
        printf("\t\tEnter product name       : \t");
        scanf("%s",&BBCL.bname);
        printf("\t\tEnter product price      : \t");
        scanf("%d",&BBCL.bprice);
        fwrite(&BBCL,sizeof(BBCL),1,fptr);
        fclose(fptr);
        fptr=fopen(BBCLfile,"rb+");
        while(fread(&BBCL,sizeof(BBCL),1,fptr))
        {
            printf("\n\t Enter product serial no. : %d\t|||",BBCL.bserial);
            printf(" Enter product name       : %s\t|||",BBCL.bname);
            printf(" Enter product price      : %d ",BBCL.bprice);
        }
    }
    fclose(fptr);
}
void add_baby_food()
{
    FILE *fptr;
    system("cls");
    fptr=fopen(BBFDfile,"ab+");
    if(fptr==NULL)
    {
        printf("\t\tFile not created!!!\n");
    }
    else
    {
        printf("\t\tTo add baby clothing any key to continue...\n");
        printf("\t\tEnter product serial no. : \t");
        scanf("%d",&BBFD.bserial);
        printf("\t\tEnter product name       : \t");
        scanf("%s",&BBFD.bname);
        printf("\t\tEnter product price      : \t");
        scanf("%d",&BBFD.bprice);
        fwrite(&BBFD,sizeof(BBFD),1,fptr);
        fclose(fptr);
        fptr=fopen(BBCLfile,"rb+");
        while(fread(&BBFD,sizeof(BBFD),1,fptr))
        {
            printf("\n\t Enter product serial no. : %d\t|||",BBFD.bserial);
            printf(" Enter product name       : %s\t|||",BBFD.bname);
            printf(" Enter product price      : %d ",BBFD.bprice);
        }
    }
    fclose(fptr);
}
void add_baby_toys()
{

    FILE *fptr;
    system("cls");
    fptr=fopen(BBTSfile,"ab+");
    if(fptr==NULL)
    {
        printf("\t\tFile not created!!!\n");
    }
    else
    {
        printf("\t\tTo add baby clothing any key to continue...\n");
        printf("\t\tEnter product serial no. : \t");
        scanf("%d",&BBTS.bserial);
        printf("\t\tEnter product name       : \t");
        scanf("%s",&BBTS.bname);
        printf("\t\tEnter product price      : \t");
        scanf("%d",&BBTS.bprice);
        fwrite(&BBTS,sizeof(BBTS),1,fptr);
        fclose(fptr);
        fptr=fopen(BBCLfile,"rb+");
        while(fread(&BBTS,sizeof(BBTS),1,fptr))
        {
            printf("\n\t Enter product serial no. : %d\t|||",BBTS.bserial);
            printf(" Enter product name       : %s\t|||",BBTS.bname);
            printf(" Enter product price      : %d ",BBTS.bprice);
        }
    }
    fclose(fptr);
}
//void DeleteAnyProducts()
//{
//    SeeProducts();
//    getchar();
//    FILE *fptr,*tempFptr;
//    char tempDelete[50];
//    printf("\n\t\tEnter the data you want to delete :\t");
//    scanf("%s",&tempDelete);
//    fptr=fopen(BBCLfile,"rb+");
//    tempFptr=fopen("temp.bin","wb+");
//    if(tempFptr==NULL)
//    {
//        printf("File is not created\n\n");
//    }
//    rewind(fptr);
//    while(fread(&BBCL,sizeof(BBCL),1,fptr))
//    {
//        if(strcmp(BBCL.bname,tempDelete)!=0)
//        {
//            fwrite(&BBCL,sizeof(BBCL),1,tempFptr);
//        }
//    }
//    fclose(fptr);
//    fclose(tempFptr);
//    remove(BBCLfile);
//    rename("temp.bin",BBCLfile);
//}

void delete_baby_clothing()
{
    SeeProducts();
    getchar();
    FILE *fptr,*tempFptr;
    char tempDelete[50];
    printf("\n\t\tEnter the data you want to delete :\t");
    scanf("%s",&tempDelete);
    fptr=fopen(BBCLfile,"rb+");
    tempFptr=fopen("temp.bin","wb+");
    if(tempFptr==NULL)
    {
        printf("File is not created\n\n");
    }
    rewind(fptr);
    while(fread(&BBCL,sizeof(BBCL),1,fptr))
    {
        if(strcmp(BBCL.bname,tempDelete)!=0)
        {
            fwrite(&BBCL,sizeof(BBCL),1,tempFptr);
        }
    }
    fclose(fptr);
    fclose(tempFptr);
    remove(BBCLfile);
    rename("temp.bin",BBCLfile);
}

void delete_baby_food()
{
    SeeProducts();
    getchar();
    FILE *fptr,*tempFptr;
    char tempDelete[50];
    printf("\n\t\tEnter the data you want to delete :\t");
    scanf("%s",&tempDelete);
    fptr=fopen(BBFDfile,"rb+");
    tempFptr=fopen("temp.bin","wb+");
    if(tempFptr==NULL)
    {
        printf("File is not created\n\n");
    }
    rewind(fptr);
    while(fread(&BBCL,sizeof(BBCL),1,fptr))
    {
        if(strcmp(BBCL.bname,tempDelete)!=0)
        {
            fwrite(&BBCL,sizeof(BBCL),1,tempFptr);
        }
    }
    fclose(fptr);
    fclose(tempFptr);
    remove(BBFDfile);
    rename("temp.bin",BBFDfile);
}

void delete_baby_toys()
{
    SeeProducts();
    getchar();
    FILE *fptr,*tempFptr;
    char tempDelete[50];
    printf("\n\t\tEnter the data you want to delete :\t");
    scanf("%s",&tempDelete);
    fptr=fopen(BBTSfile,"rb+");
    tempFptr=fopen("temp.bin","wb+");
    if(tempFptr==NULL)
    {
        printf("File is not created\n\n");
    }
    rewind(fptr);
    while(fread(&BBCL,sizeof(BBCL),1,fptr))
    {
        if(strcmp(BBCL.bname,tempDelete)!=0)
        {
            fwrite(&BBCL,sizeof(BBCL),1,tempFptr);
        }
    }
    fclose(fptr);
    fclose(tempFptr);
    remove(BBTSfile);
    rename("temp.bin",BBTSfile);
}
void SeeProducts()
{
    FILE *fptr;
    system("cls");
    fptr=fopen(BBCLfile,"rb+");
    if(fptr==NULL)
    {
        printf("\t\tFile not created!!!\n");
    }
    else
    {
        printf("\n\t\t||| BABY CLOTHINGS |||");
        while(fread(&BBCL,sizeof(BBCL),1,fptr))
        {
            printf("\n\n\t Enter product serial no. : %d",BBCL.bserial);
            printf("\n\t Enter product name         : %s",BBCL.bname);
            printf("\n\t Enter product price        : %d",BBCL.bprice);
        }
        getch();
    }
    fclose(fptr);
}


void Mens()
{
    int n;
    printf("\t\tEnter what Mens product you want to purchase: \n");
    printf("\t\t1. Mens clothing\n");
    printf("\t\t2. Men equipments \n");
    printf("\t\t3. Men food.\n");
    printf("\t\t4. Want to go back to previous panel!!!\n");
    printf("\n\t\tEnter your choice \n\t\t=>");
    scanf("%d",&n);
    switch(n)
    {
    case 1:
        Mclothing();
        break;
    case 2:
        Mequipments();
        break;
    case 3:
        Mfood();
        break;
    case 4:
        Mens();
        break;
    default:
        printf("\t\tWrong option selected. Try again !!!");
        Mens();
        break;
    }
    Cart();
}
void Tech()
{
    int n;
    printf("\t\tEnter what Tech product you want to purchase: \n");
    printf("\t\t1. Tech Accesorries \n");
    printf("\t\t2. Tech Equipments\n");
    printf("\t\t3. Want to go back to previous panel!!!\n");
    printf("\n\t\tEnter your choice \n\t\t=>");
    scanf("%d",&n);
    switch(n)
    {
    case 1:
        TechComputers();
        break;
    case 2:
        TechAccessories();
        break;
    case 3:
        Tech();
        break;
    default:
        printf("\t\tWrong option selected. Try again !!!");
        Tech();
        break;
    }
    Cart();
}
int LoginSystem()
{
    printf("\t\t\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1");
    printf("\n\t\t\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1  LOGIN PAGE  \xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1");
    printf("\n\t\t\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1");
    printf("\n\n\t\t\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1");
    printf("\n\t\t\xB1\xB1\xB1\t\t\t\t\t\t\t\t\t\t\t\t\t\xB1\xB1\xB1\n");
    printf("\t\t\xB1\xB1\xB1\t\t\t\t\t\t\t\t\t\t\t\t\t\xB1\xB1\xB1\n");
    printf("\t\t\xB1\xB1\xB1\t\t\t  \t ### WELCOME TO ONLINE SHOPPING ### \t\t\t\t\t\xB1\xB1\xB1\n");
    printf("\t\t\xB1\xB1\xB1    \t\t\t\t \t  ### MAIN MENU ### \t\t\t\t\t\t\xB1\xB1\xB1\n");
    printf("\t\t\xB1\xB1\xB1 \t\t\t   \t   ### USER AND ADMIN SYSTEM ### \t\t\t\t\t\xB1\xB1\xB1\n");
    printf("\t\t\xB1\xB1\xB1\t\t\t\t\t\t\t\t\t\t\t\t\t\xB1\xB1\xB1\n");
    printf("\t\t\xB1\xB1\xB1\t\t\t\t\t\t\t\t\t\t\t\t\t\xB1\xB1\xB1\n");
    printf("\t\t\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\n");
    printf("\n \t\tFOR USER  (Enter 1):\n \t\tFOR ADMIN (Enter 2):\n \t\tTO EXIT PROGRAM (Enter 3):\n\n\t\t=> ");
    {
        int choice;
        scanf("%d",&choice);
        system("cls");
        if(choice == 1)
        {
            USER();
        }
        else if(choice == 2)
        {
            ADMIN();
        }
        else if(choice==3)
        {
            exit(0);
        }
        else
        {
            system("cls");
            printf("\nWrong option selected !\nTry again!!!\n");
            LoginSystem();
        }
    }
}
int USER()
{
    printf("\t\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1");
    printf("\n\t\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1 USER LOGIN PAGE \xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\n");
    printf("\t\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\n");
    printf("\n\t\t\t\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\n\n");
    printf("\t\t\t                          Welcome to USER login page                           \n\n");
    printf("\t\t\t\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1     MAIN MENU    \xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\n");
    printf("\n\t\t\t\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\n\n");
    printf("\t\t\t1.LOGIN\n");
    printf("\t\t\t2.REGISTER\n");
    printf("\t\t\t3.FORGOT PASSWORD OR USERNAME\n");
    printf("\t\t\t4.EXIT (Go back to main panel)\n");
    printf("\n\t\t\tEnter your choice \n\t\t\t=> ");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        userLogin();
        break;
    case 2:
        userReg();
        break;
    case 3:
        userForgot();
        break;
    case 4:
        system("cls");
        printf("\t\tThanks for paying a visit!!!\n\t\tWelcome back to main menu !!!\n");
        LoginSystem();
        break;
    default:
        system("cls");
        printf("\n\t\tYou've entered wrong option, give it another try\n\n");
        LoginSystem();
    }
}
int userLogin()
{
    FILE *fptr;
    int flag=0;
    char username[50],password[50];
    fptr = fopen(ULfile,"rb+");
    if(fptr==NULL)
    {
        printf("Unable to open file.\n");
        exit(1);
    }
    system("CLS");

    printf("\t\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\n");
    printf("\t\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1 TO LOGIN USER PANEL \xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\n ");
    printf("\t\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\n");

    printf("\n\t\tENTER YOUR USERNAME : ");
    scanf("%s",&username);
    printf("\t\tENTER YOUR PASSWORD : ");
    scanf("%s",&password);
    while(fread(&userInfo, sizeof(userInfo), 1, fptr))
    {
        if(strcmp(userInfo.username,username)==0 && strcmp(userInfo.password,password)==0)
        {
            flag=1;
            printf("\t\tLOGIN SUCCESSFULL\n\n");
            getch();
            system("cls");
            printf("\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1");
            printf("\n**\t\t\t\t\t\t\t\t\t\t\t\t\t\t**\n");
            printf("**\t\t\t\t\t\t\t\t\t\t\t\t\t\t**\n");
            printf("**\t\t\t\t\t   HELLO %s\t\t\t\t\t\t\t\t**\n",userInfo.name);
            printf("**\t\t\t\t\tLOGIN SUCCESSFUL\t\t\t\t\t\t\t**\n");
            printf("**\t\t\t\t   Thanks for logging in!!!\t\t\t\t\t\t\t**\n");
            printf("**\t\t\t\t We're glad that you're here \t\t\t\t\t\t\t**\n");
            printf("**\t\t\t\t    **Happy Shopping :)**\t\t\t\t\t\t\t**\n");
            printf("**\t\t\t\t\t\t\t\t\t\t\t\t\t\t**\n");
            printf("**\t\t\t\t\t\t\t\t\t\t\t\t\t\t**\n");
            printf("\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\n\n");
            getch();
            Products_Category();
        }
    }
    fclose(fptr);
    if(flag==0)
    {
        system("cls");
        printf("\n\t\tLOGIN ERROR!!!\n\t\tIncorrect user-name or password.\n\t\tOr you may try registering or log in again :\n\n\t\tTO REGISTRATION (ENTER 1):\n\t\tTO LOGIN (ENTER 2):\n\t\tFORGOTTEN PASSWORD (ENTER 3)\n\t=>");
        choice=0;
        scanf("%d",&choice);
        system("cls");
        printf("\t\tYour entered choice is %d\n",choice);
        switch(choice)
        {
        case 1:
            printf("\t\tFOR REGISTRATION!!! \n");
            userReg();
            break;
        case 2:
            printf("\t\tFOR LOGIN!!!\n");
            userLogin();
            break;
        case 3:
            printf("\t\tFORGOTTEN PASSWORD!!!\n");
            userForgot();
            break;
        }
    }
}
int userReg()
{
    FILE *fptr;
    fptr = fopen(ULfile,"ab+");
    if(fptr==NULL)
    {
        printf("\t\tFile not created\n");
    }
    printf("\n\t\tENTER NAME : ");
    scanf("%s",&userInfo.name);
    printf("\n\t\tENTER USERNAME : ");
    scanf("%s",&userInfo.username);
    printf("\n\t\tENTER MAIL : ");
    scanf("%s",&userInfo.mail);
    printf("\n\t\tENTER PASSWORD : ");
    scanf("%s",&userInfo.password);
    fwrite(&userInfo,sizeof(userInfo),1,fptr);
    fclose(fptr);
    system("cls");
    printf("\t\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\n");
    printf("\t\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1 LOGIN USER PANEL NOW \xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\n ");
    printf("\t\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\n");


    userLogin();
}
int userForgot()
{
    count=0;
    char Uname[50];
    FILE *fptr;
    printf("\t\tEnter your remembered name : ");
    scanf("%s",&Uname);
    fptr = fopen(ULfile,"rb");
    while (fread(&userInfo, sizeof(userInfo), 1, fptr) )
    {
        if(strcmp(userInfo.username,Uname)==0)
        {
            printf("\n\t\tHello %s, \n\t\tyour username is : \" %s \"",userInfo.name,userInfo.username);
            printf("\n\t\tYour password is : \" %s \"\n",userInfo.password);
            count++;
            getchar();
            getchar();
            printf("\t\tPress any key to login...");
            userLogin();
        }
    }
    if(count==0)
    {
        printf("\t\tOpps !! SORRY,\n\t\tNO RECORD FOUND!\n\t\tTRY AGAIN !!!\n\n");
        printf("\t\tPress any key to login...");
        getchar();
        getchar();
        userForgot();
    }
    fclose(fptr);
}
int ADMIN()
{
    printf("\t\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1");
    printf("\n\t\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1 ADMIN LOGIN PAGE \xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\n");
    printf("\t\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\n");
    printf("\n\t\t\t\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\n\n");
    printf("\t\t\t                          Welcome to ADMIN login page                           \n\n");
    printf("\t\t\t\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1     MAIN MENU    \xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\n");
    printf("\n\t\t\t\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\n\n");
    printf("\t\t\t1.LOGIN\n");
    printf("\t\t\t2.REGISTER\n");
    printf("\t\t\t3.FORGOT PASSWORD OR USERNAME\n");
    printf("\t\t\t4.EXIT (Go back to main panel)\n");
    printf("\n\t\t\tEnter your choice \n\t\t\t=> ");
    scanf("%d",&choice);

    switch(choice)
    {
    case 1:
        adminLogin();
        break;
    case 2:
        adminReg();
        break;
    case 3:
        adminForgot();
        break;
    case 4:
        system("cls");
        printf("\t\t\tThanks for paying a visit!!!\n\t\t\tWelcome back to main menu !!!\n");
        LoginSystem();
        break;
    default:
        system("cls");
        printf("\n\t\tYou've entered wrong option, give it another try\n\n");
        LoginSystem();
    }
}
int adminLogin()
{
    FILE *fptr;
    int flag=0;
    char username[50],password[50];
    fptr = fopen(ALfile,"rb+");
    if(fptr==NULL)
    {
        printf("\t\tUnable to open file.\n");
        exit(1);
    }
    system("CLS");

    printf("\t\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\n");
    printf("\t\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1 TO LOGIN ADMIN PANEL \xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\n ");
    printf("\t\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\n");

    printf("\n\t\tENTER YOUR USERNAME : ");
    scanf("%s",&username);
    printf("\t\tENTER YOUR PASSWORD : ");
    scanf("%s",&password);
    while(fread(&adminInfo, sizeof(adminInfo), 1, fptr))
    {
        if(strcmp(adminInfo.username,username)==0 && strcmp(adminInfo.password,password)==0)
        {
            flag=1;
            printf("\t\tLOGIN SUCCESSFULL\n\n");
            getch();
            system("cls");
            printf("\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1");
            printf("\n**\t\t\t\t\t\t\t\t\t\t\t\t\t\t**\n");
            printf("**\t\t\t\t\t\t\t\t\t\t\t\t\t\t**\n");
            printf("**\t\t\t\t\t   HELLO %s\t\t\t\t\t\t\t\t**\n",adminInfo.name);
            printf("**\t\t\t\t\tLOGIN SUCCESSFUL\t\t\t\t\t\t\t**\n");
            printf("**\t\t\t\t   Thanks for logging in!!!\t\t\t\t\t\t\t**\n");
            printf("**\t\t\t\t Glad to have you back here \t\t\t\t\t\t\t**\n");
            printf("**\t\t\t\t    **Happy developing :)**\t\t\t\t\t\t\t**\n");
            printf("**\t\t\t\t\t\t\t\t\t\t\t\t\t\t**\n");
            printf("**\t\t\t\t\t\t\t\t\t\t\t\t\t\t**\n");
            printf("\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\n\n");
            getch();
            ABclothing();
            main();
        }
    }
    fclose(fptr);
    if(flag==0)
    {
        system("cls");
        printf("\n\t\tLOGIN ERROR!!!\n\t\tIncorrect user-name or password.\n\t\tOr you may try registering or log in again :\n\n\t\tTO REGISTRATION (ENTER 1):\n\t\tTO LOGIN (ENTER 2):\n\t\tFORGOTTEN PASSWORD (ENTER 3)\t\tn=>");
        choice=0;
        scanf("%d",&choice);
        system("cls");
        printf("\t\tYour entered choice is %d\n",choice);
        switch(choice)
        {
        case 1:
            printf("\t\tFOR REGISTRATION!!! \n");
            adminReg();
            break;
        case 2:
            printf("\t\tFOR LOGIN!!!\n");
            adminLogin();
            break;
        case 3:
            printf("\t\tFORGOTTEN PASSWORD!!!\n");
            adminForgot();
            break;
        }
    }
}
int adminReg()
{
    FILE *fptr;
    fptr = fopen(ALfile,"ab+");
    if(fptr==NULL)
    {
        printf("\t\tFile not created\n");
    }
    printf("\n\t\tENTER NAME : ");
    scanf("%s",&adminInfo.name);
    printf("\n\t\tENTER USERNAME : ");
    scanf("%s",&adminInfo.username);
    printf("\n\t\tENTER MAIL : ");
    scanf("%s",&adminInfo.mail);
    printf("\n\t\tENTER PASSWORD : ");
    scanf("%s",&adminInfo.password);
    fwrite(&adminInfo,sizeof(adminInfo),1,fptr);
    fclose(fptr);
    system("cls");
    printf("\n\t\t||| ADMIN PANEL |||\nLOGIN NOW \n");
    adminLogin();
}
int adminForgot()
{
    count=0;
    char Uname[50];
    FILE *fptr;
    printf("\t\tEnter your remembered name : ");
    scanf("%s",&Uname);
    fptr = fopen(ALfile,"rb+");
    while (fread(&adminInfo, sizeof(adminInfo), 1, fptr))
    {
        if(strcmp(adminInfo.username,Uname)==0)
        {
            printf("\n\t\tHello %s, \n\t\tyour username is : \" %s \"",adminInfo.name,adminInfo.username);
            printf("\n\t\tYour password is : \" %s \"\n",adminInfo.password);
            count++;
            getchar();
            getchar();
            printf("\t\tPress any key to login...");
            adminLogin();
        }
    }
    if(count==0)
    {
        printf("\t\tOpps !! SORRY,\n\t\tNO RECORD FOUND!\n\t\tTRY AGAIN !!!\n\n");
        printf("\t\tPress any key to login...");
        getchar();
        getchar();
        adminForgot();
    }
    fclose(fptr);
}

//void welcome()
//{
//    printf(" ***                    *** ********  **               ******     **********            **      **          *********  \n");
//    printf("  **                    **  **        **             *          **          **         ** **   ** **        **         \n");
//    printf("   **                  **   **        **           *          **              **      **   ** **   **       **         \n");
//    printf("    **                **    **        **          *          **                **    **     ***     **      **         \n");
//    printf("     **      **      **     ******    **          *          **                **   **       *       **     ******     \n");
//    printf("      **    ****    **      **        **           *          **              **   **                 **    **         \n");
//    printf("       **  **  **  **       **        **            *          **             **  **                   **   **         \n");
//    printf("        ****    ****        **        **             *           **         **   **                     **  **         \n");
//    printf("         **      **         ********  ************     *****       ********     **                       ** *********  \n");
//
//    printf("Any key to continue...");
//    getch();
//    system("cls");
//}
