# Aplicação Socket em C++ (Cliente/Servidor)

Este projeto implementa uma aplicação socket utilizando C++ com comunicação cliente-servidor via TCP/IP. O servidor aceita múltiplas conexões e mantém a comunicação ativa em loop, permitindo troca contínua de mensagens com os clientes.

Funcionalidades

- Comunicação cliente-servidor via TCP/IP
- Loop de envio/recebimento de mensagens
- Cliente recebe mensagem como argumento na linha de comando
- Uso de Docker para facilitar testes e execução
- Código simples e didático para fins de estudo

## Tecnologias utilizadas

- C++
- Sockets (Berkeley sockets)
- Docker
- Terminal/CLI

## Como executar

### 1. Clonar o repositório
```bash
git clone https://github.com/nicmoraesnasc/Socket-Programming.git
cd Socket-Programming 
```

### 2. Compilar os arquivos (modo local)

g++ server.cpp -o server

g++ client.cpp -o client

### 3. Executar (bash)

### Servidor:
./server

### Cliente:
./client "Sua mensagem aqui"

### 4. (Opcional) Executar com docker

### Build da imagem:
docker build -t socket-comm

### Criar e rodar o container com volume montado:
docker run -d --name app -v ${PWD}/volume:/app socket-comm

### Acessar o terminal dentro do container:
docker exec -it app bash

### Siga o passo 2 para compilar os arquivos
