#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<ctime>
#include<windows.h>
#include<conio.h>
using namespace std;

/*
comments,change all cout statements, spaces not readed in cin
 */



struct patron{//structure patron to store the details of patron
                char id[10];
                char name[40];
             };

struct book{//structure book to store the details of book
                char ref_no[10];
                char title[30];
                char author[30];
                bool availability;
                char* dt;
                char course[10];
                patron p;
           };

int patron_addition(patron &p1,patron &p2,long int psize);
int patron_deletion(patron &p1,long int psize);
int book_issue(book &b,patron &p1,long int psize,long int bsize);
int book_return(book &b,patron &p1,long int psize,long int bsize);
int book_addition(book &b,book &b2,long int bsize);
int book_deletion(book &b,long int bsize);
int bsearch_title(book &b,long int bsize);
int bsearch_refno(book &b,long int bsize);
int bsearch_author(book &b,long int bsize);
int bsearch_course(book &b,long int bsize);
bool password();
int SetColor(int colorno);

FILE *fb,*tp,*fp;

int main() {
            int pswd;
            char c,d;
            patron p1,p2;
            book b,b2;


            tp=fopen("temp.txt","ab+");//opening file in append mode
                if(tp==NULL)
                            {// output appropriate error message in case of memory allocation failure
                                cout<<"error in opening the file"<<endl;
                                return -1;
                            }

            fb=fopen("book.txt","rb+");
                if(fb==NULL)
                            {
                                fb=fopen("book.txt","wb");
                                if(fb==NULL)
                                            {
                                                cout<<"error in opening the file"<<endl;
                                                return -1;
                                            }
                            }
            fp=fopen("patron.txt","rb+");
                if(fp==NULL)
                            {
                                fp=fopen("patron.txt","wb");
                                if(fp==NULL)
                                            {
                                                cout<<"error in opening the file"<<endl;
                                                return -1;
                                            }
                            }
	        long int bsize=sizeof(b);//size of the structure book in bytes
	        long int psize=sizeof(p1);


   LOOP: do{
        SetColor(4);
        cout<<"\n-----------------------------------------------"<<endl;
        cout<<"          Welcome to Library Manager            "<<endl;
        cout<<"-----------------------------------------------\n"<<endl;
        SetColor(2);
        cout<<"To access the program as a Librarian....PRESS 1 "<<endl;
        cout<<"To access the program as a Patron.......PRESS 2 "<<endl;
        cout<<"To exit the program.....................PRESS 3 "<<endl;
        SetColor(7);
        cin >>c;
        fflush(stdin);
		switch(c){
		    case '1':
		  {
		      pswd=password();// asking for the login details

              if (pswd==1){

              while(true)
			     {
                    SetColor(6);
                    cout<<"\n-----------------------------------------------"<<endl;
                    cout<<"               Welcome Librarian                 "<<endl;
                    cout<<"-----------------------------------------------\n"<<endl;
                    cout<<"To Add a Patron.........................PRESS 1"<<endl;
                    cout<<"To Delete a Patron......................PRESS 2"<<endl;
                    cout<<"To Issue a book.........................PRESS 3"<<endl;
                    cout<<"To Return a book........................PRESS 4"<<endl;
                    cout<<"To Add book to data base................PRESS 5"<<endl;
                    cout<<"To Delete book From data base...........PRESS 6"<<endl;
                    cout<<"To go to main menu..........PRESS any other key"<<endl;

                SetColor(7);
				cin>>d;
				fflush(stdin);
				SetColor(6);
                switch(d){
                    case '1':
						{
						    patron_addition(p1,p2,psize);
						}   break;
					case '2':
						{
						    patron_deletion(p1,psize);
						}   break;
					case '3':
						{
						    book_issue(b,p1,psize,bsize);
						}   break;
					case '4':
						{
						    book_return(b,p1,psize,bsize);
						}   break;

					case '5':
						{
						    book_addition(b,b2,bsize);
                        }   break;
					case '6':
						{
						    book_deletion(b,bsize);
						}   break;

					default:{goto LOOP;}
                    }
                }
                }
		  }break;

        case '2':

               {SetColor(3);
                cout<<"\n-----------------------------------------------"<<endl;
                cout<<"                Welcome Patron    "<<endl;
                cout<<"-----------------------------------------------\n"<<endl;
                cout<<"Please enter your ID"<<endl;
                char j[8];
                SetColor(7);// output in different colors
                fflush(stdin);
                gets(j);
                SetColor(1);
                fclose(fp);
                fp=fopen("patron.txt","r+");
                rewind(fp);
                int g=0;

                while(fread(&p1,psize,1,fp)==1)
                {
                if(strcmp(j,p1.id)==0){g=1;}
                }
                if(g==0)
                {
                cout<<"You're not a patron of this Library!"<<endl;goto LOOP;
                }

        while(true){
                SetColor(3);
                cout<<"\n-----------------------------------------------"<<endl;
                cout<<"                Welcome Patron    "<<endl;
                cout<<"-----------------------------------------------\n"<<endl;
               /* cout<<"Please enter your ID"<<endl;
                char j[8];
                SetColor(7);// output in different colors
                cin>>(j);
                SetColor(1);
                fclose(fp);
                fp=fopen("patron.txt","r+");
                rewind(fp);
                int g=0;

                while(fread(&p1,psize,1,fp)==1)
                {
                if(strcmp(j,p1.id)==0){g=1;}
                }
                if(g==0)
                {
                cout<<"You're not a patron of this Library!"<<endl;goto LOOP;
                }*/
                SetColor(3);
                cout<<"To search book by its Reference Number..PRESS 1"<<endl;
                cout<<"To search book by its Title.............PRESS 2"<<endl;
                cout<<"To search book by its Course............PRESS 3"<<endl;
                cout<<"To search book by its Author............PRESS 4"<<endl;
                cout<<"To go back PRESS ANY KEY other than above"<<endl;

            SetColor(7);
            cin>>d;
            fflush(stdin);
            SetColor(6);
            switch(d){
                case '1':

							{
                                bsearch_refno(b,bsize);


                            }break;
                case '2':
                            {
							    bsearch_title(b,bsize);

                            }break;
                case '3':
                            {
							    bsearch_course(b,bsize);


                            }break;
                case '4':
                            {

							    bsearch_author(b,bsize);



                            }break;
					default: {goto LOOP;}
                     }

                }
            }break;

		case '3':
            {return 0;}break;
		default:{cout <<"Invalid Choice"<<endl;}
                }
     }while (true);


	fclose(fb);
	fclose(fp);
	return 0;
}



