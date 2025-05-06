#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
  int bs, ip, n, cap, leak;

  printf("Enter the Bucket-Size: \n");
  scanf("%d", &bs);
  printf("Enter the LeakRate: \n");
  scanf("%d", &leak);
  printf("Enter the No of Inputs: \n");
  scanf("%d", &n);

  cap = bs;

  for (int i = 0; i < n; i++) {
    printf("Input: \n");
    scanf("%d", &ip);

    if (ip > cap) {
      printf("Insufficient Capacity: Packet Loss of %d has Occured!\n",
             ip - cap);
      
    } else {
      cap -= ip;
    }
    int time = 1;
    while (time > 0) {
      sleep(1);
      int leaked;
      if (leak < cap) {
        leaked = leak;
      } else {
        leaked = cap;
      }

      if (cap < 0) {
        cap = 0;
      }

      printf("Leaked Amount is: %d\n", leaked);
      printf("Remaining Capacity is: %d\n", cap);
      time--;
    }
    cap = bs;
    printf("Capacity refilled to: %d\n", cap);
  }
}