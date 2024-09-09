/* High-School TOI */

/*After compiling run: 1. ./"binary_name"
 * 		       2. ./"binary_name" 8282
 * 		       You should see 0.0.0.0:8282 or 127.0.0.1:8282
 *          From here on open a new terminal to keep the program & webserver running
 * 		       3. netstat -an | grep LISTEN
 * 		       You should see:
 * 		       tcp		127.0.0.1:8282 
 * 		       4.env - telnet localhost*/

#include <netinet/in.h>
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

/*Local host: 127.0.0.1
* Public: 0.0.0.0       */
#define LISTENADDR "127.0.0.1"

/*global*/
char *error;

/* returns 0 on error, or it retrurns a socket fd
 * fd = "file descriptor"*/
int srv_init(int portno)
{
 int s;
 struct sockaddr_in srv;

 s = socket(AF_INET, SOCK_STREAM, 0);
 if (s < 0) {
  error = "socket() error";
  return 0;
 }
 
 srv.sin_family = AF_INET;
 srv.sin_addr.s_addr = inet_addr(LISTENADDR);
 srv.sin_port =htons(portno);


if ( bind(s, (struct sockaddr *)&srv, sizeof(srv))) {
 close(s);
 error = "bind() error";
 return 0;
}
if (listen(s, 5))
{
 close(s);
 error = "listen() error";
 return 0;
}
return s;
}

/*Returns 0 on error, or returns the new client's socket fd */
int cli_accept(int s) {
 int c;
 socklen_t addrlen;
 struct sockaddr_in cli;

 addrlen = 0;
 memset(&cli, 0, sizeof(cli));
 c = accept(s, (struct sockaddr *)&cli, &addrlen);
 if (c < 0)
 {
  error = "accept() error";
  return 0;
 }
 return c;
}
/* Dummy function*/
void cli_conn(int s, int c) {
return;
}

int main(int argc, char *argv[]) {
 int s, c;
 char *port;

 if (argc < 2)
 {
 fprintf(stderr, "Usage: %s <listiningport>\n", argv[0]);
 return -1;
 }
 else
  port = argv[1];

 s = srv_init(atoi(port));
 if (!s)
 {
  fprintf(stderr, "%s\n", error);
  return -1;
 }

 printf("Listening on %s:%s\n", LISTENADDR, port);
 while(1)
 {
 c = cli_accept(s);
 if (!c)
 {
  fprintf(stderr, "%s\n", error);
  continue;
 }

 printf("Incoming connection\n");
 if (!fork())
 cli_conn(s, c);
  /*For the main process: retrun the new  processes' is
   * for the new process: return 0*/
 return -1;
 }
}
