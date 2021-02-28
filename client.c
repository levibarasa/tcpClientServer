#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>

#define MAX 80
#define PORT 30000
#define SA struct sockaddr

void menu();
void prices();
void maxProfits();
void clientSocket();
void clientFunc(int sockfd);
bool clientSocket();
void clientPr();

int main () {
    menu();
   return 0;
}

void menu() {
int c;
    printf( " \n \n \n \t *******************TCP CLIENT SERVER PROGRAM MENU ************************* \n");
    printf( " \t press \n \n \t  (1) PRICES \n \t  (2) MAX PROFIT  \n \t  (3) QUIT \n \n \n \t \t");
   c = getchar();
switch(c) {
      case '1' :
         prices();
         break;
      case '2' :
         maxProfits();
         break;
      case '3' :
         exit(-1);
         break;
      default :
         printf("Invalid Choice\n" );
         menu();


   }

}
void prices() {
   char stockname[20];
   char stockdate[20];
    printf("Enter name of the stock(AAPL or TWTR) : ");
    scanf("%s", stockname);
    printf("Enter date of the stock: ");
    scanf("%s", stockdate);
    int sizeofname = sizeof(stockname);
    int sizeofdate = sizeof(stockdate);
    bool connected =  clientSocket();

   printf("Your name is %s and date %s", stockname,stockdate);

}
void maxProfits() {
   char stockname[20];
    printf("Enter name of the stock(AAPL or TWTR) :  ");
    scanf("%s", stockname);
    int sizeofname = sizeof(stockname);
     printf("Your name is %s ", stockname);
}
void func(int sockfd)
{
    char buff[MAX];
    int n;
    for (;;) {
        bzero(buff, sizeof(buff));
        //readFile here
        printf("Enter the string : ");
        n = 0;
        while ((buff[n++] = getchar()) != '\n')
            ;
        write(sockfd, buff, sizeof(buff));
        bzero(buff, sizeof(buff));
        read(sockfd, buff, sizeof(buff));
        printf("From Server : %s", buff);
        if ((strncmp(buff, "exit", 4)) == 0) {
            printf("Client Exit...\n");
            break;
        }
    }
}
void clientPr(){
printf("Prices AAPL 2018-09-06");
}
bool clientSocket(){
int sockfd, connfd;
    struct sockaddr_in servaddr, cli;
    bool isConnected = false;

    // socket create and varification
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("socket creation failed...\n");
        exit(0);
    }
    else
        printf("Socket successfully created..\n");
        bool isConnected = true;
    bzero(&servaddr, sizeof(servaddr));

    // assign IP, PORT
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    servaddr.sin_port = htons(PORT);

    // connect the client socket to server socket
    if (connect(sockfd, (SA*)&servaddr, sizeof(servaddr)) != 0) {
        printf("connection with the server failed...\n");
        exit(0);
    }
    else
        printf("connected to the server..\n");

    // function for chat
    func(sockfd);

    // close the socket
    close(sockfd);
    return isConnected;
}