int patron_addition(patron &p1,patron &p2,long int psize)// function to add a patron to the library management database
	{SetColor(5);
        cout<<"\n-----------------------------------------------"<<endl;
        cout<<"           Adding patron to the library     "<<endl;
        cout<<"-----------------------------------------------\n"<<endl;

        cout<<"Give the Patron ID (Not more than 10 characters)"<<endl;
        SetColor(7);
        cin>>p1.id;
        SetColor(5);
        int j=0;
        rewind(fp);
        while(fread(&p2,psize,1,fp)==1)
        {
            if(!strcmp(p2.id,p1.id)){j=1;cout<<"This patron ID already exists!"<<endl;}
        }
        if(j==0){
                cout<<"Enter the Patron Name"<<endl;
                SetColor(7);
                fflush(stdin);
                gets(p1.name);
                SetColor(5);
                fseek(fp,0,SEEK_END);
                if(fwrite(&p1,psize,1,fp)!=0){cout<<"The Patron is successfully added to the Library Database"<<endl;}
                return 0;
                }
    }

int patron_deletion(patron &p1,long int psize){//function to delete a patron from database
    SetColor(5);
    char str[10];
    char oldname[] ="temp.txt";
    char newname[] ="patron.txt";
    rewind (tp);

    cout<<"\n-----------------------------------------------"<<endl;
    cout<<"               Deleting a patron         "<<endl;
    cout<<"-----------------------------------------------\n"<<endl;

	cout<<"Give the ID of the patron to be deleted"<<endl;
	SetColor(7);
	fflush(stdin);
	gets(str);
	SetColor(5);
	rewind(fp);
	int r=0;

	while (fread(&p1,psize,1,fp)==1)
		{//cout<<"2"<endl;
            if (strcmp(str,p1.id)!=0)
                {//cout<<"3"<<endl;
                    fwrite(&p1,psize,1,tp);
                }
			else
                {   r=1;
                    cout<<"The Patron : "<<p1.name<<"  is found and deleted"<<endl;
                }
		}
    if(r==0){cout<<"There is no Patron with ID  "<<str<<endl;}
	fclose(fp);
	fclose(tp);
	if(remove("patron.txt")!=0)
        {
            cout<<"Error in deleting the Patron!"<<endl;
        }
	if(rename(oldname,newname)!=0)
        {
            cout<<"Error in deleting the Patron!"<<endl;
        }
	fp=fopen("patron.txt","rb+");
	tp=fopen("temp.txt","ab+");
	return 0;
}


