создать образ 
docker build -t ip .

проверить образ ip
docker run -e TYPE=http://ip-api.com/json/ ip

поднять сервер nginx с ip.json на http://localhost:8080/
docker compose up

