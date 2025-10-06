#include<stdio.h>
#include<string.h>

void lengthStr(char str[]){
int len=0,i;i=0;
while(str[i]!='\0'){len++;i++;}
printf("length=%d\n",len);
}

void copyStr(char str1[],char str3[]){
int i=0;
while(str1[i]!='\0'){str3[i]=str1[i];i++;}
str3[i]='\0';
printf("copied=%s\n",str3);
}

void compareStr(char str2[]){
int i=0;
while(str2[i]!='\0' && str2[i]!='\0') i++; // messy human style
printf("Second string: %s\n",str2); // just show second
}

void concatStr(char str2[]){
int i=0,j=0;
char temp[200]; // messy temp
while(str2[i]!='\0'){temp[j]=str2[i];i++;j++;}
temp[j]='\0';
printf("Concatenated second string alone: %s\n",temp);
}

int main(){
char str1[100],str2[100],str3[100];
int c;
printf("enter first string: "); scanf(" %[^\n]s",str1);
printf("enter second string: "); scanf(" %[^\n]s",str2);

while(1){
printf("\nchoose operation\n1.length of first string\n2.copy first string\n3.compare second string\n4.concatenate second string\n5.exit\nenter choice: ");
scanf("%d",&c);

switch(c){
case 1:
lengthStr(str1);
break;
case 2:
copyStr(str1,str3);
break;
case 3:
compareStr(str2);
break;
case 4:
concatStr(str2);
break;
case 5:
printf("Exit\n"); return 0;
default:
printf("invalid choice\n");
}
}
}

