#include<conio.h>
#include<iostream>
#include<fstream>
#include<map>
#include<string>

int status =1;
using namespace std;

typedef map<string,int> resolved_query;

int match(char *, char *);
void solve(char*, char*);
void Negate (char*);
void removeNegate(char*);

int isPresent(char * str, char x){
    int i = 0,count = 0;
    int l= strlen(str);
    for(;i<l;i++){
      if(str[i]==x)
         count++;
    }
    return count;
}
void Convert(char * str){
   int imply = isPresent(str, '>');
  // int and   = isPresent(str, '&');
   
   if(imply){
        char str1[200];
        char str2[200];
        strcpy(str2,str);
        int i = 0;
        while(str[i]!='>'){
           str1[i]= str[i];
           i++;
        }
        str1[i]='\0';
        Negate(str1);
        int j=0;
        while(str1[j]!='\0'){
           str[j]=str1[j];
           j++;
        }
        str[j]= 'V';
        j++;
        i++;
        while(str2[i]!='\0'){
           str[j]= str2[i];
           i++;j++;
        }
        str[j]='\0';
   }

}
resolved_query query;
string temp2;
char temp3[200];
int Find(char *temp,char given[][200], int num){
   int i =0,resolve=1000,k=-1, resolve_new,j=0;
   for(;i<num;i++){
        strcpy(temp3,temp);
        j=0;
        resolve_new = match(given[i],temp);
        if(resolve_new<1000){
           solve(given[i],temp3);
           temp2=&temp3[0];
           if(query[temp2]==0){
              query[temp2]= resolve_new;
           }
           resolve_new=query[temp2];
        }
        if(resolve_new<resolve){
           k=i;
           resolve=resolve_new;
        }
   }    
//   cout<<"\nstatus"<<status<<" : "<<temp;
   if(resolve < 1000){
      solve(given[k],temp);
       temp2=&temp[0];
       query[temp2]++;
   }
//   cout<<"\nstatus"<<status<<" : "<<temp<<"\n";
   status++;
   if(query[temp2]==900)return 1000;
   if(resolve==1000) return -1;
   return resolve;
}
int isSubstring(char * str1, char *str2){
    int l1=strlen(str1);
    int l2=strlen(str2);
    if(l1<l2){
      return -1;
    }

    int i = 0,j;
    for(i=0;i<l1-l2+1;i++){
       for(j=0;j<l2;j++){
          if(str2[j]!=str1[i+j])
             break;
       }
       if(j==l2)
         if(i==0?1:str1[i-1]=='V')
          if(str1[i+l2]=='V'||str1[i+l2]=='\0'){
             return i;
          }
    }
    return -1;
}
int match(char * str1, char *str2){
   int resolve = 2 + isPresent(str1,'V')+ isPresent(str2,'V');
   int pos = isSubstring(str1,str2);
   if(pos != -1) return 1000;
   char str3[200];
   strcpy(str3,str2);
   removeNegate(str3); 
    char str4[200];
    int i =0, flag = 0,k=0;
    while(i==0||str3[i-1]!='\0'){
       k=0;
       while(str3[i]!='\0'&&str3[i]!='V'){
          str4[k]=str3[i];
          i++;k++;
       }
       str4[k]='\0';i++;
       pos = isSubstring(str1,str4);
       if(pos!=-1){
          flag = 1;
          break;
       }
    }
    if(flag==1)
      return resolve - 2;
    else
       return 1000;
}
void removeCommon(char * str){
   char str2[200];
   strcpy(str2,str);
   int i=0;
   while(str2[i]!='\0'&&str2[i]!='V')
   i++;
   if(str2[i]=='\0') return;
   str2[i]='\0';
   int pos = isSubstring(&str[i+1],str2);
   if(pos==-1)removeCommon(&str[i+1]);
   else{
      i++;
      int x = 0;
      while(str[i]!='\0'){
         str[x]=str[i];
         x++;i++;
      }
      str[x]='\0';
      removeCommon(str);
   }
}

