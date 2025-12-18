лабораторная №1
Перед сборкой выполнить: apt-get -y install libcurl4-gnutls-dev gcc
сборка: build.sh

Для корректной работы приложения ip задать переменную TYPE:
export TYPE=http://ip-api.com/json/
или
export TYPE=https://jsonip.com/

лабораторная №2
создать образ 
docker build -t ip .

проверить образ ip
docker run -e TYPE=http://ip-api.com/json/ ip

поднять сервер nginx (вывод по адресу http://localhost:8080/ip.json)
docker compose up

лабораторная №3
добавлены файлы:
nginx-config.yaml
secret.yaml для env переменных
deployment.yaml
service.yaml
ingress.yaml

bash.sh содержит команды для запуска