int book_issue(book &b,patron &p1,long int psize,long int bsize)//function to issue a book from library to a patron
	{
	    SetColor(5);
        int j=0,r=0;
        char str[10];
        cout<<"\n-----------------------------------------------"<<endl;
        cout<<"                  ISSUE OF BOOK               "<<endl;
        cout<<"-----------------------------------------------\n"<<endl;

        cout<<"Enter the book ID to be issued"<<endl;
        SetColor(7);
        fflush(stdin);
        gets(str);

        SetColor(5);
	//fclose(fb);
	//fb=fopen("book.txt","r+");
        rewind(fb);

		while(fread(&b,bsize,1,fb)==1)
            {
                if((strcmp(b.ref_no,str))==0)
                    {
                        j=1;
                       // cout<<b.availability<<endl;
                        if(b.availability!=0)
                            {
                                time_t now = time(0);
                                b.dt=ctime(&now);
                                fseek(fb,-bsize,SEEK_CUR);
                                fwrite(&b,bsize,1,fb);
                                break;
                            }
                        else
                            {   r=1;
                                cout<<"Sorry! The book with reference no. : "<<b.ref_no<<"and title : "<<b.title<<" has already been issued to other patron"<<endl;return 0;
                            }

                    }
            }
                if(j==0)
                    {   r=1;
                        cout<<"Oops! Something has gone wrong.There is no such book in the library"<<endl;
                    }

    if(r==0){
    j=0;
    fseek(fb,-bsize,SEEK_CUR);
    fread(&b,bsize,1,fb);
	cout<<"Enter the ID of Patron to whom the book is being issued"<<endl;
    char y[8];
    SetColor(7);
    fflush(stdin);
    gets(y);
    SetColor(5);
	rewind(fp);
    while(fread(&p1,psize,1,fp)==1)
        {
            if((strcmp(y,p1.id))==0)
                {
                    j=1;
                    strcpy(b.p.id,p1.id);
                    strcpy(b.p.name,p1.name);
                    b.availability=0;
                    //cout<<"1213"<<endl;
                    fseek(fb,-bsize,SEEK_CUR);
                    fwrite(&b,bsize,1,fb);
                    cout<<"The book : "<<b.title<<" is being issued to the patron "<<p1.name<<" with ID "<<p1.id<<" on "<<b.dt<<endl;
                    break;
                }

        }
            if (j==0)
                {
                    cout<<"Patron not found!"<<endl;return 0;
                }
    return 0;}
}

int book_return(book &b,patron &p1,long int psize,long int bsize)//function to return book
	{
	    SetColor(5);
        cout<<"\n-----------------------------------------------"<<endl;
        cout<<"                RETURNING A BOOK             "<<endl;
        cout<<"-----------------------------------------------\n"<<endl;

    int j=0;
    char str[10],a[10];
	cout<<"Enter the reference no. of the book to be returned"<<endl;
	SetColor(7);
	fflush(stdin);
	gets(str);
	SetColor(5);
	//fclose(fb);
	//fb=fopen("book.txt","r+");
	rewind(fb);

		while(fread(&b,bsize,1,fb)==1)
            {
                if((strcmp(b.ref_no,str))==0)
                    {
                        j=1;

                        if(b.availability==0)
                            {
                                cout<<"Give the ID of Patron who is returning the book"<<endl;
                                SetColor(7);
                                fflush(stdin);
                                gets(a);
                                SetColor(5);
                                rewind(fp);
                                while(fread(&p1,psize,1,fp)==1)
                                {
                                    if((strcmp(a,p1.id))==0){break;}
                                }
                                if(strcmp(b.p.id,a)==0)
                                    {
                                        b.availability=1;
                                        fseek(fb,-bsize,SEEK_CUR);
                                        fwrite(&b,bsize,1,fb);
                                        cout<<"The book "<<b.title<<" is successfully returned\n"<<endl;
                                     }
                                else{cout<<"Something is wrong! Returning somebody else's book?"<<endl;}
                            }
                        else
                            {
                                cout<<"Something is wrong! The book is in the Library itself"<<endl;
                            }
             break;
                    }
            }
        if(j==0)
			{
              cout<<"There is no such book!"<<endl;
			}
	//fclose(fb);
	//fb=fopen("book.txt","r+");
    return 0;
}

