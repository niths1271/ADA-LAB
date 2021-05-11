#include<stdio.h>
#include<string.h>
int pattern_matching( char Text[],char pattern[]){
    int i,j;
    int n=strlen(Text);
    int m=strlen(pattern);
    for(i=0;i<=(n-m);i++){
        j=0;
        while(j<m && Text[i+j]==pattern[j]){
             j++;
        }
        if(j==m){
            return i;
        }
    }
    return -1;
}

void main(){
   char text[20],pattern[20];
   printf("ENTER THE TEXT\n");
   scanf("%s",text);
   printf("ENTER THE PATTERN TO BE MATCHED\n");
   scanf("%s",pattern);
   if(pattern_matching(text,pattern)==-1){
       printf("THE PATTERN IS NOT PRESENT IN THE TEXT");
   }
   else{
   printf("THE PATTERN IS FOUND AT THE INDEX %d IN THE GIVEN TEXT",pattern_matching(text,pattern));
   }
}