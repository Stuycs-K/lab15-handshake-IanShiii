#include "pipe_networking.h"

int main() {
  int to_client;
  int from_client;

  from_client = server_handshake( &to_client );

  printf("server: to_client: %d\n", to_client);
  printf("server: from_client: %d\n", from_client);

  int value = 0;
  while (1) {
    value = rand() % 101;
    if (write(to_client, &value, sizeof(value)) == -1) {
      exit(0);
    }
    printf("server: sent %d\n", value);
    sleep(1);
  }
}