int book_addition(book &b,book &b2,long int bsize)//function to add book to the library
	{
	    SetColor(5);
        cout<<"\n-----------------------------------------------"<<endl;
        cout<<"                ADDITION OF BOOK                  "<<endl;
        cout<<"-----------------------------------------------\n"<<endl;

        rewind(fb);
        int j=0;

        cout<<"Give the Book Reference No. (Not more than 10 characters)"<<endl;
        SetColor(7);
        cin>>b.ref_no;
        SetColor(5);
        while(fread(&b2,bsize,1,fb)==1)
        {
            if (strcmp(b2.ref_no,b.ref_no)==0){j=1;cout<<"A book with this Reference Number already exists"<<endl;}
        }
        if(j==0)
        {
        cout<<"Give the Book Title "<<endl;
        SetColor(7);
        fflush(stdin);
        gets(b.title);
        SetColor(5);
        cout<<"Give the Author name "<<endl;
        SetColor(7);
        fflush(stdin);
        gets(b.author);
        SetColor(5);
        cout<<"Give the Course name "<<endl;
        SetColor(7);
        fflush(stdin);
        gets(b.course);
        SetColor(5);
        b.availability=1;
        fseek(fb,0,SEEK_END);
        if(fwrite(&b,bsize,1,fb)!=0){cout<<"The book is successfully added to the Library Database"<<endl;}

        return 0;
        }
}

int book_deletion(book &b,long int bsize)// function to delete a book from the library
    {
        SetColor(5);
        char a[10];
        rewind(tp);
        cout<<"\n-----------------------------------------------"<<endl;
        cout<<"               DELETION OF BOOK                  "<<endl;
        cout<<"-----------------------------------------------\n"<<endl;

        cout<<"Give the reference no. of the book to be deleted"<<endl;
        SetColor(7);
        fflush(stdin);
        gets(a);
        SetColor(5);
        rewind(fb);
        int r=0;
        while (fread(&b,bsize,1,fb)==1)
		{
            if (strcmp(a,b.ref_no)!=0)
                {
                    fwrite(&b,bsize,1,tp);
                }
            else
                {   r=1;
                    cout<<"The required book found and deleted"<<endl;
                }
        }
        if(r==0){cout<<"There is no book with reference no. "<<a<<endl;}
        fclose(fb);
        fclose(tp);
        if(remove("book.txt")!=0)
            {
                cout<<"Error in deleting the book!"<<endl;
            }

        char oldname[]="temp.txt";
        char newname[]="book.txt";

        if(rename(oldname,newname)!=0)
            {
                cout<<"Error in deleting the book!"<<endl;
            }
        fb=fopen("book.txt","rb+");
        tp=fopen("temp.txt","ab+");
	return 0;
}

int bsearch_title(book &b,long int bsize)// function to search a book by it's name
	{
    SetColor(6);
	char btitle[30];
	cout<<"\n-----------------------------------------------"<<endl;
    cout<<"            SEARCHING OF BOOK BY TITLE           "<<endl;
    cout<<"-----------------------------------------------\n"<<endl;
    cout<<"Give the title of the book"<<endl;
    SetColor(7);
	cin>>btitle;
	fflush(stdin);
	SetColor(6);
	strlwr(btitle);
	rewind(fb);
	cout<<"Matching books with the letters "<<btitle<<" in thier title are "<<endl;
	cout<<"Ref_no       Title       Author       Course       Availability"<<endl;
	while(fread(&b,bsize,1,fb)==1)
	   {
          SetColor(7);
          strlwr(b.title);
          if(strstr(b.title,btitle))
	      {
              cout<<b.ref_no<<"          "<<b.title<<"         "<<b.author<<"          "<<b.course<<"       "<<b.availability<<endl;
	      }
	   }
    return 0;
    }

