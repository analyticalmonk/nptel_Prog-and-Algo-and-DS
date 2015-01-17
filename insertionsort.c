  #include<stdio.h>

  void switch(int*, int*)

  int main(){
  int a[10], i, j, temp;
  for(i = 0; i < 10; i++){
    scanf("%d", &a[i]);
  }

  // Insertion sort - main code starts
  for(i = 0; i < 10; i++){
    for(j = i-1; j >=0; j--){
        if(a[j + 1] < a[j]){
          switch(&a[j+1], &a[j]);
        }
    }
  }

  for(i = 0; i < 10; i++){
    printf("%d ", a[i]);
  }
  return 0;
}

void switch(int* a, int* b){
  int temp;
  temp = *a;
  *a = *b;
  *b = temp;
}
