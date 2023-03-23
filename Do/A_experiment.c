#include<stdio.h>
int main()
{
 float BMI,kg,h;
 printf("enter h and kg : \n");
 scanf("%f,%f",&h,&kg);
 BMI=kg/(h*h);
 printf("ur BMI : %f\n",BMI);
 if(BMI<18)
    printf("flight");
 else
 {
   if(BMI>17&&BMI<25)
      printf("of middium");
   else
   {
    if(BMI>24&&BMI<28)
        printf("heavey");
     else
        printf("Obisety");
   } 
 }
 return 0;
}

void create_pointer(char* name) {
    // 分配内存来存储指针
    char** ptr = (char**) malloc(sizeof(char*));

    // 复制传入的字符串值到新指针名称中
    *ptr = strdup(name);

    // 打印新指针名称的值
    printf("New pointer name: %s\n", *ptr);

    // 释放分配的内存
    free(*ptr);
    free(ptr);
}

int main() {
    // 传递字符串作为函数参数
    create_pointer("my_new_pointer");

    return 0;
}