#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

struct dns_db {
  char name[50];
  char ip_addr[50];
};

int main() {
  char msg[256], res[50];
  int sockfd;
  int count = 0;
  struct dns_db db[10];
  FILE *f = fopen("base.txt", "r");
  if (!f) {
    perror("Failed to open file");
    return 1;
  }
  while (fscanf(f, "%49s %49s", db[count].name, db[count].ip_addr) == 2) {
    count++;
    if (count >= 10)
      break; // Prevent buffer overflow
  }
  fclose(f); // Properly close the file

  struct sockaddr_in addr1, addr2;
  addr1.sin_family = AF_INET;
  addr1.sin_addr.s_addr = INADDR_ANY;
  addr1.sin_port = htons(3000);
  sockfd = socket(AF_INET, SOCK_DGRAM, 0);
  if (sockfd < 0) {
    perror("Socket creation failed");
    return 1;
  }
  if (bind(sockfd, (struct sockaddr *)&addr1, sizeof(addr1)) < 0) {
    perror("Bind failed");
    close(sockfd);
    return 1;
  }
  printf("Server started\n");

  socklen_t len = sizeof(addr2);
  do {
    if (recvfrom(sockfd, msg, sizeof(msg) - 1, 0, (struct sockaddr *)&addr2,
                 &len) < 0) {
      perror("Recvfrom failed");
      break;
    }
    msg[sizeof(msg) - 1] = '\0'; // Ensure null-termination
    printf("Client-: %s\n", msg);
    if (strcmp(msg, "stop") == 0) {
      break;
    }
    strcpy(res, "Not Found");
    for (int i = 0; i < count; i++) {
      if (strcmp(db[i].name, msg) == 0) {
        strcpy(res, db[i].ip_addr);
        break;
      }
    }
    if (sendto(sockfd, res, strlen(res) + 1, 0, (struct sockaddr *)&addr2,
               len) < 0) {
      perror("Sendto failed");
      break;
    }
  } while (1);
  close(sockfd);
  return 0;
}