void solve(char * str1, char *str2){
   int pos;
   char str3[200];
   strcpy(str3,str2);
   removeNegate(str3);
   
    char str4[200];
    int i =0, j=0,k=0;
    while(i==0||str3[i-1]!='\0'){
       k=0;
       while(str3[i]!='\0'&&str3[i]!='V'){
          str4[k]=str3[i];
          i++;k++;
       }
       str4[k]='\0';i++;
       
       pos = isSubstring(str1,str4);
       if(pos!=-1){
          break;
       }
    }
    Negate(str4);
    int pos2 =  isSubstring(str2,str4);
    i=pos2;
    while(str2[i]!='\0'&&str2[i]!='V')i++;
    if(str2[i]=='\0'&&pos2>0)str2[pos2-1]='\0';
    else if(str2[i]=='\0'&&pos2==0)str2[0]='\0';
    else{
      while(str2[i]!='\0'){
         str2[pos2-1]=str2[i];
         pos2++;
         i++;
      }
      str2[pos2-1]='\0';
    }
    removeNegate(str4);
    i = strlen(str2);
    if(i!=0){
       str2[i]='V';i++;
    }
    int x=0;
    j = strlen(str4)+pos;
    while(x<pos-1){
      str2[i]=str1[x];
      i++;x++;
    }
    while(str1[j]!='\0'){
       str2[i]=str1[j];
       i++;j++; 
    }
    str2[i]='\0';
    if(str2[i-1]=='V'){
       str2[i-1]='\0';
    }
    removeCommon(str2);
}   
void removeNegate(char * str){
     int i=0;
     int x=0;
     while(str[x]!='\0'){
        if(str[x]=='~');
        else{
           str[i]=str[x];
           i++;
        }
        x++;
     }    
     str[i]='\0';
}  
void Negate(char * str){
     int andd = isPresent(str,'&');
     int l = strlen(str);
     int x = l;

     while(l-->0){
        str[l+1]=str[l];
     }
     str[0] = '~';
     str[x+1]='\0';
     
     l = strlen(str);
     l = l+andd;
     str[l]='\0';
     while(l-->0 && andd > 0){
        if(str[l-andd] == '&'){
          str[l] = '~';
          str[l-1] = 'V';
          andd--;
        }
        str[l]=str[l-andd];
     }  
        
}
int main(){
    char toProve[200];
    int num,t,i,fir=0;
    //cin>>num;
    char given[50][200];
    char c;
    fstream fin("AI.txt", fstream::in);
    while(fin >> c&&c !='#'){
       i=0;
       if(fir==0)
            toProve[i]=c;
         else if(fir==1)
           num = c-'0'; 
         else
            given[fir-2][i]=c;
       i++;
       while(fin >> c&&(c !='@'&& c !='#')){
         if(fir==0)
            toProve[i]=c;
         else if(fir==1)
           num = c-'0'; 
         else
            given[fir-2][i]=c;
         i++;
       }
       
       if(fir==0){
            toProve[i]='\0'; 
            cout<<"\n"<<toProve;
       }
       else if(fir>=2){
          given[fir-2][i]='\0';
       }
       if(c=='#')
        break;
       fir++;
   
    }
    i = 0;
    char temp[20];
    strcpy(temp,toProve);
    int resolve = 1;
    Negate(temp); 
    cout<<"\n";
    for(i=0;i<num;i++){
        Convert(given[i]);
        cout<<"\n"<<given[i];
    }
    cout<<"\n";
    char firstOne[200];
    strcpy(firstOne,temp);
   while(resolve < 1000){
       resolve = Find(temp,given,num);
       if(resolve==0){
          cout<<"\nYES";
          break;
       }
       if(resolve==-1)
         strcpy(temp,firstOne);
    }
    if(resolve==1000){
       cout<<"\nNO";
    }
    getch();
    }