int bsearch_refno(book &b,long int bsize)//function to search a book by it's ID
	{
    SetColor(6);
	char bref[10];
	cout<<"\n-----------------------------------------------"<<endl;
    cout<<"       SEARCHING OF BOOK BY REFERENCE NUMBER     "<<endl;
    cout<<"-----------------------------------------------\n"<<endl;
	cout<<"Give the ref_no of the book"<<endl;
	SetColor(7);
	cin>>bref;
	fflush(stdin);
	SetColor(6);
	rewind (fb);
	cout<<"Matching books with the reference number "<<bref<<" are "<<endl;
	cout<<"Ref_no       Title       Author       Course       Availability"<<endl;
	while(fread(&b,bsize,1,fb)==1)
		{
		    SetColor(7);
		if(strstr(b.ref_no,bref))
			{
			cout<<b.ref_no<<"          "<<b.title<<"         "<<b.author<<"           "<<b.course<<"            "<<b.availability<<endl;
			}
		}
    return 0;
	}

int bsearch_course(book &b,long int bsize)//function to search a book by it's related course
	{
    SetColor(6);
	char bcourse[30];
	cout<<"\n-----------------------------------------------"<<endl;
    cout<<"       SEARCHING OF BOOK BY RELATED COURSE       "<<endl;
    cout<<"-----------------------------------------------\n"<<endl;
	cout<<"Give the course related to the book"<<endl;
	SetColor(7);
	cin>>bcourse;
	fflush(stdin);
	SetColor(6);
	rewind(fb);
	strlwr(bcourse);
	cout<<"Matching books whose related course is "<<bcourse<<" are "<<endl;
	cout<<"Ref_no       Title       Author       Course       Availability"<<endl;
	while(fread(&b,bsize,1,fb)==1)
	   {
	      SetColor(7);
          strlwr(b.course);
          if(strstr(b.course,bcourse))
	      {
              cout<<b.ref_no<<"          "<<b.title<<"           "<<b.author<<"           "<<b.course<<"          "<<b.availability<<endl;
	      }
	   }
    return 0;
	}



int bsearch_author(book &b,long int bsize)//function to search a book by it's author name
	{
    SetColor(6);
	char bauthor[30];
    cout<<"\n-----------------------------------------------"<<endl;
    cout<<"       SEARCHING OF BOOK BY AUTHOR               "<<endl;
    cout<<"-----------------------------------------------\n"<<endl;
	cout<<"Give the name of the author"<<endl;
	SetColor(7);
	cin>>bauthor;
	fflush(stdin);
	strlwr(bauthor);
	SetColor(6);
	rewind(fb);
	cout<<"Matching books whose author is "<<bauthor<<" are "<<endl;
	cout<<"Ref_no       Title       Author       Course       Availability"<<endl;
	while(fread(&b,bsize,1,fb)==1)
	   {
	      SetColor(7);
          strlwr(b.author);
          if(strstr(b.author,bauthor))
	      {
              cout<<b.ref_no<<"          "<<b.title<<"           "<<b.author<<"           "<<b.course<<"           "<<b.availability<<endl;
	      }
	   }
    return 0;
	}



bool password()//function to check the login details of the librarian
{
    int x=1;
    char u[10],p;
    char username[]="0";
    char password='0';
    do
	{
        cout<<"Enter user name"<<endl;
        fflush(stdin);
        gets(u);

        if (!strcmp(u,username))
		{
		    cout<<"Enter password"<<endl;
            p=getch();
		    if (p==password)
            {cout<<"*";return 1;}
            else {cout<<"\nWrong Password\n"<<endl;}
		}
		else {cout<<"\nWrong Username\n"<<endl;}
        if (x>=3){cout<<"\n\nYou have reached maximum number of tries for login"<<endl;return 0;}
        x++;
	}while(true);

}

int SetColor(int colorno)//function to set different colors in output
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),colorno);
    }
