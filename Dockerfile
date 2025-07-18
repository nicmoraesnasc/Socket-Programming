# Base da imagem Docker a ser utilizada
FROM gcc:4.9

# Adicionar a camada que será o diretório padrão a ser utilizado
WORKDIR /app

# Comando para o container não parar após a leitura de todas as camadas
ENTRYPOINT ["tail", "-f", "/dev/null"]