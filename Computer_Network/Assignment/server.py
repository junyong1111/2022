from http import server
from multiprocessing.connection import Connection
from socket import *

host = "127.0.0.1"
port = 8080

serverSocket = socket(AF_INET, SOCK_STREAM) ## TCP 소켓 생성
serverSocket.bind(("",port)) ## 생성한 소켓에 지정한 호스트와 포트에 맵핑
serverSocket.listen(1) ## 대기

while(True):
    print("입력 대기중")
    connectionSocket,addr = serverSocket.accept()
    print(str(addr), "에서 접속되었습니다.")
    connectionSocket.send("I am a server".encode("utf-8"))
    print("메시지를 보냈습니다.")
    
    
    try:
        data = connectionSocket.recv(1024)
        file_name = data.split()[1]
        f = open(file_name[1:])
        out = f.read()
        connectionSocket.send(str.encode("HTTP/1.1 200 OK\r\n\r\n"))
    except IOError:
            connectionSocket.send(str.encode("HTTP/1.1 404 Not Found\r\n\r\n"))
            connectionSocket.send(str.encode("<html><head></head><body><h1>404 Not Found</h1></body></html>\r\n"))
            connectionSocket.close()





data = data.decode("utf-8")
print(data)




## serverSocket.close()