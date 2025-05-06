#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
  char msg[40];
  struct sockaddr_in addr1;
  addr1.sin_family = AF_INET;
  addr1.sin_addr.s_addr = INADDR_ANY;
  addr1.sin_port = htons(3000); // Convert port number to network byte order

  int sockid = socket(AF_INET, SOCK_DGRAM, 0);
  if (sockid < 0) {
    perror("Socket creation failed");
    return 1;
  }

  if (connect(sockid, (struct sockaddr *)&addr1, sizeof(addr1)) < 0) {
    perror("Connect failed");
    close(sockid);
    return 1;
  }

  printf("Session Created\n");

  do {
    printf("Send-: ");
    if (fgets(msg, sizeof(msg), stdin) == NULL) {
      perror("Error reading from stdin");
      break;
    }
    msg[strcspn(msg, "\n")] = 0; // Remove newline character

    if (send(sockid, msg, strlen(msg), 0) < 0) {
      perror("Send failed");
      break;
    }

    if (strcmp(msg, "END") == 0) {
      break;
    }

    socklen_t addr_len = sizeof(addr1);
    if (recvfrom(sockid, msg, sizeof(msg), 0, (struct sockaddr *)&addr1,
                 &addr_len) < 0) {
      perror("Receive failed");
      break;
    }

    printf("Server-: %s\n", msg);
  } while (1);

  close(sockid);
  return 0;
}
