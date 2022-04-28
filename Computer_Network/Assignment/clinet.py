from socket import *

serverName = '172.30.1.6'
serverPort = 80

def create_socket_and_send_message(request_message):
  # 클라이언트 소켓 만들기
  clienntSocket = socket(AF_INET, SOCK_STREAM)
  clienntSocket.connect((serverName, serverPort))
  clienntSocket.send(request_message.encode('utf-8'))

  # 응답확인
  receive_message = clienntSocket.recv(65535)
  print(receive_message.decode())

  clienntSocket.close()
  
   
request_message = 'HEAD / HTTP/1.1\r\n'
request_message += 'Host: ' + serverName + str(serverPort)+'\r\n'
request_message += 'Connection: Keep-Alive\n\n'
create_socket_and_send_message(request_message)

####################↑↑↑↑↑HEAD↑↑↑↑↑↑↑↑##############  
  


request_message = 'GET /index.html HTTP/1.1\r\n'
request_message += 'Host: ' + serverName + '\r\n'
request_message += 'Connection: Keep-Alive\n\n'
create_socket_and_send_message(request_message)

request_message = 'GET /Hello.html HTTP/1.1\r\n'
request_message += 'Host: ' + serverName + '\r\n'
request_message += 'Connection: Keep-Alive\n\n'
create_socket_and_send_message(request_message)  


####################↑↑↑↑↑GET↑↑↑↑↑↑↑↑##############


request_message = 'POST / HTTP/1.1\r\n'
request_message += 'Host: ' + serverName + '\r\n'
request_message += 'Connection: Keep-Alive\r\n'
## 전송데이터 없이 post 요청
create_socket_and_send_message(request_message)

request_message = 'POST / HTTP/1.1\r\n'
request_message += 'Host: ' + serverName + '\r\n'
request_message += 'Connection: Keep-Alive\r\n'
request_message += 'Data: data....\n\n'
create_socket_and_send_message(request_message)

####################↑↑↑↑↑POST↑↑↑↑↑↑↑↑##############


request_message = 'HEAD / HTTP/2\r\n'
request_message += 'Host: ' + serverName + '\r\n'
request_message += 'Connection: Keep-Alive\n\n'
create_socket_and_send_message(request_message)

####################↑↑↑↑↑ERROR HTTP VERISON↑↑↑↑↑↑↑↑##############