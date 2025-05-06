#include <stdio.h>
#include <stdlib.h>
int input(int a[], int frame_size) {
  int i;
  printf("\n Input \n");
  for (i = 1; i <= frame_size; i++) {
    printf("Enter the Value for frame[%d]: ", i);
    scanf("%d", &a[i]);
    printf("\n");
  }
  printf("\n\n");
  return 1;
}

int display(int a[], int frame_size) {
  printf("\n Display \n");
  for (int i = 1; i <= frame_size; i++) {
    printf("frames[%d]:%d", i, a[i]);
    printf("\n");
  }
  return 1;
}

int selective_repeat(int frames[], int window_size, int frame_size) {
  int nt = 0;
  int k = 0;
  int left[1000] = {-1};
  int i;
  for (i = 0; i <= frame_size; i++) {
    int flag = rand() % 2;
    if (flag) {
      printf("Frame[%d] with value %d is Acknowledged\n", i, frames[i]);
      nt++;
    } else {
      printf("Frame[%d] with value %d is not Acknowledged\n", i, frames[i]);
      left[k++] = frames[i];
      nt++;
    }
    printf("\n\n");
    if (i % window_size == 0) {
      for (int x = 0; x < k; x++) {
        printf("Frame[%d] with value %d is Retransmitted\n", i, left[i]);
        nt++;
        printf("Frame[%d] with value %d is Acknowledged on second attempt\n", i,
               left[i]);
      }
      k = 0;
    }
  }
  for (i = 0; i < k; i++) {
    printf("Frame[%d] with value %d is Retransmitted\n", i, left[i]);
    nt++;
    printf("Frame[%d] with value %d is Acknowledged on second attempt\n", i,
           left[i]);
  }
  printf("Total Transmissions: %d\n", nt);
}

int main() {
  int frames[50];
  int window_size;
  int frame_size;

  printf("Selective repeat \n");
  printf("Enter the Window Size: \n");
  scanf("%d", &window_size);
  printf("Enter the no of frames to be transmitted : \n");
  scanf("%d", &frame_size);
  input(frames, frame_size);
  display(frames, frame_size);
  selective_repeat(frames, window_size, frame_size);
  return 0;
}