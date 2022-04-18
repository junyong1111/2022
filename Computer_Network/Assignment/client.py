from http import client
from socket import *

ip = "127.0.0.1"
port = 8080

clinetSocket = socket(AF_INET, SOCK_STREAM)
clinetSocket.connect((ip,port))

print("연결 확인")
clinetSocket.send("I am a clinet".encode("utf-8"))

print("메시지 전송 완료")

msg = input()
clinetSocket.send(msg.encode("utf-8") )
print("메시지 전송 완료")

data = clinetSocket.recv(1024)

print("받은 데이터 : ",data.decode("utf-8"))
## clinetSocket.close()