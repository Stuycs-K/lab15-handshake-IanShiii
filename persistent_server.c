#include <signal.h>

#include "pipe_networking.h"

int main() {
  signal(SIGINT, handle_sigint_server);
  signal(SIGPIPE, handle_sigpipe_server);

  int to_client;
  int from_client;

  from_client = server_handshake( &to_client );

  printf("server: to_client: %d\n", to_client);
  printf("server: from_client: %d\n", from_client);

  int value = 0;
  while (1) {
    value = rand() % 101;
    if (write(to_client, &value, sizeof(value)) == -1) {
        printf("server: failed to send value, waiting for new connection\n");
        close(to_client);
        close(from_client);
        from_client = server_handshake( &to_client );
    }
    else {
        printf("server: sent %d\n", value);
        sleep(1);
    }
  }
}
