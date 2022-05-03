from cgitb import html
import sys
from socket import *
from datetime import datetime
from urllib import request, response

# server_name = '127.0.0.1'
serverPort = 8080
serverSocket = socket(AF_INET, SOCK_STREAM) ## TCP 소켓 연결
serverSocket.bind(('', serverPort)) 

serverSocket.listen(5)

while True:
    
    client_socket, addr = serverSocket.accept()  ## 클라이언트와 연결
    data = client_socket.recv(65535)  ## 메시지 대기

    request_data = data.decode().split() ## 받은 요청을 해석
    request_method = request_data[0] ## 요청메소드
    request_item = request_data[1] ## 요청 아이템
    request_version = request_data[2] ## HTTP 버전
    request_body = request_data[-2:-1]
    print(data.decode())
     
    server_name = addr[0]  ## 접속한 클라이언트 주소
    
    if request_version == "HTTP/1.1": ## 정삭적인 HTTP 버전 요청
        
        if request_method == "GET": ## 정상적인 index.html 요청
            if request_item != "/index.html": ### Get 요청 실패
                response_data = "{0} 404 Error\nDate: {1}\nServer: {2}\n".format(request_version, 
                datetime.now().strftime('%a, %d %b %Y %H:%M:%S KST'), server_name)
            else:
                response_data = "{0} 200 OK\nDate: {1}\nServer: {2}\n".format(request_version, 
                datetime.now().strftime('%a, %d %b %Y %H:%M:%S KST'), server_name)
                with open ('index.html', 'r') as txt:
                    body = txt.readline()
                response_data +="\n"+ body
        
            
        elif request_method == "POST" : ## 정상적인 POST 요청
            if request_body[0] =='Data:': ## 요청 성공 +  전송할 Data가 있는 경우
                response_data = "{0} 200 OK\nDate: {1}\nServer: {2}\n".format(request_version, 
                datetime.now().strftime('%a, %d %b %Y %H:%M:%S KST'), server_name)
                
            else: ## 요청은 성공했지만 전송할 data가 없는경우
                response_data = "{0} 204 No content\nDate: {1}\nServer: {2}\n".format(request_version, 
                datetime.now().strftime('%a, %d %b %Y %H:%M:%S KST'), server_name)
            
            
        elif request_method == "HEAD" : ## 정상적이 HEAD 요청
            response_data = "{0} 200 OK\nDate: {1}\nServer: {2}\n".format(request_version, 
            datetime.now().strftime('%a, %d %b %Y %H:%M:%S KST'), server_name)
            
        else: ## 다른 메소드를 요청 오류
            response_data = "{0} 405 Method Not Allowed\nDate: {1}\nServer: {2}\n".format(request_version,
            datetime.now().strftime('%a, %d %b %Y %H:%M:%S KST'), server_name)
    else: ## 다른 HTTP 버전 요청 오류
        response_data = "{0} 505  HTTP version not supported\nDate: {1}\nServer: {2}\n".format(request_version,
        datetime.now().strftime('%a, %d %b %Y %H:%M:%S KST'), server_name)
            

    client_socket.send(response_data.encode())
    client_socket.close()