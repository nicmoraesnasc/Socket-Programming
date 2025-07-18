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

### 2. Executar com docker

#### Build da imagem:
```bash
docker build . -t socket-comm  
```

#### Criar e rodar o container com volume montado:
```bash
docker run -d --name app -v ${PWD}/volume:/app socket-comm
```

#### Acessar o terminal dentro do container:
```bash
docker exec -it app bash
```

### 3. Compilar (bash):

#### Servidor:
```bash
g++ server.cpp -o server
```

#### Cliente:
```bash
g++ client.cpp -o client
```

### 4. Rodar a aplicação:

#### Dentro do container, abra dois terminais bash separados
#### No primeiro terminal, execute o servidor:
```bash
./server
```

#### No segundo terminal, execute o cliente, enviando uma mensagem como argumento:
```bash
./client "mensagem para o servidor"
```

